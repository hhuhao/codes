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
#define N 50010
#define N_ 150010
int g[N_],ans[N],p[N_],n,d,m;
vector<int>t[N_];
vector<int>b[N_];
void draw(int x)
{
	if(!p[x])
		rt;
	p[x]=0;
	fr(i,0,b[x].size()-1)
		draw(b[x][i]);
}
void print(int x)
{
	if(ans[(x-1)%n+1]==(x-1)/n+1)
		rt;
	ans[(x-1)%n+1]=(x-1)/n+1;
	fr(i,0,t[x].size()-1)
		print(t[x][i]);
}
int main(){
#ifndef ONLINE_JUDGE
//	freopen("game.in","r",stdin);
//	freopen("game.out","w",stdout);
#endif
	n=read();
	d=read();
	fr(i,1,n)
	{
		char c=gc;
		while((c<'a'||c>'c')&&c!='x')
			c=gc;
		if(c<='c')
			g[i]=c-'a'+1;
	}
	//fr(i,1,n)
	//	printf("%d%c",g[i],i==n?'\n':' ');
	m=read();
	fr(i,1,m)
	{
		int u,v;
		char _,__;
		u=read();
		_=getchar();
		v=read();
		__=getchar();
		int f_=u+n*(_-'A'),t_=v+n*(__-'A');
		//printf("%d %c %d %c %d %d\n",u,_,v,__,f_,t_);
		t[f_].push_back(t_);
		b[t_].push_back(f_);
	}
	//fr(i,1,3*n)
	//	fr(j,0,t[i].size()-1)
	//		printf("%d%c",t[i][j],j==t[i].size()-1?'\n':' ');
	//cerr<<'x';
	fr(i,1,3*n)
		p[i]=1;
	//cerr<<'x';
	fr(i,1,n)
	{
		draw(i+n*g[i]-n);
		//cerr<<i<<' '<<p[i]<<endl;
	}
	//cerr<<'x';
	//fr(i,1,3*n)
	//	printf("%d%c",p[i],i%n?' ':'\n');
	fr(i,1,n)
		if(!ans[i])
		{
			int k=-1;
			fr(j,0,2)
				if(p[i+j*n])
				{
					k=j;
					break;
				}
			//printf("%d %d\n",i,k);
			if(!(k+1))
			{
				printf("-1\n");
				rt 0;
			}
			print(i+n*k);
		}
	//cerr<<'x';
	//fr(i,1,n)
	//	printf("%d%c",ans[i],i==n?'\n':' ');
	fr(i,1,n)
		putchar(ans[i]+'A'-1);
	ln;
	rt 0;
}
/*
3 1
xcc
3
1 A 2 C
2 A 1 A
2 B 1 A
*/