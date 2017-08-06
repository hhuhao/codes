#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
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

const int N = 100010;
const int INF = 1e+9;

//LCT
struct gtr{
	bool operator ()(const int &x,const int &y)const{
		return x>y;
	}
};
struct point{
	int val0,val1,d,id,adx,ady;
	int tot,s[2];
	bool bz;
}tree[N];
int fa[N];
multiset<int,gtr>s[N];
//tree
struct edge{
	int x,nxt;
}e[N*2];
int h[N],tot;
int f[N];
int n,q;

int pd(int x){
	if (tree[fa[x]].s[0]==x)return 0;
	if (tree[fa[x]].s[1]==x)return 1;
	return -1;
}

void add(int x,int adx,int ady){
	if (adx==-1){
		swap(tree[x].val0,tree[x].val1);
		tree[x].id=-tree[x].id;
		tree[x].adx=-tree[x].adx;
		tree[x].ady=-tree[x].ady;
	}
	if (ady!=0){
		tree[x].val0=tree[x].val0+ady;
		tree[x].val1=tree[x].val1-ady;
		tree[x].id=tree[x].id+ady;
		tree[x].ady=tree[x].ady+ady;
	}
}

void down(int x){
	if (tree[x].bz){
		swap(tree[x].s[0],tree[x].s[1]);
		if (tree[x].s[0])tree[tree[x].s[0]].bz^=1;
		if (tree[x].s[1])tree[tree[x].s[1]].bz^=1;
		tree[x].bz=0;
	}
	if (tree[x].adx==-1||tree[x].ady!=0){
		if (tree[x].s[0])add(tree[x].s[0],tree[x].adx,tree[x].ady);
		if (tree[x].s[1])add(tree[x].s[1],tree[x].adx,tree[x].ady);
		tree[x].adx=1;tree[x].ady=0;
	}
}

void update(int x){
	down(x);
	tree[x].tot=tree[tree[x].s[0]].tot+tree[tree[x].s[1]].tot+1;
	tree[x].val0=max(tree[tree[x].s[0]].val0,max(tree[tree[x].s[1]].val0,tree[x].d+tree[x].id));
	tree[x].val1=max(tree[tree[x].s[0]].val1,max(tree[tree[x].s[1]].val1,tree[x].d-tree[x].id));
}

void rotate(int x){
	int y=fa[x],z=fa[y];
	int tx=pd(x),ty=pd(y);
	if (ty!=-1)tree[z].s[ty]=x;
	fa[x]=z;
	if (tree[x].s[tx^1])fa[tree[x].s[tx^1]]=y;
	tree[y].s[tx]=tree[x].s[tx^1];
	tree[x].s[tx^1]=y;
	fa[y]=x;
	update(y);
	update(x);
	if (ty!=-1)update(z);
}

int sk,ss[N];

void clear(int x){
	sk=0;
	for(;pd(x)!=-1;x=fa[x])ss[++sk]=x;
	ss[++sk]=x;
	fd(i,sk,1)down(ss[i]);
}

void splay(int x){
	clear(x);
	while(pd(x)!=-1){
		if (pd(fa[x])!=-1){
			if (pd(x)==pd(fa[x]))rotate(fa[x]);
			else rotate(x);
		}
		rotate(x);
	}
}

void merge(int x,int y){
	down(x);
	tree[x].s[1]=y;
	s[x].erase(s[x].find(tree[y].val0));
	if (s[x].begin()!=s[x].end())tree[x].d=*(s[x].begin());
	else tree[x].d=0;
	add(y,1,tree[x].id);
	update(x);
}

void split(int x){
	down(x);
	int y=tree[x].s[1];
	tree[x].s[1]=0;
	add(y,1,-tree[x].id);
	s[x].insert(tree[y].val0);
	tree[x].d=max(tree[x].d,tree[y].val0);
	update(x);
}

void access(int x){
	splay(x);
	if (tree[x].s[1])split(x);
	while(fa[x]){
		int y=fa[x];
		splay(y);
		if (tree[y].s[1])split(y);
		merge(y,x);
		splay(x);
	}
}

