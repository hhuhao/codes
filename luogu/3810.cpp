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
struct point
{
	int a,b,c,cnt,ans;
}g[100010];
int n,m,ans[100010],bit[10000010],num;
bool cmp2(point x,point y)
{
	if(x.b==y.b)
		rt x.c<y.c;
	rt x.b<y.b;
}
bool cmp1(point x,point y)
{
	if(x.a==y.a)
		rt cmp2(x,y);
	rt x.a<y.a;
}
void add(int x,int y)
{
	while(x<=m)
	{
		bit[x]+=y;
		x+=x&(-x);
	}
}
int query(int x)
{
	int r=0;
	while(x)
	{
		r+=bit[x];
		x-=x&(-x);
	}
	rt r;
}
void cdq(int l,int r)
{
	if(l==r)
		rt;
	int mid=(l+r)>>1;
	cdq(l,mid);
	cdq(mid+1,r);
	sort(g+l,g+mid+1,cmp2);
	sort(g+mid+1,g+r+1,cmp2);//2D
	int t1=l,t2=mid+1;
	while(t2<=r)
	{
		while(t1<=mid&&g[t1].b<=g[t2].b)
		{
			add(g[t1].c,g[t1].cnt);
			t1++;
		}
		g[t2].ans+=query(g[t2].c);
		t2++;
	}
	fr(i,l,t1-1)
		add(g[i].c,-g[i].cnt);//3D
}
int main()
{
	n=read();
	m=read();
	fr(i,1,n)
		g[i].a=read(),g[i].b=read(),g[i].c=read(),g[i].cnt=1;
	sort(g+1,g+n+1,cmp1);//1D
	fr(i,1,n)
	{
		int k=i+1;
		while(g[i].a==g[k].a&&g[i].b==g[k].b&&g[i].c==g[k].c)
			k++;
//		printf("%d %d\n",i,k);
		num++;
		k--;
		g[i].cnt+=k-i;
		g[num]=g[i];
		i=k;
	}
//	fr(i,1,num)
//		printf("%d %d %d %d\n",g[i].a,g[i].b,g[i].c,g[i].cnt);
	cdq(1,num);
	fr(i,1,num)
		ans[g[i].ans+g[i].cnt-1]+=g[i].cnt;
	fr(i,0,n-1)
		printf("%d\n",ans[i]);
	rt 0;
}