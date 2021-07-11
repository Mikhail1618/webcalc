#include"handler_str.hpp"


Point2 * getPoints(char * str, unsigned int & count_points)
{
    std::string s(str);

    count_points = 0;

    for (int i = 0; i < s.length(); ++i)
        if (s.at(i) == ';')
            ++count_points;


    Point2 * p = new Point2[count_points];

    // remove all '(' and ')' from the string (s)
    s.erase(std::remove(s.begin(), s.end(), '('), s.end());
    s.erase(std::remove(s.begin(), s.end(), ')'), s.end());


    int k = 0;
    int pos = 0, pos2 = 0;
    std::string token;

    // now all points have form  x1;y1 x2;y2 ... xn;yn
    while ((pos = s.find(' ')) != std::string::npos)
    {
        // token is  xi;yi
        token = s.substr(0, pos);
        {
            pos2 = token.find(';');

            // split token on x and y
            p[k].x = std::stod(token.substr(0, pos2));
            p[k].y = std::stod(token.substr(pos2 + 1, token.length() - 1));
        }
        // remove the parsed part of the string
        s.erase(0, pos + 1);
        ++k;
    }
    // process the last line
    pos2 = s.find(';');
    p[k].x = std::stod(s.substr(0, pos2));
    p[k].y = std::stod(s.substr(pos2+1, s.length()-1));

    return p;
}
