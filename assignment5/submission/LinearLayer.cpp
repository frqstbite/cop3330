#include "LinearLayer.h"
#include <iostream>

LinearLayer::LinearLayer(int in_size, int out_size)
	: input_size(in_size), output_size(out_size), bias(out_size, 1.0) {
	weights.resize(output_size * input_size, 1.0);
}

vector<double> LinearLayer::forward(const vector<double>& input) const {
	vector<double> result(output_size);

	// Matrix multiplication
	for (int i = 0; i < output_size; i++)
		for (int j = 0; j < input_size; j++)
			result[i] += weights[i * input_size + j] * input[j];

	// Apply bias
	for (int i = 0; i < output_size; i++)
		result[i] += bias[i];

	return result;
}

void LinearLayer::display() const {
	// Size
	cout << "LinearLayer expected weight dimensions: " << input_size
		 << " (input) x " << output_size << " (output)";

	// Bias
	cout << endl << "Bias: ";
	for (int i = 0; i < output_size; i++)
		cout << bias[i] << ' ';

	// Weights
	cout << endl << "Flat weight vector: ";
	for (int i = 0; i < output_size * input_size; i++)
		cout << weights[i] << ' ';
}

void LinearLayer::size() const {
	cout << "LinearLayer - Input size: " << input_size
		 << ", Output size: " << output_size;
}

void LinearLayer::setFlatWeights(const vector<double>& newWeights) {
	weights = newWeights;
}
