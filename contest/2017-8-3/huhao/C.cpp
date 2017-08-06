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
int n,m,v[2010],w[2010],f[2010][2010],h[2010],p[2010],rank[2010];
vector<int>t[2010],s[2010];
void build(int x)
{
	fr(i,0,t[x].size()-1)
		if(p[t[x][i]])
		{
			p[t[x][i]]=0;
			h[t[x][i]]=h[x]+1;
			s[x].push_back(t[x][i]);
			build(t[x][i]);
		}
}
bool cmp(int x,int y)
{
	rt h[x]>h[y];
}
int main(){
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	n=read();
	m=read();
	fr(i,1,n)
		v[i]=read(),w[i]=read();
	fr(i,1,n-1)
	{
		int u=read(),v=read();
		t[u].push_back(v);
		t[v].push_back(u);
	}
	fr(i,2,n)
		p[i]=1;
	build(1);
	fr(i,1,n)
		rank[i]=i;
	sort(rank+1,rank+n+1,cmp);
//	fr(i,1,n)
//		printf("%d %d\n",rank[i],h[rank[i]]);
	fr(i,1,n)
	{
		int d=rank[i];
//		cerr<<i<<' '<<d<<endl;
		fr(j,0,s[d].size()-1)
			fd(o,m,w[s[d][j]])
				fr(k,0,o-w[s[d][j]])
					f[d][o]=max(f[d][o],f[d][k]+
					f[s[d][j]][o-w[s[d][j]]-k]+v[s[d][j]]);
//		cerr<<i<<' '<<d<<endl;
	}
//	fr(i,1,n)
//		fr(j,0,m)
//			printf("%d%c",f[i][j],j==m?'\n':' ' );
	int ans=0;
	fr(i,0,m-w[1])
		ans=max(ans,f[1][i]);
	printf("%d\n",ans+v[1]);
	rt 0;
}