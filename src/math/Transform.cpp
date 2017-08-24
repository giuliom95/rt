#include "Transform.h"

Transform Transform::T(const Vector& v)
{
	Matrix4x4 m {};
	m(3,0) = v.x; m(3,1) = v.y; m(3,2) = v.z;

	return {m};
}

double det3x3(const Matrix4x4& m)
{
	return 	m[0]*(m[5]*m[10] - m[6]*m[9])  +
			m[1]*(m[6]*m[8]  - m[4]*m[10]) +
			m[2]*(m[4]*m[9]  - m[5]*m[8]);
}

Matrix4x4 Transform::inv(const Matrix4x4& m)
{
	double det = det3x3(m);
	Matrix4x4 ret {
		m[5]*m[10] -  m[6]*m[9],  m[2]*m[9] - m[1]*m[10], m[1]*m[6] - m[2]*m[5], 0,
		 m[6]*m[8] - m[4]*m[10], m[0]*m[10] -  m[2]*m[8], m[2]*m[4] - m[0]*m[6], 0,
		 m[4]*m[9] -  m[5]*m[8],  m[1]*m[8] -  m[0]*m[9], m[0]*m[5] - m[1]*m[4], 0,
		0, 0, 0, 0
	};
	ret = (1/det)*ret;
	ret(3, 0) = -(m(3,0)*ret(0,0) + m(3,1)*ret(1,0) + m(3,2)*ret(2,0));
	ret(3, 1) = -(m(3,0)*ret(0,1) + m(3,1)*ret(1,1) + m(3,2)*ret(2,1));
	ret(3, 2) = -(m(3,0)*ret(0,2) + m(3,1)*ret(1,2) + m(3,2)*ret(2,2));
	ret(3, 3) = 1;
	return ret;
}