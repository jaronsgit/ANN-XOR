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
        numEpochs = 0;
    }

    //Perceptron output function -> outputs either a 1 or a zero
    int Perceptron::predict(const std::vector<float> &inputVector)
    {

        float summation = std::inner_product(weights.begin() + 1, weights.end(), inputVector.begin(), weights[0]);
        return summation > 0 ? 1 : 0;
    }

    //Train the perceptron with a given training set.
    //Training set is a vector of pairs: first is the input vector, second is the desired ouput
    void Perceptron::learn(std::vector<std::pair<std::vector<float>, int>> trainingSet)
    {
        for (int iteration = 0; iteration < epochThreshold; ++iteration)
        {
            bool errors = false;
            for (const auto &trainingExample : trainingSet)
            {
                int prediction = predict(trainingExample.first);

                weights[0] += learningRate * (trainingExample.second - prediction);

                auto l = learningRate;

                std::transform(weights.begin() + 1, weights.end(), trainingExample.first.begin(), weights.begin() + 1, [&](float weight, float x) -> float {
                    return weight + l * (trainingExample.second - prediction) * x;
                });

                if (prediction != trainingExample.second)
                {
                    errors = true;
                }
            }
            if (!errors)
            {
                numEpochs = iteration + 1;
                break;
            }
        }
    }

    int Perceptron::getNumEpochs(void)
    {
        return numEpochs;
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
