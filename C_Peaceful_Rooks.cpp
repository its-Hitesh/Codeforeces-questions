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
int ans = 0;
bool dfsrec(int s, vector<int>& visited, vector<int>& temp, vector<int> grp[]){
    visited[s] = 1;
    bool f = false ;
    temp[s] = 1;
    for(auto x : grp[s]){
        if(temp[x] == 1){
            return true ;
        }
        if(visited[x] == 0) {
            f |= dfsrec(x, visited, temp, grp);
        }
    }
    temp[s] = 0;
    return f ;
}
void dfs(int n, vector<int>& visited, vector<int>& temp, vector<int> grp[]){
    foo(i,0,n){
        if(visited[i] == 0){
            bool f = dfsrec(i, visited, temp, grp);
            // cout<<i<<" "<<f<<ed;
            if(f) ans++;                               // counting cycles 
        }
    }
}

void solve(){                                               // look as directed graph 
    ans = 0;
    int n, m; cin >>n >>m;
    int loop = 0;
    vector<int> grp[n];
    foo(i,0,m){
        int x, y; cin>>x>>y;
        x--; y--;
        if(x == y) loop++;
        else grp[x].pb(y);
    }
    vector<int> visited(n, 0), temp(n,0);
    dfs(n, visited, temp, grp);

    cout<< m - loop + ans <<ed;
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