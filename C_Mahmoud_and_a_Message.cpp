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
#define mod           1000000007
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

void solve(){
    int n; cin>>n;
    string s; cin>>s;
    // a -> 97
    int a[26] ; foo(i,0,26) cin>>a[i];
    int dp[n+1],dp2[n+1];
    dp[0] = 1;
    dp2[0] = 0;
    int len = 0;
    foo(i,1,n+1){
        int chk = 0;
        dp[i] = 0;
        dp2[i] = n ;
        for(int j = i - 1; j >=0; j--){
            chk = max(chk,i - a[s[j] - 'a']);
            // cout<<a[25]<<ed;
            if(chk > j) continue;
            dp[i] = (dp[i] + dp[j]) % mod ;
            dp2[i] = min(dp2[i],dp2[j]+1);
            // cout<<j<<" "<<len<<ed;
            len = max(len , i - j);
        }
    }
    cout<<dp[n]<<ed;
    cout<<len<<ed;
    cout<<dp2[n]<<ed;

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