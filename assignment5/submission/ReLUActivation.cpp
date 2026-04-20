#include "ReLUActivation.h"
#include <iostream>

ReLUActivation::ReLUActivation(double p_s, double n_s) {
	setWeights({p_s, n_s});
}

vector<double> ReLUActivation::forward(const vector<double>& inputs) const {
	vector<double> result(inputs.size());

	for (int i = 0; i < inputs.size(); i++)
		result[i] = (inputs[i] < 0 ? weights[1] : weights[0]) * inputs[i];

	return result;
}

void ReLUActivation::display() const {
	cout << "ReLUActivation: slope = " << weights[0]
		 << ", negative slope = " << weights[1];
}

void ReLUActivation::setWeights(const vector<double>& newWeights) {
	weights = newWeights;
}
