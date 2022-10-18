#include ".\src\complementos\complementos.hpp"
using namespace Implementaciones;
Console con = *new Console();

// metodo principal
int main()
{
    con.error("this is a msg error !", true);
    con.log("we get info !");
    return 0;
}