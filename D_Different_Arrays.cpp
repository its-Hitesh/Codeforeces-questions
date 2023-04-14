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

// for fast hashing
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { // To use most bits rather than just the lowest ones:
    const uint64_t C = ll(4e18 * acos(0)) | 71; // large odd number
    ll operator()(ll x) const { return __builtin_bswap64((x^RANDOM)*C); }
};
template<class K,class V> using ht = gp_hash_table<K,V,chash>;
//__gnu_pbds::gp_hash_table<ll, int, chash> ht({},{},{},{}, {1 << 16});

//oset<int>s:s.find_by_order(k):Kth element in "s",s.order_of_key(k):Number of item strictly lessthan k
template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
int dp[301][180006];
int n ;
int a[301];
int fun(int x, int val){
    if(x == n-1){
        return 1;
    } 

    // cout<<dp[x][val]<<ed;
    if(dp[x][val] != -1 ) return dp[x][val]%mod;
    dp[x][val] = 0;
    dp[x][val] += fun(x+1, val + a[x+1])%mod;
    if(val != 0) dp[x][val] = ((dp[x][val]%mod) + (fun(x+1, a[x+1] - val)%mod))%mod;
    return dp[x][val]%mod;
}
// int fun2(int x, int val){
//     cout<<x<<" "<<val<<ed;
//     if(x == n-2) return 1;
//     if(dp[x][val] != -1 ) return 0;
//     int ans = fun(x+1, val + a[x+1]);
//     if(val + a[x+1] != a[x+1] - val) ans += fun(x+1, a[x+1] - val);
//     return ans;
// }
void solve(){
    cin>>n;
    foo(i,0,n) cin>>a[i];
    foo(i,0,n + 1) foo(j,0,180006) dp[i][j] = -1;
    int ans = fun(1,a[1]);
    // cout<<ans<<ed;
    // if(a[1] + a[2] != a[2] - a[1]) ans += fun2(1,a[2] - a[1]); 
    cout<<ans%mod<<ed;
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