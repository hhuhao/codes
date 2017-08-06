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
#define mod 998244353
#define arr 10000010
int n,T,ans,len,k;
int g[arr],f[arr],t[arr],l[arr],o[arr],num[arr];
char s[10000010];
bool check(int x,int y,int l)
{
	fr(i,1,l)
	{
		if(g[x]!=s[y])
			rt 0;
		x=t[x];
		y++;
	}
	rt 1;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("","r",stdin);
	freopen("","w",stdout);
#endif
	n=read();
	T=read();
	fr(i,1,n)
		num[g[i]=read()]++,l[i]=1;;
	while(T--)
	{
		int tmp=read();
		if(tmp==1)
		{
			int u=read(),v=read();
			t[u]=v;
			int k=u;
			while(k)
			{
				l[k]+=l[v];
				k=f[k];
			}
			f[v]=u;
		}
		if(tmp==2)
		{
			int u=read(),v=t[u];
			f[v]=0;
			int k=u;
			while(k)
			{
				l[k]-=l[v];
				k=f[k];
			}
			t[u]=0;
		}
		if(tmp==3)
		{
			ans=1;
			scanf("%s",s+1);
			len=strlen(s+1);
			fr(i,1,len)
				s[i]^=48;
			k=read();
			if(k==1)
				fr(i,1,len)
					ans=((ll)ans*num[s[i]])%mod;
			else
			{
				fr(i,1,len-k+1)
					o[i]=0;
				fr(i,1,n)
					if(l[i]>=k)
						fr(j,1,len-k+1)
							if(check(i,j,k))
								o[j]++;
				fr(i,1,len-k+1)
					ans=((ll)ans*o[i])%mod;
			}
			printf("%d\n",ans);
		}
	}
	rt 0;
}
/*
5 9
1 2 3 2 1
1 1 2
1 2 3
2 2
3 12312131 1
3 12312131 2
2 1
1 2 3
1 1 2
3 123 2
*/