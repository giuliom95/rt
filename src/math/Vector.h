#ifndef VECTOR_H
#define VECTOR_H

class Vector
{
public:
	double x, y, z;

	Vector() : x{0}, y{0}, z{0} {}
	Vector(double x, double y, double z) : x{x}, y{y}, z{z} {}

	inline			double& operator[](unsigned);
	inline const	double& operator[](unsigned) const;
	
			Vector	operator- ()		{return {-x, -y, -z};}
	const	Vector	operator- () const	{return {-x, -y, -z};}

			Vector	operator+ (double a) {return {x+a, y+a, z+a};}
			Vector	operator- (double a) {return (*this)+(-a);}
			Vector	operator* (double a) {return {x*a, y*a, z*a};}
			void	operator+=(double a) {x += a; y += a; z += a;}
			void	operator-=(double a) {*this += -a;}
			void	operator*=(double a) {x *= a; y *= a; z *= a;}

			Vector	operator+ (const Vector& v) {return {x+v.x, y+v.y, z+v.z};}
			Vector	operator- (const Vector& v) {return (*this)+(-v);}
			void	operator+=(const Vector& v) {x += v.x; y += v.y; z += v.z;}
			void	operator-=(const Vector& v) {*this += -v;}


	inline static double dot(const Vector&, const Vector&);
	inline static Vector cross(const Vector&, const Vector&);
};
inline Vector operator*(double a, Vector v) {return v*a;}



double& Vector::operator[](unsigned idx)
{
	switch(idx) {case 0: return x; case 1: return y; case 2: return z;}
}

const double& Vector::operator[](unsigned idx) const
{
	switch(idx) {case 0: return x; case 1: return y; case 2: return z;}
}

double Vector::dot(const Vector& v1, const Vector& v2)
{
	return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}

Vector Vector::cross(const Vector& v1, const Vector& v2)
{
	return {v1.y*v2.z - v1.z*v2.y, v1.z*v2.x - v1.x*v2.z, v1.x*v2.y - v1.y*v2.x};
}


#endif //VECTOR_H