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
#define eps 1e-7
struct point
{
	double x,y;
}f[100010];
bool cmp1(point a,point b)
{
	rt a.y<b.y;
}
bool cmp2(point a,point b)
{
	rt a.x*b.y<a.y*b.x;
}
bool check(point a,point b,point c)
{
	b.x-=a.x;
	b.y-=a.y;
	c.x-=a.x;
	c.y-=a.y;
	rt b.x*c.y>=c.x*b.y;
}
int n,top,s[100010];
int main(){
#ifndef ONLINE_JUDGE
	freopen("","r",stdin);
	freopen("","w",stdout);
#endif
	n=read();
	fr(i,1,n)
		scanf("%lf%lf",&f[i].x,&f[i].y);
	//fr(i,1,n)
	//	printf("%lf %lf\n",f[i].x,f[i].y);
	sort(f+1,f+n+1,cmp1);
	fd(i,n,1)
		f[i].x-=f[1].x,f[i].y-=f[1].y;
	//fr(i,1,n)
	//	printf("%lf %lf\n",f[i].x,f[i].y);
	sort(f+2,f+n+1,cmp2);
	top=1;
	s[1]=1;
	fr(i,2,n)
	{
		while(top>2&&check(f[s[top-1]],f[s[top]],f[i]))
			top--;
		top++;
		s[top]=i;
	}
	double ans=0.0;
	//printf("%d\n",top);
	//fr(i,1,top)
	//	printf("%d %lf %lf\n",s[i],f[s[i]].x,f[s[i]].y);
	fr(i,3,top)
		ans+=fabs(f[s[i-1]].x*f[s[i]].y-f[s[i-1]].y*f[s[i]].x);
	printf("%lf\n",ans/2);
	rt 0;
}
/*
6
0 0
0 2
1 1
1 -1
-1 -1
-1 1

5
*/