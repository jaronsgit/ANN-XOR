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
        std::vector<float> weights;
        /* data */
    public:
        Node(/* args */);
        ~Node();
    };

} // namespace CHNJAR003

#endif