#include "game.h"
using namespace shah;
game::game()
{
    money[1]=5000;
    for(int i=2; i<=15; i++)
    {
        money[i]=2*money[i-1];
    }
    memset(visited,0,sizeof visited);//member set array all element become zero
    ans.clear();
    ques.clear();
    read();
}
void game::show(int rn)
{
    cout<<"\t\t\t1. "<<option[rn][0]<<"\t| 2."<<option[rn][1]<<endl;
    cout<<"\t\t\t3. "<<option[rn][2]<<"\t| 4."<<option[rn][3]<<endl;
}
void println()
{
    cout<<"\t\t\t";
    for(int i=0; i<80; i++)
        cout<<"_";
    cout<<endl;
}
void game::show_life(int life)
{
    if(life)
    {
        cout<<"\t\t\tLifeline"<<endl;
        cout<<"\t\t\t5.50-50";
        printf("%s",ff[0]==0?" Not Used":" Used");
        cout<<"\t6. Audience Pool";
        printf("%s\n",ff[1]==0?" Not Used":" Used");
        printf("\t\t\t7.End Game %s\n",ff[2]==0?" Not Used":" Used");
    }
    else
        cout<<"\t\t\tNo LifeLine for you"<<endl;
}
int game::startgame()
{
    memset(visited,0,sizeof visited);
    memset(prev,0,sizeof prev);
    memset(ff,0,sizeof ff);
    srand(time(NULL));//time fixing korar jonno
    int x,pos,life=3;
    int j=0;
    long long fix=0,sum=0;
    while(j<15)
    {
        memset(prev,0,sizeof prev);
        system("cls");
        j++;
        println();
        cout<<"\t\t\t>>You have won so far "<<sum<<" and fixed Winning money "<<fix<<endl;
        println();
        cout<<"\t\t\t>>You are in Stage "<<j<<endl<<"\t\t\t>>By answering successfully you will get "<<money[j]<<" Money"<<endl;
        println();
        cout<<"\t\t\t>>you have "<<life<<" lifeline available"<<endl;
        println();
        cout<<endl;
        if(j==4 or j==8 or j==15)
            cout<<"\t\t\tBy answering this question successfully you will secure"<<money[j]<<" for You"<<endl;
        int rn=rand()%(ques.size());
        if(rn==2)
        {
            cout<<"debug"<<endl;
            cout<<option[rn][0]<<endl;
        }
        while(visited[rn]!=0)
        {
            rn=rand()%(ques.size());//repeat number generate na korar jonno
        }
        for(int i=0; i<4; i++)
        {
            if(option[rn][i]==ans[rn])
            {
                pos=i;
                break;
            }
        }
        visited[rn]=1;
        cout<<"\t\t\tQuestion::>\n";
        println();
        cout<<"\t\t\t";
        cout<<ques[rn]<<endl;
        println();
        show(rn);
        println();
xxx:
        show_life(life);
        println();
        cout<<"\t\t\tEnter Your Choice :: ";
        cin>>x;
        if((x==5 or x==6 or x==7) and !life)
        {
            cout<<"\t\t\tInvalid t\>Try Again"<<endl;
            goto xxx;
        }
        if(x==5 and !ff[0])
        {
            prev[0]=1;
            ff[0]=1;
            life--;
            pos1=pos;
            pos2=(pos+1)%4;
            show_life1(pos1,pos2,rn);
            goto xxx;
        }
        else if(x==5 and ff[0])
        {
            cout<<"\t\t\tInvalid input\t<<Try again\n";
            goto xxx;
        }
        else if(x==6 and !ff[1])
        {
            prev[1]=1;
            ff[1]=1;
            life--;
            show_life2(pos,rn);
            goto xxx;
        }
        else if(x==6 and ff[1])
        {
            cout<<"\t\t\tInvalid input\t<<Try again\n";
            goto xxx;
        }
        else if(x==7 and !ff[2])
        {
            ff[2]=1;
            fix=sum;
            break;
        }
        else if(x==7 and ff[2])
        {
            cout<<"\t\t\tInvalid input\t<<Try again\n";
            goto xxx;
        }
        else
        {
            if(x-1==pos)
            {
                if(j==4 or j==8 or j==15)
                    fix=money[j];
                sum=money[j];
                continue;//it will go upwards
            }
            break;
        }
    }
    return fix;
}
void game::read()
{
    string s;
    int j=0;
    ifstream fin("file.txt");
    while(getline(fin,s))
    {
        ques.push_back(s);
        for(int i=0; i<4; i++)
        {
            getline(fin,s);
            option[j][i]=s;
        }
        getline(fin,s);
        ans.push_back(s);
        j++;
    }
    fin.close();
}
void game::show_life1(int xy,int yy,int rn)
{
    xy++;
    yy++;
    if(xy==1)
    {
        cout<<"\t\t\t "<<xy<<". "<<option[rn][xy-1];
        if(prev[1])
            printf("-\xdb1 %d",ara[xy-1]);
    }
    else if(yy==1)
    {
        cout<<"\t\t\t"<<yy<<". "<<option[rn][yy-1];
        if(prev[1])
            printf("-\xdb1 %d",ara[yy-1]);
    }
    else
        cout<<"\t\t\t1. \xdb\xdb\xdb\xdb\xdb\xdb";
    if(xy==2)
    {
        cout<<"\t2."<<option[rn][xy-1];
        if(prev[1])
            printf("-\xdb1 %d",ara[xy-1]);
        cout<<endl;
    }
    else if(yy==2)
    {
        cout<<"\t2."<<option[rn][yy-1];
        if(prev[1])
            printf("-\xdb1 %d",ara[yy-1]);
        cout<<endl;
    }
    else
        cout<<"\t| 2. \xdb\xdb\xdb\xdb\xdb\xdb"<<endl;
    if(xy==3)
    {
        cout<<"\t\t\t3. "<<option[rn][xy-1];
        if(prev[1])
            printf("-\xdb1 %d",ara[xy-1]);
    }
    else if(yy==3)
    {
        cout<<"\t\t\t3. "<<option[rn][yy-1];
        if(prev[1])
            printf("-\xdb1 %d",ara[yy-1]);
    }
    else
        cout<<"\t\t\t3. \xdb\xdb\xdb\xdb\xdb\xdb";
    if(xy==4)
    {
        cout<<"\t4. "<<option[rn][xy-1];
        if(prev[1])
            printf("-\xdb1 %d",ara[xy-1]);
        cout<<endl;
    }
    else if(yy==4)
    {
        cout<<"\t4. "<<option[rn][yy-1];
        if(prev[1])
            printf("-\xdb1 %d",ara[yy-1]);
        cout<<endl;
    }
    else
        cout<<"\t| 4.\xdb\xdb\xdb\xdb\xdb\xdb"<<endl;
}
void game::show_life2(int pos,int rn)
{
    ara[pos]=44;
    int s=44;
    for(int i=1; i<=3; i++)
    {
        ara[(pos+i)%4]=rand()%(100-s);
        s+=ara[(pos+i)%4];
    }
    if(prev[0])
    {
        show_life1(pos1,pos2,rn);
        return;
    }
    cout<<"\t\t\t1. "<<option[rn][0]<<"-\xdb1"<<ara[0]<<"%\t| 2."<<option[rn][1]<<"-\xdb1"<<ara[1]<<"%"<<endl;
    cout<<"\t\t\t3. "<<option[rn][2]<<"-\xdb1"<<ara[2]<<"%\t4."<<option[rn][3]<<"-\xdb1"<<ara[3]<<"%"<<endl;
}
