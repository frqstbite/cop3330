#include "Module.h"

class ReLUActivation : public Module {
  public:
	ReLUActivation(double p_s = 1.0, double n_s = 0.0);
	vector<double> forward(const vector<double> &inputs) const;
	void display() const;
	void setWeights(const vector<double> &newWeights);
};
