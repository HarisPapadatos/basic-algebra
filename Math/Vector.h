#pragma once

#include<array>
#include<iostream>

namespace math {

	template <typename Ty, size_t N>
	class Vector;
	template<typename Ty>
	class Vector2;
	template<typename Ty>
	class Vector3;
	template<typename Ty>
	class Vector4;

	typedef Vector2<float> Vector2f;
	typedef Vector2<int> Vector2i;
	typedef Vector2<unsigned> Vector2u;
	typedef Vector2<double> Vector2d;

	typedef Vector3<float> Vector3f;
	typedef Vector3<int> Vector3i;
	typedef Vector3<unsigned> Vector3u;
	typedef Vector3<double> Vector3d;

	typedef Vector4<float> Vector4f;
	typedef Vector4<int> Vector4i;
	typedef Vector4<unsigned> Vector4u;
	typedef Vector4<double> Vector4d;

	template <typename Ty, size_t N>
	class Vector
	{
	public:
		Vector();
		Vector(const std::array<Ty, N>& e);

		virtual double Length()const; //Returns Magnitude
		virtual Vector<Ty,N> Unit()const; //Return Unit Vector
		virtual void Print()const;
		virtual void PyPrint()const;
		virtual double AngleWith(const Vector<Ty,N>& other)const; //Returns the angle between this and another vector
		virtual Ty Dot(Vector<Ty, N> other)const;

		virtual Vector<Ty,N> operator+(const Vector<Ty,N>& other)const;
		virtual Vector<Ty,N> operator-(const Vector<Ty,N>& other)const;
		virtual Vector<Ty,N> operator*(const Ty& a)const;
		virtual Vector<Ty,N> operator/(const Ty& a)const;
		virtual Vector<Ty,N> operator-()const;

		virtual bool operator==(const Vector<Ty,N>& other)const;

		virtual Vector<Ty,N>& operator+=(const Vector<Ty,N>& other);
		virtual Vector<Ty,N>& operator-=(const Vector<Ty,N>& other);
		virtual Vector<Ty,N>& operator*=(const Ty& a);
		virtual Vector<Ty,N>& operator/=(const Ty& a);


		std::array<Ty, N> v;
		static const Vector<Ty,N> ZERO;

	private:
		static Vector<Ty, N> GetZeroVector();

	};

	template<typename Ty, size_t N>
	const Vector<Ty, N> Vector<Ty, N>::ZERO = Vector<Ty, N>::GetZeroVector();

	// 2D Vector
	template<typename Ty>
	class Vector2:public Vector<Ty,2>
	{
	public:
		
		Ty &x, &y;

		Vector2();
		Vector2(const Ty& x,const Ty& y);

		Vector3<Ty> Cross(const Vector2<Ty>& other)const;

		void ConsoleScan()const;
		

		static const Vector2<Ty> UP, DOWN, RIGHT, LEFT, ZERO, ONE;

	};

	template<typename Ty>
	const Vector2<Ty> Vector2<Ty>::UP = Vector2<Ty>(0, 1);
	template<typename Ty>
	const Vector2<Ty> Vector2<Ty>::DOWN = Vector2<Ty>(0, -1);
	template<typename Ty>
	const Vector2<Ty> Vector2<Ty>::RIGHT = Vector2<Ty>(1, 0);
	template<typename Ty>
	const Vector2<Ty> Vector2<Ty>::LEFT = Vector2<Ty>(-1, 0);
	template<typename Ty>
	const Vector2<Ty> Vector2<Ty>::ZERO = Vector2<Ty>(0, 0);
	template<typename Ty>
	const Vector2<Ty> Vector2<Ty>::ONE = Vector2<Ty>(1, 1);

	// 3D Vector

	template<typename Ty>
	class Vector3:public Vector<Ty,3>
	{
	public:

		Ty &x, &y, &z;

		Vector3();
		Vector3(const Ty& x, const Ty& y, const Ty& z);

		Vector3<Ty> Cross(const Vector3<Ty>& other)const;

		void ConsoleScan()const;

		static const Vector3<Ty> UP, DOWN, RIGHT, LEFT, BACK, FORWARD, ZERO, ONE;

	};

	template<typename Ty>
	const Vector3<Ty> Vector3<Ty>::UP = Vector3<Ty>(0, 0, 1);
	template<typename Ty>
	const Vector3<Ty> Vector3<Ty>::DOWN = Vector3<Ty>(0, 0, -1);
	template<typename Ty>
	const Vector3<Ty> Vector3<Ty>::RIGHT = Vector3<Ty>(1, 0,0);
	template<typename Ty>
	const Vector3<Ty> Vector3<Ty>::LEFT = Vector3<Ty>(-1, 0,0);
	template<typename Ty>
	const Vector3<Ty> Vector3<Ty>::BACK = Vector3<Ty>(0, 1,0);
	template<typename Ty>
	const Vector3<Ty> Vector3<Ty>::FORWARD = Vector3<Ty>(0, -1,0);
	template<typename Ty>
	const Vector3<Ty> Vector3<Ty>::ZERO = Vector3<Ty>(0, 0, 0);
	template<typename Ty>
	const Vector3<Ty> Vector3<Ty>::ONE = Vector3<Ty>(1, 1, 1);

