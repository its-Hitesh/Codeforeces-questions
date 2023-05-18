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
    int n, k; cin>>n>>k;
    string s; cin>>s;
    int cnt[k][26] = {};
    foo(i,0,k){
        for(int j = i; j < n; j += k){
            cnt[i][s[j] - 'a'] += 1;
        }
    }
    int ans = 0;
    for(int i = 0; i < k / 2; i++){
        int mini = INT_MAX;
        foo(j,0,26){
            mini = min(mini, (2 * n / k) - cnt[i][j] - cnt[k - i - 1][j]);            
        }
        ans += mini;
    }
    if(k % 2 == 1){
        int mini = INT_MAX;
        foo(j,0,26){
            mini = min(mini, n / k - cnt[k / 2][j]);            
        }
        ans += mini;
        // if(n/k % 2 == 1 && ) ans -= 1; 
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