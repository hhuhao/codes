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
int read()
{
	int s=0,k=1;
	char c=getchar();
	while((c<'0'||c>'9')&&c!='-')c=gc;
	if(c=='-'){
		k=-1;
		c=gc;
	}
	while(c>=48&&c<='9'){
		s=(s<<3)+(s<<1)+(c^48);
		c=gc;
	}
	rt s*k;
}
ll readmod(ll p)
{
	ll s=0;
	int k=1;
	char c=getchar();
	while((c<'0'||c>'9')&&c!='-')c=gc;
	if(c=='-'){
		k=-1;
		c=gc;
	}
	while(c>=48&&c<='9'){
		s=(s<<3)+(s<<1)+(c^48);
		s%=p;
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
ll power(ll x,ll y,ll p)//x^y%p
{
	x%=p;
	y%=p;
	ll r=1;
	while(y)
	{
		if(y&1)r=r*x%p;
		y>>=1;
		x=x*x%p;
	}
	rt r;
}
#define mod 998244353
int n,m,t,a[11];
int g[5][5],p[10][10];
ll ans;
void draw(int x,int y,int z)
{
	fr(i,1,3)
		fr(j,1,3)
			if(g[i][j])
				p[x+i-2][y+j-2]+=z;
}
void dfs(int x,int y,int t)
{
	//printf("%d %d %d\n",x,y,t);
	if(!t)
	{
		ans++;
		rt;
	}
	if(x==n+1&&y==1)
		rt;
	if(!p[x][y])
	{
		draw(x,y,1);
		if(y==3)
			dfs(x+1,1,t-1);
		else
			dfs(x,y+1,t-1);
		draw(x,y,-1);
	}
	if(y==3)
		dfs(x+1,1,t);
	else
		dfs(x,y+1,t);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("final.in","r",stdin);
	freopen("final.out","w",stdout);
#endif
	n=read();
	m=read();
	if(n<=5)
	{
		fr(i,1,3)
			fr(j,1,3)
				g[i][j]=read();
		g[1][1]=g[3][3]=g[1][1]|g[3][3];
		g[1][2]=g[3][2]=g[1][2]|g[3][2];
		g[1][3]=g[3][1]=g[1][3]|g[3][1];
		g[2][1]=g[2][3]=g[2][1]|g[2][3];
		dfs(1,1,m);
		printf("%d\n",ans);
		rt 0;
	}
	fr(i,1,9)
		a[i]=read();
	fr(i,1,4)
	{
		a[10-i]|=a[i];
		a[i]=0;
	}
	fr(i,1,9)
		t=t*10+a[i];
	if(t==10000)
	{
		ans=1;
		fr(i,2,m)
		{
			int x,y;
			exgcd(i,mod,x,y);
			x=(mod+x%mod)%mod;
			ans=ans*x%mod;
		}
		fr(i,1,m)
			ans=ans*(n+n+n-i+1)%mod;
		printf("%lld\n",ans);
	}
	if(t==10001)
	rt 0;
}