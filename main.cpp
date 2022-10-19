#include <iostream>
using std::to_string;
#include ".\src\complementos\complementos.hpp"
using namespace Implementaciones;
Console con = *new Console();

int main()
{
    con.log("console log example ");
    con.ResizeScreen(20,80);
    return 0;
}