	// 4D Vector

	template<typename Ty>
	class Vector4 :public Vector<Ty, 4>
	{
	public:

		Ty &x, &y, &z, &w;

		Vector4();
		Vector4(const Ty& x, const Ty& y, const Ty& z, const Ty& w);

		void ConsoleScan()const;

		static const Vector4<Ty> UP, DOWN, RIGHT, LEFT, BACK, FORWARD, ZERO, ONE, W_DIR;

	};

	template<typename Ty>
	const Vector4<Ty> Vector4<Ty>::UP = Vector4<Ty>(0, 0, 1, 0);
	template<typename Ty>
	const Vector4<Ty> Vector4<Ty>::DOWN = Vector4<Ty>(0, 0, -1, 0);
	template<typename Ty>
	const Vector4<Ty> Vector4<Ty>::RIGHT = Vector4<Ty>(1, 0, 0, 0);
	template<typename Ty>
	const Vector4<Ty> Vector4<Ty>::LEFT = Vector4<Ty>(-1, 0, 0, 0);
	template<typename Ty>
	const Vector4<Ty> Vector4<Ty>::BACK = Vector4<Ty>(0, 1, 0, 0);
	template<typename Ty>
	const Vector4<Ty> Vector4<Ty>::FORWARD = Vector4<Ty>(0, -1, 0, 0);
	template<typename Ty>
	const Vector4<Ty> Vector4<Ty>::ZERO = Vector4<Ty>(0, 0, 0, 0);
	template<typename Ty>
	const Vector4<Ty> Vector4<Ty>::ONE = Vector4<Ty>(1, 1, 1, 1);
	template<typename Ty>
	const Vector4<Ty> Vector4<Ty>::W_DIR = Vector4<Ty>(0, 0, 0, 1);

	//Vector 2 Defintions:

		//Constructors
	template<typename Ty>
	inline Vector2<Ty>::Vector2()
		:x{Vector<Ty,2>::v[0]}, y{Vector<Ty, 2>::v[1]}
	{}

	template<typename Ty>
	inline Vector2<Ty>::Vector2(const Ty& x,const Ty& y)
		:x{ Vector<Ty,2>::v[0]}, y{Vector<Ty, 2>::v[1]}
	{
		this->x = x;
		this->y = y;
	}

	template<typename Ty>
	inline Vector3<Ty> Vector2<Ty>::Cross(const Vector2<Ty>& other)const
	{
		return Vector3<Ty>(0,0,x*other.y-y*other.x);
	}

	template<typename Ty>
	inline void Vector2<Ty>::ConsoleScan() const
	{
		scanf_s("%lf, %lf", &x, &y);
	}


	template<typename Ty, size_t N>
	inline Vector<Ty, N>::Vector()
		:v{}
	{
	}

	template<typename Ty, size_t N>
	inline Vector<Ty, N>::Vector(const std::array<Ty, N>& e)
		:v{e}
	{
	}

	template<typename Ty, size_t N>
	inline double Vector<Ty, N>::Length()const
	{
		Ty s = 0;
		for (size_t i = 0; i < N; i++)
			s += abs(v[i] * v[i]);
		return sqrt(s);
	}

	template<typename Ty, size_t N>
	inline Vector<Ty, N> Vector<Ty, N>::Unit()const
	{
		return *this/Length();
	}

	template<typename Ty, size_t N>
	inline void Vector<Ty, N>::Print()const
	{
		for (size_t i = 0; i < N - 1; i++)
			std::cout << v[i] << ", ";
		std::cout << v[N - 1];
	}

	template<typename Ty, size_t N>
	inline void Vector<Ty, N>::PyPrint()const
	{
		std::cout << "[ ";
		for (size_t i = 0; i < N - 1; i++)
			std::cout << v[i] << ", ";
		std::cout << v[N - 1] << " ]";
	}

	template<typename Ty, size_t N>
	inline double Vector<Ty, N>::AngleWith(const Vector<Ty, N>& other)const
	{
		return acos(this->Dot(other)/(Length()*other.Length()));
	}

	template<typename Ty, size_t N>
	inline Ty Vector<Ty, N>::Dot(Vector<Ty, N> other) const
	{
		Ty r=0;
		for (size_t i = 0; i < N - 1; i++)
			r += v[i] * other.v[i];
		return r;
	}

	template<typename Ty, size_t N>
	inline Vector<Ty, N> Vector<Ty, N>::operator+(const Vector<Ty, N>& other)const
	{
		Vector<Ty, N> r;
		for (size_t i = 0; i < N - 1; i++)
			r.v[i] = v[i] + other.v[i];
		return r;
	}

	template<typename Ty, size_t N>
	inline Vector<Ty, N> Vector<Ty, N>::operator-(const Vector<Ty, N>& other)const
	{
		Vector<Ty, N> r;
		for (size_t i = 0; i < N - 1; i++)
			r.v[i] = v[i]-  other.v[i];
		return r;
	}

