#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int VT_MAX=100000+10,Q_MAX=30;
const int LG_MAX=28;
const int LN_MAX=5000+10;
namespace Hash_Data
{
    const int seed=13331;
    int Power(int e)
    {
        if(!e)return 1;
        int tmp=Power(e/2);tmp*=tmp;
        if(e&1)tmp*=seed;
        return tmp;
    }
    struct Tstr
    {
        int hash,len,pow;
        Tstr(){}
        Tstr(int _hash,int _len=1):
            hash(_hash),len(_len)
        {
            pow=Power(len);
        }
        bool operator==(const Tstr&str)
        {
            return len==str.len&&hash==str.hash;
        }
    }none(0,0);
    Tstr operator+(const Tstr&l,const Tstr&r)
    {
        Tstr ret;
        ret.len=l.len+r.len;
        ret.hash=l.hash*r.pow+r.hash;
        ret.pow=l.pow*r.pow;
        return ret;
    }
}
namespace Pre2K_Data
{
    using namespace Hash_Data;
    struct Tlink
    {
        Tstr str;
        int dest;
        Tlink(){}
        Tlink(Tstr _str,int _dest):
            str(_str),dest(_dest){}
    };
    Tlink operator+(const Tlink&l,const Tlink&r)
    {
        Tlink ret;ret.dest=r.dest;
        ret.str=l.str+r.str;
        return ret;
    }
    struct Pre2K
    {
        Tlink Link[VT_MAX][LG_MAX];
        char*val;
        int*next;
        int n;
        void doit(int _n,char*_val,int*_next)
        {
            n=_n;val=_val;next=_next;
            rep(i,n)
                Link[i][0]=Tlink(Tstr(val[i]),next[i]);
            for(int i=1;i<LG_MAX;i++)
            {
                rep(v,n)
                {
                    int go=Link[v][i-1].dest;
                    Link[v][i]=Link[v][i-1]+Link[go][i-1];
                }
            }
        }
        int cmp(int u,int v)
        {
            for(int i=LG_MAX-1;i>=0;i--)
            {
                if(Link[u][i].str==Link[v][i].str)
                    u=Link[u][i].dest,v=Link[v][i].dest;
            }
            if(val[u]==val[v])return 0;
            return val[u]<val[v]?-1:1;
        }
    };
}
namespace Solve
{
    using namespace Hash_Data;
    using namespace Pre2K_Data;
    Pre2K p2K;
    char val[VT_MAX];
    int next[VT_MAX],N,Q;
    void input_data()
    {
        cin>>N;rep(i,N)scanf(" "),scanf("%c",val+i);
        rep(i,N)scanf("%d",next+i),next[i]--;
    }
    bool cmp(int u,int v)
    {
        int tmp=p2K.cmp(u,v);
        if(tmp!=0)return tmp==-1;
        return u<v;
    }
    void work()
    {
        static int rank[VT_MAX];
        rep(i,N)rank[i]=i;
        sort(rank,rank+N,cmp);
        rep(i,N)printf("%d\n",rank[i]+1);
    }
    void solve()
    {
        input_data();//puts("OK");
        p2K.doit(N,val,next);//puts("OK");
        work();
    }
}
int main()
{
    freopen("in","r",stdin);
    Solve::solve();
}

