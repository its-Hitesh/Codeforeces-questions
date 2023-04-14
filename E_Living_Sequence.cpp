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
ll dp[19][2];
// passing by reference whitout it giving tle ; 
ll notfour(ll i, string& s, bool f){                        // counting numbers which does not contain 4 
  ll cnt = 0; 
  if(i == s.size()) return 1;
  if(dp[i][f] != -1) return dp[i][f] ;
  for(ll j = 0; j <= (f ? (s[i] - '0') : 9); j++){
    if(j == 4) continue;
    cnt += notfour(i + 1, s, f?((s[i] - '0') == j) : 0);
  }
  return dp[i][f] = cnt ;
}

void solve(){
    ll n; cin>>n;
    ll l = 0, r = 1e15, ans = 0;
    while(l <= r){
      ll mid = l + ( r - l) / 2;
      foo(i,0,19) dp[i][0] = dp[i][1] = -1 ;
      string s = to_string(mid);
      ll cnt = notfour(0, s, 1) - 1;              // removing one when all digits are 0
      if(cnt >= n){                               
        ans = mid;                                      // if cnt of numbers which does not contain 4 is equal to n, its the ans ; 
        r = mid - 1;                         
      }
      else l = mid + 1;
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