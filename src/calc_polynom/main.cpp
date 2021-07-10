#include<iostream>
#include"lagrange.hpp"
#include<fstream>
#include<algorithm>

int count = 0;


Point2 * getPoints(char * str)
{
    std::string s(str);

    int n = 0;

    for (int i = 0; i < s.length(); ++i)
        if (s.at(i) == ';')
            ++n;

    count = n;
    Point2 * p = new Point2[n];

    s.erase(std::remove(s.begin(), s.end(), '('), s.end());
    s.erase(std::remove(s.begin(), s.end(), ')'), s.end());
    
    int pos = 0, pos2;
    std::string token, token2;
    while ((pos = s.find(' ')) != std::string::npos)
    {
        token = s.substr(0, pos);
        while ((pos2 = token.find(';')) != std::string::npos)
        {
            token2 = token.substr(0, pos2);
            std::cout << "p1->" << token2 << "\n";
            std::cout << "p1->" << token.substr(pos2, token.end()) << "\n";
        }
        //std::cout << token << "\n";
        //s.erase(0, pos + 1);
    }
    //std::cout << s << "\n";


//for (int i = 0; i < count; ++i)
//std::cout << " x-> " << p[i].x << " y-> " << p[i].y << "\n";



    return p;
}


int main(int argc, char ** argv)
{
    if (argc != 5)
    {
	std::cerr << "number of arguments != 5\n";
	return 1;
    }   

    Lagrange_data data;
    data.x_start = std::stod(argv[2]);
    data.x_end = std::stod(argv[3]);
    data.step = std::stod(argv[4]);
    data.arr_points = getPoints(argv[1]);
    data.count_points = count;

    Lagrange polynom(data);

    for (double xi = data.x_start; xi < data.x_end + data.step; xi += data.step)
        std::cout << "(" << xi << ";" << polynom.F(xi) << ")\n";

    std::ofstream outfile ("test.txt");

    outfile << "hello" << std::endl;

    outfile.close();

    return 0;
}