void makeroot(int x){
	access(x);
	splay(x);
	add(x,-1,tree[x].id+1);
	tree[x].bz^=1;
}

int rmq[N][20];
int dfn[N],k,dep[N],mxdfn[N],d[N];
int F[N][20];

void getrmq(){
	fo(j,1,log(n)/log(2))
		fo(i,1,n-(1<<j)+1)
		rmq[i][j]=max(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);
}

void dfs(int x){
	f[x]=1;
	fo(i,1,log(n)/log(2))F[x][i]=F[F[x][i-1]][i-1];
	rmq[dfn[x]=++k][0]=dep[x];
	d[k]=x;
	for(int p=h[x];p;p=e[p].nxt)
	if (!f[e[p].x]){
		F[e[p].x][0]=x;
		dep[e[p].x]=dep[x]+1;
		dfs(e[p].x);
		fa[e[p].x]=x;
		f[x]=max(f[x],f[e[p].x]+1);
	}
	tree[x].d=f[x]-1;
	tree[x].val0=f[x];
	tree[x].val1=f[x]-2;
	tree[x].id=tree[x].adx=tree[x].tot=1;
	tree[x].ady=tree[x].bz=tree[x].s[0]=tree[x].s[1]=0;
	for(int p=h[x];p;p=e[p].nxt)
	if (fa[e[p].x]==x)s[x].insert(f[e[p].x]);
	mxdfn[x]=k;
}

void inse(int x,int y){
	e[++tot].x=y;
	e[tot].nxt=h[x];
	h[x]=tot;
}

void init(){
	n=get();q=get();
	fo(i,2,n){
		int x=get(),y=get();
		inse(x,y);
		inse(y,x);
	}
}

int a[N*2];
int lef[N],rig[N];
int g[N];
bool is[N];
int sta[N],c[N],top,sef[N];
int ans;

bool cmp(int x,int y){
	return dfn[x]<dfn[y];
}

int lca(int x,int y){
	if (dep[x]<dep[y])swap(x,y);
	fd(i,log(n)/log(2),0)
	if (dep[F[x][i]]>=dep[y])x=F[x][i];
	if (x==y)return x;
	fd(i,log(n)/log(2),0)
	if (F[x][i]!=F[y][i])x=F[x][i],y=F[y][i];
	return F[x][0];
}

void getf(int x){
	if (is[x])f[x]=0,c[x]=x;else f[x]=INF,c[x]=0;
	sef[x]=INF;
	for(int y=lef[x];y;y=rig[y]){
		getf(y);
		int tmp=f[y]+dep[y]-dep[x];
		if (tmp<f[x]){
			sef[x]=f[x];
			f[x]=tmp;
			c[x]=y;
		}
		else
			if (tmp<sef[x])sef[x]=tmp;
	}
}

int jump(int x,int y){
	fd(i,log(n)/log(2),0)
	if (dep[F[x][i]]>dep[y])x=F[x][i];
	return x;
}

void get1(int x,int y,int a,int b){
	int u=jump(y,x);
	int t=y;
	fd(i,log(n)/log(2),0)
	if (2*(dep[F[t][i]]-dep[x]+1)>=b-a)t=F[t][i];
	if (dep[t]<dep[u])t=u;
	makeroot(x);
	access(y);
	if (t!=y){
		splay(x);tree[x].s[1]=0;
		update(x);
		splay(y);tree[y].s[0]=0;
		update(y);
		splay(t);
		if (tree[t].s[0])ans=max(ans,tree[tree[t].s[0]].val0+a);
		if (tree[t].s[1])ans=max(ans,tree[tree[t].s[1]].val1+b);
		ans=max(ans,tree[t].d-tree[t].id+b);
		tree[y].s[0]=t;
		tree[x].s[1]=y;
		update(y);
		update(x);
	}
	else{
		splay(x);tree[x].s[1]=0;
		update(x);
		splay(y);
		if (tree[y].s[0])ans=max(ans,tree[tree[y].s[0]].val0+a);
		tree[x].s[1]=y;
		update(x);
		
	}
}

