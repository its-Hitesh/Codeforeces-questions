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
    int n, m;
    cin>>n>>m;
    if(m > n) cout<<"NO"<<ed;
    else{
        if(m == n) {
            cout<<"YES"<<ed;
            return;
        }
        while(n > m){
            while(n % 3 == 0 && n > m){
                n /= 3;
            }
            while(m % 2 == 0 && m > n){
                m /= 2;
            }
            if(n % 3 != 0 && n > m){
                cout<<"NO"<<ed;
                return;
            }
            if(m % 2 != 0 && m > n){
                cout<<"NO"<<ed;
                return;
            }
            if(n == m){
                cout<<"YES"<<ed;
                return;
            }
        }
        cout<<"NO"<<ed;
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

  int tt =1; cin>>tt;

  while(tt--){

    solve();
  }
  return 0;
}