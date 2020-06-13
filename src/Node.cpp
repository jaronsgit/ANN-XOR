#include "../include/Node.h"
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>

namespace CHNJAR003
{
    Node::Node(const int numInputs, const std::vector<float> &weights) : numberOfInputs(numInputs), weights(weights)
    {
    }

    float Node::output(const std::vector<float> &inputConnections)
    {
        outputPrediction = std::inner_product(weights.begin() + 1, weights.end(), inputConnections.begin(), weights[0]);
        return outputPrediction;
    }

} // namespace CHNJAR003