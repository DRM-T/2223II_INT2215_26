#include <iostream>
using namespace std;
int max(int a, int b)
{
    if (a>b)
        return a;
    return b;
}
int main()
{
    int n, k, a[1001], res[1001], sum[1001], i;
    cin>> n>> k;
    for (i=1; i<=n; i++)
        cin>> a[i];

    res[0]=sum[0]=0;

    for (i=1; i<k; i++)
        res[i]=res[i-1]+a[i];

    for (i=1; i<=n; i++)
        sum[i]=sum[i-1]+a[i];

    for (i=k; i<=n; i++)
    {
        res[i]=res[i-1];
        for (int j=i-k+1; j<=i-1; j++)
            res[i]=max(res[j-1]+sum[i]-sum[j-1]-a[j], res[i]);
    }
    for (i=1; i<=n; i++)
        cout<< res[i]<< " ";
}
