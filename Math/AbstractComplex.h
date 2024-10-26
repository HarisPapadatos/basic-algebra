#pragma once
#include"Vector.h"
#include<sstream>

namespace math {

	template<typename Ty>
	class AbstractComplex;
	class Complex;

	template<typename Ty>
	class AbstractComplex
	{
	public:
		Ty x, y;

		AbstractComplex();
		AbstractComplex(Ty real ,Ty imaginary );
		AbstractComplex(Ty real);


		Vector2<Ty> GetVector()const;
		double Arg()const;
		double Length()const;

		std::string Str()const;
		std::string StrPolar()const;
		void Print()const;
		void PrintPolar()const;
		AbstractComplex<Ty> Conjugate()const;

		template<typename Ty2>
		AbstractComplex<Ty> operator+(const AbstractComplex<Ty2>& other)const ;
		template<typename Ty2>
		AbstractComplex<Ty> operator-(const AbstractComplex<Ty2>& other)const;
		template<typename Ty2>
		AbstractComplex<Ty> operator*(const AbstractComplex<Ty2>& other)const;
		template<typename Ty2>
		AbstractComplex<Ty> operator/(const AbstractComplex<Ty2>& other)const;

		template<typename Ty2>
		AbstractComplex<Ty> operator+(const Ty2& other)const;
		template<typename Ty2>
		AbstractComplex<Ty> operator-(const Ty2& other)const;
		template<typename Ty2>
		AbstractComplex<Ty> operator*(const Ty2& other)const;
		template<typename Ty2>
		AbstractComplex<Ty> operator/(const Ty2& other)const;

		AbstractComplex<Ty> operator-()const;
		

		template<typename Ty2>
		bool operator==(const AbstractComplex<Ty2>& other)const;

		template<typename Ty2>
		AbstractComplex<Ty>& operator+=(const AbstractComplex<Ty2>& other);
		template<typename Ty2>
		AbstractComplex<Ty>& operator-=(const AbstractComplex<Ty2>& other);
		template<typename Ty2>
		AbstractComplex<Ty>& operator*=(const AbstractComplex<Ty2>& other);
		template<typename Ty2>
		AbstractComplex<Ty>& operator/=(const AbstractComplex<Ty2>& other);

		template<typename Ty2>
		AbstractComplex<Ty>& operator+=(const Ty2& other);
		template<typename Ty2>
		AbstractComplex<Ty>& operator-=(const Ty2& other);
		template<typename Ty2>
		AbstractComplex<Ty>& operator*=(const Ty2& other);
		template<typename Ty2>
		AbstractComplex<Ty>& operator/=(const Ty2& other);

	private:

	};

	template<typename Ty>
	inline AbstractComplex<Ty>::AbstractComplex()
	{
	}

	template<typename Ty>
	inline AbstractComplex<Ty>::AbstractComplex(Ty real, Ty imaginary)
		:x{real}, y{imaginary}
	{
	}

	template<typename Ty>
	inline AbstractComplex<Ty>::AbstractComplex(Ty real)
		: x{ real }, y{ 0}
	{
	}

	template<typename Ty>
	inline Vector2<Ty> AbstractComplex<Ty>::GetVector()const
	{
		return Vector2<Ty>(x,y);
	}

	template<typename Ty>
	inline double AbstractComplex<Ty>::Arg()const
	{
		return atan2(y, x);
	}

	template<typename Ty>
	inline double AbstractComplex<Ty>::Length() const
	{
		return sqrt(x*x+y*y);
	}

	template<typename Ty>
	inline std::string AbstractComplex<Ty>::Str() const
	{
		std::stringstream ss;
		ss << x << " + " << y << "i";
		return ss.str();
	}

	template<typename Ty>
	inline std::string AbstractComplex<Ty>::StrPolar() const
	{
		std::stringstream ss;
		ss << Length() << "*e^(i" << Arg() << ")";
		return ss.str();
	}

	template<typename Ty>
	inline void AbstractComplex<Ty>::Print() const
	{
		std::cout << Str();
	}

	template<typename Ty>
	inline void AbstractComplex<Ty>::PrintPolar() const
	{
		std::cout << StrPolar();
	}

	template<typename Ty>
	inline AbstractComplex<Ty> AbstractComplex<Ty>::Conjugate()const
	{
		return AbstractComplex<Ty>(x, -y);
	}

	template<typename Ty>
	template<typename Ty2>
	inline AbstractComplex<Ty> AbstractComplex<Ty>::operator+(const AbstractComplex<Ty2>& other)const
	{
		return AbstractComplex<Ty>(x+other.x,y+other.y);
	}

	template<typename Ty>
	template<typename Ty2>
	inline AbstractComplex<Ty> AbstractComplex<Ty>::operator-(const AbstractComplex<Ty2>& other)const
	{
		return AbstractComplex<Ty>(x-other.x,y-other.y);
	}

	template<typename Ty>
	template<typename Ty2>
	inline AbstractComplex<Ty> AbstractComplex<Ty>::operator*(const AbstractComplex<Ty2>& other)const
	{
		return AbstractComplex<Ty>(x*other.x-y*other.y,x*other.y+y*other.x);
	}

	template<typename Ty>
	template<typename Ty2>
	inline AbstractComplex<Ty> AbstractComplex<Ty>::operator/(const AbstractComplex<Ty2>& other)const
	{
		constexpr Ty z = other.x * other.x + other.y * other.y;
		return AbstractComplex<Ty>((x * other.x + y * other.y)/z, (x * other.y - y * other.x)/z);
	}



