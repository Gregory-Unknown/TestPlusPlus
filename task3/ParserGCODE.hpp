#ifndef MANIPULATOR_HPP
#define MANIPULATOR_HPP

#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>

template<class T>
class ParserGCODE;

template<class T>
class ParserGCODE {
    private:
        T m_x;
        T m_y;
        T m_z;
        int m_flag;
    public:
        ParserGCODE()
        : m_x(0), m_y(0), m_z(0), m_flag(0)
        {

        }
        ParserGCODE(const ParserGCODE& code)
        {
            *this = code;
        }
        ~ParserGCODE()
        {

        }
        ParserGCODE& operator=(const ParserGCODE& code)
        {
            if (this != &code) {
                m_x = code.m_m_x;
                m_y = code.m_y;
                m_z = code.m_z;
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
        T getZ() const
        {
            return (m_z);
        }
        void setX(T x)
        {
            m_x = x;
        }
        void setY(T y)
        {
            m_y = y;
        }
        void setZ(T z)
        {
            m_z = z;
        }
        void checkLine(const std::string& line)
        {
            if (!line.size()) {
                clear();
                return ;
            }
            if (!m_flag)
                checkFirstLine(line);
            else
                checkParamLine(line);
        }
        void clear()
        {
            std::cout << m_x << " " << m_y << " " << m_z << std::endl;
            m_x = 0;
            m_y = 0;
            m_z = 0;
            m_flag = 0;
        }
    private:
        void checkFirstLine(const std::string& line)
        {
            std::vector<std::string>tmp;
            std::stringstream ss(line);
            std::string str;
            while (std::getline(ss, str, ' ')) {
                tmp.push_back(str);
            }
            if (tmp.size() != 3)
                throw ("Bad parametrs !");
            for (size_t i = 0; i < tmp.size(); ++i) {
                ss.clear();
                ss.str("");
                if (isDigit(tmp.at(i)))
                    ss << tmp.at(i);
                else {
                    std::cout << m_x << " " << m_y << " " << m_z << std::endl;
                    throw ("ERROR SCRIPT");
                }
                if (i == 0)
                    ss >> m_x;
                else if (i == 1)
                    ss >> m_y;
                else
                    ss >> m_z;
            }
            m_flag = 1;
        }
        void checkParamLine(const std::string& line)
        {
            std::vector<std::string>tmp;
            std::stringstream ss(line);
            std::string str;
            while (std::getline(ss, str, ';')) {
                tmp.push_back(str);
            }
            if (tmp.size() != 3)
                throw ("Bad parametrs !");
            T nb_x = 0;
            T nb_y = 0;
            T nb_z = 0;
            for (size_t i = 0; i < tmp.size(); ++i) {
                ss.clear();
                ss.str("");
                ss << checkNumber(tmp.at(i));
                if (i == 0)
                    ss >> nb_x;
                else if (i == 1)
                    ss >> nb_y;
                else
                    ss >> nb_z;
            }
            m_x += nb_x;
            m_y += nb_y;
            m_z += nb_z;
        }
        std::string checkNumber(const std::string& line)
        {
            std::string str = "a";
            if (line.at(0) != 'X' && line.at(0) != 'Y' && line.at(0) != 'Z') {
                std::cout << m_x << " " << m_y << " " << m_z << std::endl;
                throw ("ERROR SCRIPT");
            }
            size_t pos = line.find("X");
            if (pos == std::string::npos)
                pos = line.find("Y");
            if (pos == std::string::npos)
                pos = line.find("Z");
            if (pos != std::string::npos) {
                str = line.substr(pos + 1);
                if (isDigit(str))
                    return (str);
                else {
                    std::cout << m_x << " " << m_y << " " << m_z << std::endl;
                    throw ("ERROR SCRIPT");
                }
            }
            std::cout << m_x << " " << m_y << " " << m_z << std::endl;
            throw ("ERROR SCRIPT");
            return (str);
        }
        int isDigit(const std::string& s)
        {
            size_t i = 0;
            if (s.at(i) == 45)
                ++i;
            for(; i < s.size(); ++i) {
                if ((s.at(i) < 48 || s.at(i) > 57) && s.at(i) != 46)
                    return (0);
            }
            return (1);
        }
};
template<class T>
std::ostream &operator<<(std::ostream &out, const ParserGCODE<T>& code)
{
	out << code.getX() << " " << code.getY() << " " << code.getZ();

	return (out);
}

#endif
