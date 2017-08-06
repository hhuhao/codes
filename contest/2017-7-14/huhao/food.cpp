#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<iostream>
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
struct node
{
	int v,w;
}f[110];
bool cmp(node a,node b)
{
	return a.v>b.v;
}
int n,top,ans,g[1000010];
int main()
{
	freopen("food.in","r",stdin);
	freopen("food.out","w",stdout);
	n=read();
	fr(i,1,n)
	{
		f[i].v=read();
		f[i].w=read();
	}
	sort(f+1,f+n+1,cmp);
	fr(i,1,n)
		if(f[i].v>0)
			top+=f[i].v;
		else
			break;
	fr(i,0,top)
		g[i]=-10000000;
	g[0]=0;
	fr(i,1,n)
		if(f[i].v>0)
			fd(j,top,f[i].v)
				g[j]=max(g[j],g[j-f[i].v]+f[i].w);
		else
			fr(j,0,top+f[i].v)
				g[j]=max(g[j],g[j-f[i].v]+f[i].w);
	//fr(i,0,top)
	//	printf("%d %d %d\n",i,g[i],i*g[i]);
	fr(i,0,top)
		if(g[i]>0)
			ans=max(ans,i*g[i]);
	printf("%d\n",ans);
	return 0;
}
