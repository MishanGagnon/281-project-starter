#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>

// Struct to hold test case information
struct TestCase {
    std::string inputFilename;
    std::string outputFilename;
};

int main() {
    std::string EXE_NAME = "EXE_NAME_HERE";
    std::string executableName = "./" + EXE_NAME + "debug";
    std::vector<TestCase> testCases = {
        {"test-in.txt", "test-out.txt"},
    };
    //make debug before run
    std::string makeDebug = "make debug";
    std::system(makeDebug.c_str());
    for (const auto& test : testCases) {
        std::string command = executableName + " < " + test.inputFilename + " > output.txt";
        int result = std::system(command.c_str());
        if (result != 0) {
            std::cerr << "Failed to execute the test for: " << test.inputFilename << std::endl;
            continue;
        }

        std::string diffCommand = "diff -y " + test.outputFilename + " output.txt > diff.txt";
        int diffResult = std::system(diffCommand.c_str());
        if (diffResult != 0) {
            std::cout << "Test failed for: " << test.inputFilename << std::endl;
            std::cout << "Differences:" << std::endl;

            // Read and display the differences from the temporary file
            std::ifstream diffFile("diff.txt");
            std::string line;
            while (getline(diffFile, line)) {
                std::cout << line << std::endl;
            }
            diffFile.close();
        } else {
            std::cout << "Test passed for: " << test.inputFilename << std::endl;
        }
    }

    std::remove("output.txt");
    std::remove("diff.txt"); // Clean up the temporary diff file

    return 0;
}