	template<typename Ty>
	template<typename Ty2>
	inline AbstractComplex<Ty> AbstractComplex<Ty>::operator+(const Ty2& other)const
	{
		return AbstractComplex<Ty>(x + other, y);
	}

	template<typename Ty>
	template<typename Ty2>
	inline AbstractComplex<Ty> AbstractComplex<Ty>::operator-(const Ty2& other)const
	{
		return AbstractComplex<Ty>(x - other, y);
	}

	template<typename Ty>
	template<typename Ty2>
	inline AbstractComplex<Ty> AbstractComplex<Ty>::operator*(const Ty2& other)const
	{
		return AbstractComplex<Ty>(x * other, y*other);
	}

	template<typename Ty>
	template<typename Ty2>
	inline AbstractComplex<Ty> AbstractComplex<Ty>::operator/(const Ty2& other)const
	{
		return AbstractComplex<Ty>(x / other, y / other);
	}

	template<typename Ty>
	AbstractComplex<Ty> AbstractComplex<Ty>::operator-()const {
		return 0 - *this;
	}

	template<typename Ty>
	template<typename Ty2>
	bool AbstractComplex<Ty>::operator==(const AbstractComplex<Ty2>& other)const {
		return x == other.x && y == other.y;
	}

	template<typename Ty>
	template<typename Ty2>
	AbstractComplex<Ty>& AbstractComplex<Ty>::operator+=(const AbstractComplex<Ty2>& other) {
		*this = *this + other;
		return *this;
	}

	template<typename Ty>
	template<typename Ty2>
	AbstractComplex<Ty>& AbstractComplex<Ty>::operator-=(const AbstractComplex<Ty2>& other) {
		*this = *this - other;
		return *this;
	}


	template<typename Ty>
	template<typename Ty2>
	AbstractComplex<Ty>& AbstractComplex<Ty>::operator*=(const AbstractComplex<Ty2>& other) {
		*this = *this * other;
		return *this;
	}


	template<typename Ty>
	template<typename Ty2>
	AbstractComplex<Ty>& AbstractComplex<Ty>::operator/=(const AbstractComplex<Ty2>& other) {
		*this = *this / other;
		return *this;
	}


	template<typename Ty>
	template<typename Ty2>
	AbstractComplex<Ty>& AbstractComplex<Ty>::operator+=(const Ty2& other) {
		*this = *this + other;
		return *this;
	}


	template<typename Ty>
	template<typename Ty2>
	AbstractComplex<Ty>& AbstractComplex<Ty>::operator-=(const Ty2& other) {
		*this = *this - other;
		return *this;
	}


	template<typename Ty>
	template<typename Ty2>
	AbstractComplex<Ty>& AbstractComplex<Ty>::operator*=(const Ty2& other) {
		*this = *this * other;
		return *this;
	}


	template<typename Ty>
	template<typename Ty2>
	AbstractComplex<Ty>& AbstractComplex<Ty>::operator/=(const Ty2& other) {
		*this = *this / other;
		return *this;
	}



	template<typename Ty, typename Ty2>
	inline AbstractComplex<Ty> operator+(const Ty2& other,const AbstractComplex<Ty>& z)
	{
		return z+other;
	}

	template<typename Ty,typename Ty2>
	inline AbstractComplex<Ty> operator-(const Ty2& other, const AbstractComplex<Ty>& z)
	{
		return AbstractComplex<Ty>(other.x-z.x,-z.y);
	}

	template<typename Ty, typename Ty2>
	inline AbstractComplex<Ty> operator*(const Ty2& other, const AbstractComplex<Ty>& z)
	{
		return z*other;
	}

	template<typename Ty, typename Ty2>
	inline AbstractComplex<Ty> operator/(const Ty2& other, const AbstractComplex<Ty>& z)
	{
		return AbstractComplex<Ty>((other * z.x - other * z.y) / (z.x * z.x + z.y * z.y));
	}
	//Complex Number
	class Complex :public AbstractComplex<double> {
	public:

		Complex();
		Complex(double real, double imaginary);
		Complex(double real);

		static const Complex i;
	};

	std::ostream& operator<<(std::ostream& os, const Complex& z);


}	//public functions
	template<typename Ty>
	math::AbstractComplex<Ty> exp(const math::AbstractComplex<Ty>& z) {
		return exp(z.x) * math::AbstractComplex<Ty>(cos(z.y), sin(z.y));
	}

	template<typename Ty, typename Ty2>
	math::AbstractComplex<Ty> pow(const math::AbstractComplex<Ty>& z, const math::AbstractComplex<Ty2>& z2) {
		double l = log(z.Length()), t = z.Arg();
		Ty2 r = z.y * l + t * z2.x;
		return ::exp(z2.x*l-z2.y*t) * math::AbstractComplex<Ty>(cos(r),sin(r));
	}

	template<typename Ty, typename Ty2>
	math::AbstractComplex<Ty> pow(const math::AbstractComplex<Ty>& z,const Ty2& c) {
		double l = log(z.Length()), t = z.Arg();
		Ty r = t * c;
		return ::exp(c * l) * math::AbstractComplex<Ty>(cos(r), sin(r));
	}

	template<typename Ty, typename Ty2>
	math::AbstractComplex<Ty> abs(const math::AbstractComplex<Ty>& z) {
		return z.Length();
	}