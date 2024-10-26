#pragma once
#include"Vector.h"

namespace math {


	template<size_t Dimentions>
	class Line {
	private:
		typedef math::Vector<double, Dimentions> _vec;


	public:
		Line();
		Line(const _vec& direction, const _vec& bias); //From point to point

		void PointDefine(const _vec& from, const _vec& to);

		bool ContainsPoint(const _vec& p)const;
		bool IsParallelTo(const Line<Dimentions>& other)const;
		bool IsParallelTo(const _vec& other)const;
		bool IsIdentical(const Line<Dimentions>& other)const;
		bool IntersectionPoint(const Line<Dimentions>& other, _vec& intp)const;

		_vec Project(const _vec& vec);

		_vec direction, bias;

		bool isSemiLine;

	private:

	};




	class Line2D
	{
	public:
		Line2D();
		Line2D(double A, double B, double C); // For General Form
		Line2D(const Vector2d& p1, const Vector2d& p2); //From point to point
		Line2D(double slope, double yInt); // For y = mx + b form
		Line2D(double vertPosition); // For Vertical Lines
		Line2D(const Vector2d& pivot, double angle); //Rotation around Pivot

		
		bool ContainsPoint(const Vector2d& v)const;

		bool IsPerpendicularTo(const Vector2d& v)const;
		bool IsPerpendicularTo(const Line2D& other)const;

		bool IsParallelTo(const Vector2d& v)const;
		bool IsParallelTo(const Line2D& other)const;

		double AngleWith(const Vector2d& v)const;
		double AngleWith(const Line2D& other)const;

		bool IntercectionPoint(const Line2D& other, Vector2d& inxP)const;

		double DistanceFrom(Vector2d v)const;
		double Slope()const;
		double YIntercept()const;

		void setSlope(double slope);
		void setYIntercept(double yInt);
		void DirectionBiasDefine(const Vector2d& dir, const Vector2d& bias);
		void RotateAround(const Vector2d& pivot, double angle);

		double A, B, C;// General Form Ax + By = C

	private:



	};

	template<size_t Dimentions>
	inline Line<Dimentions>::Line()
		:direction{}, bias{}
	{

	}
	template<size_t Dimentions>
	inline Line<Dimentions>::Line(const _vec& direction, const _vec& bias)
		: direction{ direction }, bias{ bias }
	{

	}
	template<size_t Dimentions>
	inline void  Line<Dimentions>::PointDefine(const _vec& from, const _vec& to)
	{
		direction = to - from;
		bias = from;
	}
	template<size_t Dimentions>
	inline bool  Line<Dimentions>::ContainsPoint(const _vec& p) const
	{
		if (isSemiLine) 
			return direction.Dot(p - bias) == p.Length() * bias.Length();
		else 
			return abs(direction.Dot(p - bias)) == p.Length() * bias.Length();
	}

	template<size_t Dimentions>
	inline bool  Line<Dimentions>::IsParallelTo(const Line<Dimentions>& other) const
	{
		return abs(direction.Dot(other.direction)) == direction.Length() * other.direction.Length();
	}

	template<size_t Dimentions>
	inline bool Line<Dimentions>::IsParallelTo(const _vec& other) const
	{
		return abs(direction.Dot(other)) == direction.Length() * other.Length();
	}

	template<size_t Dimentions>
	inline bool  Line<Dimentions>::IsIdentical(const Line<Dimentions>& other) const
	{
		if(isSemiLine)
			return IsParallelTo(other) && ContainsPoint(other.bias);
		return IsParallelTo(other) && ContainsPoint(other.bias);
	}

	template<size_t Dimentions>
	inline bool  Line<Dimentions>::IntersectionPoint(const  Line<Dimentions>& other,_vec& intp) const
	{
		_vec v = other.bias - bias;
		double D = this->direction[1] * other.direction[0] - this->direction[0] * other.direction[1],
			Dt = v[1] * other.direction[0] - v[0] * other.direction[1],
			Ds = this->direction[0] * v[1] - this->direction[1] * v[0];
		double t, s;
		if (D == 0)
		{
			return false;
		}
		t = Dt / D;
		s = Ds / D;

		if (direction * Dt + bias == other.direction * t + other.bias) {
			intp = direction * Dt + bias;
			return true;
		}
		else
			return false;

		
	}

	template<size_t Dimentions>
	inline  Line<Dimentions>::_vec  Line<Dimentions>::Project(const Line<Dimentions>::_vec& vec)
	{
		return direction.Dot(vec)*direction/direction.Dot(direction);
	}
}

