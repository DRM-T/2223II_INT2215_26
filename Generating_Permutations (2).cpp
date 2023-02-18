#include <iostream>
using namespace std;

string s, result;
bool Free[100];     // Free[i]=Did the result contain s[i]?
int n, count=0;

void start();       // Read s && create result, n, free[]
void print();       // Print result
void choose(int x); // Select the i-th character for the result

int main()
{
    start();
    choose(0);
    return 0;
}

void start()
{
    cin>> s;
    result=s;
    n=s.length();
    for (int i=0; i<n; i++)
        Free[i]=false;
}
void print()
{
    count++;
    cout<< count<< ":   "<< result<< endl;
}

void choose(int x)
{
    int i;
    if (x==n)
    {
        print();
        return;
    }
    for (i=0; i<n; i++)
        if (!Free[i])
        {
            result[x]=s[i];
            Free[i]=true;
            choose(x+1);
            Free[i]=false;
        }
}

