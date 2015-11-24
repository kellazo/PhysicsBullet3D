#pragma once
#include "Module.h"
#include "p2DynArray.h"
#include "Globals.h"
#include "Primitive.h"

struct PhysBody3D;

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

	void OnCollision(PhysBody3D* body1, PhysBody3D* body2);

public:
	Module* listener;
	PhysBody3D* b;
	Sphere ball;
	PhysBody3D* c;
	Cylinder cil;
	Cube box;
	PhysBody3D* pbox;
	Plane planePrimitive;
	PhysBody3D* pPlane;

};
