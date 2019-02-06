#ifndef RATIONAL_H
#define RATIONAL_H

#include "coursera.h"

class Rational {
public:
	Rational(int numerator = 0, int denominator = 1);	//	как в решении будут сделаны конструкторы???

	int Numerator() const;
	int Denominator() const;
	
private:
	int numerator;
	int denominator;
};

bool operator==(const Rational& lrat, const Rational& rrat);

bool operator<(const Rational& lrat, const Rational& rrat);

Rational operator+(const Rational& lrat, const Rational& rrat);

Rational operator-(const Rational& lrat, const Rational& rrat);

Rational operator*(const Rational& lrat, const Rational& rrat);

Rational operator/(const Rational& lrat, const Rational& rrat);

istream& operator>>(istream& stream, Rational& rat);

ostream& operator<<(ostream& stream, const Rational& rat);

#endif /* RATIONAL_H */
