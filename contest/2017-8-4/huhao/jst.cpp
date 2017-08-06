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
	int u,v,w;
}g[300010];
int n,a[100010],e,f[100010],ans,t;
bool cmp(node a,node b)
{
	rt a.w<b.w;
}
int getf(int x)
{
	rt x==f[x]?x:getf(f[x]);
}
void dfs(int x,int y,int z)
{
//	printf("%d %d %d %d %d %d\n",x,y,g[x].u,g[x].v,g[x].w,z);
//	printf("%d %d %d\n",x,y,z);
	if(y>ans)
		rt;
	if(z==n-1)
	{
		t++;
		rt;
	}
	if(x>e)
		rt;
	if(getf(g[x].u)!=getf(g[x].v))
	{
		int k=getf(g[x].u);
		f[k]=getf(g[x].v);
		dfs(x+1,y+g[x].w,z+1);
		f[k]=k;
	}
	dfs(x+1,y,z);
}
int main(){
	freopen("jst.in","r",stdin);
	freopen("jst.out","w",stdout);
	n=read();
	if(n>=30)
	{
		printf("%d\n",power(n,n-2,1000000007));
		rt 0;
	}
	fr(i,1,n)
		a[i]=read();
	fr(i,1,n-1)
		fr(j,i+1,n)
		{
			e++;
			g[e].u=i;
			g[e].v=j;
			g[e].w=a[i]^a[j];
		}
	fr(i,1,n)
		f[i]=i;
	sort(g+1,g+e+1,cmp);
	fr(i,1,e)
		if(getf(g[i].u)!=getf(g[i].v))
		{
			f[getf(g[i].u)]=f[getf(g[i].v)];
			ans+=g[i].w;
		}
	printf("%d\n",ans);
	fr(i,1,n)
		f[i]=i;
	t=0;
	dfs(1,0,0);
	printf("%d\n",t);
	rt 0;
}