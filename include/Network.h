#ifndef Network_H
#define Network_H

#include <vector>
#include "../include/Node.h"

namespace CHNJAR003
{
    class Network
    {
    private:
        std::vector<int> topology;
        std::vector<std::vector<Node>> layers;

    public:
        Network(const std::vector<int> &topology, const std::vector<std::vector<std::vector<float>>> &nodeWeights);
        void setNetworkWeights(const std::vector<std::vector<std::vector<float>>> &nodeWeights);
        std::vector<float> output(void) const;
        float hiddenOutput(const int layer, const int nodeNum) const;
        float meanSquaredError(const std::vector<float> &targetOutput) const;
        void feedForward(const std::vector<float> &inputVector);
        friend std::ostream &operator<<(std::ostream &os, const Network &n); //Overloaded output stream operator
    };

} // namespace CHNJAR003

#endif