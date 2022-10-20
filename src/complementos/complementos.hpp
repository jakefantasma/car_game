#pragma once
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
        // separadores constantes
        const string __error_separador = "##";
        const string __normal_separador = "--";
        const int __limit_w = 20; // limit windows size
        // genera los strings para dividir
        string separador_er = dupliS(__error_separador, __limit_w);
        string separador_normal = dupliS(__normal_separador, __limit_w);
        string __warn_color = "6";
        string __clear = "cls";
        // windows config
        int __z_x = 10;
        int __z_y = 50;
        string __normal_color = "7";
        // config by error
        int __er_z_x = 4;
        int __er_z_y = 40;
        string __error_color = "4";
        int __awaitFrame = 10;

    public:
        Console(){};
        // itera un string y retorna su valor <-
        string dupliS(string msg, int iteraciones)
        {
            string tmp = "";
            for (size_t i = 0; i < iteraciones; i++)
            {
                tmp += msg;
            }
            return tmp;
        }
        void log(string msg)
        {
            color(__normal_color);
            cout << msg << endl;
        };
        void log(int msg)
        {
            log(to_string(msg));
        };
        void warn(string msg, bool _clear = false)
        {
            log(msg);
            color(__warn_color);
            __subAwait();
            if (_clear)
            {
                clear();
            }
        };
        void error(int valor)
        {
            error(to_string(valor));
        }
        void error(string msg, bool _clear = false)
        {
            setScreenSize(__er_z_x, __er_z_y);
            clear();
            log(separador_er);
            log(msg);
            log(separador_er);
            color(__error_color);
            __subAwait();
            if (_clear)
            {
                clear();
            }
            setDefaultSize();
        }
        void color(string color)
        {
            system(("color " + color).c_str());
        };
        void clear()
        {
            system(__clear.c_str());
        };
        void __subAwait()
        {
            getch();
        }

        // screen
        void setDefaultSize()
        {
            setScreenSize(__z_x, __z_y);
        }
        void setScreenSize(int x, int y)
        {
            string lines = " lines=" + to_string(x);
            string col = " cols=" + to_string(y);
            string comando = "mode con:" + col + lines;
            system(comando.c_str());
        };

        void setDefValueSize(int x, int y, bool update = false)
        {
            __z_x = x;
            __z_y = y;
            if (update)
            {
                setDefaultSize();
            }
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
        void AwaitFrame(float segundos)
        {
            Sleep(segundos * 1000);
        }
    };

    //reference to use console funcion 
    Console console = *new Console();


}
#endif