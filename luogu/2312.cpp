#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<vector>
#include<map>
#include<queue>
#include<time.h>
#include<fstream>
#include<string>
#include<set>
#include<list>
#include<stdlib.h>
#define fr(i,a,b) for(int i=a,_end_=b;i<=_end_;i++)
#define fd(i,a,b) for(int i=a,_end_=b;i>=_end_;i--)
#define frei(s) freopen(s,"r",stdin)
#define freo(s) freopen(s,"w",stdout)
#define ll long long
#define uns unsigned
using namespace std;
#define rt return
#define gc getchar()
#define ln putchar('\n')
ll lowbit(ll x)
{
	rt x&(-x);
}
int read(){
	int s=0,k=1;
	char c=getchar();
	while((c<'0'||c>'9')&&c!='-')c=gc;
	if(c=='-'){
		k=-1;
		c=gc;
	}
	while(c>=48&&c<='9'){
		s=s*10+c-48;
		c=gc;
	}
	rt s*k;
}
int exgcd(int a,int b,int &x,int &y)  
{  
    if(b==0)  
    {  
        x=1;
		y=0;  
        return a;  
    }  
    int d=exgcd(b,a%b,x,y);  
    int temp=x;  
    x=y;  
    y=temp-a/b*y;  
    return d;  
}  
double log(double x,double y)
{
	rt log10(x)/log10(y);
}
ll gcd(ll x,ll y)
{
	rt y?gcd(y,x%y):x;
}
ll P(ll x,ll y)//x>=y
{
	ll r=1;
	fr(i,1,y)
		r*=(x-i+1);
	rt r;
}
ll P(ll x,ll y,ll modnum)//x>=y
{
	ll r=1;
	fr(i,1,y)
		r=r*(x-i+1)%modnum;
	rt r;
}
#define s 10
int prime[s]={4621,8053,9227,3001,2333,5011,7121,8009,9973,1117};
int g[100010][s],p[1000010],n,m;
int f(int x,int y)
{
	int r=0,t=1;
	fr(i,0,n)
	{
		r=(r+t*g[i][y])%prime[y];
		t=t*x%prime[y];
	}
	rt r;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("","r",stdin);
	freopen("","w",stdout);
#endif
	n=read();
	m=read();
	fr(i,0,n)
	{
		char c=gc;
		while(c<'0'&&c>'9'&&c!='-')
			c=gc;
		int k=c=='-'?-1:1;
		c=c=='-'?gc:c;
		while(c>='0'&&c<='9')
		{
			fr(j,0,s-1)
				g[i][j]=(g[i][j]*10+c-48)%prime[j];
			c=gc;
		}
		fr(j,0,s-1)
			g[i][j]*=k;
	}
	fr(i,0,s-1)
		fr(j,0,prime[i]-1)
			if(f(j,i))
				for(int k=j;k<=m;k+=prime[i])
					p[k]=1;
	int ans=0;
	fr(i,1,m)
		if(!p[i])
			ans++;
	printf("%d\n",ans);
	fr(i,1,m)
		if(!p[i])
			printf("%d\n",i);
	rt 0;
}
/*
2 10
1 -1 1
*/