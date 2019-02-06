#ifndef FUNCTION_H
#define FUNCTION_H

#include "coursera.h"

class FunctionParts {
public:
	FunctionParts(const char&, const double&);
	double Apply(const double&) const;
	void Invert();
private:
	char operation;
	double value;
}; 

class Function {
public:
	void AddPart (const char&, const double&);
	double Apply(double) const;
	void Invert();
private:
	vector<FunctionParts> parts;	
};

struct Image {
	double quality;
	double freshness;
	double rating;
};

struct Params {
	double a;
	double b;
	double c;
};

double ComputeImageWeight(const Params& params, const Image& image);
double ComputeQualityByWeight(const Params& params,
                              const Image& image,
                              double weight);

#endif /* FUNCTION_H */

