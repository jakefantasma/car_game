#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
using std::cin;
using std::cout;
using std::endl;
using std::getline;
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
        // todo add set methods to config
        string separador_er = dupliS(__error_separador, __limit_w);
        string separador_normal = dupliS(__normal_separador, __limit_w);
        string __error_color = "4";
        string __normal_color = "7";
        string __warn_color = "6";
        string __clear = "cls";
        int __z_x = 100;
        int __z_y = 100;
        int __awaitFrame = 10;
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
        // set or show info in console
        void log(string msg)
        {
            color(__normal_color);
            cout << msg << endl;
        };
        void log(int msg)
        {
            log(to_string(msg));
        };
        void warn(string msg)
        {
            warn(msg, false);
        }
        void warn(string msg, bool cl)
        {
            log(msg);
            color(__warn_color);
            __subAwait();
            if (cl)
            {
                clear();
            }
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
            system(__clear.c_str());
        };
        void defsize()
        {
            ResizeScreen(__z_x, __z_y);
        }
        void ResizeScreen(int x, int y)
        {
            string lines = " lines=" + to_string(x);
            string col = " cols=" + to_string(y);
            string comando = "mode con:" + col + lines;
            system(comando.c_str());
        };
        void __subAwait()
        {
            getch();
        }
        // get info
        string getString(string msg)
        {
            log(msg);
            return getString();
        }
        string getString()
        {
            string tmp;
            getline(cin, tmp);
            return tmp;
        }
        int getInteger(string msg)
        {
            log(msg);
            return getInteger();
        }
        int getInteger()
        {
            int tmp;
            cin >> tmp;
            return tmp;
        }
        // wait in screen
        void AwaitFrame()
        {
            AwaitFrame(__awaitFrame);
        }
        void AwaitFrame(int segundos)
        {
            Sleep(segundos * 1000);
        }
    };
}
#endif