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
queue<int>q;
int n,m,e,h[2010],g[2010][2010],w[2010];
int main(){
/*
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
*/
	n=read();
	m=read();
	e=read();
	fr(i,1,n)
	{
		g[i][0]=1;
		h[i]=2;
	}
	fr(i,n+1,n+m)
	{
		g[i][n+m+1]=1;
		h[i]=1;
	}
	while(e--)
	{
		int u=read(),v=read();
		if(v<=m&&u<=n)
			g[u][n+v]=1;
	}
	h[0]=n+m+2;
	int o=n+m+1;
	fr(i,1,n)
	{
		w[i]=1;
		q.push(i);
	}
	//fr(i,0,o)
	//	fr(j,0,o)
	//		printf("%d%c",g[i][j],j==o?'\n':' ');
	//gc;
	//puts("1");
	while(!q.empty())
	{
		int d=q.front();
	//	printf("%d\n",d);
		q.pop();
		while(w[d])
		{
	//		printf("%d %d %d\n",d,w[d],h[d]);
			fr(i,0,o)
				if(g[d][i]&&h[d]-h[i]==1)
					if(g[d][i]>=w[d])
					{
	//					printf("%d %d %d\n",d,i,w[d]);
						g[d][i]-=w[d];
						g[i][d]+=w[d];
						w[i]+=w[d];
						w[d]=0;
						if(i&&i!=o)
							q.push(i);
						goto nex;
					}
					else
					{
	//					printf("%d %d %d\n",d,i,g[d][i]);
						g[i][d]+=g[d][i];
						w[d]-=g[d][i];
						w[i]+=g[d][i];
						g[d][i]=0;
						if(i&&i!=o)
							q.push(i);
					}
			h[d]++;
		}
		nex:;
	}
	printf("%d\n",w[o]);
	rt 0;
}
/*
4 4 7
1 1
1 2
2 2
2 3
3 3
3 4
4 4
*/