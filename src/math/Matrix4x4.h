#ifndef MATRIX4X4_H
#define MATRIX4X4_H
#include "../general.h"

class Matrix4x4
{
	Float values[16];
public:

	inline	Matrix4x4();
	inline	Matrix4x4(const Matrix4x4&);
	inline 	Matrix4x4(	Float, Float, Float, Float,
						Float, Float, Float, Float, 
						Float, Float, Float, Float, 
						Float, Float, Float, Float);

					Float& 	operator[](unsigned idx)		{return values[idx];}
	const			Float& 	operator[](unsigned idx) const	{return values[idx];}
					Float& 	operator()(unsigned i, unsigned j)			{return values[i*4+j];}
	const			Float& 	operator()(unsigned i, unsigned j) const 	{return values[i*4+j];}

	inline			Matrix4x4	operator* (Float);
	inline			Matrix4x4	operator* (const Matrix4x4&);
	inline const	Matrix4x4	operator* (const Matrix4x4&) const;
	inline			Matrix4x4	operator+ (const Matrix4x4&);

	inline			Matrix4x4 t();
	inline const	Matrix4x4 t() const;
					Matrix4x4 inv(); //To implement

			Float* begin()			{return &values[0];}
	const	Float* begin()	const	{return &values[0];}
			Float* end()			{return &values[16];}
	const 	Float* end()	const	{return &values[16];}
};
inline Matrix4x4 operator*(Float a, Matrix4x4 m) {return m*a;}

#include "Matrix4x4.inl"

#endif //MATRIX4X4_H