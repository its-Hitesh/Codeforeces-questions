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
    int prefix[n] = {};
    int prev = a[0];
    foo(i,1,n){
        if(prev > a[i]){
            prefix[i] = prev - a[i];
            a[i] = prev;
        }
        else prev = max(prev, a[i]);
    }
    foo(i,1,n) prefix[i] += prefix[i - 1];
    foo(i,0,q){
        int x, y; cin>>x>>y;
        x--; y--;
        if(x < 0) x = 0;

        cout<<prefix[y] <<" "<< prefix[x]<<ed;
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