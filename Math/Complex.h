#pragma once

#include <math.h>
#include <iostream>

template <typename T>
class Complex
{
private:
	T imaginary_, real_;
public:
	Complex();
	Complex(const T& real, const T& imaginary);

	T getReal() const;
	T getImaginary() const;

	T getAbsolute() const;
	T getArgument() const;
	Complex<T> getConjugate() const;

	void setReal(const T& real);
	void setImaginary(const T& imaginary);
};

#include "Complex.inl"