#include "Matrix4x4.h"

void pivot(int p, Matrix4x4& left, Matrix4x4& right)
{
	//Modify the pivot row
	const auto invPivot = 1 / left(p, p);
	for(auto j = 0; j < 4; ++j)
	{
		left(p, j)  *= invPivot;
		right(p, j) *= invPivot;
	}

	//Modify the other rows
	for(auto i = 0; i < 4; ++i)
		if(i != p)
		{
			const auto a = left(i, p);
			for(auto j = 0; j < 4; ++j)
			{
				left(i, j)  -= a*left(p, j);
				right(i, j) -= a*right(p, j);
			}
		}
}

Matrix4x4 Matrix4x4::inv()
{
	Matrix4x4 left = (*this);
	Matrix4x4 right {};

	pivot(0, left, right);
	pivot(1, left, right);
	pivot(2, left, right);
	pivot(3, left, right);

	return right;
}