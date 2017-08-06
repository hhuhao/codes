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
vector<int>to[100010];
queue<int>q;
#define inf 0x3f3f3f3f
int n,t,u,v,ans,k,f[100010],p[100010],a[100010];
int main(){
#ifndef ONLINE_JUDGE
	freopen("do.in","r",stdin);
	freopen("do.out","w",stdout);
#endif
	n=read();
	t=read();
	fr(i,1,n-1)
	{
		int u=read(),v=read();
		to[u].push_back(v);
		to[v].push_back(u);
	}
	if((n<=3000&&t<=3000)||t<=10)
	{
		while(t--)
		{
			k=read();
			fr(i,1,n)
				f[i]=inf;
			while(k--)
			{
				int _=read();
				f[_]=0;
				q.push(_);
				while(!q.empty())
				{
					int __=q.front();
					q.pop();
					fr(i,0,to[__].size()-1)
						if(f[__]+1<f[to[__][i]])
						{
							f[to[__][i]]=f[__]+1;
							q.push(to[__][i]);
						}
				}
			}
			ans=0;
			fr(i,1,n)
				ans=max(ans,f[i]);
			printf("%d\n",ans);
		}
		rt 0;
	}
	int flag=0;
	fr(i,1,n)
		if(to[i].size()>2)
			flag=-inf;
		else
			if(to[i].size()==1)
				flag++;
	if(flag==2)
	{
		int k=0;
		fr(i,1,n)
			if(to[i].size())
				k=i;
		fr(i,1,n)
		{
			f[k]=i;
			if(i==1)
				k=to[i][0];
			else
				if(i!=n)
					if(f[to[i][0]])
						k=to[i][1];
					else
						k=to[i][0];
		}
		while(t--)
		{
			int k=read();
			fr(i,1,k)
				a[i]=f[read()];
			sort(a+1,a+k+1);
			int ans=min(a[1]-1,n-a[k]-1);
			fr(i,1,k-1)
				ans=min(ans,(a[i+1]-a[i]-1)/2);
			printf("%d\n",ans);
		}
		rt 0;
	}
	rt 0;
}