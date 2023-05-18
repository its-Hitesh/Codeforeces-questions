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
    int n, q; cin>>n>>q;
    int a[n]; foo(i,0,n) cin>>a[i];
    sort(a, a + n);
    foo(i,0,q){
        int b[n];
        foo(i,0,n) b[i] = a[i];
        int x; cin>>x;
        foo(i,0,n){
            if (x == 0) {
                break;
            }
            if (x % 2 == 0 && i == n - 1) {
                break;
            }
            if(x < 1){
            
            }
            else {
                b[i] +=  x;
                x--;
            }
        }
        // assert(k % 2 == 0);
        x /= 2;
        sort(b, b + n);
        long long diff = 0;
        for (int j = 0; j < n; j++) {
            diff += b[j] - b[0];
        }
        int ans = b[0];
        if (x > diff) {
            x -= diff;
            ans -= (x + n - 1) / n;
        }
        cout << ans << '\n';
        
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