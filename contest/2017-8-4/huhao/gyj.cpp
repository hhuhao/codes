#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<bitset>
#include<vector>
#include<map>
#include<queue>
#include<string>
#include<set>
#include<list>
#include<stdlib.h>
#define fr(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define fd(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
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
struct node
{
	int u,v;
	double w;
}g[1000010];
bool cmp1(node a,node b)
{
	rt a.w<b.w||(a.w==b.w&&(a.u<b.u||(a.u==b.u&&a.v<b.v)));
}
bool cmp2(int a,int b)
{
	rt a>b;
}
int n,v[100010],w[100010],e,m,k;
ll s[10000010];
int main(){
	freopen("gyj.in","r",stdin);
	freopen("gyj.out","w",stdout);
	n=read();
	fr(i,1,n)
		v[i]=read(),w[i]=read();
	fr(i,1,n)
		fr(j,1,n)
			if(v[i]<v[j]&&w[i]>w[j])
			{
				e++;
				g[e].u=i;
				g[e].v=j;
				g[e].w=(v[j]-v[i])/(w[i]-w[j]);
			}
	sort(g+1,g+e+1,cmp1);
	m=read();
	k=read();
	fr(i,1,m)
		printf("%d %d\n",g[i].u,g[i].v);
	e=0;
	fr(i,1,m)
		fr(j,1,m)
			s[++e]=w[g[i].u]*w[g[j].v];
	sort(s+1,s+e+1,cmp2);
	printf("%lld\n",s[k]);
	rt 0;
}