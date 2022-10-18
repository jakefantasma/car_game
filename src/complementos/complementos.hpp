#include <iostream>
#include <string>
#include <conio.h>

// impllementaciones
using std::cout;
using std::endl;
using std::string;
using std::to_string;
#ifndef Implementaciones
namespace Implementaciones
{
    class Console
    {
    private:
        const string __error_separador = "##";
        const string __normal_separador = "--";
        const int __limit_w = 20; // el calculo va de la mano con separador
        string separador_er = dupliS(__error_separador, __limit_w);
        string separador_normal = dupliS(__normal_separador, __limit_w);
        const string __error_color = "4";
        const string __normal_color = "7";
        string dupliS(string msg, int iteraciones)
        {
            string tmp = "";
            for (size_t i = 0; i < iteraciones; i++)
            {
                tmp += msg;
            }
            return tmp;
        }
    public:
        Console(){};
        void log(string msg)
        {
            color(__normal_color);
            cout << msg << endl;
        };
        void log(int msg)
        {
            log(to_string(msg));
        };
        void error(string msg)
        {
            error(msg, false);
        }
        void error(string msg, bool cl)
        {
            clear();
            log(separador_er);
            log(msg);
            color(__error_color);
            __subAwait();
            if (cl)
            {
                clear();
                log(separador_normal);
            }
        }
        void color(string color)
        {
            system(("color " + color).c_str());
        };
        void clear()
        {
            system("cls");
        };
        void __subAwait()
        {
            getch();
        }
    };
}
#endif