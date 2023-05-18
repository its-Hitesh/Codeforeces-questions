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
const int N = 10000005;

int n,maax;
void update(int x, int val, int bit[]){
    while(x <= maax){
        bit[x] += val;
        x += (x & (-x));
    }
}
int sum(int x, int bit[]){
    int res = 0;
    while(x > 0){
        res += bit[x];
        x -= (x & (-x));
    }
    return res ;
}
void solve(){
    cin >> n;
    int ans = 0;
    maax = 0;
    int a[n + 1]; foo(i,1,n+1) cin>>a[i], maax = max(maax, a[i]);
    int bit[maax + 2]={};
    foo(i,1,n + 1){
        ans += sum(maax, bit) - sum(a[i], bit);
        update(a[i], 1, bit);
    }
    cout<<ans<<ed;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);
  /*#ifndef ONLINE_JUDGE
    freopen("input.ta[i]t","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
*/

  int tt =1; cin>>tt;

  while(tt--){

    solve();
  }
  return 0;
}