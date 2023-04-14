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

void solve(){
    int n, m, q; cin>>n>>m>>q;
    vector<vector<int>>dis(n+1,vector<int>(n+1, 1e15)), grp(n+1, vector<int>(n+1,1e15));
    while(m--){
        int x,y,z; cin>>x>>y>>z;
        grp[x][y] = min(grp[x][y], z);
        grp[y][x] = min(grp[y][x], z);
    }
    foo(i,1,n+1){
        foo(j,1,n+1){
            if(i == j){
                dis[i][j] = 0;
            }
            else{
                dis[i][j] = grp[i][j];
                dis[j][i] = grp[j][i];
            }
        }
    }
    foo(k,1,n+1){
        foo(i,1,n+1){
            foo(j,1,n+1){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    while(q--){
        int x, y; cin>>x>>y;
        if(dis[x][y] >= 1e15) cout<<-1<<ed;
        else cout<<dis[x][y]<<ed;
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