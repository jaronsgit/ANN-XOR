#ifndef XOR_H
#define XOR_H

#include "../include/Perceptron.h"
#include <vector>
namespace CHNJAR003
{

    class XOR
    {
    private:
        Perceptron ANDgate, ORgate, NANDgate;

    public:
        XOR(const Perceptron &ANDgate, const Perceptron &ORgate, const Perceptron &NANDgate);
        int predict(const std::vector<float> &inputVector);
    };

} // namespace CHNJAR003

#endif