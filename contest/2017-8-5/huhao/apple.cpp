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
struct chair
{
	int l,r;
}c[210];
int g[1000010],n,m,h,k,a[1000010],s[1000010],f[210][210],ans;
bool cmp1(chair a,chair b)
{
	rt a.l<b.l;
}
int findl(int x)
{
	int l=1,r=n+1;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(g[mid]<x)
			l=mid+1;
		else
			r=mid;
	}
	rt l;
}
int findr(int x)
{
	int l=1,r=n+1;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(g[mid]<=x)
			l=mid+1;
		else
			r=mid;
	}
	rt l;
}
map<int,int>ap;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	n=read();
	m=read();
	h=read();
	k=read();
	fr(i,1,n)
		g[i]=read()-h;
	sort(g+1,g+n+1);
	//nlogn
	fr(i,1,m)
	{
		c[i].l=findl(read());
		c[i].r=findr(read())-1;
	}
	//mlogn
//	fr(i,1,m)
//		printf("%d %d\n",c[i].l,c[i].r);
	sort(c+1,c+m+1,cmp1);
	//mlogm
/*
	fr(i,1,m)
		a[i]=c[i].l;
	fr(i,1,m)
		a[m+i]=c[i].r;
	fr(i,1,m<<1)
		printf("%d%c",a[i],i==_end_?'\n':' ');
	sort(a+1,a+m+m+1);//mlogm
	fr(i,1,m<<1)
		printf("%d%c",a[i],i==_end_?'\n':' ');
//	fr(i,1,m<<1)
//		s[i]=s[i-1]+a[i];
	fr(i,1,m<<1)
		ap[a[i]]=i;
	fr(i,1,m)
	{
		c[i].l=ap[c[i].l];
		c[i].r=ap[c[i].r];
	}
	fr(i,1,m)
		printf("%d %d\n",c[i].l,c[i].r);

	fr(i,1,m)
	{
		fr(j,0,m<<1)
			fr(o,0,k)
				f[i][j][o]=f[i-1][j][o];
		fr(j,0,m<<1)
			fr(o,1,k)
				f[i][c[i].r][o]=max(f[i][c[i].r][o],
				f[i-1][j][o-1]+a[c[i].r]-a[max(j+1,c[i].l)]+1);
	}//km^2
	fr(i,0,m<<1)
		fr(o,1,k)
			ans=max(f[m][i][o],ans);//mk
*/
	fr(i,1,m)
		fr(j,1,k)
			fr(o,0,i-1)
				if(c[i].r>c[o].r)
					ans=max(f[i][j]=max(f[i][j],
					f[o][j-1]+c[i].r-max(c[i].l,c[o].r+1)+1),ans);
	//O(m^2k)
	printf("%d\n",ans);
//	fr(i,1,m)
//		printf("%d %d\n",c[i].l,c[i].r);
	rt 0;
}