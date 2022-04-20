#ifndef GAME_H
#define GAME_H
#include<deque>
#include<string>
#include "Vector.h"
#include<cstring>
#include<iostream>
#include<windows.h>
#include <time.h>
#include<fstream>
using namespace std;
namespace shah
{
class game
{
public:
    int startgame();
    void read();
    void show(int rn);
    void show_life(int);
    void show_life1(int pos1,int pos2,int rn);
    void show_life2(int x,int rn);
    game();
protected:
private:
    bool ff[5];
    bool prev[5];
    int ara[5];
    int pos1,pos2;
    long long money[17];
    bool visited[40];
    Vector<string>ques;
    Vector<string>ans;
    string option[40][5];
};
}

#endif // GAME_H
