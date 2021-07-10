#include<iostream>
#include"lagrange.hpp"
#include<fstream>
#include<algorithm>


void fun(char * str)
{
    std::string s(str);

    int n = 0

    for (int i = 0; i < s.length(); ++i)
        if (s[i] == ';')
            ++n;

    std::string open = "(";
    std::string midle = ";";
    std::string close = ")";

    s.erase(std::remove(s.begin(), s.end(), '('), s.end());
    s.erase(std::remove(s.begin(), s.end(), ')'), s.end());
    
    int pos = 0;
    std::string token;
    while ((pos = s.find(';')) != std::string::npos)
    {
        token = s.substr(0, pos);
        std::cout << token << std::endl;
        s.erase(0, pos + 1);
    }

    std::cout << s << n << "\n";
}


int main(int argc, char ** argv)
{
    if (argc != 5)
    {
	std::cout << "number of arguments != 5\n";
	return 1;
    }
   
   
        for (int i = 0; i < argc; ++i)
            std::cout << argv[i] << "\n";
   

    fun(argv[1]);

    Point2 *p = new Point2[3];
    p[0] = Point2(-1.0, 1.0);
    p[1] = Point2(0.0, 0.0);
    p[2] = Point2(1.0, 1.0);

    Lagrange_data data;
    data.x_start = std::stod(argv[2]);
    data.x_end = std::stod(argv[3]);
    data.step = std::stod(argv[4]);
    data.arr_points = p;
    data.count_points = 3;

    Lagrange polynom(data);

    //for (double xi = data.x_start; xi < data.x_end + data.step; xi += data.step)
        //std::cout << "(" << xi << ";" << polynom.F(xi) << ")\n";

    std::ofstream outfile ("test.txt");

    outfile << "hello" << std::endl;

    outfile.close();

    return 0;
}
