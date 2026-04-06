#pragma once
#include <vector>
using namespace std;

class Module {
  protected: //protected because LinearLayer and ReLUActivation need this
	mutable vector<double> weights; //mutable because forward needs to be able to resize it while being const

  public:
	Module();
	vector<double> forward(const vector<double> &input) const;
};
