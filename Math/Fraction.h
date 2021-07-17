#pragma once

#include <stdexcept>
#include <iostream>

class Fraction
{
private:
	void normalize(int& numerator, int& denominator);
	int numerator, denominator;
public:
	Fraction();
	Fraction(int numerator, int denominator);

	int getNumerator() const;
	int getDenominator() const;
	float getValue() const;

	void setNumerator(int numerator);
	void setDenominator(int denominator);
};

std::ostream& operator<<(std::ostream& stream, const Fraction& fraction);
std::istream& operator>>(std::istream& stream, Fraction& fraction);
Fraction operator+(const Fraction& left, const Fraction& right);
Fraction operator-(const Fraction& left, const Fraction& right);
Fraction operator*(const Fraction& left, const Fraction& right);
Fraction operator/(const Fraction& left, const Fraction& right);