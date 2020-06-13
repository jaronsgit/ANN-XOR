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

    void Node::feedForward(const std::vector<float> &inputConnections)
    {
        outputPrediction = sigmoid(std::inner_product(weights.begin() + 1, weights.end(), inputConnections.begin(), weights[0]));
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

    std::ostream &operator<<(std::ostream &os, const Node &n)
    {
        for (auto weight : n.weights)
        {
            os << " " << weight;
        }

        os << std::endl;

        return os;
    }

} // namespace CHNJAR003