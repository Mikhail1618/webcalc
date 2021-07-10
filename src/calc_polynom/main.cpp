#include<iostream>
#include"lagrange.hpp"
#include<fstream>
#include<algorithm>


std::string * substrs(char * str)
{
    std::string s(str);

    int n = 0;

    for (int i = 0; i < s.length(); ++i)
        if (s.at(i) == ';')
            ++n;

   //std::string * mas = new std::string[n];
    Point2 * p = new Point2[n];

    s.erase(std::remove(s.begin(), s.end(), '('), s.end());
    s.erase(std::remove(s.begin(), s.end(), ')'), s.end());
    
    int pos = 0;
    int j = 0, k = 0;
    std::string token;
    while ((pos = s.find(';')) != std::string::npos)
    {
        token = s.substr(0, pos);

        if (j%2 == 0)
            p[k].x = std::stod(token);
        else
        {
            p[k].y = std::stod(token);
            ++k;
        }
        //mas[j] = token;
        ++j;
        s.erase(0, pos + 1);
    }

    p[k].y = std::stod(s);
    //mas[j] = s;

    //for (int i = 0; i < n; i+=2)
        
        //std::cout << mas[i] << " " << mas[i+1] << "\n";
    return mas;
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
   

    //fun(argv[1]);

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
