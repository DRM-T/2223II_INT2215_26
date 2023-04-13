#include <iostream>
#include <map>
using namespace std;
int main()
{
    int n, a[1000], i, max=0;
    map<int, int> f;
    cin>> n;

    for (i=0; i<n; i++)
    {
        cin>> a[i];
        f[a[i]]=i;
    }

    for (i=0; i<n; i++)
        if (f[a[i]]-i>max)
            max=f[a[i]]-i;
    cout<< max;
}
