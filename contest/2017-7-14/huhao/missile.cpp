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
int a[200010],s[200010],g1[200010],top,n,f1[200010],g2[200010],f2[200010],ans;
int main()
{
	freopen("missile.in","r",stdin);
	freopen("missile.out","w",stdout);
	n=read();
	fr(i,1,n)
		a[i]=read();
	fr(i,1,n)
		if(a[i]>s[top])
		{
			s[++top]=a[i];
			g1[i]=top;
		}
		else
		{
			int l=1,r=top,mid;
			while(l<r)
			{
				mid=(l+r)>>1;
				if(a[i]>s[mid])
					l=mid+1;
				else
					r=mid;
			}
			s[l]=a[i];
			g1[i]=l;
		}
	fr(i,1,n)
		f1[i]=max(f1[i-1],g1[i]);
	fr(i,1,top)
		s[i]=0;
	top=0;
	fd(i,n,1)
		if(a[i]>s[top])
		{
			s[++top]=a[i];
			g2[i]=top; Z
		}
		else
		{
			int l=1,r=top,mid;
			while(l<r)
			{
				mid=(l+r)>>1;
				if(a[i]>s[mid])
					l=mid+1;
				else
					r=mid;
			}
			s[l]=a[i];
			g2[i]=l;
		} 
	fd(i,n-1,1)
		f2[i]=max(f2[i+1],g2[i+1]);
	/*printf("%d\n",top);
	fr(i,1,top)
		printf("%d%c",s[i],i==top?'\n':' ');
	fr(i,1,n)
		printf("%d %d %d %d\n",g1[i],f1[i],g2[i],f2[i]);*/
	fr(i,1,n)
		ans=max(ans,f1[i]+f2[i]);
	printf("%d\n",n-ans+1);
	return 0;
}
