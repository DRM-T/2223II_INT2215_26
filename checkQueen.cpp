#include <iostream>

using namespace std;

bool row[20002], col[20002], dia1[20002], dia2[20002], check;
int n;

void restart();
bool valid(int x, int y);
void visit(int x, int y);
void solve();

int main()
{
    restart();
    solve();
    if (check)
        cout<< "yes";
    else
        cout<< "no";
}

void restart()
{
    cin>> n;
    for (int i=0; i<=2*n; i++)
        row[i]=col[i]=dia1[i]=dia2[i]=true;
}

void visit(int x, int y)
{
    row[x]=col[y]=dia1[x+y]=dia2[n-y+x]=false;
}

bool valid(int x, int y)
{
    if (row[x] && col[y] && dia1[x+y] && dia2[n-y+x])
        return true;
    return false;
}

void solve()
{
    check=false;
    int x, y, i;
    for (i=0; i<n; i++)
    {
        cin>> x>> y;
        if (valid(x, y))
            visit(x, y);
        else
            check=true;
    }
    return;
}
