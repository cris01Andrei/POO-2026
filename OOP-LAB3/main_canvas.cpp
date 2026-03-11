#include "Canvas.h"

int main() {
    Canvas c(50, 20);
    
    c.DrawRect(5, 2, 15, 8, '#');
    c.FillRect(20, 2, 30, 8, '*');
    c.DrawCircle(10, 15, 4, '@');
    c.FillCircle(40, 15, 4, '+');
    c.DrawLine(0, 0, 49, 19, '.');
    
    c.Print();
    return 0;
}