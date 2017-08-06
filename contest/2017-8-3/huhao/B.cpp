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
#define mod 998244353
int n,m,ans[510],s[510],t[510],g[510],_;
void dfs(int x)
{
//	cerr<<x<<endl;
//	printf("%d\n",x);
	if(x==m+1)
	{
		_++;
		fr(i,1,n)
			ans[i]=(ans[i]+t[i])%mod;
		rt;
	}
	fr(i,1,n)
		fr(j,i,n)
		{
			fr(k,1,n)
				s[k]=t[k];
			int __=0;
			fr(k,i,j)
				__=max(__,t[k]);
			fr(k,i,j)
				t[k]=__;
			dfs(x+1);
			fr(k,1,n)
				t[k]=s[k];
		}
}
int main(){
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	n=read();
	m=read();
	fr(i,1,n)
		t[i]=read();
	dfs(1);
	int x=_,y;
	exgcd(_,mod,_,y);
	_=(_%mod+mod)%mod;
//	fr(i,1,n)
//		printf("%d%c",ans[i],i==n?'\n':' ');
	fr(i,1,n)
		printf("%d%c"/*,1.0*ans[i]/x*/,(ll)ans[i]*_%mod,i==n?'\n':' ');
	rt 0;
}
/*
3 1
1 3 2

1 3 2 
1 3 2
1 3 2
3 3 2 
1 3 3 
3 3 3 

10 18 14

*/