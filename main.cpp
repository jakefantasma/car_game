#include <iostream>
using std::to_string;
#include ".\src\complementos\complementos.hpp"
#include ".\src\game\game.hpp"
using  Implementaciones::console;
using  Game::GameOb;

//using  Game::newGame;

const string separador = "--";
void __separador()
{
    console.log(console.dupliS(separador, 15));
}

int main()
{
start_mainMenu:
    console.clear();
    console.setDefValueSize(10, 50, true);
    __separador();
    console.log(" Menu game");
    __separador();
    console.log("1 new game");
    console.log("2 history");
    console.log("3 settings");
    console.log("");
    console.log("0 exit");
    __separador();
    int opt = console.getInteger();
    if (opt == 1)
    {
        //update();
    }
    else if (opt == 0)
    {
        console.log("adios !");
        return 0;
    }
    else
    {
        console.error("opcion invalida");
        goto start_mainMenu;
    }
    return 0;
}