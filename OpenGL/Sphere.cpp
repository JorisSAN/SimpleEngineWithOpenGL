#include "Sphere.h"
#include "MeshComponent.h"
#include "Asset.h"

Sphere::Sphere() : Actor()
{
	MeshComponent* mc = new MeshComponent(this);
	mc->setMesh(Assets::getMesh("Mesh_Sphere"));
}