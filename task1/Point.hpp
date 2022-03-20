#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

template<class T>
class Point;

template<class T>
class Point {
    private:
        T m_x;
        T m_y;
    public:
        Point()
        : m_x(0), m_y(0)
        {
            std::cout << "Please, enter parameters for Point : " << std::endl;
            std::cin >> m_x;
            std::cout << "X = " << m_x << std::endl;
            std::cin >> m_y;
            std::cout << "Y = " << m_y << std::endl;
        }
        Point(T x, T y)
        : m_x(x), m_y(y)
        {

        }
        Point (const Point& point)
        {
            *this = point;
        }
        ~Point ()
        {

        }
        Point& operator=(const Point& point)
        {
            if (*this != point) {
                m_x = point.m_x;
                m_y = point.m_y;
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
        void setX(T x)
        {
            m_x = x;
        }
        void setY(T y)
        {
            m_y = y;
        }

};

template<class T>
std::ostream &operator<<(std::ostream &out, const Point<T>& point)
{
	out << "X = " << point.getX() << std::endl
        << "Y = " << point.getY();
	return (out);
}

#endif
