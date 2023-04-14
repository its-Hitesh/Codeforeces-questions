#include <bits/stdc++.h>
#include <bits/extc++.h>//
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
#define int long long

// LCA application 
int par[200005][30], depth[200005], dis[200005];
void dfs(int s, int p, vector<int>grp[]){
    foo(i,1,30) par[s][i] = par[par[s][i - 1]][i - 1];                     // calculating parents of curr node
    for(auto x : grp[s]){
        if(x != p){
            depth[x] = depth[s] + 1;
            par[x][0] = s;
            dfs(x, s, grp);
        }
    }
}
void dfs2(int s, int p, vector<int>grp[]){
    for(auto x : grp[s]){
        if(x != p){
            dfs2(x, s, grp);
            dis[s] += dis[x];
        }
    }
}
int LCA(int x, int y){
    if(depth[x] < depth[y]) swap(x,y);
        int up = depth[x] - depth[y];
        // cout<<x<<" "<<par[x][0]<<" "<<par[x][2]<<ed;
        for(int j = 29; j >= 0; j--){
            if(up & (1 << j)){
                x = par[x][j];
                up -= (1 << j);
            }
        }
        if(x == y) return x; 
        else{
            for(int j = 29; j >= 0; j--){
                if(par[x][j] != par[y][j]){
                    x = par[x][j];
                    y = par[y][j];
                }
            }
            return par[x][0];
        }
}
void solve(){
    int n, m; cin>>n>>m;
    vector<int> grp[n+1];
    foo(i,1,n){
        int x, y; cin>>x>>y;
        grp[x].pb(y);
        grp[y].pb(x);
    }
    dfs(1, -1, grp);
    

    // foo(i,1,n+1) cout<<depth[i]<<" ";
    foo(i,0,m){
        int x, y; cin>>x>>y;
        dis[x] += 1; dis[y] += 1;
        int lca = LCA(x,y);
        dis[lca] -= 1;
        dis[par[lca][0]] -= 1;
        // cout<< "lca "<<x<<" "<<y<<" "<<lca<<ed;
    }
    dfs2(1, -1, grp);
    foo(i,1,n+1) cout<<dis[i]<<" ";
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