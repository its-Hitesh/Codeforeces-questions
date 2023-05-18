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
int centroid = 0;
int n, m; 
vector<int> siz(300,0);
void dfs(int s, vector<int> &vis, vector<int> grp[]){
    vis[s] = 1;
    siz[s] = 1;
    for(auto x : grp[s]){
        if(vis[x] == 0){
            dfs(x, vis, grp);
            siz[s] += siz[x];
        }
    }
}
int findCentroid(int x, vector<int> &vis, vector<int> grp[]){
            // cout<<siz[x]<<" "<<x<<" "<<p<<ed;
            vis[x] = 1;
    for(auto z : grp[x]){
        if(vis[z] == 0){
            if(siz[z] > (n / 2)) return findCentroid(z, vis, grp);
        }
    }
    return x; 
}
void solve(){
    cin>>n>>m;
    centroid = 0;
    vector<int> grp[300];
    foo(i,0,m){
        int x, y; cin>>x>>y;
        x--; y--;
        grp[x].pb(y);
        grp[y].pb(x);
    }
    vector<int> vis(n + 1,0), vis2(n + 1, 0);
    dfs(0, vis, grp); 
    // cout<<1<<ed;
    int z = findCentroid(0,vis2, grp);
    int x = grp[z].size();
    cout<<x<<" "<<n / x - 1<<ed;
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

  int tt =1; cin>>tt;

  while(tt--){

    solve();
  }
  return 0;
}