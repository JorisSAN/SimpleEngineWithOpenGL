#include "Cube.h"
#include "MeshComponent.h"
#include "Asset.h"

Cube::Cube() :
	rotation(Vector2(0.0f, 0.0f)),
	velocite(Vector2(0.0f,0.0f)),
	tourne(false),
	x1(0),
	xMouse(0)
{
	MeshComponent* mc = new MeshComponent(this);
	mc->setMesh(Assets::getMesh("Mesh_Cube"));
}

void Cube::updateActor(float dt)
{
	Quaternion q;
	if (tourne)
	{
		SDL_GetMouseState(&xMouse, NULL);
		rotation = Vector2((x1 - xMouse) / 20, 0.0f);
		q = Quaternion::concatenate(q, Quaternion(Vector3::unitZ, rotation.x / 100));
		setRotation(q);
	}
	else
	{
		q = Quaternion::concatenate(q, Quaternion(Vector3::unitZ, rotation.x / 100));
		setRotation(Quaternion::concatenate(getRotation(), q));
	}
}

void Cube::actorInput(SDL_MouseButtonEvent& mouseEvent)
{
	if (mouseEvent.button == SDL_BUTTON_LEFT && mouseEvent.type == SDL_MOUSEBUTTONDOWN)
	{
		tourne = true;
		SDL_GetMouseState(&x1, NULL);
	}
	if (mouseEvent.button == SDL_BUTTON_LEFT && mouseEvent.type == SDL_MOUSEBUTTONUP)
	{
		tourne = false;
	}
}