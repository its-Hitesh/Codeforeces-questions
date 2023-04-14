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
int total = 0, dpth[200005];
vector<int> grp[200005], inv(200005);
map<pair<int,int>,int> m;
void dfs(int s, int p){
    for(auto x : grp[s]){
        if(x != p){
            if(m[{s,x}] != 1) inv[x] = inv[s] + 1, total += 1;
            else inv[x] = inv[s];
            dpth[x] = dpth[s] + 1;
            dfs(x, s);
        }
    }
}
void solve(){
    int n; cin>>n;
    foo(i, 0, n - 1){
        int x, y; cin>>x>>y;
        x--; y--;
        m[{x,y}] = 1;
        grp[x].pb(y);
        grp[y].pb(x);
    }
    dfs(0, -1);
    int ans[n];
    foo(i,0,n) ans[i] = dpth[i] - 2 * inv[i] + total;                          // from root to inv all edges sjould be inverted else top down

    int mini = 1e12;
    foo(i,0,n) mini = min(mini, ans[i]);
    cout<<mini<<ed;
    foo(i,0,n) if(ans[i] == mini) cout<<i + 1<<" ";

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