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
        int res = -1;
        res = min(hipotenuse1, hipotenuse1);
        if (!hipotenuse1) 
            res = hipotenuse2;
        if (!hipotenuse2)
            res = hipotenuse1;
        if (!res)
            std::cerr << "Error parametrs !" << std::endl;
        else
            std::cout << "RESULT : " << res << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
		return (1);
    }
    
    return (0);
}