struct section{
	int l,r;
}sec[N];
int m;

int getmax(int l,int r){
	if (l>r)return 0;
	int t=log(r-l+1)/log(2);
	return max(rmq[l][t],rmq[r-(1<<t)+1][t]);
}

void getans(int x){
	for(int y=lef[x];y;y=rig[y]){
		if (y==c[x])g[y]=min(g[x],sef[x])+dep[y]-dep[x];
		else g[y]=min(g[x],f[x])+dep[y]-dep[x];
		getans(y);
		int t=jump(y,x);
		if (x!=F[y][0])
		get1(x,y,g[y]-dep[y]+dep[x]-1,f[y]+dep[y]-dep[x]+1);
		sec[++m].l=dfn[t];
		sec[m].r=mxdfn[t];
	}
	int l=dfn[x],tmp=min(f[x],g[x]);
	for(;m&&sec[m].l>=dfn[x]&&sec[m].r<=mxdfn[x];l=sec[m--].r+1)ans=max(ans,getmax(l,sec[m].l-1)-dep[x]+tmp);
	ans=max(ans,getmax(l,mxdfn[x])-dep[x]+tmp);
}

int getdis(int x,int y){
	return dep[x]+dep[y]-2*dep[lca(x,y)];
}

struct straight{
	int a[2],l;
	straight(const int a0=0,const int a1=0,const int l_=0){a[0]=a0;a[1]=a1;l=l_;}
	friend bool operator < (straight a,straight b){
		return a.l<b.l;
	} 
}pre[N],suf[N];
straight operator * (straight a,straight b){
	straight c=a;
	if (c<b)c=b;
	straight u;
	fo(i,0,1)
		fo(j,0,1){
			u=straight(a.a[i],b.a[j],getdis(a.a[i],b.a[j]));
			if (c<u)c=u;
		}
	return c;
}

void work(){
	fo(i,1,n){f[i]=is[i]=0;g[i]=INF;}
	pre[1]=straight(d[1],d[1],0);
	suf[n]=straight(d[n],d[n],0);
	fo(i,2,n)pre[i]=pre[i-1]*straight(d[i],d[i],0);
	fd(i,n-1,1)suf[i]=suf[i+1]*straight(d[i],d[i],0);
	fo(cas,1,q){
		int k=get();
		fo(i,1,k)is[a[i]=get()]=1;
		sort(a+1,a+1+k,cmp);
		int rt=lca(a[1],a[k]);
		sta[top=1]=rt;
		int k_=k;
		a[++k]=rt;
		fo(i,1,k_){
			int x=a[i];
			int y=lca(a[i],sta[top]);
			while(dep[y]<dep[sta[top]]){
				if (dep[sta[top-1]]>=dep[y]){
					rig[sta[top]]=lef[sta[top-1]];
					lef[sta[top-1]]=sta[top];
				}
				else{
					rig[sta[top]]=lef[y];
					lef[y]=sta[top];
				}
				top--;
			}
			if (y!=sta[top])a[++k]=sta[++top]=y;
			if (x!=sta[top])sta[++top]=x;
		}
		fo(i,2,top){
			int x=sta[i-1],y=sta[i];
			rig[y]=lef[x];
			lef[x]=y;
		}
		ans=0;
		getf(rt);
		g[rt]=INF;
		m=0;
		getans(rt);
		if (rt!=1){
			straight s=pre[dfn[rt]-1];
			if (mxdfn[rt]!=n)s=s*suf[mxdfn[rt]+1];
			ans=max(ans,max(getdis(rt,s.a[0]),getdis(rt,s.a[1]))+f[rt]);
		}
		printf("%d\n",ans);
		fo(i,1,k){
			int x=a[i];
			rig[x]=lef[x]=is[x]=0;
			g[x]=INF;
		}
	}
}

int main(){
	freopen("do.in","r",stdin);
	freopen("do.out","w",stdout);
	init();
	dfs(dep[1]=1);
	tree[0].val0=tree[0].val1=-INF;
	getrmq();
	work();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
