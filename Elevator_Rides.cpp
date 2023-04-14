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
    int n,k; cin>>n>>k;
    pair<int,int> dp[1 << n];                                     // min number of rides and weight in last lift 
    int a[n] ; foo(i,0,n) cin>>a[i];
    dp[0] = {1, 0};

    for(int i = 1; i < (1 << n); i++){
        dp[i] = {n + 1, 1};
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                if(dp[i ^ (1 << j)].second + a[j] <= k){
                    dp[i] = min(dp[i],{dp[i ^ (1 << j)].first, dp[i ^ (1 << j)].second + a[j]});
                }
                else{
                    dp[i] = min(dp[i], {dp[i ^ (1 << j)].first + 1, a[j]});
                }
            }
        }
    }

    cout<<dp[(1 << n) - 1].first<<ed;
    
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