#include"Vector.h"
#include"AbstractComplex.h"
#define ENDL std::cout<<'\n';

const math::Complex& i = math::Complex::i;

int main() {

	auto z = 12 + 7*i;
	z = pow(i, 2);

	z.Print();

	system("pause");

}

