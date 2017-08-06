/*************************************************************************
	> File Name: C.cpp
	> Author: huhao
	> Mail: 826538400@qq.com 
	> Created Time: 2017/5/13 14:36:07
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
int f[210][210],p[210][210],n,m,ans;
int dfs(int x,int y)
{
	if(!f[x][y]||p[x][y])rt 0;
	p[x][y]=1;
	rt 1+dfs(x+1,y)+dfs(x-1,y)+dfs(x,y+1)+dfs(x,y-1);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("", "r", stdin);
    freopen("", "w", stdout);
#endif
	n=read();
	m=read();
	fr(i,1,read())
		f[read()][read()]=1;
	fr(i,1,n)
		fr(j,1,m)
			if(!p[i][j]&&f[i][j])
				ans=max(ans,dfs(i,j));
	printf("%d\n",ans);
	rt 0;
}
