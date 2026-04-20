#include "Block.h"
#include <iostream>

Block::Block(int in_size, int out_size) : linear(in_size, out_size) {}

vector<double> Block::forward(const vector<double>& input) const {
	return relu.forward(linear.forward(input));
}

void Block::display() const {
	linear.display();
	cout << endl;
	relu.display();
}

void Block::size() const {
	linear.size();
}

void Block::setWeights(const vector<double>& flatWeights) {
	linear.setFlatWeights(flatWeights);
}

void Block::setActivationWeights(const vector<double>& actWeights) {
	relu.setWeights(actWeights);
}
