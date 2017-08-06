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
int len[210],_;
void dfs(int x,int y,int i_,int j_,int w)
{
	//printf("%d %d %d %d %d %d %d\n",x,y,i_,j_,w,w+abs(len[i_]-x-len[j_]+y),_);
	if(w+abs(len[i_]-x-len[j_]+y)>=_)
		return;
	//puts("1");
	while(x<len[i_]&&y<len[j_])
	{
		if(s[i_][x]!=s[j_][y])
		{
			dfs(x+1,y,i_,j_,w+1);
			dfs(x,y+1,i_,j_,w+1);
			dfs(x+1,y+1,i_,j_,w+1);
			rt;
		}
		x++;
		y++;
	}
	if(x==len[i_])
		_=min(_,w+len[j_]-y);
	else
		_=min(_,w+len[i_]-x);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("say.in","r",stdin);
	freopen("say.out","w",stdout);
#endif
	scanf("%d\n",&n);
	fr(i,1,n)
	{
		scanf("%s",s[i]);
		len[i]=strlen(s[i]);
	//	printf("%s %d\n",s[i],len[i]);
	}
	//fr(i,1,n)
	//	puts(s[i]);
	fr(i,1,n-1)
		fr(j,i+1,n)
			if(abs(len[i]-len[j])<=8)
			{
				_=9;
				dfs(0,0,i,j,0);
				ans[_]++;
			}
	fr(i,1,8)
		printf("%d%c",ans[i],i==8?'\n':' ');
	rt 0;
}