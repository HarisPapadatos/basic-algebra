#include "Line.h"

math::Line2D::Line2D()
	:A{}, B{}, C{}
{
}

math::Line2D::Line2D(double A, double B, double C)
	: A{ A }, B{ B }, C{ C }
{
}

math::Line2D::Line2D(const Vector2d& p1, const Vector2d& p2)
	: A{}, B{}, C{}
{
	double Det = Determinant(p1, p2);
	if (Det == 0) {
		C = 0;
		A = p1.x;
		B = -p1.y;
	}
	else {
		C = 1;
		A = (p2.y - p1.y) / Det;
		B = (p1.x - p2.x) / Det;
	}
}

math::Line2D::Line2D(double slope, double yInt)
{
	B = 1;
	A = -slope;
	C = yInt;
}

math::Line2D::Line2D(double vertPosition)
{
	B = 0;
	A = 1;
	C = vertPosition;
}

math::Line2D::Line2D(const Vector2d& pivot, double angle)
{
	if (cos(angle) == 0)
	{
		B = 0;
		A = 1;
		C = pivot.x;
	}
	else {
		double slope = tan(angle);
		C = pivot.y - slope * pivot.x;
		B = 1;
		A = -slope;
	}
}

bool math::Line2D::ContainsPoint(const Vector2d& v) const
{
	return A*v.x+B*v.y==C;
}

bool math::Line2D::IsPerpendicularTo(const Vector2d& v) const
{
	return A * v.y == B * v.x;
}

bool math::Line2D::IsPerpendicularTo(const Line2D& other) const
{
	return A*other.A == -B * other.B;
}

bool math::Line2D::IsParallelTo(const Vector2d& v) const
{
	return A * v.x == -B * v.y;
}

bool math::Line2D::IsParallelTo(const Line2D& other) const
{
	return A * other.B == B * other.A;
}

double math::Line2D::AngleWith(const Vector2d& v) const
{
	Vector2d a{B,-A};
	return acos(v.Dot(a)/(a.Length()*v.Length()));
}

double math::Line2D::AngleWith(const Line2D& other) const
{
	Vector2d a{ A,B }, b {other.B,other.A};
	return acos(b.Dot(a) / (a.Length() * b.Length()));
	return 0.0;
}

bool math::Line2D::IntercectionPoint(const Line2D& other, Vector2d& inxP) const
{
	double D = A * other.B - B * other.A, Dx = C * other.B - B * other.C, Dy = A * other.C - C * other.A;
	if (D == 0)
	{
		return false;
	}
	else {
		inxP = Vector2d(Dx/D, Dy/D);
		return true;
	}

}

double math::Line2D::DistanceFrom(Vector2d v) const
{
	return 0.0;
}

double math::Line2D::Slope() const
{
	return 0.0;
}

double math::Line2D::YIntercept() const
{
	return 0.0;
}

void math::Line2D::setSlope(double slope)
{
}

void math::Line2D::setYIntercept(double yInt)
{
}

void math::Line2D::DirectionBiasDefine(const Vector2d& dir, const Vector2d& bias)
{
}

void math::Line2D::RotateAround(const Vector2d& pivot, double angle)
{
}
