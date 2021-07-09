#include"lagrange.hpp"
#include<iostream>

double Lagrange::F(double x)
{
    double result = 0;
    double temp = 1;

    for (unsigned int i = 0; i < data.count_points; ++i)
    {
        for (unsigned int j = 0; j < data.count_points; ++j)
        {
            if (i != j)
                temp *=  (x - data.arr_points[j].x) /
                    (data.arr_points[i].x - data.arr_points[j].x);
        }

        result += data.arr_points[i].y * temp;
        temp = 1;
    }

    return result;
}
