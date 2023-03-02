#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

int n, m, k, map[101][101], count=0;
char banDo[101][101];
int dx[8]={0, 0, -1, -1, -1, 1, 1, 1};
int dy[8]={-1, 1, -1, 0, 1, -1, 0, 1};

int random(int );
void createMap();
void open();
void prResult();
void prNow();
void set_color( int code )
{
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute( color , code );
}
void normal()
{
    set_color(7 << 4 | 0);
}
void color1()
{
    set_color(6 << 4 | 1);
}
int main()
{
    normal();
    srand(time(0));
    cin>> m>> n>> k;
    count=n*m-k;
    createMap();
    prNow();
    while (k>0 && count>0)
    {
        count--;
        open();
    }

    if (k==0 || count<=0)
    {
        cout<< "WIN"<< endl<< endl;
        prResult();
    }
}

int random(int x)
{
    return rand()%x + 1;
}

void createMap()
{
    int num=k, i, j, x, y, h;
    for (i=0; i<=m+1; i++)
        for (j=0; j<=n+1; j++)
            map[i][j]=0;
    while (num>0)
    {
        x=random(m);
        y=random(n);
        if (map[x][y]==0)
        {
            //cout<< "choose "<< x<< " ; "<< y<< endl;
            map[x][y]=-1;
            num--;
        }
    }

    for (i=1; i<=m; i++)
        for (j=1; j<=n; j++)
            for (h=0; h<8; h++)
                if (map[i+dx[h]][j+dy[h]]==-1 && map[i][j]!=-1)
                    map[i][j]++;
    for (i=1; i<=m; i++)
        for (j=1; j<=n; j++)
            banDo[i][j]='*';
}

void open()
{
    int x, y;
    bool valid=false;
    while (!valid)
    {
        valid=false;
        cout<< "Yourchoice: (x, y)= ";
        cin>> x>> y;
        if (banDo[x][y]!='*')
            cout<< "Invalid!!!"<< endl;
        else
            valid=true;
    }
    if (map[x][y]==-1)
    {
        k=-100;
        system("cls");
        cout<< "You lose!!!!"<< endl;
        prResult();
    }
    else
    {
        banDo[x][y]=char(map[x][y]+48);
        system("cls");
        prNow();
    }
}

void prNow()
{
    int i, j;
    color1();
    for (i=0; i<=n; i++)
        cout<< i<< " ";
    cout<< endl;
    for (i=1; i<=m; i++)
    {
        color1();
        cout<< i<< " ";
        normal();
        for (j=1; j<=n; j++)
            cout<< banDo[i][j]<< " ";
        cout<< endl;
    }
}

void prResult()
{
    int i, j;
    for (i=1; i<=m; i++)
        for (j=1; j<=n; j++)
            if (map[i][j]!=-1)
                banDo[i][j]=char(map[i][j]+48);
            else
                banDo[i][j]='B';
    prNow();
}
