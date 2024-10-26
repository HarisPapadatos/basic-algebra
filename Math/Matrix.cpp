#include "Matrix.h"

math::Matrix2x2d math::RotationMtx(double angle)
{
	return math::Matrix2x2d({ {
		{cos(angle),-sin(angle)},
		{sin(angle),cos(angle)}
		} });
}

math::Matrix3x3d math::RotationMtxX(double angle)
{
	return Matrix3x3d({ {
		{1,0,0},
		{0,cos(angle),-sin(angle)},
		{0,sin(angle),cos(angle)}
	} });
}

math::Matrix3x3d math::RotationMtxY(double angle)
{
	return Matrix3x3d({ {
		{cos(angle),0,sin(angle)},
		{0,1,0},
		{-sin(angle),0,cos(angle)}
	} });
}

math::Matrix3x3d math::RotationMtxZ(double angle)
{
	return Matrix3x3d({ {
		{cos(angle),-sin(angle),0},
		{sin(angle),cos(angle),0},
		{0,0,1}
	} });
}
