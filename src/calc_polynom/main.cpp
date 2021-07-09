#include<iostream>
#include"lagrange.hpp"

int main(int argc, char ** argv)
{
    if(argc != 2)
    {
	std::cerr << "number of arguments != 2\n";
	return 1;
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

    for(double xi = data.x_start; xi < data.x_end + data.step; xi += data.step)
        std::cout << "(" << xi << ";" << polynom.F(xi) << ")\n";

    return 0;
}
