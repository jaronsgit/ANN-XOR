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
    auto ANDtrainingSet = constructTrainingSet("trainingExamples/AND.txt");
    auto ORtrainingSet = constructTrainingSet("trainingExamples/OR.txt");
    auto NANDtrainingSet = constructTrainingSet("trainingExamples/NAND.txt");
    /*for (auto trainingExample : trainingSet)
    {
        for (auto exampleVectorElement : trainingExample.first)
        {
            std::cout << exampleVectorElement << " ";
        }
        std::cout << ": " << trainingExample.second << std::endl;
    }*/

    CHNJAR003::Perceptron ANDgate(2, 0.01, 0, 100);
    ANDgate.learn(ANDtrainingSet);
    std::cout << "AND predictions:" << std::endl;
    std::cout << "{0, 0} -> " << ANDgate.predict({0, 0}) << std::endl;
    std::cout << "{0, 1} -> " << ANDgate.predict({0, 1}) << std::endl;
    std::cout << "{1, 0} -> " << ANDgate.predict({1, 0}) << std::endl;
    std::cout << "{1, 1} -> " << ANDgate.predict({1, 1}) << std::endl;
    std::cout << "________________\n";

    CHNJAR003::Perceptron ORgate(2, 0.01, 0, 100);
    ORgate.learn(ORtrainingSet);
    std::cout << "OR predictions:" << std::endl;
    std::cout << "{0, 0} -> " << ORgate.predict({0, 0}) << std::endl;
    std::cout << "{0, 1} -> " << ORgate.predict({0, 1}) << std::endl;
    std::cout << "{1, 0} -> " << ORgate.predict({1, 0}) << std::endl;
    std::cout << "{1, 1} -> " << ORgate.predict({1, 1}) << std::endl;
    std::cout << "________________\n";

    CHNJAR003::Perceptron NANDgate(2, 0.01, 0, 100);
    NANDgate.learn(NANDtrainingSet);
    std::cout << "NAND predictions:" << std::endl;
    std::cout << "{0, 0} -> " << NANDgate.predict({0, 0}) << std::endl;
    std::cout << "{0, 1} -> " << NANDgate.predict({0, 1}) << std::endl;
    std::cout << "{1, 0} -> " << NANDgate.predict({1, 0}) << std::endl;
    std::cout << "{1, 1} -> " << NANDgate.predict({1, 1}) << std::endl;
    std::cout << "________________\n";

    std::cout << ANDgate;
    std::cout << ORgate;
    std::cout << NANDgate;
    return 0;
}
