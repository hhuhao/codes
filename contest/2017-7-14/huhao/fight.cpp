#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
#define fr(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define fd(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
int read()
{
	int r=0,t=1,c=getchar();
	while(c<'0'&&c>'9'&&c!='-')
		c=getchar();
	if(c=='-')
	{
		t=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*t;
}
bool check(int x,int r)
{
	if(x<2)
		return 0;
	fr(i,2,r)
		if(x%i==0)
			return 0;
	return 1;
}
long long calc(long long x,long long y,long long mod)
{
	int rt=0;
	while(y)
	{
		if(y&1)
			rt=(rt+x)%mod;
		y>>=1;
		x=(x+x)%mod;
	}
	return rt;
}
long long powmod(long long x,long long y,long long mod)
{
	int rt=1;
	while(y)
	{
		if(y&1)
			rt=calc(rt,x,mod);
		y>>=1;
		x=calc(x,x,mod);
	}
	return rt;
}
bool check1(int x)
{
	if(!check(x,10000))
		return 0;
	fr(i,1,100)
		if(powmod(rand()%x+1,x-1,x)!=1)
			return 0;
	return 1;
}
int t;
long long n;
int main()
{
	freopen("fight.in","r",stdin);
	freopen("fight.out","w",stdout);
	t=read();
	srand(time(0));
	while(t--)
	{
		scanf("%lld",&n);
		if(n<=100000000)
			if(check(n,sqrt(n)))
				puts("Yes");
			else
				puts("No");
		else
			if(check1(n))
				puts("Yes");
			else
				puts("No");
	}
	return 0;
}
