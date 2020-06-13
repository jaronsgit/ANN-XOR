#ifndef Network_H
#define Network_H

#include <vector>
#include <utility>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../include/Node.h"

namespace CHNJAR003
{
    class Network
    {
    private:
        std::vector<int> topology;
        std::vector<Node> layers;
        /* data */
    public:
        Network(const std::vector<int> &topology, const std::vector<std::vector<std::vector<float>>> &nodeWeights);
        void setNetworkWeights(const std::vector<std::vector<std::vector<float>>> &nodeWeights);
        std::vector<float> output(const std::vector<float> &inputVector);
        float hiddenOutput(const int layer, const int nodeNum, const std::vector<float> &inputVector);
        float meanSquaredError(const std::vector<float> &output);
    };

} // namespace CHNJAR003

#endif