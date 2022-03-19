#include <iostream>
#include "Manipulator.hpp"
#include "Point.hpp"

template<typename T>
const T min(const T &a, const T &b) {
	return (((a < b) ? a : b));
}

int main()
{
    try {
        Manipulator<int> O1;
        Manipulator<int> O2;
        Point<int> point;
        int hipotenuse1 = O1.getHypotenuse(point);
        int hipotenuse2 = O2.getHypotenuse(point);
        if (hipotenuse1 && (hipotenuse1 < hipotenuse2 || !hipotenuse2)) 
            std::cout << "RESULT : first manipulator\n" << O1 << std::endl;
        else if (hipotenuse2 && (hipotenuse2 < hipotenuse1 || !hipotenuse1))
            std::cout << "RESULT : second manipulator\n" << O2 << std::endl;
        else if (hipotenuse1 && hipotenuse1 == hipotenuse2)
            std::cout << "RESULT : first and second manipulator\n" << O1 << std::endl << O2 << std::endl;
        else
            std::cerr << "Error parametrs !" << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
	    return (1);
    }
    
    return (0);
}