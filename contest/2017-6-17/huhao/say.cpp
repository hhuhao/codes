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
int n,ans[10];
char s[210][5010];
struct node
{
	int x,y,w;
	node()
	{
		x=y=w=0;
	}
}d;
queue<node>q;
int main(){
#ifndef ONLINE_JUDGE
	freopen("say.in","r",stdin);
	freopen("say.out","w",stdout);
#endif
	scanf("%d\n",&n);
	fr(i,1,n)
		gets(s[i]);
	//fr(i,1,n)
	//	puts(s[i]);
	fr(i,1,n-1)
		fr(j,i+1,n)
			if(abs((int)(strlen(s[i])-strlen(s[j])))<=8)
			{
				int l1=strlen(s[i]),l2=strlen(s[j]),_=9;
				d.x=d.y=d.w=0;
				q.push(d);
				while(!q.empty())
				{
					d=q.front();
					
					q.pop();
					//printf("%d %d %d %d %d\n",i,j,d.x,d.y,d.w);
					if(d.x==l1&&d.y==l2)
					{
						_=min(_,d.w);
						continue;
					}
					if(d.w==8)
						continue;
					if(d.x==l1)
					{
						d.y++;
						d.w++;
						q.push(d);
						continue;
					}
					if(d.y==l2)
					{
						d.x++;
						d.w++;
						q.push(d);
						continue;
					}
					if(s[i][d.x]==s[j][d.y])
					{
						d.x++;
						d.y++;
						q.push(d);
						continue;
					}
					d.w++;
					d.x++;
					d.y++;
					q.push(d);
					d.x--;
					q.push(d);
					d.x++;
					d.y--;
					q.push(d);
				}
				while(!q.empty())
					q.pop();
				ans[_]++;
			}
	fr(i,1,8)
		printf("%d%c",ans[i],i==8?'\n':' ');
	rt 0;
}