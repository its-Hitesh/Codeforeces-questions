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

int andOperator(int a, int b) {
      // ShiftCount variables counts till which bit every value will convert to 0
      int shiftcount = 0;
    //Iterate through every bit of a and b simultaneously
      //If a == b then we know that beyond that the and value will remain constant
      while(a != b and a > 0) {
          shiftcount++;
          a = a >> 1;
          b = b >> 1;
    }
      return int64_t(a << shiftcount);
}

void solve(){
    int n,k; cin>>n>>k;
    int l = n, r = LONG_LONG_MAX;
    // cout<<r<<ed;
    int ans = LONG_LONG_MAX;
    foo(i,0,100){
        int mid = l+(r-l)/2;
        int getand = andOperator(n,mid);
        if(getand > k){
            l = mid + 1;
        }
        else if(getand < k){
            r = mid - 1;
        }
        else{
            ans = min(mid,ans);
            r = mid - 1 ;
        }
    }
    if(ans == LONG_LONG_MAX){
        cout<<-1<<ed;
    }
    else{
        cout<<ans<<ed;
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