#include "../include/XOR.h"
#include <vector>

namespace CHNJAR003
{

    XOR::XOR(const Perceptron &ANDgate, const Perceptron &ORgate, const Perceptron &NANDgate) : ANDgate(ANDgate), ORgate(ORgate), NANDgate(NANDgate)
    {
    }

    int XOR::predict(const std::vector<float> &inputVector)
    {
        int NANDPrediction = NANDgate.predict(inputVector);
        int ORPrediction = ORgate.predict(inputVector);
        return ANDgate.predict({float(NANDPrediction), float(ORPrediction)});
    }

} // namespace CHNJAR003
