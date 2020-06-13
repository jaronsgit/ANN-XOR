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
            if (topology.size() - 1 != nodeWeights.size())
                throw std::logic_error("Topology does not match node weights given.");

            for (int i = 1; i < topology.size(); i++)
            {
                if (topology[i] != nodeWeights[i - 1].size())
                    throw std::logic_error("Topology does not match node weights given.");
            }

            //Topology is correct -> construct the network with the given topology and weights
            //Push back the input nodes first
            std::vector<Node> inputLayer;

            for (int i = 0; i < topology[0]; ++i)
            {
                inputLayer.push_back(Node(1, {}));
            }

            layers.push_back(inputLayer);

            //Push back the hidden layer nodes
            for (int i = 0; i < nodeWeights.size(); i++) //for each layer
            {
                std::vector<Node> tempHiddenLayer;

                //for each node in the new layer
                for (int j = 0; j < nodeWeights[i].size(); j++)
                {
                    //set the node's weights
                    tempHiddenLayer.push_back(Node(nodeWeights[i][j].size() - 1, nodeWeights[i][j])); //(numInputs, weights)
                }

                layers.push_back(tempHiddenLayer); //push back new layer of Nodes
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

    std::ostream &operator<<(std::ostream &os, const Network &n)
    {
        os << "Network internals:\n";
        os << "topology:";
        for (const auto &num : n.topology)
        {
            os << " " << num;
        }
        os << "\nlayers:\n";
        int layerNum = 0;
        for (const auto &layer : n.layers)
        {
            ++layerNum;
            os << "layer: " << layerNum << std::endl;
            for (const auto &node : layer)
            {
                os << node;
            }
            os << std::endl;
        }
        os << std::endl;
        return os;
    }

} // namespace CHNJAR003