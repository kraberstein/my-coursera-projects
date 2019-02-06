#include "function.h"

Function MakeWeightFunction(const Params& params,
                            const Image& image) {
	Function function;
  function.AddPart('*', params.a);
  function.AddPart('-', image.freshness * params.b);
  function.AddPart('+', image.rating * params.c);
	return function;
}

double ComputeImageWeight(const Params& params, const Image& image) {
	Function function = MakeWeightFunction(params, image);
	return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params,
                              const Image& image,
                              double weight) {
	Function function = MakeWeightFunction(params, image);
	function.Invert();
	return function.Apply(weight);
}

FunctionParts::FunctionParts(const char& op, const double& val) {
	operation = op;
	value = val;
}

double FunctionParts::Apply(const double& new_value) const {
	if (operation == '+') {
		return new_value + value;
	}
	else if (operation == '-') {
		return new_value - value;
	}
	else if (operation == '*') {
		return new_value*value;
	}
	else {
		return new_value/value;
	}
}

void FunctionParts::Invert() {
	if (operation == '+') {
		operation = '-';
	}
	else if (operation == '-') {
		operation = '+';
	}
	else if (operation == '*') {
		operation = '/';
	}
	else {
		operation = '*';
	}
}

void Function::AddPart(const char& op, const double& val) {
	parts.push_back({op, val});
}

double Function::Apply(double val) const {
	for (const FunctionParts& part : parts) {
		val = part.Apply(val);
	}
	return val;
}

void Function::Invert() {
	for (FunctionParts& part : parts) {
		part.Invert();
	}
	reverse(begin(parts), end(parts));
}
