#include <iostream>
using std::cout;
int main()
{
    enum class Color {white, grey, blue, red};
    Color myColor = Color::blue;
    if (myColor==Color::red)
    {
        cout<<" My color is red! "<<"\n";
    }
    else
    {
        cout<<" My color is not red "<<"\n";
    }
    return 0;
}