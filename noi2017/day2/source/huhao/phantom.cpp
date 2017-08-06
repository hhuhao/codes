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
/*
struct point
{
	int x,y,num;
}g[N];
bool cmp1(point a,point b)
{
	rt a.y<b.y;
}
bool cmp2(point a,point b)
{
	rt (ll)a.x*b.y<(ll)a.y*b.x;
}
bool check(point a,point b,point c)
{
	b.x-=a.x;
	b.y-=a.y;
	c.x-=a.x;
	c.y-=a.y;
	rt (ll)b.x*c.y>=(ll)b.y*c.x;
}
int n,m,s[N],top;
*/
struct point
{
	int x,y;
}g[N];
bool cmp1(point a,point b)
{
	rt a.y<b.y;
}
bool cmp2(point a,point b)
{
	rt (ll)a.x*b.y<(ll)a.y*b.x;
}
bool check(point a,point b,point c)
{
	b.x-=a.x;
	b.y-=a.y;
	c.x-=a.x;
	c.y-=a.y;
	rt (ll)b.x*c.y>=(ll)b.y*c.x;
}
ll calc(point a,point b)
{
	ll k=(ll)a.x*b.y-a.y*b.x;
	rt k<0?-k:k;
}
#define PR //puts("...");
int n,t,k,top,x[N],y[N],p[N],s[N];
ll ans;
int main(){
#ifndef ONLINE_JUDGE
	freopen("","r",stdin);
	freopen("","w",stdout);
#endif
	n=read();
	t=read();
	if(n<=1000&&t<=1000)
	{
		fr(i,1,n)
			x[i]=read(),y[i]=read();
		ans=-1;
		while(t--)
		{
			fr(i,1,n)
				p[i]=1;
			k=read();
			fr(i,1,k)
				p[(ans+read())%n+1]=0;
			PR;
			int l=0;
			fr(i,1,n)
				if(p[i])
				{
					l++;
					g[l].x=x[i];
					g[l].y=y[i];
				}
			sort(g+1,g+l+1,cmp1);
			PR;
			fd(i,l,1)
			{
				g[i].x-=g[1].x;
				g[i].y-=g[1].y;
			}
			sort(g+2,g+l+1,cmp2);
			PR;
			top=1;
			s[top]=1;
			fr(i,2,l)
			{
				while(top>2&&check(g[s[top-1]],g[s[top]],g[i]))
					top--;
				top++;
				s[top]=i;
			}
			ans=0;
			PR;
			fr(i,3,l)
				ans+=calc(g[s[i-1]],g[s[i]]);
			printf("%lld\n",ans);
		}
	}
	/*
	fr(i,1,n)
	{
		g[i].x=read();
		g[i].y=read();
		g[i].num=i;
	}
	sort(g+1,g+n+1,cmp1);
	fd(i,n,1)
	{
		g[i].x-=g[1].x;
		g[i].y-=g[1].y;
	}
	sort(g+2,g+n+1,cmp2);
	//fr(i,1,n)
	//	printf("%d%c",g[i].num,i==n?'\n':' ');
	s[1]=1;
	top=1;
	fr(i,2,n)
	{
		while(top>2&&check(g[s[top-1]],g[s[top]],g[i]))
			top--;
		//printf(" %d %d\n",i,top);
		top++;
		s[top]=i;
	}
	//printf("%d\n",top);
	//fr(i,1,top)
	//	printf("%d\n",g[s[i]].num);
	*/
	rt 0;
}
/*
15 1
2 2
-3 3
-5 2
-3 1
-1 5
2 6
5 4
3 1
5 1
6 2
-2 2
-4 4
-7 1
-5 6
-3 8
0

6 2
-1 0
-1 -1
0 -1
1 0
0 1
0 0
3 1 3 6
2 0 1
*/