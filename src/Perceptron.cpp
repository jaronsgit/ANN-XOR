#include "../include/Perceptron.h"
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>

namespace CHNJAR003
{

    Perceptron::Perceptron(const int numberOfInputs, const float learningRate, const float bias, const int epochThreshold) : numberOfInputs(numberOfInputs), learningRate(learningRate), epochThreshold(epochThreshold)
    {
        weights = std::vector<float>(numberOfInputs + 1, 0.0);
        weights[0] = bias;
    }

} // namespace CHNJAR003
