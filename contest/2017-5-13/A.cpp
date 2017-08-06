/*************************************************************************
	> file name: a.cpp
	> author: huhao
	> mail: 826538400@qq.com 
	> created time: 2017/5/13 9:20:05
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
int pow(int x,int y)
{
	int k=1;
	while(y)
	{
		if(y&1)
			k*=x;
		x*=x;
		y>>=1;
	}
	rt k;
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
int x[10],k[10],p[10];
int main()
{
#ifndef online_judge
    freopen("", "r", stdin);
    freopen("", "w", stdout);
#endif
	fr(i,1,3)
		fr(j,1,3)
			k[i*3+j-3]=x[i*3+j-3]=readchar('0','3')-48;
	fr(_1,0,3)
	fr(_2,0,3)
	fr(_3,0,3)
	fr(_4,0,3)
	fr(_5,0,3)
	fr(_6,0,3)
	fr(_7,0,3)
	fr(_8,0,3)
	fr(_9,0,3)
	{
		x[1]+=_1,x[2]+=_1,x[4]+=_1,x[5]+=_1;
		x[1]+=_2,x[2]+=_2,x[3]+=_2;
		x[2]+=_3,x[3]+=_3,x[5]+=_3,x[6]+=_3;
		x[1]+=_4,x[4]+=_4,x[7]+=_4;
		x[2]+=_5,x[4]+=_5,x[5]+=_5,x[6]+=_5,x[8]+=_5;
		x[3]+=_6,x[6]+=_6,x[9]+=_6;
		x[4]+=_7,x[5]+=_7,x[7]+=_7,x[8]+=_7;
		x[7]+=_8,x[8]+=_8,x[9]+=_8;
		x[5]+=_9,x[6]+=_9,x[8]+=_9,x[9]+=_9;
		bool flag=1;
		fr(i,1,9)
			if(x[i]%4)
			{
				flag=0;
				break;
			}
		if(flag)
		{
			int o=0;
			if(_1)fr(i,1,_1)p[++o]=1;
			if(_2)fr(i,1,_2)p[++o]=2;
			if(_3)fr(i,1,_3)p[++o]=3;
			if(_4)fr(i,1,_4)p[++o]=4;
			if(_5)fr(i,1,_5)p[++o]=5;
			if(_6)fr(i,1,_6)p[++o]=6;
			if(_7)fr(i,1,_7)p[++o]=7;
			if(_8)fr(i,1,_8)p[++o]=8;
			if(_9)fr(i,1,_9)p[++o]=9;
			fr(i,1,o)
				printf("%d%c",p[i],i==o?'\n':' ');
			rt 0;
		}
		fr(i,1,9)
			x[i]=k[i];
	}
	rt 0;
}
