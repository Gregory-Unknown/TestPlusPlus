#include <iostream>
#include "Manipulator.hpp"
#include "Point.hpp"

int main()
{
    Manipulator<int> O1;
    Manipulator<int> O2;
    Point<int> point;
    int hipotenuse1 = O1.getHypotenuse(point);
    int hipotenuse2 = O2.getHypotenuse(point);
    if (hipotenuse1 < hipotenuse2)
        std::cout << "RESULT : first manipulator\n" << std::endl;
    else
        std::cout << "RESULT : second manipulator\n"  << std::endl;
    return (0);
}