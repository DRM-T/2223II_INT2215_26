#include <iostream>
using namespace std;
int main()
{
    int a, n, m, res=1;
    cin>> a>> n>> m;
    a=a%m;
    res=1;
    while (n>0)
    {
        res=(res*a)%m;
        n--;
    }
    cout<< res;
}
