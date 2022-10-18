#include <iostream>
#include <string>


//impllementaciones
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
    public:
        Console(){};
        void log(string msg)
        {
            cout << msg << endl;
        };

        void log(int msg)
        {
            log(to_string(msg));
        };
    };
}
#endif