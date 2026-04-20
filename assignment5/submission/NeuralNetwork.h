#include "Block.h"

class NeuralNetwork {
   private:
	vector<Block> blocks;

   public:
	NeuralNetwork(int num_blocks, int in_size, int hidden_size, int out_size);
	vector<double> forward(const vector<double>& input) const;
	void printModel() const;
	void printBlockSizes() const;
	void setBlockWeights(int block_index, const vector<double>& flatWeights);
	void setBlockActivationWeights(int block_index,
								   const vector<double>& actWeights);
};
