#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
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

	// TODO 2: Chain few N spheres together to form a snake

	for (int i = 0; i < MAX_SNAKE; i++) {
		s_snake[i] = Sphere(1.0F);
		s_snake[i].color.Set(0.50*i,0.00*i,0.60*i,1.0);
		pb_snake[i] = App->physics->AddBody(s_snake[i]);
	}

	
	for (int i = 0; i < MAX_SNAKE-1; i++) {
	App->physics->AddConstraintP2P(*pb_snake[i], *pb_snake[i+1], { 0,0,0 }, {3,0,0});
	}

	// TODO 4: Chain few N spheres together to form a a bike's sphere
	// Be sure to put the right axis

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

	
	for(int i = 0; i < MAX_SNAKE; ++i)
	{
		pb_snake[i]->GetTransform(&(s_snake[i].transform));
		s_snake[i].Render();
	}

	/*for(int i = 0; i < MAX_SNAKE; ++i)
	{
		pb_snake2[i]->GetTransform(&(s_snake2[i].transform));
		s_snake2[i].Render();
	}*/

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

