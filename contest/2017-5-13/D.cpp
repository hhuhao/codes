/*************************************************************************
	> File Name: D.cpp
	> Author: huhao
	> Mail: 826538400@qq.com 
	> Created Time: 2017/5/13 8:37:30
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
int f[410],l[410],r[410],a[410],b[410],n,k,o,x[410],y[410],g[410][410];
int getf(int x)
{
	rt x==f[x]?x:getf(f[x]);
}
void merge(int x,int y)
{
	int u=getf(x),v=getf(y);
	f[v]=f[u];
	l[u]+=l[v];
	r[u]+=r[v];
	l[v]=r[v]=0;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("", "r", stdin);
    freopen("", "w", stdout);
#endif
	fr(interesting,1,read())
	{
		fr(i,1,n<<1)
			f[i]=l[i]=r[i]=0;
		fr(i,1,k)
			a[i]=b[i]=0;
		fr(i,1,o)
			x[i]=y[i]=0;
		fr(i,0,n)
			fr(j,0,n)
				g[i][j]=0;
		n=read();
		fr(i,1,n<<1)
			f[i]=i;
		fr(i,1,n)
			l[i]=1;
		fr(i,n+1,n<<1)
			r[i]=1;
		k=read();
		fr(i,1,k)
		{
			a[i]=read();
			b[i]=read();
			merge(a[i],n+b[i]);
		}
		o=0;
		fr(i,1,n<<1)
			if(l[i]&&r[i])
			{
				o++;
				x[o]=l[i];
				y[o]=r[i];
			}
		g[0][0]=1;
		fr(i,1,o)
			fd(j,n,x[i])
				fd(k,n,y[i])
					if(g[j-x[i]][k-y[i]])
						g[j][k]=1;
		fd(i,n>>1,0)
			if(g[i][i])
			{
				printf("%d\n",i);
				break;
			}
	}
	rt 0;
}
