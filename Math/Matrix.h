#pragma once
#include"Vector.h"
#include<functional>
#include<vector>
#include<exception>

namespace math {


	template <typename Ty, size_t M, size_t N>
	class Matrix;
	template <typename Ty, size_t N>
	class SquareMatrix;

	// Templated Square Matrices
	template <typename Ty>
	using Matrix2x2 = SquareMatrix<Ty, 2>;
	template <typename Ty>
	using Matrix3x3 = SquareMatrix<Ty, 3>;
	template <typename Ty>
	using Matrix4x4 = SquareMatrix<Ty, 4>;

	// Templated Metrix Style Vectors
	template <typename Ty>
	using mVector2 = Matrix<Ty, 2, 1>;
	template <typename Ty>
	using mVector3 = Matrix<Ty, 3, 1>;
	template <typename Ty>
	using mVector4 = Matrix<Ty, 4, 1>;

	// Basic Square Matrices
	typedef Matrix2x2<double> Matrix2x2d;
	typedef Matrix2x2<float> Matrix2x2f;
	typedef Matrix2x2<int> Matrix2x2i;
	typedef Matrix2x2<unsigned> Matrix2x2u;

	typedef Matrix3x3<double> Matrix3x3d;
	typedef Matrix3x3<float> Matrix3x3f;
	typedef Matrix3x3<int> Matrix3x3i;
	typedef Matrix3x3<unsigned> Matrix3x3u;

	typedef Matrix4x4<double> Matrix4x4d;
	typedef Matrix4x4<float> Matrix4x4f;
	typedef Matrix4x4<int> Matrix4x4i;
	typedef Matrix4x4<unsigned> Matrix4x4u;

	// Basic Matrix Style Vectors
	typedef mVector2<double> mVector2d;
	typedef mVector2<float> mVector2f;
	typedef mVector2<int> mVector2i;
	typedef mVector2<unsigned> mVector2u;

	typedef mVector3<double> mVector3d;
	typedef mVector3<float> mVector3f;
	typedef mVector3<int> mVector3i;
	typedef mVector3<unsigned> mVector3u;

	typedef mVector4<double> mVector4d;
	typedef mVector4<float> mVector4f;
	typedef mVector4<int> mVector4i;
	typedef mVector4<unsigned> mVector4u;

	// Matrix Class Implementation
	template <typename Ty, size_t M, size_t N>
	class Matrix
	{
	public:
		Matrix();
		Matrix(Ty** elements);
		Matrix(const std::array<std::array<Ty,N>,M>& elements);

		math::Vector<Ty, N>& operator[](size_t rowIndex);
		const math::Vector<Ty, N>& operator[](size_t rowIndex)const;

		Matrix<Ty, N, M> Transpose()const;
		Ty& getElement(size_t rowIndex, size_t columnIndex);
		const Ty& getElement(size_t rowIndex, size_t columnIndex)const;
		virtual Matrix<Ty, M - 1, N - 1> SubMatrix(size_t rowIndex, size_t columnIndex)const;
		bool IsZero();

		void ReplaceRowWith(size_t row, const math::Vector<Ty,N>& v);
		void ReplaceColumnWith(size_t column, const math::Vector<Ty, M>& v);

		static const Matrix<Ty, M, N> zeroMatrix;

		template <typename Ty2>
		Matrix<Ty, M, N> operator+(const Matrix<Ty2, M, N>& other)const;
		template <typename Ty2>
		Matrix<Ty, M, N> operator-(const Matrix<Ty2, M, N>& other)const;
		template <typename Ty2, size_t P>
		Matrix<Ty, M, P> operator*(const Matrix<Ty2, N, P>& other)const;
		template <typename Ty2>
		Matrix<Ty, M, N> operator*(const Ty2& scalar)const;
		template <typename Ty2>
		Matrix<Ty, M, N> operator/(const Ty2& scalar)const;
		Matrix<Ty, M, N> operator-()const;

		template <typename Ty2>
		bool operator==(const Matrix<Ty2, M, N>& other)const;

