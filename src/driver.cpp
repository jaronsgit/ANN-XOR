#include "../include/Perceptron.h"
#include "../include/XOR.h"
#include "../include/Network.h"
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

    std::cout << "****************\n";
    std::cout << "Answers:\n";
    std::cout << "****************\n";
    std::cout << "Part 1:" << std::endl;
    std::cout << "****************\n";

    CHNJAR003::Perceptron ANDgate(2, 0.01, 0, 100);
    ANDgate.learn(ANDtrainingSet);
    std::cout << "AND Perceptron predictions:" << std::endl;
    std::cout << "{0, 0} -> " << ANDgate.predict({0, 0}) << std::endl;
    std::cout << "{0, 1} -> " << ANDgate.predict({0, 1}) << std::endl;
    std::cout << "{1, 0} -> " << ANDgate.predict({1, 0}) << std::endl;
    std::cout << "{1, 1} -> " << ANDgate.predict({1, 1}) << std::endl;
    std::cout << "________________\n";

    CHNJAR003::Perceptron ORgate(2, 0.01, 0, 100);
    ORgate.learn(ORtrainingSet);
    std::cout << "OR Perceptron predictions:" << std::endl;
    std::cout << "{0, 0} -> " << ORgate.predict({0, 0}) << std::endl;
    std::cout << "{0, 1} -> " << ORgate.predict({0, 1}) << std::endl;
    std::cout << "{1, 0} -> " << ORgate.predict({1, 0}) << std::endl;
    std::cout << "{1, 1} -> " << ORgate.predict({1, 1}) << std::endl;
    std::cout << "________________\n";

    CHNJAR003::Perceptron NANDgate(2, 0.01, 0, 100);
    NANDgate.learn(NANDtrainingSet);
    std::cout << "NAND Perceptron predictions:" << std::endl;
    std::cout << "{0, 0} -> " << NANDgate.predict({0, 0}) << std::endl;
    std::cout << "{0, 1} -> " << NANDgate.predict({0, 1}) << std::endl;
    std::cout << "{1, 0} -> " << NANDgate.predict({1, 0}) << std::endl;
    std::cout << "{1, 1} -> " << NANDgate.predict({1, 1}) << std::endl;
    std::cout << "________________\n";

    //Replicate XOR behaviour
    CHNJAR003::XOR XORgate(ANDgate, ORgate, NANDgate);
    std::cout << "XOR Perceptron predictions:" << std::endl;
    std::cout << "{0, 0} -> " << XORgate.predict({0, 0}) << std::endl;
    std::cout << "{0, 1} -> " << XORgate.predict({0, 1}) << std::endl;
    std::cout << "{1, 0} -> " << XORgate.predict({1, 0}) << std::endl;
    std::cout << "{1, 1} -> " << XORgate.predict({1, 1}) << std::endl;
    std::cout << "****************\n";
    std::cout << "Question 1:\n\n";
    std::cout << "The minimum number of perceptrons required to solve the XOR problem is 3." << std::endl;
    std::cout << "\nThe XOR logic gate behaviour can be recreated, through the use of Boolean algebra, by a circuit consisting of an AND, OR and NAND gate." << std::endl;
    std::cout << "\nIn boolean algebra: A XOR B = (A OR B) AND (A NAND B)" << std::endl;
    std::cout << "\nThis ultimately results in a network topology with 2 hidden layer nodes and 1 output layer node." << std::endl;
    std::cout << "The perceptrons were connected such that the NAND gate perceptron and OR gate perceptron were placed in the hidden layer and connected\nto the AND gate perceptron in the output layer." << std::endl;
    std::cout << "\nThe topology of the network is represented below:" << std::endl;
    std::cout << "\nInput A ---> OR   --->\n";
    std::cout << "\t\t\tAND---> XOR output\n";
    std::cout << "Input B ---> NAND --->\n";
    std::cout << "****************\n";
    std::cout << "Question 2:\n\n";
    std::cout << "It took 12 training examples in total to train the perceptrons to solve the binary XOR problem.\n";
    std::cout << "The training examples used can be found within the \"trainingExamples\" directory.\n";
    std::cout << "****************\n";
    std::cout << "Part 2:\n";
    std::cout << "****************\n";

    std::vector<std::vector<std::vector<float>>> part2NodeWeights =
        {
            {{0.1, 0.1, 0.2, 0.5}, {-0.3, -0.4, 1.0, -0.6}},
            {{-0.3, 0.8, 1.0}}};
    CHNJAR003::Network feedForwardAnn({3, 2, 1}, part2NodeWeights);
    feedForwardAnn.feedForward({1.30, 2.70, 0.80});

    std::cout << "Question 3:\n\n";
    float neuron1 = feedForwardAnn.hiddenOutput(1, 0);
    float neuron2 = feedForwardAnn.hiddenOutput(1, 1);
    std::cout << "Hidden layer neuron 1 output: " << neuron1 << std::endl;
    std::cout << "Hidden layer neuron 2 output: " << neuron2 << std::endl;
    std::cout << "****************\n";
    std::cout << "Question 4:\n\n";
    std::cout << "Value of output neuron: " << feedForwardAnn.output()[0] << std::endl;
    std::cout << "****************\n";
    std::cout << "Question 5:\n\n";
    float MSE = feedForwardAnn.meanSquaredError({0.36});
    std::cout << "MSE for input x: " << MSE << std::endl;
    std::cout << "****************\n";

    //Write answers to text file
    std::ofstream answers;
    answers.open("Answers.txt");
    answers << "****************\n";
    answers << "Answers:\n";
    answers << "****************\n";
    answers << "Part 1:" << std::endl;
    answers << "****************\n";

    answers << "AND Perceptron predictions:" << std::endl;
    answers << "{0, 0} -> " << ANDgate.predict({0, 0}) << std::endl;
    answers << "{0, 1} -> " << ANDgate.predict({0, 1}) << std::endl;
    answers << "{1, 1} -> " << ANDgate.predict({1, 1}) << std::endl;
    answers << "________________\n";

    answers << "OR Perceptron predictions:" << std::endl;
    answers << "{0, 0} -> " << ORgate.predict({0, 0}) << std::endl;
    answers << "{0, 1} -> " << ORgate.predict({0, 1}) << std::endl;
    answers << "{1, 0} -> " << ORgate.predict({1, 0}) << std::endl;
    answers << "{1, 1} -> " << ORgate.predict({1, 1}) << std::endl;
    answers << "________________\n";

    answers << "NAND Perceptron predictions:" << std::endl;
    answers << "{0, 0} -> " << NANDgate.predict({0, 0}) << std::endl;
    answers << "{0, 1} -> " << NANDgate.predict({0, 1}) << std::endl;
    answers << "{1, 0} -> " << NANDgate.predict({1, 0}) << std::endl;
    answers << "{1, 1} -> " << NANDgate.predict({1, 1}) << std::endl;
    answers << "________________\n";

    //Replicate XOR behaviour
    answers << "XOR Perceptron predictions:" << std::endl;
    answers << "{0, 0} -> " << XORgate.predict({0, 0}) << std::endl;
    answers << "{0, 1} -> " << XORgate.predict({0, 1}) << std::endl;
    answers << "{1, 0} -> " << XORgate.predict({1, 0}) << std::endl;
    answers << "{1, 1} -> " << XORgate.predict({1, 1}) << std::endl;
    answers << "****************\n";
    answers << "Question 1:\n\n";
    answers << "The minimum number of perceptrons required to solve the XOR problem is 3." << std::endl;
    answers << "\nThe XOR logic gate behaviour can be recreated, through the use of Boolean algebra, by a circuit consisting of an AND, OR and NAND gate." << std::endl;
    answers << "\nIn boolean algebra: A XOR B = (A OR B) AND (A NAND B)" << std::endl;
    answers << "\nThis ultimately results in a network topology with 2 hidden layer nodes and 1 output layer node." << std::endl;
    answers << "The perceptrons were connected such that the NAND gate perceptron and OR gate perceptron were placed in the hidden layer and connected\nto the AND gate perceptron in the output layer." << std::endl;
    answers << "\nThe topology of the network is represented below:" << std::endl;
    answers << "\nInput A ---> OR   --->\n";
    answers << "\t\t\t\t\t\tAND---> XOR output\n";
    answers << "Input B ---> NAND --->\n";
    answers << "****************\n";
    answers << "Question 2:\n\n";
    answers << "It took 12 training examples in total to train the perceptrons to solve the binary XOR problem.\n";
    answers << "The training examples used can be found within the \"trainingExamples\" directory.\n";
    answers << "****************\n";
    answers << "Part 2:\n";
    answers << "****************\n";

    answers << "Question 3:\n\n";

    answers << "Hidden layer neuron 1 output: " << neuron1 << std::endl;
    answers << "Hidden layer neuron 2 output: " << neuron2 << std::endl;
    answers << "****************\n";
    answers << "Question 4:\n\n";
    answers << "Value of output neuron: " << feedForwardAnn.output()[0] << std::endl;
    answers << "****************\n";
    answers << "Question 5:\n\n";

    answers << "MSE for input x: " << MSE << std::endl;
    answers << "****************\n";
    answers.close();

    return 0;
}
