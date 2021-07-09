#pragma once
#ifndef LAGRANGE_H
#define LAGRANGE_H
#include<iostream>

struct Point2
{
    double x;
    double y;

    Point2()
	: x(0), y(0)
    {}

    Point2(double x, double y)
	: x(x), y(y)
    {}
};

struct Lagrange_data
{
    double x_start;
    double x_end;
    double step;
    Point2 *arr_points;
    unsigned int count_points;
};

class Lagrange
{
    Lagrange_data data;
 
public:
        Lagrange(Lagrange_data d) 
	    : data(d)
        {}

        double F(double x);
        
//private:

};

#endif // !LAGRANGE_H
