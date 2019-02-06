#include "rational.h"

Rational::Rational(int numerator, int denominator) {
	int gcd_num = gcd(numerator, denominator);
	if ((numerator < 0 && denominator > 0) ||
		(numerator > 0 && denominator < 0)) {
		this->numerator = -abs(numerator/gcd_num);
		this->denominator = abs(denominator/gcd_num);
	} else {
		this->numerator = abs(numerator/gcd_num);
		this->denominator = abs(denominator/gcd_num);
	}
}

int Rational::Numerator() const {
	return numerator;
}

int Rational::Denominator() const {
	return denominator;
}

bool operator==(const Rational& lrat, const Rational& rrat) {
	return (lrat.Numerator() == rrat.Numerator() &&
		   lrat.Denominator() == rrat.Denominator());
}

bool operator<(const Rational& lrat, const Rational& rrat) {
	return (lrat.Numerator()*rrat.Denominator() <
			lrat.Denominator()*rrat.Numerator());
}

Rational operator+(const Rational& lrat, const Rational& rrat) {
	return Rational(lrat.Numerator()*rrat.Denominator() + 
					lrat.Denominator()*rrat.Numerator(),
					lrat.Denominator()*rrat.Denominator());
}

Rational operator-(const Rational& lrat, const Rational& rrat) {
	return Rational(lrat.Numerator()*rrat.Denominator() - 
					lrat.Denominator()*rrat.Numerator(),
					lrat.Denominator()*rrat.Denominator());
}

Rational operator*(const Rational& lrat, const Rational& rrat) {
	return Rational(lrat.Numerator()*rrat.Numerator(), 
					lrat.Denominator()*rrat.Denominator());
}

Rational operator/(const Rational& lrat, const Rational& rrat) {
	return Rational(lrat.Numerator()*rrat.Denominator(), 
					lrat.Denominator()*rrat.Numerator());
}

istream& operator>>(istream& stream, Rational& rat) { 
	int numerator = 0;
	int denominator = 0;
	if (stream >> numerator) {
		stream.ignore(1);
		stream >> denominator;
		rat = Rational(numerator, denominator);
	}
	return stream;
}

ostream& operator<<(ostream& stream, const Rational& rat) {
	return stream << rat.Numerator() << "/" << rat.Denominator();	 
}
