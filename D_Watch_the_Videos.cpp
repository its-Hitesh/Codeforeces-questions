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
int n, m;
bool good(int x, int a[]){
  int maxa = 0;
  for(int i =0; i < n - x; i++){
    if(i != n - x - 1 -i)maxa = max(maxa, a[i] + a[n - x - 1 - i]);
    // cout<<i<<" "<<n-x-1-i<<" "<<a[i]<<" "<<a[n-x-1-i]<<" "<<x<<" "<<maxa<<ed;
  }
  // cout<<maxa<<" "<<m<<" "<<x<<ed;
  if(maxa <= m) return true;
  return false ;
}
void solve(){
     cin>>n>>m;
    int ans = 0;
    int a[n]; foo(i,0,n){
      cin>>a[i];
      ans += a[i] + 1;
    }
    int k = n;
    sort(a,a+n);
    int l = 0, r = n;
    while(l <= r){                                // if all pairs are not good then we have to delete some elements from the end of the 
                                                  // sorted array 
      int mid = (l+r) >> 1;
      if(good(mid , a)){
        k = min(mid,k);
        r = mid - 1;
      }
      else l = mid + 1;
    }
    // cout<<" k "<<k<<ed;
    if(k != n)ans -= (n - k - 1);
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

  int tt =1; //cin>>tt;

  while(tt--){

    solve();
  }
  return 0;
}