#ifndef NODE_H
#define NODE_H

#include <vector>
#include <utility>

namespace CHNJAR003
{

    class Perceptron
    {
    private:
        float learningRate; //Real value between 0 and 1
        float threshold;    //Number of allowable epochs
        //float bias;
        std::vector<float> weights; //W0 will effectively be used as a bias

    public:
        Perceptron(const int numberOfInputs, const float learningRate, const int threshold);
        int output(const std::vector<float> &inputVector);                       //Perceptron output function -> outputs either a 1 or a zero
        void learn(std::vector<std::pair<std::vector<float>, int>> trainingSet); //Training set is a vector of pairs: first is the input vector, second is the desired ouput
        ~Perceptron();
    };

} // namespace CHNJAR003

#endif