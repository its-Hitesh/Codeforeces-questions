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
#define int long long
int n, m; 
int a[200003], dp[200003];
vector<int> grp[200002], grpt[200002],newgrp[200002], order, vis(200002,0), comp, vis2(200002, 0), compid(200002, -1);
void dfs1(int st, vector<int> gp[], vector<int>&vi){
    vi[st] = 1;
    for(auto x : gp[st]){
        if(vi[x] == 0) dfs1(x, gp, vi);
    }
    order.pb(st);
}
void dfs2(int st, int id){
    comp[id] += a[st];
    compid[st] = id;
    // cout<<compid[st]<<" "<<id<<" "<<comp[id]<<ed;
    vis2[st] = 1;
    for(auto x : grpt[st]){
        if(vis2[x] == 0) dfs2(x, id);
    }
}
void Dfs(int s, vector<int> gp[], vector<int> &vis3){
    vis3[s] = 1;
    // dp[s] = 0;
    for(auto x : gp[s]){
        if(vis3[x] == 0){
            Dfs(x, gp, vis3);
        }
        dp[s] = max(dp[s], dp[x]);
    }
    dp[s] += comp[s];
    // cout<<dp[s]<<" "<<s<<ed;
}
void solve(){
    cin>>n>>m;
    foo(i,0,n) cin>>a[i];
    foo(i,0,m) {
        int x, y; cin>>x>>y; 
        x--; y--; 
        grp[x].pb(y);
        grpt[y].pb(x);
    }
    foo(i,0,n){
        if(vis[i] == 0){
            dfs1(i, grp, vis);
        }
    }
    int id = 0;
    foo(i,0,n){
        int x = order[n - i - 1];
        if(vis2[x] == 0){
            comp.pb(0);
            dfs2(x, id);
            id++;
        }
    }
    // foo(i,0,n) cout<<compid[i]<<" ";
    // cout<<ed;
    for(int i = 0; i < n; i++){
        for(auto x : grp[i]){
            if(compid[i] != compid[x]){
                newgrp[compid[i]].pb(compid[x]);
                // cout<<compid[i]<<" "<<compid[x]<<endl;
            }
        }
    }
    order.clear();
    vector<int> viss(200003, 0);
    for(int i = 0; i < id; i++){
        if(viss[i] == 0)
            dfs1(i, newgrp, viss);
    }
    vector<int> vis3(200003, 0);
    for(int i = 0; i < id; i++){
        int x = order[i];
        // cout<<x<<ed;
        if(vis3[x] == 0){
            Dfs(x, newgrp, vis3);
        }
    }
    int ans = 0;
    for(int i = 0; i < id; i++) ans = max(dp[i], ans); //, cout<<dp[i]<<" ";
    cout<<ans<<ed;
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