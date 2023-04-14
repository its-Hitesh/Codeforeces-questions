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
bool good(int x, vector<int> &cnt, int c){
    int temp = 0;
    for(int i = 1; i + x <= cnt.size(); i++){
        int j = i + x - 1;
        temp = cnt[j] - cnt[i - 1];
        // cout<<temp<<" "<<i<<" "<<j<<ed;
        if(temp < c) return false; 
    }
    // cout<<x<<" "<<temp<<" "<<c<<ed;
    return true ;
}
void solve(){
    int a, b, c; cin>>a>>b>>c;
    bool prime[b + 10];
    for(int i = 0; i <= b; i++) prime[i] = true;
    prime[0] = prime[1] = false;
    for(int i = 2; i * i <= b + 1; i++){
        if(prime[i]){
            for(int j = i * i; j <= b + 1; j += i){
                prime[j] = false;    
            }    
        }
    }
    vector<int> cnt(b - a + 2, 0);
    int j = 1;
    foo(i,a,b+1){
        if(prime[i]) cnt[j] = 1 + cnt[j - 1];
        else cnt[j] = cnt[j - 1];
        // cout<<cnt[j]<<" "<<prime[i]<<ed;
        j++;
    }
    // foo(i,0,b - a + 2) cout<<cnt[i]<<" ";
    // cout<<ed;
    int ans = -1;
    int l = 1, r = b - a + 1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(good(mid, cnt, c)){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
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

  int tt =1; //cin>>tt;

  while(tt--){

    solve();
  }
  return 0;
}