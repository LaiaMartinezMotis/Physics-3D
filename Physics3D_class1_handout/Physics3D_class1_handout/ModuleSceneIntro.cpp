#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "ModuleCamera3D.h"

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
	
	// TODO 2: Place the camera one unit up in Y and one unit to the right
	// experiment with different camera placements, then use LookAt()
	// to make it look at the center
	
	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{
	Plane plane;
	// TODO 1: Create a Plane primitive. This uses the plane formula
	// so you have to express the normal of the plane to create 
	// a plane centered around 0,0. Make that it draw the axis for reference
	plane.SetPos(0, 0, 0);
	plane.Scale(30, 30, 30);
	
	plane.wire = true;
	plane.axis = true;
	plane.color.Set(0, 255, 0, 100);
    plane.Render();


	
	
	// TODO 6: Draw a sphere of 0.5f radius around the center
	// Draw somewhere else a cube and a cylinder in wireframe

	Sphere sphere;

	sphere.SetPos(0,0,0);
	sphere.Scale(20, 20, 20);

	sphere.wire = true;
	sphere.axis = true;
	sphere.color.Set(255, 0, 0, 100);
	sphere.Render();



	return UPDATE_CONTINUE;
}

