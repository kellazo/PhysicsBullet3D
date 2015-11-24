#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	listener = NULL;
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	App->camera->LookAt(vec3(0, 0, 0));

	// TODO 3: create a sphere in the world with a primitive
	// and create a physics body for it. Remember to render it in Update()
	ball.radius = 1.0f;
	ball.axis = true;
	ball.SetPos(0, 1, 0);
	ball.color.Set(0, 0, 1, 1);
	b = App->physics->AddBody(ball);


	/*cil.radius = 1.0f;
	cil.axis = true;
	cil.SetPos(1, 1, 0);
	cil.color.Set(0, 1, 0, 1);
	c = App->physics->AddCylinder(cil,1.f,1,1,0);*/

	//box.Scale(12, 2, 6);
	box.size = 5;
	box.size.x = 30;
	box.axis = true;
	box.SetPos(4, 4, 8);
	box.color.Set(40, 0, 80, 1);
	pbox = App->physics->AddBox(box, 20, 5, 5, 1);


	/*planePrimitive.Scale(-1, 1, 1);
	planePrimitive.axis = true;
	planePrimitive.SetPos(10, 4, 9);
	vec3 plart(1, 1, 1);
	planePrimitive.SetRotation(RADTODEG * 1, plart);
	box.color.Set(0, 40, 100, 1);
	pPlane = App->physics->AddPlane(planePrimitive, 1, 1, 1, 1, 0);*/

	// TODO 5: Add this module to the list of collision listeners
	listener = App->scene_intro;
	b->collision_listeners.add(listener);
	//c->collision_listeners.add(listener);
	pbox->collision_listeners.add(listener);
	//pPlane->collision_listeners.add(listener);
		 
	

	
	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();
	//ball.Render();
	
 

	// TODO 4: update the transform of the shape to meet the
	// physics one
	b->GetTransform(&ball.transform);
	ball.Render();
	
	//c->GetTransform(&cil.transform);
	//cil.Render();

	pbox->GetTransform(&box.transform);
	//pbox->SetPos(30, 5, 5);
	box.Render();

	//pPlane->GetTransform(&planePrimitive.transform);
	//planePrimitive.Render();

	return UPDATE_CONTINUE;
}

// TODO 5: ... and define it for the ModuleScenario. Set the ball
// in red if it happens using is color property

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
	if (body1 != NULL && body2 != NULL)
	{
		ball.color.Set(1, 0, 0);
	}

	
}
