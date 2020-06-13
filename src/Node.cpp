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

} // namespace CHNJAR003