#ifndef VECTOR_H
#define VECTOR_H
#include "../general.h"

class Vector
{
public:
	Float x, y, z;

	Vector() : x{0}, y{0}, z{0} {}
	Vector(Float x, Float y, Float z) : x{x}, y{y}, z{z} {}

	inline			Float& operator[](unsigned);
	inline const	Float& operator[](unsigned) const;
	
			Vector	operator- ()		{return {-x, -y, -z};}
	const	Vector	operator- () const	{return {-x, -y, -z};}

			Vector	operator+ (Float a) {return {x+a, y+a, z+a};}
			Vector	operator- (Float a) {return (*this)+(-a);}
			Vector	operator* (Float a) {return {x*a, y*a, z*a};}
			void	operator+=(Float a) {x += a; y += a; z += a;}
			void	operator-=(Float a) {*this += -a;}
			void	operator*=(Float a) {x *= a; y *= a; z *= a;}

			Vector	operator+ (const Vector& v) {return {x+v.x, y+v.y, z+v.z};}
			Vector	operator- (const Vector& v) {return (*this)+(-v);}
			void	operator+=(const Vector& v) {x += v.x; y += v.y; z += v.z;}
			void	operator-=(const Vector& v) {*this += -v;}


	inline static Float dot(const Vector&, const Vector&);
	inline static Vector cross(const Vector&, const Vector&);
	inline static Vector normalize(const Vector&);
	inline static Vector abs(const Vector&);

	// Builds a reference system from a single vector
	static std::pair<Vector, Vector> referenceSystem(const Vector&);
};
inline Vector operator*(Float a, Vector v) {return v*a;}



Float& Vector::operator[](unsigned idx)
{
	switch(idx) {case 0: return x; case 1: return y; case 2: return z;}
}

const Float& Vector::operator[](unsigned idx) const
{
	switch(idx) {case 0: return x; case 1: return y; case 2: return z;}
}

Float Vector::dot(const Vector& v1, const Vector& v2)
{
	return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}

Vector Vector::cross(const Vector& v1, const Vector& v2)
{
	return {v1.y*v2.z - v1.z*v2.y, v1.z*v2.x - v1.x*v2.z, v1.x*v2.y - v1.y*v2.x};
}

Vector Vector::normalize(const Vector& v)
{
	Float invLength = 1/std::sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
	return invLength*v;
}

Vector Vector::abs(const Vector& v)
{
	return {std::abs(v.x), std::abs(v.y), std::abs(v.z)};
}

#endif //VECTOR_H