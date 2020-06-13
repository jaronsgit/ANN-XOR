#include "../include/Perceptron.h"
#include "../include/XOR.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <sstream>

std::vector<std::pair<std::vector<float>, int>> constructTrainingSet(const std::string &trainingExamplesFile)
{
    std::ifstream inputFile(trainingExamplesFile);
    std::vector<std::pair<std::vector<float>, int>> trainingSet;

    if (inputFile.is_open())
    {
        std::string line;

        while (getline(inputFile, line))
        {
            std::istringstream ss(line);
            std::string token;

            std::vector<std::string> tokens;

            while (getline(ss, token, ' '))
            {
                tokens.push_back(token);
            }

            std::vector<float> exampleVector;
            int exampleTarget;

            for (int i = 0; i < tokens.size() - 1; ++i)
            {
                exampleVector.push_back(std::stof(tokens[i]));
            }
            exampleTarget = std::stoi(tokens[tokens.size() - 1]);

            std::pair<std::vector<float>, int> tempPair(exampleVector, exampleTarget);

            trainingSet.push_back(tempPair);
        }
    }
    return trainingSet;
}

int main(int argc, char *argv[])
{

    return 0;
}
