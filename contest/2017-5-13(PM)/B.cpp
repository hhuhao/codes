/*************************************************************************
	> File Name: B.cpp
	> Author: huhao
	> Mail: 826538400@qq.com 
	> Created Time: 2017/5/13 14:47:15
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
void SWAP(int a,int b)
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
int h[8010],l[8010],r[8010];
int can(int x,int y)
{
	if(h[x]==h[y])rt 0;
	if(l[x]>r[y])rt 0;
	if(r[x]<l[y])rt 0;
	rt 1;
}
int n,ans;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("", "r", stdin);
    freopen("", "w", stdout);
#endif
	fr(interesting,1,read())
	{
		n=read();
		fr(i,1,n)
			l[i]=read(),r[i]=read(),h[i]=read();
		fr(i,1,n-2)
			fr(j,i+1,n-1)
				if(can(i,j))
					fr(k,j+1,n)
						if(can(i,k)&&can(j,k))
							ans++;
	}
	printf("%d\n",ans);
	rt 0;
}
