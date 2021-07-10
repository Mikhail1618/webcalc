#include<iostream>
#include"lagrange.hpp"
#include<fstream>

int main(int argc, char ** argv)
{
    if (argc == 5)
    {
	std::cerr << "number of arguments != 5\n";
	return 1;
    }
    else
    {
        for (int i = 0; i < argc; ++i)
            std::cout << argv[i] << "\n";
    }

    Point2 *p = new Point2[3];
    p[0] = Point2(-1.0, 1.0);
    p[1] = Point2(0.0, 0.0);
    p[2] = Point2(1.0, 1.0);

    Lagrange_data data;
    data.x_start = -1;
    data.x_end = 1;
    data.step = 0.01;
    data.arr_points = p;
    data.count_points = 3;

    Lagrange polynom(data);

    //for (double xi = data.x_start; xi < data.x_end + data.step; xi += data.step)
        //std::cout << "(" << xi << ";" << polynom.F(xi) << ")\n";

    std::ofstream outfile ("test.txt");

    outfile << argv[0] << std::endl;

    outfile.close();

    return 0;
}
