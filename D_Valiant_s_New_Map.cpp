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
int n,m; 
bool good(int l, vector<vector<int>> &a){
    vector<vector<int>> prefix(n+1,vector<int>(m+1, 0));
    foo(i,1,n+1){
        foo(j,1,m+1){
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + ((a[i-1][j-1] >= l)? 1 : 0)  ;
            // cout<<i<<" "<<j<<" "<<prefix[i-1][j]<<" "<<prefix[i][j-1]<<" "<<prefix[i-1][j-1]<<" "<<
            // ((a[i-1][j-1] >= l)? 1 : 0 ) <<" "<<prefix[i][j]<<ed;
        }
    }
    // cout<<" aerhgea "<<l<<ed;
    // foo(i,0,n+1) {
    //     foo(j,0,m+1) cout<<prefix[i][j]<<" ";
    //     cout<<ed;
    // }
    foo(i,l,n+1){
        foo(j,l,m+1){
            int tt = prefix[i][j] - prefix[i-l][j] - prefix[i][j-l] + prefix[i-l][j-l];
            if(tt == l*l) return true ; 
        }
    }
    return false ;
}
void solve(){
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m)); foo(i,0,n) foo(j,0,m) cin>>a[i][j];
    int l = 0, r = min(n,m), ans = 0;
    while(l <= r){
        int mid = l+(r-l)/2;
        if(good(mid,a)){
            l = mid +1 ;
            ans = max(ans,mid);
        }
        else r = mid -1;
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

  int tt =1; cin>>tt;

  while(tt--){

    solve();
  }
  return 0;
}