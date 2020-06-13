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

    int Perceptron::predict(const std::vector<float> &inputVector)
    {

        float summation = std::inner_product(weights.begin() + 1, weights.end(), inputVector.begin(), weights[0]);
        /*float summation = weights[0];
        for (int i = 1; i < weights.size(); ++i)
        {
            summation += weights[i] * inputVector[i - 1];
        }*/
        return summation > 0 ? 1 : 0;
    }

    void Perceptron::learn(std::vector<std::pair<std::vector<float>, int>> trainingSet)
    {
        for (int iteration = 0; iteration < epochThreshold; ++iteration)
        {
            for (const auto &trainingExample : trainingSet)
            {
                int prediction = predict(trainingExample.first);

                weights[0] += learningRate * (trainingExample.second - prediction);

                auto l = learningRate;

                std::transform(weights.begin() + 1, weights.end(), trainingExample.first.begin(), weights.begin() + 1, [&](float weight, float x) -> float {
                    return weight + l * (trainingExample.second - prediction) * x;
                });

                /*for (int i = 1; i < weights.size(); ++i)
                {
                    weights[i] += learningRate * (trainingExample.second - prediction) * trainingExample.first[i - 1];
                }*/

                //Print out the weights for testing
                /*std::cout << "[";
                std::cout << weights[0];
                for (int i = 1; i < weights.size(); ++i)
                {
                    std::cout << ", " << weights[i];
                }
                std::cout << "]\n";*/
            }
        }
    }

    std::ostream &operator<<(std::ostream &os, const Perceptron &p)
    {
        os << "Perceptron internals:\n";
        os << "numberOfInputs:\t" << p.numberOfInputs << std::endl;
        os << "learningRate:\t" << p.learningRate << std::endl;
        os << "epochThreshold:\t" << p.epochThreshold << std::endl;
        os << "weights:\n";
        for (auto weight : p.weights)
        {
            os << weight << std::endl;
        }

        return os;
    }

} // namespace CHNJAR003
