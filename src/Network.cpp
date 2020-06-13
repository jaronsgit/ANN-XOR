#include "../include/Network.h"
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <stdexcept>

namespace CHNJAR003
{

    Network::Network(const std::vector<int> &topology, const std::vector<std::vector<std::vector<float>>> &nodeWeights) : topology(topology)
    {
        //Check that topology matches node weights
        try
        {
            if (topology.size() != nodeWeights.size())
                throw std::logic_error("Topology does not match node weights given.");

            for (int i = 0; i < topology.size(); i++)
            {
                if (topology[i] != nodeWeights[i].size())
                    throw std::logic_error("Topology does not match node weights given.");
            }

            //Topology is correct -> construct the network with the given topology and weights
            for (int i = 0; i < nodeWeights.size(); i++) //for each layer
            {

                std::vector<Node> tempLayer = std::vector<Node>(nodeWeights[i].size());

                //for each node in the new layer
                for (int j = 0; j < nodeWeights[i].size(); j++)
                {
                    //set the node's weights
                    tempLayer[j] = Node(nodeWeights[i][j].size() - 1, nodeWeights[i][j]); //(numInputs, weights)
                }

                layers.push_back(tempLayer); //push back new layer of Nodes
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    float Network::hiddenOutput(const int layer, const int nodeNum, const std::vector<float> &inputVector)
    {
        return layers[layer][nodeNum].output(inputVector);
    }

} // namespace CHNJAR003