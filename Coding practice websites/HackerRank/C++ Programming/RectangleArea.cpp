/* 30 points : https://www.hackerrank.com/challenges/rectangle-area/problem?isFullScreen=true
Thuan 23.11.13 */

#include <iostream>

using namespace std;
/*
 * Create classes Rectangle and RectangleArea
 */

class Rectangle
{
protected:
    int width;
    int height;

public:
    void read_input();
    void display();
};

class RectangleArea : public Rectangle
{
public:
    void display();
};

void Rectangle::read_input()
{
    cin >> width >> height;
}

void Rectangle::display()
{
    cout << width << " " << height;
}

void RectangleArea::display()
{
    cout << "\n" << width * height;
}

int main()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;

    /*
     * Read the width and height
     */
    r_area.read_input();

    /*
     * Print the width and height
     */
    r_area.Rectangle::display();

    /*
     * Print the area
     */
    r_area.display();

    return 0;
}