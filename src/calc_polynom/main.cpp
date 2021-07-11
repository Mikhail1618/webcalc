#include<iostream>
#include<fstream>
#include"lagrange.hpp"
#include"handler_str.hpp"


int main(int argc, char ** argv)
{
    if (argc != 5)
    {
	std::cerr << "number of arguments != 5\n";
	return 1;
    }   

    unsigned int count_p = 0;
    Point2 * p = getPoints(argv[1], count_p);

    Lagrange_data data;
    data.x_start = std::stod(argv[2]);
    data.x_end = std::stod(argv[3]);
    data.step = std::stod(argv[4]);
    data.arr_points = p;
    data.count_points = count_p;

    Lagrange polynom(data);


    std::ofstream outfile("points.txt");

    outfile << "#X\t\tY" << std::endl;

    for (double xi = data.x_start; xi < data.x_end; xi += data.step)
        outfile << xi << "\t\t" << polynom.F(xi) << "\n";

    outfile.close();

    return 0;
}
