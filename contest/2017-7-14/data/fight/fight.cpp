#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#define up(a,b,c) for(int a=b;a<=c;++i)
using namespace std;
const int MAXN = 65;
long long n, x[MAXN];

long long multi(long long a, long long b, long long p) {
    long long ans = 0;
    while(b) {
        if(b&1LL) ans = (ans+a)%p;
        a = (a+a)%p;
        b >>= 1;
    }
    return ans;
}

long long qpow(long long a, long long b, long long p) {
    long long ans = 1;
    while(b) {
        if(b&1LL) ans = multi(ans, a, p);
        a = multi(a, a, p);
        b >>= 1;
    }
    return ans;
}

bool Miller_Rabin(long long n) {
    if(n == 2) return true;
    int s = 128, i, t = 0;
    long long u = n-1;
    while(!(u & 1)) {
        t++;
        u >>= 1;
    }
    while(s--) {
        long long a = rand()%(n-2)+2;
        x[0] = qpow(a, u, n);
        for(i = 1; i <= t; i++) {
            x[i] = multi(x[i-1], x[i-1], n);
            if(x[i] == 1 && x[i-1] != 1 && x[i-1] != n-1) return false;
        }
        if(x[t] != 1) return false;
    }
    return true;
}

int main(){
	srand(time(0));
	
	int t;
	long long s;
	scanf("%d",&t);
	while(t){
		--t;
		scanf("%I64d",&s);
		if(Miller_Rabin(s)){
			printf("Yes\n");
		}
		else printf("No\n");
	}
	return 0;
}
