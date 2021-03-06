#include "driver.h"
#include<algorithm>
using namespace shah;
driver::driver()
{
    read_hall();
}
driver::~driver()
{

}
void driver::read_hall()
{
    ifstream fin("hall.txt");
    long long x;
    while(fin>>s>>x)
    {
        v.push_back(make_pair(s,x));
    }
    fin.close();
}
void driver::write_hall()
{
    ofstream fout("hall.txt");
    for(int i=0; i<v.size(); i++)
        fout<<v[i].first<<" "<<v[i].second<<endl;
    fout.close();
}
void driver::show_hall()
{
    system("cls");
    cout<<endl;
    for(int i=0; i<30; i++)
        cout<<'<';
    cout<<" |  Hall of fame  | ";
    for(int i=0; i<30; i++)
        cout<<'>';
    cout<<endl;
    for(int i=0; i<80; i++)
        cout<<'_';
    cout<<endl;
    cout<<"Rank Name";
    for(int i=0; i<33; i++)
        cout<<' ';
    cout<<"Money"<<endl;
    for(int i=0; i<(int)v.size(); i++)
    {
        cout<<'>'<<i+1;
        int x=i+1,len=0;
        while(x)
        {
            len++;
            x/=10;
        }
        for(int j=0; j<5-len; j++)
        {
            if(j==2)
                cout<<'|';
            else
                cout<<' ';
        }
        cout<<v[i].first;
        len=v[i].first.size();
        for(int i=0; i<37-len; i++)
            cout<<' ';
        cout<<v[i].second<<endl;
    }
    for(int i=0; i<80; i++)
        cout<<'_';
    cout<<endl;
    cout<<endl;
}
void driver::intro()
{
    system("COLOR 1E");
    for(int i=0; i<5*16; i++)
        cout<<'_';
    cout<<endl;
    cout<<"\t\t\tEnter Your name: ";
    cin>>s;
    for(int i=0; i<5*16; i++)
        cout<<'_';
    cout<<endl<<endl<<endl;
    long long x,ss;
    while(1)
    {
        for(int i=0; i<32; i++)
            cout<<'\xdb';
        cout<<"    MENU    ";
        for(int i=0; i<36; i++)
            cout<<'\xdb2';
        cout<<endl<<endl<<"\t\t\t";
        for(int i=0; i<22; i++)
            cout<<'_';
        cout<<endl;
        cout<<"\t\t\t\xdb 1.Show hall Of fame  \xdb1"<<endl;
        cout<<"\t\t\t\xdb 2. Start Game        \xdb1"<<endl;
        cout<<"\t\t\t\xdb 3. Any Key to exit   \xdb1"<<endl;
        cout<<"\t\t\t\xdb ";
        for(int i=0; i<21; i++)
            cout<<'_';
        cout<<"\xdb1"<<endl;
        cout<<"\t\t\t\xdb Your Choice: ";
        cin>>x;
        cout<<"\t\t\t  ";
        for(int i=0; i<21; i++)
            cout<<'_';
        cout<<'\xdb1'<<endl;
        if(x==1)
            show_hall();
        else if(x==2)
        {
            ss=startgame();
            v.push_back(make_pair(s,ss));
            //sort(ev.begin(), ev.end(),[](Employee& e1,Employee& e2){return e1.id<e2.id;});
            std::sort(v.begin(),v.end(),[](pair<string,long long>&A,pair<string,long long>&B){return A.second>B.second;});
        }
        else
            break;
    }
    write_hall();
}
void driver::sort()
{
    for(int i=0; i<v.size(); i++)
        for(int j=i+1; j<v.size(); j++)
            if(v[i].second<v[j].second)
                std::swap(v[i],v[j]);
}
