#include <iostream>
using namespace std;

char a[100][100];
int m, n;

struct vt
{
	string word;
	int x;
	int y;
	int c=-1;
	int d=-1;

	bool check()
	{
	    int m=word.length();
		for (int i=0; i<m; i++)
			if (word[i]<'a' || word[i]>'z')
				return false;
		return true;
	}

	string reserve()
	{
	    int m=word.length();
		string res="";
		for (int i=0; i<m; i++)
			res=word[i]+res;
		return res;
	}

	void ngang()
	{
    	int l=word.length(), i=0;
    	while (i<l)
    	{
        	if (a[x][(y+i)%n]!=word[i])
            	return;
        	i++;
    	}
    	i--;
    	c=x;
    	d=(y+i)%n;
    	return;
	}

	void doc()
	{
    	int l=word.length(), i=0;
    	while (i<l)
    	{
        	if (a[(x+i)%m][y]!=word[i])
            	return;
        	i++;
    	}
    	i--;
    	c=(x+i)%m;
    	d=y;
    	return;
	}

	void cheo1()
	{
    	int l=word.length(), i=0;
    	while (i<l)
    	{
        	if (a[(x+i)%m][(y+i)%n]!=word[i])
            	return;
        	i++;
    	}
    	i--;
    	c=(x+i)%m;
    	d=(y+i)%n;
    	return;
	}

	void cheo2()
	{
    	int l=word.length(), i=0;
    	while (i<l)
    	{
        	if (y==0 && i!=0)
            	y+=n;
        	if (a[(x+i)%m][y-i]!=word[i])
            	return;
        	i++;
    	}
    	i--;
    	c=(x+i)%m;
    	d=y-i;
    	if (d<0)
    		d+=n;
    	return;
	}

	void pr()
	{
		cout<< x%m+1<< " "<< y%n+1<< " "<< c+1<< " "<< d+1<< endl;
	}

	void pr2()
	{
		cout<< c+1<< " "<< d+1<< " "<< x%m+1<< " "<< y%n+1<< endl;
	}
	void pr3()
	{
		cout<< "not found"<< endl;
	}
};

bool tuyet(vt &s, int e, int f)
{
	s.x=e;
	s.y=f;
	s.c=-1;
	s.d=-1;

	s.ngang();
	s.doc();
	s.cheo1();
	s.cheo2();
	if (s.c!=-1)
		return true;
	return false;
}

int main()
{
    cin>> m>> n;
    int i, j;
    for (i=0; i<m; i++)
        for (j=0; j<n; j++)
            cin>> a[i][j];

    int k;
    cin>> k;
    cin.ignore();

    for (i=0; i<k; i++)
    {
    	vt s;
    	getline(cin, s.word);
    	if (s.check())
    	{
    		for (int e=0; e<m; e++)
			{
				if (s.c!=-1)
					break;
				for (int f=0; f<n; f++)
					if (tuyet(s, e, f))
						break;
			}

			if (s.c!=-1)
				s.pr();
			else
			{
				s.word=s.reserve();
				for (int e=0; e<m; e++)
				{
					if (s.c!=-1)
						break;
					for (int f=0; f<n; f++)
						if (tuyet(s, e, f))
							break;
				}
				if (s.c!=-1)
					s.pr2();
				else
					s.pr3();
			}
		}
		else
			cout<< "input error"<< endl;
	}
}
