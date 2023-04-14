#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
#define pb            push_back
#define ld            long double
#define sz            size()
#define foo(i,a,b)    for (ll i=a;i<b;i++)
#define pll           pair<ll,ll>
#define ed            "\n"
#define m_p           make_pair
#define mod           998244353

int imp[100005], siz[100005], parent[100005];
ll importance[100005];
set<pair<int,int>> child[100005];
vector<int> grp[100005];
void dfs(int s, int p){
    siz[s] = 1;
    parent[s] = p;
    importance[s] = imp[s];
    for(auto x : grp[s]){
        if(x != p){
            dfs(x, s);
            importance[s] += importance[x];
            siz[s] += siz[x]; 
        }
    }
    for(auto x : grp[s]){
        if(x == p) continue;
        child[s].insert({-siz[x], x});
    }
}
void solve(){
    int n, q; cin>>n>>q;
    foo(i,0,n) cin>>imp[i];
    foo(i,0,n-1){
        int x, y; cin>>x>>y;
        x--; y--;
        grp[x].pb(y);
        grp[y].pb(x);
    }
    dfs(0, -1);
    foo(i,0,q){
        int x, y; cin>>x>>y;
        y--;
        if(x == 1){
            cout<<importance[y]<<ed;
        }
        else{
            if(siz[y] == 1){
                
            }
            else{
                int superchild = (*child[y].begin()).second;
                // cout<<superchild<<ed;
                child[parent[y]].erase(child[parent[y]].find({-siz[y], y}));
                child[y].erase(child[y].find({-siz[superchild], superchild}));
                importance[y] -= importance[superchild];
                siz[y] -= siz[superchild];
                siz[superchild] += siz[y];
                child[superchild].insert({-siz[y], y});
                importance[superchild] += importance[y];
                child[parent[y]].insert({-siz[superchild], superchild});
                int tt = parent[y];
                parent[y] = superchild;
                parent[superchild] = tt;
            }
        }
    }
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);
  /*#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
*/

  int tt =1; //cin>>tt;

  while(tt--){

    solve();
  }
  return 0;
}