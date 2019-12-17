#ifndef __PhysBody3D_H__
#define __PhysBody3D_H__

#include "p2List.h"
#include "glmath.h"
#include "Bullet/include/LinearMath/btScalar.h"

class btRigidBody;
class Module;





// =================================================
struct PhysBody3D
{
	friend class ModulePhysics3D;
public:
	PhysBody3D(btRigidBody* body);
	PhysBody3D(btRigidBody* body, ContactType type);
	~PhysBody3D();

	void Push(float x, float y, float z);
	void GetTransform(float* matrix) const;
	void SetTransform(const float* matrix) const;
	void SetPos(float x, float y, float z);
	vec3 GetPos() const;
	vec3 GetFoward();
	void SetAsSensor(bool IsSensor);
	void SetRestitution(btScalar restitution);

	ContactType cntType;
	bool is_sensor, sensorOnline, isInvisible;
	float innerSensorTimer;

private:
	btRigidBody* body = nullptr;

public:
	p2List<Module*> collision_listeners;
};

#endif // __PhysBody3D_H__