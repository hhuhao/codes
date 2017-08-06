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
int n,k,t[1000010];
double p[1000010],f[1000010][2],ans;
void dfs(int x)
{
//	cerr<<x<<endl;
	if(x==n+1)
	{
		double p_=1;
		fr(i,1,n)
			if(t[i])
				p_*=p[i];
			else
				p_*=1-p[i];
		int l=2,l_=0,tt=-k;
		fr(i,1,n)
			if(l!=t[i])
			{
				if(l)
					tt+=k+l_*l_*l_;
				else
					tt-=k+l_*l_;
				l=t[i];
				l_=1;
			}
			else
				l_++;
		if(l)
			tt+=k+l_*l_*l_;
		else
			tt-=k+l_*l_;
		ans+=tt*p_;
//		fr(i,1,n)printf("%d%c",t[i],i==n?'\n':' ');
//		printf("%d %lf %lf\n",tt,p_,ans);
		rt;
	}
	dfs(x+1);
	t[x]=1;
	dfs(x+1);
	t[x]=0;
}
int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	n=read();
	k=read();
	fr(i,1,n)
		scanf("%lf",&p[i]);
	dfs(1);
	printf("%.6lf\n",ans);
	rt 0;
}