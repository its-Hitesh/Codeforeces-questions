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
int n, m, ans = 0, temp = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int a[1000][1000];
bool in_range(int x, int y){
    if(x >= 0 && y >= 0 && y < m && x < n) return true ;
    return false ; 
}
void dfs(int x, int y, vector<vector<int>> &vis){
    vis[x][y] = 1;
    temp += a[x][y];
    foo(q,0,4){
        int i = x + dx[q];
        int j = y + dy[q];
        if(in_range(i, j) && a[i][j] != 0 && vis[i][j] == 0){
            dfs(i, j, vis);
        }
    }
}
void solve(){
    cin>>n>>m;
    ans = 0;
    foo(i,0,n) foo(j,0,m) cin>>a[i][j];
    vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0));
    foo(i,0,n){
        foo(j,0,m){
            if(vis[i][j] == 0 && a[i][j] > 0){
                temp = 0;
                dfs(i, j, vis);
                ans = max(ans, temp);
            }
        }
    }
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

  int tt =1; cin>>tt;

  while(tt--){

    solve();
  }
  return 0;
}