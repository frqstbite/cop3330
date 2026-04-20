#include "Module.h"

Module::Module() : weights{1.0} {}

vector<double> Module::forward(const vector<double>& input) const {
	if (input.size() > weights.size())
		weights.resize(input.size());

	vector<double> result(input.size(), 0.0);

	// Multiply each index of weights against inputs and store in result
	for (int i = 0; i < input.size(); i++) {
		result[i] = input[i] * weights[i];
	}

	return result;
}