		template <typename Ty2>
		Matrix<Ty, M, N>& operator+=(const Matrix<Ty2, M, N>& other)const;
		template <typename Ty2>
		Matrix<Ty, M, N>& operator-=(const Matrix<Ty2, M, N>& other)const;
		template <typename Ty2>
		Matrix<Ty, M, N>& operator*=(const Matrix<Ty2, N, N>& other)const;
		template <typename Ty2>
		Matrix<Ty, M, N>& operator*=(const Ty2& other)const;
		template <typename Ty2>
		Matrix<Ty, M, N>& operator/=(const Ty2& other)const;

	protected:

		static Matrix<Ty, M, N> GetZeroMatrix();
		std::array<math::Vector<Ty, N>, M> rows; //Array of Rows


	private:



	};

	// Static Member Variable Initialization
	template <typename Ty, size_t M, size_t N>
	const Matrix<Ty, M, N> Matrix<Ty, M, N>::zeroMatrix = Matrix<Ty, M, N>::GetZeroMatrix();

	// Foreign Functions Related to the class
	template <typename Ty, typename Ty2, size_t M, size_t N>
	Matrix<Ty, M, N> operator*(const Ty2& scalar, const Matrix<Ty, M, N>& m) {
		return m * scalar;
	}

	// Matrix Class Member Function Definitions
		//Constructors
	template<typename Ty, size_t M, size_t N>
	inline Matrix<Ty, M, N>::Matrix()
		:rows{}
	{

	}

	template<typename Ty, size_t M, size_t N>
	inline Matrix<Ty, M, N>::Matrix(Ty** elements)
		:rows{}
	{
		for (unsigned i = 0; i < M; i++)
			for (unsigned j = 0; j < N; j++)
				rows[i][j] = elements[i][j];
	}

	template<typename Ty, size_t M, size_t N>
	inline Matrix<Ty, M, N>::Matrix(const std::array<std::array<Ty, N>, M>& elements)
		:rows{}
	{
		for (unsigned i = 0; i < M; i++)
			for (unsigned j = 0; j < N; j++)
				rows[i][j] = elements[i][j];
	}

	//Operators
	template<typename Ty, size_t M, size_t N>
	template<typename Ty2>
	inline Matrix<Ty, M, N> Matrix<Ty, M, N>::operator+(const Matrix<Ty2, M, N>& other) const
	{
		Matrix<Ty, M, N> r;
		for (size_t i = 0; i < M; i++)
		{
			for (size_t j = 0; j < N; j++)
			{
				r.rows[i][j] = rows[i][j] + other.rows[i][j];
			}
		}


		return r;
	}

	template<typename Ty, size_t M, size_t N>
	template<typename Ty2>
	inline Matrix<Ty, M, N> Matrix<Ty, M, N>::operator-(const Matrix<Ty2, M, N>& other) const
	{
		Matrix<Ty, M, N> r;
		for (size_t i = 0; i < M; i++)
		{
			for (size_t j = 0; j < N; j++)
			{
				r.rows[i][j] = rows[i][j] - other.rows[i][j];
			}
		}


		return r;
	}

	template<typename Ty, size_t M, size_t N>
	template<typename Ty2, size_t P>
	inline Matrix<Ty, M, P> Matrix<Ty, M, N>::operator*(const Matrix<Ty2, N, P>& other) const
	{
		Matrix<Ty, M, N> r;
		for (size_t i = 0; i < M; i++)
		{
			for (size_t j = 0; j < P; j++)
			{
				r.rows[i][j] = 0;
				for (size_t k = 0; k < N; k++)
				{
					r.rows[i][j] += rows[i][k] * other.rows[k][j];
				}

			}
		}
		return r;
	}

	template<typename Ty, size_t M, size_t N>
	template<typename Ty2>
	inline Matrix<Ty, M, N> Matrix<Ty, M, N>::operator*(const Ty2& scalar) const
	{
		Matrix<Ty, M, N> r;
		for (size_t i = 0; i < M; i++)
		{
			for (size_t j = 0; j < N; j++)
			{
				r.rows[i][j] = rows[i][j] * scalar;
			}
		}


		return r;
	}

