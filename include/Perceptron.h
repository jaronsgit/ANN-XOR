#ifndef Perceptron_H
#define Perceptron_H

#include <vector>
#include <utility>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

namespace CHNJAR003
{

    class Perceptron
    {
    private:
        int numberOfInputs;
        float learningRate; //Real value between 0 and 1
        //float threshold;
        float epochThreshold;       //Number of allowable epochs
        std::vector<float> weights; //W0 will effectively be used as a bias

    public:
        Perceptron(const int numberOfInputs, const float learningRate, const float bias, const int epochThreshold);
        int predict(const std::vector<float> &inputVector);                      //Perceptron output function -> outputs either a 1 or a zero
        void learn(std::vector<std::pair<std::vector<float>, int>> trainingSet); //Training set is a vector of pairs: first is the input vector, second is the desired ouput

        friend std::ostream &operator<<(std::ostream &os, const Perceptron &p); //Overloaded output stream operator
    };

} // namespace CHNJAR003

#endif