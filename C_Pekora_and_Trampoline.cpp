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
    int n; cin>>n;
    int a[n]; foo(i,0,n) cin>>a[i];
    int ans = 0, exa[n + 1] = {};
    foo(i,0,n){
        if(exa[i] >= a[i]){
            exa[i] -= a[i] - 1;
            exa[i + 1] += exa[i];    
        }
        else{
            ans += a[i] -1 - exa[i]; 
        }
        foo(j,i + 2, min(i + a[i] + 1, n)){
            exa[j] += 1;   
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