	template<typename Ty, size_t M, size_t N>
	template<typename Ty2>
	inline Matrix<Ty, M, N> Matrix<Ty, M, N>::operator/(const Ty2& scalar) const
	{
		Matrix<Ty, M, N> r;
		for (size_t i = 0; i < M; i++)
		{
			for (size_t j = 0; j < N; j++)
			{
				r.rows[i][j] = rows[i][j] / scalar;
			}
		}


		return r;
	}


	template<typename Ty, size_t M, size_t N>
	inline Matrix<Ty, M, N> Matrix<Ty, M, N>::operator-() const
	{
		Matrix<Ty, M, N> r;
		for (size_t i = 0; i < M; i++)
		{
			for (size_t j = 0; j < N; j++)
			{
				r.rows[i][j] = -rows[i][j];
			}
		}


		return r;
	}

	template<typename Ty, size_t M, size_t N>
	template<typename Ty2>
	inline bool Matrix<Ty, M, N>::operator==(const Matrix<Ty2, M, N>& other) const
	{
		for (size_t i = 0; i < M; i++)
			for (size_t j = 0; j < N; j++)
				if (rows[i][j] != other[i][j])
					return false;
		return true;
	}

	template<typename Ty, size_t M, size_t N>
	template<typename Ty2>
	inline Matrix<Ty, M, N>& Matrix<Ty, M, N>::operator+=(const Matrix<Ty2, M, N>& other) const
	{
		*this = *this + other;
		return *this;
	}

	template<typename Ty, size_t M, size_t N>
	template<typename Ty2>
	inline Matrix<Ty, M, N>& Matrix<Ty, M, N>::operator-=(const Matrix<Ty2, M, N>& other) const
	{
		*this = *this - other;
		return *this;
	}

	template<typename Ty, size_t M, size_t N>
	template<typename Ty2>
	inline Matrix<Ty, M, N>& Matrix<Ty, M, N>::operator*=(const Matrix<Ty2, N, N>& other) const
	{
		*this = *this * other;
		return *this;
	}

	template<typename Ty, size_t M, size_t N>
	template<typename Ty2>
	inline Matrix<Ty, M, N>& Matrix<Ty, M, N>::operator*=(const Ty2& other) const
	{
		*this = *this * other;
		return *this;
	}

	template<typename Ty, size_t M, size_t N>
	template<typename Ty2>
	inline Matrix<Ty, M, N>& Matrix<Ty, M, N>::operator/=(const Ty2& other) const
	{
		*this = *this / other;
		return *this;
	}


	template<typename Ty, size_t M, size_t N>
	inline math::Vector<Ty, N>& Matrix<Ty, M, N>::operator[](size_t rowIndex)
	{
		return rows[rowIndex];
	}

	template<typename Ty, size_t M, size_t N>
	inline const math::Vector<Ty, N>& Matrix<Ty, M, N>::operator[](size_t rowIndex) const
	{
		return rows[rowIndex];
	}



