#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int mo = 99991;

struct number{
	db x,y;
	number(const db x_=0,const db y_=0){x=x_;y=y_;}
};
number operator *(number a,number b){return number(a.x*b.y+a.y*b.x+a.x*b.x*2,a.y*b.y+a.x*b.x*3);}
number operator +(number a,number b){return number(a.x+b.x,a.y+b.y);}
number operator -(number a,number b){return number(a.x-b.x,a.y-b.y);}
number operator /(number a,db v){return number(a.x/v,a.y/v);}
const number n0={0,0};

struct comp{
	number x,y;
	comp(const number x_=n0,const number y_=n0){x=x_;y=y_;}
};
comp operator *(comp a,comp b){return comp(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}
comp operator +(comp a,comp b){return comp(a.x+b.x,a.y+b.y);}
comp operator -(comp a,comp b){return comp(a.x-b.x,a.y-b.y);}
const comp c0={n0,n0};

const db pi = acos(-1);
const int MAXN = 140010;
const db eps = 1e-1;

comp A[MAXN],B[MAXN],C[MAXN];
number a[MAXN];
int bitr[MAXN];
int N,L;
int n,k;
int mi[25];

void prepare(){
	fo(i,0,N-1){
		bitr[i]=0;
		fo(j,0,L-1)
		if ((i&mi[j])>0)bitr[i]+=mi[L-1-j];
	}
}

LL getll(db x){
	LL v=LL(x);
	if (v+eps<x)v++;
	if (v>x+eps)v--;
	return v;
}

void dft(comp *a,int sig){
	fo(i,0,N-1)if (i<bitr[i])swap(a[i],a[bitr[i]]);
	for(int now=2;now<=N;now<<=1){
		int half=now/2;
		fo(i,0,half-1){
			comp w=comp(number(0,cos(pi*2/now*i*sig)),number(0,sin(pi*2/now*i*sig)));
			for(int j=i;j<N;j+=now){
				comp l=a[j],r=w*a[j+half];
				a[j]=l+r;
				a[j+half]=l-r;
			}
		}
	}
	if (sig==-1)
	fo(i,0,N-1)a[i].x=a[i].x/N;
}

int main(){
	freopen("see.in","r",stdin);
	freopen("see.out","w",stdout);
	
	n=get();k=get();
	fo(i,1,n){
		int x=get();
		number u=number(1,0),v=number(0,1);
		while(x){
			if (x%2){
				v=v*u;
				v.x=LL(v.x+eps)%mo;
				v.y=LL(v.y+eps)%mo;
			}
			u=u*u;
			u.x=LL(u.x+eps)%mo;
			u.y=LL(u.y+eps)%mo;
			x/=2;
		}
		a[i]=v;
	}
	LL f0=get(),f1=get();
	
	mi[0]=1;
	fo(i,1,20)mi[i]=mi[i-1]<<1;
	
	for(N=2,L=1;N/2<n;N<<=1,L++){
		prepare();
		int half=N/2;
		for(int x=1;x<=n;x+=N){
			int y=x+half;
			if (y>n)break;
			fo(i,0,N-1)A[i]=B[i]=c0;
			A[0]=B[0]=comp(number(0,1),n0);
			int ls=half,rs=min(n-y+1,half);
			fo(i,1,ls-1)A[i]=comp(a[x+i-1],n0);
			fo(i,1,rs-1)B[i]=comp(a[y+i-1],n0);
			dft(A,1);dft(B,1);
			fo(i,0,N-1)C[i]=A[i]*B[i];
			dft(C,-1);
			C[N]=c0;
			fo(i,1,ls-1)C[rs+i]=C[rs+i]+comp(a[y+rs-1],n0)*comp(a[x+i-1],n0);
			fo(i,1,rs-1)C[ls+i]=C[ls+i]+comp(a[x+ls-1],n0)*comp(a[y+i-1],n0);
			C[ls]=C[ls]+comp(a[x+ls-1],n0);
			C[rs]=C[rs]+comp(a[y+rs-1],n0);
			C[ls+rs]=C[ls+rs]+comp(a[x+ls-1],n0)*comp(a[y+rs-1],n0);
			fo(i,1,min(N,n-x+1)){
				a[x+i-1]=C[i].x;
				a[x+i-1].x=getll(a[x+i-1].x)%mo;
				a[x+i-1].y=getll(a[x+i-1].y)%mo;
			}
		}
	}
	printf("%d\n",int(getll(a[k].x)*f1%mo+getll(a[k].y)*f0%mo)%mo);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
