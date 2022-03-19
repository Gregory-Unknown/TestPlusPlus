#ifndef MANIPULATOR_HPP
#define MANIPULATOR_HPP

#include <iostream>
#include <cmath>
#include "Point.hpp"

template<class T>
class Manipulator;

template<class T>
class Manipulator {
    private:
        T m_x;
        T m_y;
        T m_r;
    public:
        Manipulator()
        : m_x(0), m_y(0), m_r(0)
        {
            std::cout << "Please, enter parameters for manipulator : " << std::endl;
            std::cin >> m_x;
            std::cout << "X = " << m_x << std::endl;
            std::cin >> m_y;
            std::cout << "Y = " << m_y << std::endl;
            std::cin >> m_r;
            std::cout << "R = " << m_r << std::endl;
        }
        Manipulator(T x, T y, T r)
        : m_x(x), m_y(y), m_r(r)
        {

        }
        Manipulator (const Manipulator& man)
        {
            *this = man;
        }
        Manipulator& operator=(const Manipulator& man)
        {
            if (*this != man) {
                m_x = man.m_x;
                m_y = man.m_y;
                m_r = man.m_r;
            }
            return (*this);
        }
        T getX() const
        {
            return (m_x);
        }
        T getY() const 
        {
            return (m_y);
        }
        T getR() const
        {
            return (m_r);
        }
        void setX(T x)
        {
            m_x = x;
        }
        void setY(T y)
        {
            m_y = y;
        }
        void setR(T r)
        {
            m_r = r;
        }
        T getHypotenuse(const Point<T>& point)
        {
            if (m_x == point.getX() && m_y == point.getY())
                return (0);
            T r = sqrt(pow(m_x - point.getX(), 2) + pow(m_y - point.getY(), 2));
            if (r > m_r)
                return (0);
            return (r);
        }
};

template<class T>
std::ostream &operator<<(std::ostream &out, const Manipulator<T>& man)
{
	out << "X = " << man.getX() << std::endl
        << "Y = " << man.getY() << std::endl
        << "R = " << man.getR();

	return (out);
}

#endif