	//Other Member Functions
	template<typename Ty, size_t M, size_t N>
	inline Matrix<Ty, N, M> Matrix<Ty, M, N>::Transpose() const
	{
		Matrix<Ty, N, M> r;
		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < M; j++)
			{
				r.rows[i][j] = rows[j][i];
			}
		}
		return r;
	}

	template<typename Ty, size_t M, size_t N>
	inline Ty& Matrix<Ty, M, N>::getElement(size_t rowIndex, size_t columnIndex)
	{
		return rows[rowIndex][columnIndex];
	}

	template<typename Ty, size_t M, size_t N>
	inline const Ty& Matrix<Ty, M, N>::getElement(size_t rowIndex, size_t columnIndex) const
	{
		return rows[rowIndex][columnIndex];
	}

	template<typename Ty, size_t M, size_t N>
	inline Matrix<Ty, M - 1, N - 1> Matrix<Ty, M, N>::SubMatrix(size_t rowIndex, size_t columnIndex) const
	{

		if constexpr ((M >= 2 && N >= 2) && !(M != 2 || N != 2)) {
			Matrix<Ty, M - 1, N - 1> mtx();
			int r = 0, c = 0;

			for (size_t i = 0; i < M; i++)
			{
				if (i != rowIndex) {
					for (size_t j = 0; j < N; j++)
					{
						if (j != columnIndex) {
							mtx[r][c] = rows[i][j];
							c++;
						}
					}
					r++;
					c = 0;
				}
			}


			return mtx;
		}
		else
			throw std::runtime_error("Can't create submatrix!");
	}

	template<typename Ty, size_t M, size_t N>
	inline bool Matrix<Ty, M, N>::IsZero()
	{

		for (size_t i = 0; i < M; i++)
			for (size_t j = 0; j < N; j++)
				if (rows[i][j] != 0)return false;
		return true;
	}

	template<typename Ty, size_t M, size_t N>
	inline void Matrix<Ty, M, N>::ReplaceRowWith(size_t row, const math::Vector<Ty, N>& v)
	{
		for (size_t i = 0; i < N; i++)
		{
			rows[i][row] = v[i];
		}
	}

	template<typename Ty, size_t M, size_t N>
	inline void Matrix<Ty, M, N>::ReplaceColumnWith(size_t column, const math::Vector<Ty, M>& v)
	{
		for (size_t i = 0; i < M; i++)
		{
			rows[i][column] = v[i];
		}
	}

	template<typename Ty, size_t M, size_t N>
	inline Matrix<Ty, M, N> Matrix<Ty, M, N>::GetZeroMatrix()
	{
		Matrix<Ty, M, N> mtx;
		for (size_t i = 0; i < M; i++)
		{
			for (size_t j = 0; j < N; j++)
			{
				mtx[i][j] = 0;
			}
		}
		return mtx;

	}



	//Square Matrix Class
	template <typename Ty, size_t N>
	class SquareMatrix :public Matrix<Ty, N, N>
	{
	public:
		SquareMatrix();
		SquareMatrix(Ty** elements);
		SquareMatrix(const std::array<std::array<Ty, N>, N>& elements);

		Ty Trace()const;

		SquareMatrix<Ty, N> Inverse()const;
		SquareMatrix<Ty, N - 1> SubMatrix(size_t rowIndex, size_t columnIndex)const override;
		Ty Determinant()const;

		bool IsDiagonal();
		bool IsLowerTriangular();
		bool IsUpperTriangular();
		bool IsSymetric();
		bool IsSkewSymetric();
		bool IsUnit();
		bool IsOrthogonal();

		static const SquareMatrix<Ty, N> unitMatrix;

		template <typename Ty2>
		Vector<Ty2, N> operator*=(const Vector<Ty2, N>& other)const;

	protected:
		static SquareMatrix<Ty, N> GetUnitMatrix();

	private:


	};

	template<typename Ty, size_t N>
	const SquareMatrix<Ty, N> SquareMatrix<Ty, N>::unitMatrix = SquareMatrix<Ty, N>::GetUnitMatrix();

	template<typename Ty, size_t N>
	inline SquareMatrix<Ty, N>::SquareMatrix()
		:Matrix{}
	{

	}

	template<typename Ty, size_t N>
	inline SquareMatrix<Ty, N>::SquareMatrix(Ty** elements)
		:Matrix(elements)
	{
	}

	template<typename Ty, size_t N>
	inline SquareMatrix<Ty, N>::SquareMatrix(const std::array<std::array<Ty, N>, N>& elements)
		: Matrix(elements)
	{
	}

	template<typename Ty, size_t N>
	inline Ty SquareMatrix<Ty, N>::Trace() const
	{
		Ty r = 0;
		for (unsigned i = 0; i < N; i++)
		{
		
			r += this->rows[i][i];
		}
	}

	template<typename Ty, size_t N>
	inline SquareMatrix<Ty, N> SquareMatrix<Ty, N>::Inverse() const
	{
		SquareMatrix<Ty,N> mtx;

		if (N >= 3) {
			for (size_t i = 0; i < N; i++)
			{
				for (size_t j = 0; j < N; j++)
				{
					mtx[i][j] = SubMatrix(j, i).Determinant() * (i % 2 == 0 ? 1 : -1);
				}
			}
		}
		else if (N == 2)
		{
			mtx[0][0] = this->rows[1][1];
			mtx[0][1] = -this->rows[0][1];
			mtx[1][0] = -this->rows[1][0];
			mtx[1][1] = this->rows[0][0];
		}

		return mtx / Determinant();
	}

	template<typename Ty, size_t N>
	inline SquareMatrix<Ty, N - 1> SquareMatrix<Ty, N>::SubMatrix(size_t rowIndex, size_t columnIndex) const
	{
		if constexpr (N >= 3) {
			SquareMatrix<Ty, N-1> mtx();
			int r = 0, c = 0;

			for (size_t i = 0; i < N; i++)
			{
				if (i != rowIndex) {
					for (size_t j = 0; j < N; j++)
					{
						if (j != columnIndex) {
							mtx[r][c] = this->rows[i][j];
							c++;
						}
					}
					r++;
					c = 0;
				}
			}


			return mtx;
		}
		else
			throw std::runtime_error("Can't create submatrix!");
	}


	template<typename Ty, size_t N>
	inline Ty SquareMatrix<Ty, N>::Determinant() const
	{
		if constexpr (N <= 1) throw std::runtime_error("Can't calculate Determinant");


		if (N == 2)
		{
			return this->rows[0][0] * this->rows[1][1] - this->rows[0][1] * this->rows[1][0];
		}

		Ty r = 0;

		for (unsigned i = 0; i < N; i++)
		{
			r += this->rows[0][i] * (SubMatrix(0, i).Determinant()) * (i % 2 == 0 ? 1 : -1);
		}

		return r;
	}

	template<typename Ty, size_t N>
	inline bool SquareMatrix<Ty, N>::IsDiagonal()
	{
		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < N; j++)
			{
				if (i != j && this->rows[i][j] != 0)
					return false;
			}
		}
		return true;
	}

	template<typename Ty, size_t N>
	inline bool SquareMatrix<Ty, N>::IsLowerTriangular()
	{
		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < N; j++)
			{
				if (i < j && this->rows[i][j] != 0)
					return false;
			}
		}
		return true;
	}

	template<typename Ty, size_t N>
	inline bool SquareMatrix<Ty, N>::IsUpperTriangular()
	{
		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < N; j++)
			{
				if (i > j && this->rows[i][j] != 0)
					return false;
			}
		}
		return true;
	}

	template<typename Ty, size_t N>
	inline bool SquareMatrix<Ty, N>::IsSymetric()
	{
		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = i; j < N; j++)
			{
				if (this->rows[i][j] != this->rows[j][i])
					return false;
			}
		}
		return true;
	}

	template<typename Ty, size_t N>
	inline bool SquareMatrix<Ty, N>::IsSkewSymetric()
	{
		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = i; j < N; j++)
			{
				if (this->rows[i][j] != -this->rows[j][i])
					return false;
			}
		}
		return true;
	}

	template<typename Ty, size_t N>
	inline bool SquareMatrix<Ty, N>::IsUnit()
	{
		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = i; j < N; j++)
			{
				if (i == j)
				{
					if (this->rows[i][j] != 1)
						return false;
				}
				else {
					if(this->rows[i][j] != 0 )
						return false;
				}
			}
		}
		return true;
	}

	template<typename Ty, size_t N>
	inline bool SquareMatrix<Ty, N>::IsOrthogonal()
	{
		return *this * this->Transpose() == SquareMatrix<Ty, N>::unitMatrix;
	}

	template<typename Ty, size_t N>
	inline SquareMatrix<Ty, N> SquareMatrix<Ty, N>::GetUnitMatrix()
	{
		SquareMatrix<Ty, N> mtx;
		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < N; j++)
			{
				if (i == j)
					mtx[i][j] = 1;
				else
					mtx[i][j] = 0;
			}
		}
		return mtx;
	}

	template<typename Ty, size_t N>
	template<typename Ty2>
	inline Vector<Ty2, N> SquareMatrix<Ty, N>::operator*=(const Vector<Ty2, N>& other) const
	{
		Vector<Ty2, N> r{ math::Vector<Ty,N>::ZERO };
		for (size_t i = 0; i < N; i++)
		{
			for (size_t k = 0; k< N; k++)
			{
				r[i] += this->rows[i][k] * other[k];
			}
		}
		return r;

	}

	Matrix2x2d RotationMtx(double angle);
	Matrix3x3d RotationMtxX(double angle);
	Matrix3x3d RotationMtxY(double angle);
	Matrix3x3d RotationMtxZ(double angle);
}
