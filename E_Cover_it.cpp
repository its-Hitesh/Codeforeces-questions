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

// use bipartiteness of the graph 
void dfs(int s, vector<vector<int>> &grp, int f, vector<int> &visited, vector<int> &coloring){
    coloring[s] = f;
    visited[s] = 1;
    for(auto x : grp[s]){
        if(visited[x] == 0) dfs(x, grp, 1 - f, visited, coloring);
    }
}
void solve(){
    int n, m; cin>>n>>m;
    vector<vector<int>> grp(n);
    foo(i,0,m){
        int x, y; cin>>x>>y;
        x--; y--;
        grp[x].pb(y);
        grp[y].pb(x);
    }
    vector<int> visited(n,0);
    vector<int> coloring(n,-1);
    dfs(0, grp, 0, visited, coloring);
    int zero = 0, one = 0;
    foo(i,0,n){
        if(coloring[i] == 0) zero++;
        else one++;
    }
    if(one < zero){
        cout<<one<<ed;
        foo(i,0,n) {
            if(coloring[i] == 1) cout<<i+1<<" ";
        }
        cout<<ed;
    }
    else {
        cout<<zero<<ed;
        foo(i,0,n){
            if(coloring[i] == 0) cout<<i+1<<" ";
        }
        cout<<ed;
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

  int tt =1; cin>>tt;

  while(tt--){

    solve();
  }
  return 0;
}