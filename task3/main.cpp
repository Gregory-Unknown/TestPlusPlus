#include <iostream>
#include <fstream>
#include <vector>
#include "Manipulator.hpp"
#include "Point.hpp"

int main()
{
    try {
        std::ifstream file (filename);
        
        
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
	    return (1);
    }
    
    return (0);
}