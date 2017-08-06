/*************************************************************************
	> file name: d.cpp
	> author: huhao
	> mail: 826538400@qq.com 
	> created time: 2017/5/13 14:55:39
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;
#define inf 0x3f3f3f3f
#define eps 1e-8
#define rt return
#define gc getchar()
#define ll long long
#define fr(i,a,b) for(int i=a,_end_=b;i<=_end_;i++)
#define fd(i,a,b) for(int i=a,_end_=b;i>=_end_;i--)
void swap(int a,int b)
{
	a^=b^=a^=b;
}
int read()
{
	int r=1,t=0;
	char c=gc;
	while(c<'0'||c>'9')
	{
		if(c=='-')
			r=-1;
		else
			r=1;
		c=gc;
	}
	while(c>='0'&&c<='9')
	{
		t=(t<<1)+(t<<3)+(c^48);
		c=gc;
	}
	rt r*t;
}
char readchar(int x,int y)
{
	char c=gc;
	while(c<x||c>y)
		c=gc;
	rt c;
}
double log(double x,double y)
{
	rt log10(x)/log10(y);
}
int gcd(int x,int y)
{
	rt y?gcd(y,x%y):x;
}
int lcm(int x,int y)
{
	rt x*y/gcd(x,y);
}
char a[2010],b[2010],c[2010],d[2010];
int n;
bool check()
{
	fr(i,1,n<<1)
		if(d[i]!=c[i])
			rt 0;
	rt 1;
}
int main()
{
#ifndef online_judge
    freopen("", "r", stdin);
    freopen("", "w", stdout);
#endif
	fr(interesting,1,read())
	{
		n=read();
		fr(i,1,n)
			a[i]=readchar('A','Z');
		fr(i,1,n)
			b[i]=readchar('A','Z');
		fr(i,1,n<<1)
			c[i]=readchar('A','Z');
		fr(i,1,n)
			d[i]=b[i];
		fr(i,1,n)
			d[i+n]=a[i];
		if(check())
		{
			printf("%d %d\n",interesting,0);
			goto end;
		}
		//puts(c+1);
		//puts(d+1);
		fr(ans,1,2*n)
		{
			fr(i,1,n)
			{
				d[(i<<1)-1]=b[i];
				d[i<<1]=a[i];
			}
			//puts(d+1);
			fr(i,1,n)
				a[i]=d[i];
			fr(i,1,n)
				b[i]=d[n+i];
			if(check())
			{
				printf("%d %d\n",interesting,ans);
				goto end;
			}
		}
		printf("%d -1\n",interesting);
		end:;
	}
	rt 0;
}
