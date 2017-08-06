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
struct point
{
	int x,y,z;
}g[1010];
int n,f[1010],ans,l[1010],_,p[1010];
bool cmp1(point a,point b)
{
	if(a.x==b.x)
		if(a.y==b.y)
			rt a.z<b.z;
		else
			rt a.y<b.y;
	rt a.x<b.x;
}
bool cmp2(point a,point b)
{
	if(a.x>b.x&&a.y>b.y&&a.z>b.z)
		rt 1;
	rt 0;
}
int main(){
	freopen("missile.in","r",stdin);
	freopen("missile.out","w",stdout);
	n=read();
	fr(i,1,n)
		g[i].x=read(),g[i].y=read(),g[i].z=read();
	sort(g+1,g+n+1,cmp1);
	fr(i,1,n)
	{
		fr(j,1,i-1)
			if(cmp2(g[i],g[j]))
				if(f[j]>f[i])
				{
					f[i]=max(f[i],f[j]);
					l[i]=j;
				}
		f[i]++;
		if(f[i]>ans)
		{
			ans=max(ans,f[i]);
			_=i;
		}
	}
	printf("%d\n",ans);
	/*
	int __=_;
	while(__)
	{
		printf("%d%c",__,l[__]?' ':'\n');
		__=l[__];
	}
	*/
	int k=n,ax=0;
	ans=0;
	while(k)
	{
		int __=_;
		while(__&&!p[__])
		{
			p[__]=1;
			__=l[__];
			k--;
		}
		ax=0;
		fr(i,1,n)
			if(!p[i])
			{
				f[i]=0;
				if(p[l[i]])
				{
					fr(j,1,i-1)
						if(cmp2(g[i],g[j]))
							if(f[j]>f[i])
							{
								f[i]=max(f[i],f[j]);
								l[i]=j;
							}
				}
				else
					f[i]=f[l[i]]+1;
				if(f[i]>ax)
				{
					ax=f[i];
					_=i;
				}
			}
		ans++;
	}
	printf("%d\n",ans);
	rt 0;
}