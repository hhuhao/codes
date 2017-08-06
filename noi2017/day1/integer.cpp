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
int f[10000010],n,t1,t2,t3;
ll a[10000010];
void plus1(int x,int y)
{
	int k=y,p=x>0?1:-1;
	x=x<0?-x:x;
	while(x)
	{
		if(x&1)
			f[k]+=p;
		x>>=1;
		k++;
	}
	fr(i,y,k)
		if(f[i]<0)
		{
			f[i]+=2;
			f[i+1]--;
		}
		else
			if(f[i]>1)
			{
				f[i]-=2;
				f[i+1]++;
			}
	k++;
	while(f[k]<0||f[k]>1)
	{
		if(f[k]<0)
		{
			f[k]+=2;
			f[k+1]--;
		}
		if(f[k]>1)
		{
			f[k]-=2;
			f[k+1]++;
		}
		k++;
	}
}
void plus2(int x)
{
	f[x]++;
	while(f[x]>1)
	{
		f[x]-=2;
		f[++x]++;
	}
}
void plus4(int x,int y)
{
	f[x]+=y;
	while(f[x]>1||f[x]<0)
	{
		f[x]+=(-y)*2;
		f[++x]+=y;
	}
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("","r",stdin);
	freopen("","w",stdout);
#endif
	n=read();
	t1=read();
	t2=read();
	t3=read();
	if(t2<=2)//Case 1
	{
		fr(i,1,n)
			if(read()==1)
			{
				int u=read(),v=read();
				plus1(u,v);
			}
			else
			{
			//	fd(i,20,0)
			//		printf("%d%c",f[i],i?' ':'\n');
				printf("%d\n",f[read()]);
			}
		rt 0;
	}
	if(t1==1)//Case 2
	{
		fr(i,1,n)
			if(read()==1)
			{
				int u=read(),v=read();
				plus2(v);
			}
			else
			{
				printf("%d\n",f[read()]);
			}
		rt 0;
	}
	if(t3==1)//Case 3
	{
		int maxv=0;
		while(read()==1)
		{
			int u=read(),v=read();
			a[v]+=u;
			maxv=max(maxv,v);
		}
		fr(i,1,maxv)
		{
			a[i+1]+=a[i]/2-1;
			a[i]%=2;
			a[i]+=2;
			a[i+1]+=a[i]/2;
			a[i]%=2;
		}
		int i=maxv+1;
		while(a[i]<0||a[i]>1)
		{
			a[i+1]+=a[i]/2-1;
			a[i]%=2;
			a[i]+=2;
			a[i+1]+=a[i]/2;
			a[i]%=2;
			i++;
		}
		//fd(i,20,0)
		//	printf("%lld%c",a[i],i?' ':'\n');
		printf("%lld\n",a[read()]);
		int x;
		while(scanf("%d",&x)!=EOF)
			printf("%lld\n",a[read()]);
		rt 0;
	}
	if(t1==2)//Case 4
	{
		fr(i,1,n)
			if(read()==1)
			{
				int u=read(),v=read();
				plus4(v,u);
			}
			else
			{
				printf("%d\n",f[read()]);
			}
		rt 0;
	}
	rt 0;
}