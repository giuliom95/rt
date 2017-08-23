#ifndef MATRIX4X4_H
#define MATRIX4X4_H

class Matrix4x4
{
	double values[16];
public:

	inline	Matrix4x4();
	inline	Matrix4x4(const Matrix4x4&);
	inline 	Matrix4x4(	double, double, double, double,
						double, double, double, double, 
						double, double, double, double, 
						double, double, double, double);

			double& 	operator[](unsigned idx)		{return values[idx];}
	const	double& 	operator[](unsigned idx) const	{return values[idx];}
			double& 	operator()(unsigned i, unsigned j)			{return values[i*4+j];}
	const	double& 	operator()(unsigned i, unsigned j) const 	{return values[i*4+j];}

	inline			Matrix4x4 	operator* (double);
	inline			Matrix4x4 	operator* (const Matrix4x4&);
	inline const	Matrix4x4	operator* (const Matrix4x4&) const;
	inline			Matrix4x4 	operator+ (const Matrix4x4&);

	inline	Matrix4x4 t();
			Matrix4x4 inv(); //To implement

			double* begin()			{return &values[0];}
	const	double* begin()	const	{return &values[0];}
			double* end()			{return &values[16];}
	const 	double* end()	const	{return &values[16];}
};
inline Matrix4x4 operator*(double a, Matrix4x4 m) {return m*a;}

#include "Matrix4x4.inl"

#endif //MATRIX4X4_H