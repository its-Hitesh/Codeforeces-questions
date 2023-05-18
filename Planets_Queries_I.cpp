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

int n, m;
int parent[2000001][31] = {};
int par[2000001];

void solve(){
    cin>>n>>m;
    foo(i,1,n + 1){
        cin>>par[i];
        parent[i][0] = par[i];
    }
    foo(j,1,31){
        foo(i,1,n+1){
            if(parent[i][j - 1] <= 0) parent[i][j] = 0;
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }
    foo(i,0,m){
        int x, y; cin>>x>>y;
        for(int j = 31; j >= 0; j--){
            if(y & (1 << j)){
                x = parent[x][j];
                y -= (1 << j);
            }
        }
        cout<<x<<ed;
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