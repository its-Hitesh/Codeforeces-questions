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


void solve(){
    int n, m; cin>>n>>m;
    int differ = 1e12;
    vector<pair<int,int>> a;
    foo(i,0,m){
        int x, y; cin>>x>>y;
        differ = min(differ, y - x);
        a.pb({x,y});
    }
    sort(a.begin(), a.end());
    int ans = 0;
    cout<<differ + 1<<ed;
    bool f = 1;
    foo(i,0,n) {
        cout<<ans<<" ";
        ans++;
        if(ans == differ + 1) ans = 0;
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