	template<typename Ty, size_t N>
	inline Vector<Ty, N> Vector<Ty, N>::operator*(const Ty& a)const
	{
		Vector<Ty, N> r;
		for (size_t i = 0; i < N - 1; i++)
			r.v[i] = v[i] * a;
		return r;
	}


	template<typename Ty, size_t N>
	inline Vector<Ty, N> Vector<Ty, N>::operator/(const Ty& a)const
	{
		Vector<Ty, N> r;
		for (size_t i = 0; i < N - 1; i++)
			r.v[i] = v[i]/ a;
		return r;
	}


	template<typename Ty, size_t N>
	inline Vector<Ty, N> Vector<Ty, N>::operator-()const
	{
		Vector<Ty, N> r;
		for (size_t i = 0; i < N - 1; i++)
			r.v[i] = - v[i];
		return r;
	}

	template<typename Ty, size_t N>
	inline bool Vector<Ty, N>::operator==(const Vector<Ty,N>& other)const
	{
		for (size_t i = 0; i < N - 1; i++)
			if (v[i] != other.v[i])return false;
		return true;
	}

	template<typename Ty, size_t N>
	inline Vector<Ty, N>& Vector<Ty, N>::operator+=(const Vector<Ty, N>& other)
	{
		*this = *this + other;
		return *this;
	}

	template<typename Ty, size_t N>
	inline Vector<Ty, N>& Vector<Ty, N>::operator-=(const Vector<Ty, N>& other)
	{
		*this = *this - other;
		return *this;
	}

	template<typename Ty, size_t N>
	inline Vector<Ty, N>& Vector<Ty, N>::operator*=(const Ty& a)
	{
		*this = *this *a;
		return *this;
	}


	template<typename Ty, size_t N>
	inline Vector<Ty, N>& Vector<Ty, N>::operator/=(const Ty& a)
	{
		*this = *this / a;
		return *this;
	}

	template<typename Ty, size_t N>
	inline Vector<Ty, N> Vector<Ty, N>::GetZeroVector()
	{
		Vector<Ty, N> r;
		for (int i = 0; i < N; i++)
			r[i] = 0;
		return r;
	}

	//Vector 3 Defintions


	template<typename Ty>
	inline Vector3<Ty>::Vector3()
		:x{Vector<Ty,3>::v[0]},y { Vector<Ty,3>::v[1] }, z{ Vector<Ty,3>::v[2] }
	{
		scanf_s("%lf, %lf, %lf", &x, &y, &z);
	}

	template<typename Ty>
	inline Vector3<Ty>::Vector3(const Ty& x, const Ty& y, const Ty& z)
		: x{ Vector<Ty,3>::v[0] }, y{ Vector<Ty,3>::v[1] }, z{ Vector<Ty,3>::v[2] }
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	template<typename Ty>
	inline Vector3<Ty> Vector3<Ty>::Cross(const Vector3<Ty>& other)const
	{
		return Vector3<Ty>(y*other.z-other.y*z,z*other.x-x*other.z,x*other.y-y*other.x);
	}

	template<typename Ty>
	inline void Vector3<Ty>::ConsoleScan() const
	{

	}

	//Vector 4 Defintions
	template<typename Ty>
	inline Vector4<Ty>::Vector4()
		:x{ Vector<Ty,4>::v[0] }, y{ Vector<Ty,4>::v[1] }, z{ Vector<Ty,4>::v[2] }, w{ Vector<Ty,4>::v[3] }
	{
	}

	template<typename Ty>
	inline Vector4<Ty>::Vector4(const Ty& x, const Ty& y, const Ty& z, const Ty& w)
		: x{ Vector<Ty,4>::v[0] }, y{ Vector<Ty,4>::v[1] }, z{ Vector<Ty,4>::v[2] }, w{ Vector<Ty,4>::v[3] }
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}	

	template<typename Ty>
	inline void Vector4<Ty>::ConsoleScan() const
	{
		scanf_s("%lf, %lf, %lf, %lf", &x, &y, &z, &w);
	}

	template<typename Ty>
	Ty Determinant(const Vector2<Ty>& v1, const Vector2<Ty>& v2)
	{
		return v1[0] * v2[1] - v1[1] * v2[0];
	}

	template<typename Ty>
	Ty Slope(const Vector2<Ty>& v)
	{
		return v[1] / v[0];
	}

	template<typename Ty>
	double Angle(const Vector2<Ty>& v)
	{
		return atan2(v[1],v[0]);
	}
};

//Scalar Multiplication operations
template<typename Ty,size_t N>
math::Vector<Ty, N> operator*(Ty a, const math::Vector<Ty,N>& v) {
	return v * a;
}

//Printing with cout
template<typename Ty, size_t N>
std::ostream& operator<<(std::ostream& os, math::Vector<Ty,N> v) {

	for (size_t i= 0; i < N; i++)
		os << v[i];
	return os;
}


template<typename Ty>
std::ostream& operator<<(std::ostream& os, math::Vector2<Ty> v) {
	return os << v.x << ", " << v.y;
}

