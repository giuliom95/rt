#include "Transform.h"

Transform Transform::T(const Vector& v)
{
	Matrix4x4 m {};
	m(3,0) = v.x; m(3,1) = v.y; m(3,2) = v.z;
	
	Matrix4x4 mInv {};
	mInv(3,0) = -v.x; mInv(3,1) = -v.y; mInv(3,2) = -v.z;

	return {m, mInv};
}