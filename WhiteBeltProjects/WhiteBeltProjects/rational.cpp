#include "rational.h"

Rational::Rational(int numerator, int denominator) {
	if (denominator == 0) {
		throw invalid_argument("Invalid argument");
	}
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

Rational operator+=(Rational& lrat, const Rational& rrat) {
	lrat = lrat + rrat;
	return lrat;
}

Rational operator-(const Rational& lrat, const Rational& rrat) {
	return Rational(lrat.Numerator()*rrat.Denominator() - 
					lrat.Denominator()*rrat.Numerator(),
					lrat.Denominator()*rrat.Denominator());
}

Rational operator-=(Rational& lrat, const Rational& rrat) {
	lrat = lrat - rrat;
	return lrat;
}

Rational operator*(const Rational& lrat, const Rational& rrat) {
	return Rational(lrat.Numerator()*rrat.Numerator(), 
					lrat.Denominator()*rrat.Denominator());
}

Rational operator*=(Rational& lrat, const Rational& rrat) {
	lrat = lrat*rrat;
	return lrat;
}

Rational operator/(const Rational& lrat, const Rational& rrat) {
	if (rrat.Numerator() == 0) {
		throw domain_error("Division by zero");
	}
	return Rational(lrat.Numerator()*rrat.Denominator(), 
					lrat.Denominator()*rrat.Numerator());
}

Rational operator/=(Rational& lrat, const Rational& rrat) {
	lrat = lrat/rrat;
	return lrat;
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

Rational readRationalFromStream(stringstream& stream) {
	int num, den;
	stream >> num;
	stream.ignore(1);
	stream >> den;
	return Rational(num, den);
}

Rational calcRationals(const string& expression) {
	stringstream ss(expression);
	Rational lrat = readRationalFromStream(ss);
	char operation;
	ss >> operation;
	Rational rrat = readRationalFromStream(ss);
	Rational rat;
	switch (operation) {
		case '+': lrat+=rrat;
				  break;
		case '-': lrat-=rrat;
				  break;
		case '*': lrat*=rrat;
				  break;
		case '/': lrat/=rrat;
				  break;
 	}
 	return lrat;
}

