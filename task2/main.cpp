#include <iostream>
#include <vector>
#include "Manipulator.hpp"
#include "Point.hpp"

int main()
{
    try {
        Manipulator<double> O1(0, 0, 4);
        Manipulator<double> O2(2, 1, 3);
        std::vector<std::vector<double>> vec = {{1, 3}, {2, 1.41}, {0.2, -7} ,{-5, -1} , {0, 9}};
        for (size_t i = 0; i < vec.size(); ++i) {
            Point<double> point(vec.at(i).at(0), vec.at(i).at(1));
            int hipotenuse1 = O1.getHypotenuse(point);
            int hipotenuse2 = O2.getHypotenuse(point);
            if (hipotenuse1 < hipotenuse2) {
                std::cout << "RESULT : first manipulator\n" << std::endl;
                O1.setPoint(point);
            }
            else {
                std::cout << "RESULT : second manipulator\n"  << std::endl;
                O2.setPoint(point);
            }
        }
        
        
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
	    return (1);
    }
    
    return (0);
}