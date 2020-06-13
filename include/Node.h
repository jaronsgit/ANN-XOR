#ifndef Node_H
#define Node_H

#include <vector>
#include <utility>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

namespace CHNJAR003
{
    class Node
    {
    private:
        int numberOfInputs;
        std::vector<float> weights; //W0 is interpreted as the bias
        float outputPrediction;

    public:
        Node(const int numInputs, const std::vector<float> &weights);
        float sigmoid(float num) const;
        void setOutputPrediction(float num);
        float getOutputPrediction(void) const;
        void feedForward(const std::vector<float> &inputConnections);
    };

} // namespace CHNJAR003

#endif