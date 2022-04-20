#ifndef DRIVER_H
#define DRIVER_H
#include "game.h"
#include<utility>
#include<fstream>
#include "Vector.h"
using namespace std;
namespace shah{
class driver:public game
{
public:
    driver();
    ~driver();
    void read_hall();
    void show_hall();
    void intro();
    void write_hall();
    void sort();
protected:
private:
    Vector<pair<string,long long> >v;
    string s;
};
}

#endif // DRIVER_H
