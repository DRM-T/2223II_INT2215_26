#include <iostream>
using namespace std;

int n, m, a[100][100], nextX[100][100], nextY[100][100];
int dx[4]={0, 0, 1, -1};
int dy[4]={1, -1, 0, 0};
bool kt[100][100];

void Read()
{
    cin>> m>> n;
    int i, j;
    for (i=1; i<=m; i++)
        for (j=1; j<=n; j++)
        {
            cin>> a[i][j];
            kt[i][j]=true;
        }
}
void visit(int x, int y)
{
    int i;
    for (i=0; i<4; i++)
    {
        int e=x+dx[i], f=y+dy[i];
        if (a[e][f]==0 && kt[e][f] && e>=1 && e<=m && f>=1 && f<=n)
        {
            kt[e][f]=false;
            nextX[e][f]=x;
            nextY[e][f]=y;
            visit(e, f);
        }
    }
}
void solve()
{
    int i=1, j=1;
    while (!(nextX[i][j]==m && nextY[i][j]==n))
    {
        a[i][j]=2;
        int x=nextX[i][j], y=nextY[i][j];
        i=x;
        j=y;
    }
    a[i][j]=2;
    a[m][n]=2;
}
void pr()
{
    for (int i=1; i<=m; i++)
    {
        for (int j=1; j<=n; j++)
            cout<< a[i][j]<< " ";
        cout<< endl;
    }
}
int main()
{
    Read();
    kt[m][n]=false;
    visit(m, n);
    solve();
    pr();
}
