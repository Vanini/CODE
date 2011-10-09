#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXSIZE=200000;
int n,k;
int a[MAXSIZE],s[MAXSIZE];
int key[MAXSIZE],l;
void init()
{
	scanf("%d%d",&n,&k);
	s[0]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	for(int i=0;i<n;i++)key[i+1]=-s[i];
	sort(key+1,key+n+1);
	l=unique(key+1,key+n+1)-key-1;
}
const int oo=1000000000;
int tree[MAXSIZE][2];
inline int lowbit(int x){return x&-x;};
void INIT_TREE()
{
	for(int i=1;i<=l;i++)tree[i][0]=oo,tree[i][1]=-oo;
}
void INSERT_TREE(int p,int vmin,int vmax)
{
	p=lower_bound(key+1,key+l+1,p)-key;
	while(p<=l)
	{
		tree[p][0]=min(tree[p][0],vmin);
		tree[p][1]=max(tree[p][1],vmax);
		p+=lowbit(p);
	}
}
void GET_MIN(int p,int& mn,int& mx)
{
	mn=oo,mx=-oo;
	p=upper_bound(key+1,key+l+1,p)-key-1;
	while(p>0)
	{
		mn=min(mn,tree[p][0]);
		mx=max(mx,tree[p][1]);
		p-=lowbit(p);
	}
}
bool OK(int limit)
{
	INIT_TREE();
	INSERT_TREE(0,0,0);
	int add=a[1];
	int fl,fr;
	GET_MIN(limit-add,fl,fr);
	fl++;fr++;
	for(int i=2;i<=n;i++)
	{
		add+=a[i];
		INSERT_TREE(a[i]-add,fl,fr);
		GET_MIN(limit-add,fl,fr);
		fl++;fr++;
	}
	return fl<=k&&k<=fr;
}
inline int half(int x)
{
	if(x>=0)return x/2;
	return x/2-1;
}
void work()
{
	int l=-oo,r=oo;
	OK(-10);
	while(l<r)
	{
		int mid=half(l+r);
		if(OK(mid))r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
}
int main()
{
	freopen("seq10.in", "r", stdin);
	freopen("seq10.out", "w", stdout);
	init();
	work();
}
