#include "AbstractComplex.h"

const math::Complex math::Complex::i = math::Complex(0, 1);

math::Complex::Complex()
	:AbstractComplex()
{

}

math::Complex::Complex(double real, double imaginary)
	:AbstractComplex(real,imaginary)
{
}

math::Complex::Complex(double real)
	:AbstractComplex(real)
{

}

std::ostream& math::operator<<(std::ostream& os, const Complex& z)
{
	return os << z.x << " + " << z.y << "i";
}
