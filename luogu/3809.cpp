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
#define N 1000010
int g[N<<1],n,r[N],t[N],k,ans[N];
/*
bool cmp(int x,int y)
{
	rt (ll)g[x]*(n+1)+g[x+k]<(ll)g[y]*(n+1)+g[y+k];
}
bool check(int x,int y)
{
	rt (ll)g[x]*(n+1)+g[x+k]!=(ll)g[y]*(n+1)+g[y+k];
}
*/
bool cmp(int x,int y)
{
	if(g[x]!=g[y])
		rt g[x]<g[y];
	fr(i,1,n)
		if(g[x+i]!=g[y+i])
			rt g[x+i]<g[y+i];
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("","r",stdin);
	freopen("","w",stdout);
#endif
	char c=gc;
	while((c<'a'||c>'z')&&(c<'0'&&c>'9')&&(c<'A'||c>'Z'))
		c=gc;
	while((c>='a'&&c<='z')||(c>='0'&&c<='9')||(c>='A'&&c<='Z'))
	{
		if(c>='a')
			g[++n]=c-'a'+10+26+1;
		else
			if(c>='A')
				g[++n]=c-'A'+10+1;
			else
				g[++n]=c-47;
		c=gc;
	}
	fr(i,1,n)
		r[i]=i;
	sort(r+1,r+1+n,cmp);
	/*
	fr(i,0,log(n,2))
	{
		//fr(_,1,n)
		//	printf("%d%c",g[_],_==n?'\n':' ');
		k=1<<i;
		fr(j,1,n)
			r[j]=j;
		sort(r+1,r+n+1,cmp);
		//fr(_,1,n)
		//	printf("%d%c",r[_],_==n?'\n':' ');
		int p=1;
		t[r[1]]=1;
		fr(j,2,n)
			if(check(r[j],r[j-1]))
				t[r[j]]=++p;
			else
				t[r[j]]=p;
		fr(j,1,n)
			g[j]=t[j];
		//ln;
	}
	//fr(i,1,n)
	//	printf("%d%c",g[i],i==n?'\n':' ');
	*/
	fr(i,1,n)
		printf("%d%c",r[i],i==n?'\n':' ');
	/*
	fr(i,1,n)
		ans[r[i]]=i;
	fr(i,1,n)
		printf("%d%c",ans[i],i==n?'\n':' ');
	*/
	rt 0;
}
//aaaabb