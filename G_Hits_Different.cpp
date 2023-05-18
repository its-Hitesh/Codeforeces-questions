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
int dp[1000005];
void solve(){
    int n; cin>>n;
    cout<<dp[n]<<ed;
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

    int x = 2;
  dp[1] = 1; dp[2] = 5; dp[3] = 10;
    int i = 4;
  while(i < 1000001){
        int tt = x + 1;
        dp[i] = dp[i - x] + i * i;
        i++; tt-=2;
        while(tt-- && i < 1000001){
            dp[i] = dp[i - x] + dp[i - x - 1] - dp[i - x - x] + i * i;
            i++;
        }
        dp[i] = dp[i - x -1] + i * i ;
        i++;
        x++;
  }

  int tt =1; cin>>tt;

  while(tt--){

    solve();
  }
  return 0;
}