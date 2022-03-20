#include <iostream>
#include <fstream>
#include <vector>
#include "ParserGCODE.hpp"

int main()
{
    try {
        std::ifstream file ("file.txt");
        if (!file.is_open())
            throw("Bad file !");
        ParserGCODE<int> code;
        std::string line;
        while (std::getline(file, line)) {
            code.checkLine(line);
        }
    } catch (const char* e) {
        std::cerr << e << std::endl;
        return (1);
    }

    return (0);
}
