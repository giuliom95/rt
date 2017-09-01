Matrix4x4::Matrix4x4() : values{
	1, 0, 0, 0,
	0, 1, 0, 0,
	0, 0, 1, 0,
	0, 0, 0, 1} {}

Matrix4x4::Matrix4x4(const Matrix4x4& m)
{
	auto i = 0;
	for(auto el : m)
	{
		values[i] = el;
		++i;
	}
}

Matrix4x4::Matrix4x4(	Float a00, Float a01, Float a02, Float a03,
						Float a10, Float a11, Float a12, Float a13, 
						Float a20, Float a21, Float a22, Float a23, 
						Float a30, Float a31, Float a32, Float a33)
{
	values[0]  = a00; values[1]  = a01; values[2]  = a02; values[3]  = a03;
	values[4]  = a10; values[5]  = a11; values[6]  = a12; values[7]  = a13;
	values[8]  = a20; values[9]  = a21; values[10] = a22; values[11] = a23;
	values[12] = a30; values[13] = a31; values[14] = a32; values[15] = a33;
}

Matrix4x4 Matrix4x4::operator*(Float a) 
{
	return {a*values[0],  a*values[1],  a*values[2],  a*values[3], 
			a*values[4],  a*values[5],  a*values[6],  a*values[7], 
			a*values[8],  a*values[9],  a*values[10], a*values[11], 
			a*values[12], a*values[13], a*values[14], a*values[15]};
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4& m) 
{
	Matrix4x4 r;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			r(i,j) =	values[4*i+0] * m(0, j) +
						values[4*i+1] * m(1, j) +
						values[4*i+2] * m(2, j) +
						values[4*i+3] * m(3, j);
	return r;
}

Matrix4x4 Matrix4x4::operator+(const Matrix4x4& m) 
{
	Matrix4x4 r;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			r(i,j) = m(i,j) + values[i*4+j];
	return r;
}

const Matrix4x4 Matrix4x4::operator*(const Matrix4x4& m) const
{
	Matrix4x4 r;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			r(i,j) =	values[4*i+0] * m(0, j) +
						values[4*i+1] * m(1, j) +
						values[4*i+2] * m(2, j) +
						values[4*i+3] * m(3, j);
	return r;
}

Matrix4x4 Matrix4x4::t()
{
	return {values[0], values[4], values[8],  values[12],
			values[1], values[5], values[9],  values[13],
			values[2], values[6], values[10], values[14],
			values[3], values[7], values[11], values[15]};
}

const Matrix4x4 Matrix4x4::t() const
{
	return {values[0], values[4], values[8],  values[12],
			values[1], values[5], values[9],  values[13],
			values[2], values[6], values[10], values[14],
			values[3], values[7], values[11], values[15]};
}