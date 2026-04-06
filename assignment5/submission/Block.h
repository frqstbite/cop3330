#include "LinearLayer.h"
#include "ReLUActivation.h"

class Block {
  private:
	LinearLayer linear;
	ReLUActivation relu;

  public:
	Block(int in_size, int out_size);
	vector<double> forward(const vector<double> &input) const;
	void display() const;
	void size() const;
	void setWeights(const vector<double> &flatWeights);
	void setActivationWeights(const vector<double> &actWeights);
};
