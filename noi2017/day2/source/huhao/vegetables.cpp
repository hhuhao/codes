#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<vector>
#include<map>
#include<queue>
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
#define N 100010
struct node
{
	int v,u,x,t;
}g[N];
struct node2
{
	int u,v;
}f[N<<1];
bool cmp(node2 a,node2 b)
{
	rt a.v>b.v;
}
int n,m,k,ans,t,d;
int main(){
#ifndef ONLINE_JUDGE
	freopen("","r",stdin);
	freopen("","w",stdout);
#endif
	n=read();
	m=read();
	k=read();
	fr(i,1,n)
	{
		g[i].v=read();
		g[i].x=read();
		g[i].u=read();
		g[i].t=read();
	}
	fr(i,1,n)
	{
		f[i].v=g[i].v;
		f[i].u=g[i].u-1;
		f[i+n].v=g[i].v+g[i].x;
		f[i+n].u=1;
	}
	sort(f+1,f+n+n+1,cmp);
	//fr(i,1,n<<1)
	//	printf("%d %d\n",f[i].v,f[i].u);
	while(k--)
	{
		ans=0;
		t=read();
		t*=m;
		d=1;
		while(t)
		{
			if(t>f[d].u)
			{
				t-=f[d].u;
				ans+=(ll)f[d].u*f[d].v;
			}
			else
			{
				ans+=(ll)t*f[d].v;
				t=0;
			}
			d++;
		}
		printf("%lld\n",ans);
	}
	rt 0;
}
/*
3 5 1
4 3 2 0
5 2 1 0
1 10 2 0
1

30
*/