#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<vector>
#include<map>
#include<queue>
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
struct node
{
	int l,r,w;
}a[310],b[310];
int t,n,m,top;
bool cmp1(node x,node y)
{
	rt x.l<y.l;
}
bool cmp2(node x,node y)
{
	rt x.r<y.r;
}
int main(){
	freopen("machine.in","r",stdin);
	freopen("machine.out","w",stdout);
	t=read();
	while(t--)
	{
		n=read();
		m=read();
		fr(i,1,n)
			a[i].l=read(),a[i].r=read(),a[i].w=read();
		fr(i,1,m)
			b[i].l=read(),b[i].r=read(),b[i].w=read();
		sort(a+1,a+n+1,cmp1);
		sort(b+1,b+m+1,cmp1);
		top=1;
		fr(i,1,n)
		{
			while(b[top].l<=a[i].l&&top<=m)
				top++;
			top--;
			sort(b+1,b+top+1,cmp2);
			fr(j,1,top)
				if(a[i].r<=b[j].r)
					if(a[i].w<b[j].w)
					{
						b[j].w-=a[i].w;
						a[i].w=0;
						break;
					}
					else
					{
						a[i].w-=b[j].w;
						b[j].w=0;
					}
			//printf("%d %d %d\n",i,a[i].w,top);
			if(a[i].w)
			{
				puts("No");
				goto nex;
			}
		}
		puts("Yes");
		nex:;
		//ln;
	}
	rt 0;
}