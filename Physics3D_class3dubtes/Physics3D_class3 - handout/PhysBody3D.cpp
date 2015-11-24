#include "PhysBody3D.h"
#include "glmath.h"
#include "Bullet\src\btBulletDynamicsCommon.h"

// TODO 4: Fill in PhysBody methods. Remember to use 
// get/setOpenGLMatrix methods

// ---------------------------------------------------------
PhysBody3D::PhysBody3D(btRigidBody* body)
{
	this->body = body;
}

// ---------------------------------------------------------
PhysBody3D::~PhysBody3D()
{}

// ---------------------------------------------------------
void PhysBody3D::GetTransform(float* matrix) const
{
	if (body != NULL && matrix != NULL)
	{
		body->getWorldTransform().getOpenGLMatrix(matrix);

	}
	
}

// ---------------------------------------------------------
void PhysBody3D::SetTransform(const float* matrix) const
{
	if (body != NULL && matrix != NULL)
	{
		body->getWorldTransform().setFromOpenGLMatrix(matrix);
	}
}

// ---------------------------------------------------------
void PhysBody3D::SetPos(float x, float y, float z)
{
	btVector3 pos(x, y, z);
	if (body != NULL )
	{
		body->getWorldTransform().setOrigin(pos);
	}
	
}
// ---------------------------------------------------------