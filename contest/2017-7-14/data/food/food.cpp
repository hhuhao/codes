#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<complex>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<vector>
#include<string>
#define xh(a,b,c)for(long long a=(b);a<=(c);++a)
#define dxh(a,b,c)for(long long a=(b);a>=(c);--a)
#define hy(a)memset(a,0,sizeof(a))
#define sqr(a) (a)*(a)
#define all(a) a.begin(),a.end()
#define Max(a,b) a=max(a,b)
#define Min(a,b) a=min(a,b)
#define abs(a) ((a<0)?-a:a)
#define rt return
#define js exit(0)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned long long ui;
typedef double db;
typedef pair<long long,long long> lix;
void qin(long long &x){
	long long base=1,num;
	char c=getchar();
	while(!(c=='-'||c>='0'&&c<='9'||c==EOF))c=getchar();
	if(c==EOF)exit(0);
	if(c=='-')base=-1,c=getchar();
	num=c-'0';
	c=getchar();
	while(c>='0'&&c<='9'){
		num*=10;
		num+=c-'0';
		c=getchar();
	}
	x=num*base;
}
char integ[50];
void qout(long long x){
	if(x<0)putchar('-'),x=-x;
	long long len=0;
	do{
		integ[len++]=x%10+'0';
		x/=10;
	}while(x);

	while(len--){
		putchar(integ[len]);
	}
}
long long f[100010*2];
const long long oo=(long long)1e9;
int main(){
	long long n,m,w,d;
	qin(n);
	xh(i,0,200000)f[i]=-oo;
	f[100000]=0;
	xh(i,1,n){
		qin(w);
		qin(d);
		if(w>0){
			dxh(j,200000,w)if(f[j-w]>-oo)Max(f[j],f[j-w]+d);
		}
		else{
			xh(j,0,200000+w)if(f[j-w]>-oo)Max(f[j],f[j-w]+d);
		}
	}
	long long mx=0;
	xh(i,100000,200000)if(f[i]>=0)Max(mx,f[i]*(i-100000));
	qout(mx);
	putchar('\n');
	return 0;
}
