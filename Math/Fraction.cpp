#include "Fraction.h"

int gcd(int a, int b)
{
    a = std::abs(a); b = std::abs(b);

    // Everything divides 0
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    // base case
    if (a == b)
        return a;

    // a is greater
    if (a > b)
        return gcd(a - b, b);
    return gcd(a, b - a);
}

void Fraction::normalize(int& numerator, int& denominator) {
    if (denominator == 0)
        throw std::invalid_argument("Denominator can not be zero");

    if (numerator == 0) {
        denominator = 1;
    }

    int commonDivisor = gcd(numerator, denominator);

    if (commonDivisor != 0 && commonDivisor != 1) {
        numerator /= commonDivisor;
        denominator /= commonDivisor;
    }

    if ((numerator < 0 && denominator < 0) || (numerator > 0 && denominator < 0)) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

Fraction::Fraction() {
    numerator_ = 0;
    denominator_ = 1;
}

Fraction::Fraction(int numerator, int denominator) {
    normalize(numerator, denominator);

    numerator_ = numerator;
    denominator_ = denominator;
}

int Fraction::getNumerator() const {
    return numerator_;
}

int Fraction::getDenominator() const {
    return denominator_;
}

float Fraction::getValue() const {
    return (float)numerator_ / denominator_;
}

void Fraction::setNumerator(int numerator) {
    if (numerator != numerator_) {
        normalize(numerator, denominator_);
        numerator_ = numerator;
    }
}

void Fraction::setDenominator(int denominator) {
    if (denominator != denominator_) {
        normalize(numerator_, denominator);
        denominator_ = denominator;
    }
}

std::ostream& operator<<(std::ostream& stream, const Fraction& fraction){
    stream << '(' << fraction.getNumerator() << '/' << fraction.getDenominator() << ')';
    return stream;
};

std::istream& operator>>(std::istream& stream, Fraction& fraction) {
    int numerator, denominator;
    stream >> numerator;
    stream.ignore();
    stream >> denominator;

    fraction = Fraction(numerator, denominator);

    return stream;
};

Fraction operator+(const Fraction& left, const Fraction& right) {
    int numerator = left.getNumerator() * right.getDenominator() +
        right.getNumerator() * left.getDenominator();
    int denominator = left.getDenominator() * right.getDenominator();

    return Fraction(numerator, denominator);
}

Fraction operator-(const Fraction& left, const Fraction& right) {
    return left + Fraction(-right.getNumerator(), right.getDenominator());
}

Fraction operator*(const Fraction& left, const Fraction& right) {
    return Fraction(left.getNumerator() * right.getNumerator(),
        left.getDenominator() * right.getDenominator());
}

Fraction operator/(const Fraction& left, const Fraction& right) {
    return left * Fraction(right.getDenominator(), right.getNumerator());
}