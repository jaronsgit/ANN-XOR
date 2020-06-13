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
            //remember that the first layer of the topology is the set of input nodes
            if (topology.size() != nodeWeights.size() - 1)
                throw std::logic_error("Topology does not match node weights given.");

            for (int i = 1; i < topology.size(); i++)
            {
                if (topology[i] != nodeWeights[i - 1].size())
                    throw std::logic_error("Topology does not match node weights given.");
            }

            //Topology is correct -> construct the network with the given topology and weights
            //Push back the input nodes first
            layers.push_back(std::vector<Node>(topology[0]));

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

    float Network::hiddenOutput(const int layer, const int nodeNum)
    {
        return layers[layer][nodeNum].getOutputPrediction();
    }

    void Network::feedForward(const std::vector<float> &inputVector)
    {
        //Set the input layer neuron's outputs
        for (int i = 0; i < layers[0].size(); ++i)
        {
            layers[0][i].setOutputPrediction(inputVector[i]);
        }

        //Propagate the outputs forward
        for (int i = 1; i < layers.size(); ++i)
        {
            //get previous layer outputs
            std::vector<float> prevOutputs;
            for (const auto &node : layers[i - 1])
            {
                prevOutputs.push_back(node.getOutputPrediction());
            }

            auto &layer = layers[i];

            //Feed forward
            for (int j = 0; j < layer.size(); ++j)
            {
                layer[j].feedForward(prevOutputs);
            }
        }
    }

} // namespace CHNJAR003