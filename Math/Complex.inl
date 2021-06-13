#ifndef COMPLEX_INL
#define COMPLEX_INL

#include "Complex.h"

template <typename T>
Complex<T>::Complex() {
	real_ = 0;
	imaginary_ = 0;
};

template <typename T>
Complex<T>::Complex(const T& real, const T& imaginary) {
	real_ = real;
	imaginary_ = imaginary;
};

template <typename T>
T Complex<T>::getReal() const {
	return real_;
};

template <typename T>
T Complex<T>::getImaginary() const {
	return imaginary_;
};

template <typename T>
T Complex<T>::getAbsolute() const {
	return sqrt(pow(real_, 2) + pow(imaginary_, 2));
};

template <typename T>
T Complex<T>::getArgument() const {
	return atan2(imaginary_, real_);
};

template <typename T>
Complex<T> Complex<T>::getConjugate() const {
	return Complex<T>(real_, -imaginary_);
};

template <typename T>
void Complex<T>::setReal(const T& real) {
	real_ = real;
};

template <typename T>
void Complex<T>::setImaginary(const T& imaginary) {
	imaginary_ = imaginary;
};

template <typename T>
std::ostream& operator<<(std::ostream& stream, const Complex<T>& complex) {
	T real = complex.getReal();
	T imaginary = complex.getImaginary();

	if (real != 0) {
		stream << real;
		if (imaginary > 0)
			stream << "+";
	}

	if (imaginary != 0) {
		stream << imaginary << 'i';
	}

	if (real == 0 && imaginary == 0)
		stream << 0;

	return stream;
}

template <typename T>
std::istream& operator>>(std::istream& stream, Complex<T>& complex) {

	T real = 0, imaginary = 0;

	stream >> real;
	char sign = stream.peek();
	stream.ignore();

	if (sign == '+' || sign == '-') {
		if (stream.peek() == 'i')
			imaginary = 1;
		else
			stream >> imaginary;

		if (sign == '-')
			imaginary = -imaginary;
		if (stream.peek() == 'i')
			stream.ignore();
	}
	else if (sign == 'i') {
		imaginary = real;
		real = 0;
	}
	else {
		stream >> imaginary;
	}

	complex.setReal(real);
	complex.setImaginary(imaginary);

	return stream;
}

template <typename T>
Complex<T> operator+(const Complex<T>& left, const Complex<T>& right) {
	// Complex + Complex

	return Complex<T>(left.getReal() + right.getReal(), left.getImaginary() + right.getImaginary());
}

template <typename T>
Complex<T> operator-(const Complex<T>& left, const Complex<T>& right) {
	// Complex - Complex

	return Complex<T>(left.getReal() - right.getReal(), left.getImaginary() - right.getImaginary());
}

template <typename T>
Complex<T> operator*(const Complex<T>& left, const Complex<T>& right) {
	// Complex * Complex

	T real = left.getReal() * right.getReal() - left.getImaginary() * right.getImaginary();
	T imaginary = left.getReal() * right.getImaginary() + left.getImaginary() * right.getReal();
	return Complex<T>(real, imaginary);
}

template <typename T>
Complex<T> operator*(const T& left, const Complex<T>& right) {
	// scalar * Complex

	return Complex<T>(left * right.getReal(), left * right.getImaginary());
}

template <typename T>
Complex<T> operator*(const Complex<T>& left, const T& right) {
	// Complex * scalar

	return Complex<T>(right * left.getReal(), right * left.getImaginary());
}

template <typename T>
Complex<T> operator/(const Complex<T>& left, const Complex<T>& right) {
	// Complex / Complex

	Complex<T> temp = left * right.getConjugate();
	float denominator = (right * right.getConjugate()).getAbsolute();

	return Complex<T>(temp.getReal() / denominator, temp.getImaginary() / denominator);
}

#endif