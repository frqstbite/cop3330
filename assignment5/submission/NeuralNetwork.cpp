#include "NeuralNetwork.h"
#include <iostream>

NeuralNetwork::NeuralNetwork(int num_blocks, int in_size, int hidden_size,
							 int out_size) // my formatter does this i swear
	: blocks{} {
	if (num_blocks < 2)
		blocks.push_back(Block(in_size, out_size));
	else {
		blocks.push_back(Block(in_size, hidden_size)); // First

		// Intermediate
		for (int i = 0; i < num_blocks - 2; i++)
			blocks.push_back(Block(hidden_size, hidden_size));

		blocks.push_back(Block(hidden_size, out_size)); // Last
	}
}

vector<double> NeuralNetwork::forward(const vector<double> &input) const {
	vector<double> processed = blocks[0].forward(input); // First

	// Intermediate
	for (int i = 1; i < blocks.size() - 1; i++)
		processed = blocks[i].forward(processed);

	return blocks[blocks.size() - 1].forward(processed); // Last
}

void NeuralNetwork::printModel() const {
	for (int i = 0; i < blocks.size(); i++) {
		cout << "Block " << i + 1 << ":" << endl;
		blocks[i].display();
		cout << endl << "-----------------------------" << endl;
	}
}

void NeuralNetwork::printBlockSizes() const {
	for (int i = 0; i < blocks.size(); i++) {
		cout << "Block " << i + 1 << " size: ";
		blocks[i].size();
		cout << endl;
	}
}

void NeuralNetwork::setBlockWeights(int block_index,
									const vector<double> &flatWeights) {
	blocks[block_index].setWeights(flatWeights);
}

void NeuralNetwork::setBlockActivationWeights(
	int block_index, const vector<double> &actWeights) {
	blocks[block_index].setActivationWeights(actWeights);
}
