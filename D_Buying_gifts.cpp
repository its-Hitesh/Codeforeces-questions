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

void solve(){
        int n = array1.size(), array2.size();
        int median = (n + m) / 2;
        if((n + m) % 2 == 0) median -= 1;  
        for(int i= 0; i <n; i++) cin>>array1[i];
        for(int i= 0; i <m; i++) cin>>array2[i];
        int l = 0, r = n -1;
        int ans1 = -1, ans2 = -1;
        while(l <= r){
            int mid  = ( l + r ) / 2;
            int temp = upper_bound(array2.begin(), array2.end(), array1[mid]) - array2.begin();
            int sum = mid + temp;
            if(sum == median){
                ans1 = mid;
                break;
            }
            else if(sum > median){
                r = mid - 1;
            }
            else l = mid  + 1;
        }
        l = 0; r = m - 1;
        while(l <= r){
            int mid  = ( l + r ) / 2;
            int temp = upper_bound(array1.begin(), array1.end(), array2[mid]) - array1.begin();
            int sum = mid + temp;
            if(sum == median){
                ans2 = mid;
                break;
            }
            else if(sum > median){
                r = mid - 1;
            }
            else l = mid  + 1;
        }
        if(ans1 != -1){
            cout<<array1[ans1]<<ed;
        }
        else cout<<array2[ans2]<<ed;
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