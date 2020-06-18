# C++ Assignment 7: Artificial Neural Networks

The project includes Perceptron.h, XOR.h, Node.h, Network.h, their corresponding source files of the same name, driver.cpp as well as a Makefile.

Perceptron.h contains all the header declarations for the Perceptron class, which is used as part of the solution to Part 1.
The XOR class is responsible recreating the XOR behaviour through the correct combination of trained perceptrons.

The Network and Node classes are used to implement the fully connected feed-forward neural network required for Part 2 of the assignment.

The driver class is responsible for producing the required results to answer the assignment questions writes the results to the Answers.txt file.

## How to use the program

The program directory structure is as follows:

Assignment7_CHNJAR003
bin - contains the output executables
build - contains the object files (emptied on "make clean")
include - contains all the project header files
src - contains the application source files

### The structure of the command line execution is as follows:

NB: make use of the "make run" command to execute the program and produce the results.

NB: the executable is located in the bin directory

```bash
./bin/ann
```

Navigate to the Assignment7_CHNJAR003 directory in Terminal and utilise the provided Makefile to compile the program source code using:

```bash
make
```

The following command can be used to run the executable with the dataset and write the results to "Answers.txt", which will be created in the main assignment directory:

```bash
make run
```

Use the following command to remove the binary files and executable from the build and bin folders respectively:

```bash
make clean
```

## Authors

**CHNJAR003**
