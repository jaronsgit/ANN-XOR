#include "../include/Node.h"
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <cmath>

namespace CHNJAR003
{
    Node::Node(const int numInputs, const std::vector<float> &weights) : numberOfInputs(numInputs), weights(weights)
    {
    }

    float Node::output(const std::vector<float> &inputConnections)
    {
        outputPrediction = sigmoid(std::inner_product(weights.begin() + 1, weights.end(), inputConnections.begin(), weights[0]));
        return outputPrediction;
    }

    float Node::sigmoid(float num) const
    {
        return 1 / (1 + std::pow(std::exp(1.0), -num));
    }

    void Node::setOutputPrediction(float num)
    {
        outputPrediction = num;
    }

    float Node::getOutputPrediction(void) const
    {
        return outputPrediction;
    }

} // namespace CHNJAR003