#include <iostream>
using namespace std;

char a[100][100], b[100][100];

int mu(int n)
{
    int res=1;
    for (int i=0; i<n; i++)
        res*=2;
    return res;
}
void pr(int n)
{
    int i, j;
    if (n==2)
    {
        a[0][0]=a[0][1]=a[1][0]='.';
        a[1][1]='o';
    }
    else
    {
        pr(n/2);
        for (i=0; i<n/2; i++)
            for (j=0; j<n/2; j++)
                b[i][j]=a[i][j];

        for (i=0; i<n/2; i++)
            for (j=0; j<n/2; j++)
                a[i][j]=a[i+n/2][j]=a[i][j+n/2]=b[i][j];

        for (i=n/2; i<n; i++)
            for (j=n/2; j<n; j++)
                if (b[i-n/2][j-n/2]=='.')
                    a[i][j]='o';
                else
                    a[i][j]='.';
    }
}

int main()
{
    int n;
    cin>> n;
    n=mu(n);
    pr(n);
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            cout<< a[i][j];
        cout<< endl;
    }
    return 0;
}
