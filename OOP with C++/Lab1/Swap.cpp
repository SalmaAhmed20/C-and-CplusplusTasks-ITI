#include <iostream>
using namespace std;
void swap1(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
}
void swap2(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void swap3(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
int main()
{
    int x = 5, y = 6;
    swap1(x, y);
    cout << "ByValue\nx= " << x << " y= " << y << endl;
    swap2(&x, &y);
    cout << "By Address\nx= " << x << " y= " << y << endl;
    swap3(x, y);
    cout << "By Refernce\nx= " << x << " y= " << y << endl;
    return 0;
}
