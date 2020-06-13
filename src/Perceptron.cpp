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
