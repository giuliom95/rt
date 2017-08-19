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

			Vector	operator+ (double d) {return {x+d, y+d, z+d};}
			Vector	operator- (double d) {return (*this)+(-d);}
			Vector	operator* (double d) {return {x*d, y*d, z*d};}
			void	operator+=(double d) {x += d; y += d; z += d;}
			void	operator-=(double d) {*this += -d;}
			void	operator*=(double d) {x *= d; y *= d; z *= d;}

			Vector	operator+ (const Vector& v) {return {x+v.x, y+v.y, z+v.z};}
			Vector	operator- (const Vector& v) {return (*this)+(-v);}
			void	operator+=(const Vector& v) {x += v.x; y += v.y; z += v.z;}
			void	operator-=(const Vector& v) {*this += -v;}


	inline static double dot(const Vector&, const Vector&);
};
inline Vector operator*(double d, Vector v) {return v*d;}



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