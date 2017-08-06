#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define py(a,b,c,d) for(int a=b;a!=c;a+=d)
using namespace std;
int up[102424],a[102424],f[102424],down[102424],len;
int main(){
	int n;
	scanf("%d",&n);
	py(i,1,n+1,1)scanf("%d",a+i);
	f[len=1]=a[1];
	up[1]=1;
	py(i,2,n+1,1){
		int l=1,r=len,mid;
		while(l<=r){
			mid=(l+r)>>1;
			if(f[mid]<a[i])l=mid+1;
			else r=mid-1;
		}
		f[l]=a[i];
		up[i]=l;
		if(l>len)++len;
	}
	f[len=1]=a[n];
	down[n]=1; 
	py(i,n-1,0,-1){
		int l=1,r=len,mid;
		while(l<=r){
			mid=(l+r)>>1;
			if(f[mid]<a[i])l=mid+1;
			else r=mid-1;
		}
		f[l]=a[i];
		down[i]=l;
		if(l>len)++len; 
	}
	int ans=0;
	py(i,1,n+1,1){
		ans=max(ans,up[i]+down[i]-1);
		//printf("%d %d\n",up[i],down[i]);
	}
	printf("%d\n",n-ans+1);
	
	
	return 0;
}
//printf("%d %d\n",up[i],down[i]);
