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
    int n; cin>>n;
    vector<int> a(n,-1),rnk(n,-1);
    foo(i,0,n){
        foo(j,i,n){
            int x ; cin>>x;
            // cout<<x<<ed;
            if(x == 0){
                // cout<<i<<" "<<j<<" "<<0<<ed;
                foo(k,i,j +1){
                    if(rnk[k] == -1) {
                        rnk[k] = x;
                        continue;
                    }
                    if(a[k] == -1) a[k] = rnk[k];
                    // cout<<a[k]<<" zero "<<k<<ed;
                    rnk[k] = 0;
                }
            }
            if(x == 1){
                // cout<<i<<" "<<j<<" "<<1<<ed;
                foo(k,i,j+1){
                    if(rnk[k] == -1) {
                        rnk[k] = x;
                        continue;
                    }
                    else if(rnk[k] == 2 && ((rnk[k-1] == 2 || a[k-1] == 2) || (k+1 < n && (rnk[k+1] == 2 || a[k+1] == 2)))){
                        // cout<<i<<" "<<k<<" "<<1<<ed;
                        rnk[k] = 1;
                    } 
                    else if(rnk[k] == 2){
                        cout<<0<<ed;
                        return ;
                    }
                }
            }
            if(x == 2){
                // cout<<i<<" "<<j<<" "<<2<<ed;
                // cout<<"wrg "<<rnk[i]<<" "<<j<<ed;
                bool f = false ;
                foo(k,i,j +1){
                    if(rnk[k] == -1 || rnk[k] == 2 || a[k] == 2) f = true ;
                }
                foo(k,i,j +1){
                    if(rnk[k] == -1) {
                        rnk[k] = x;
                        continue;
                    }
                    if(rnk[k] == 1 && !f){
                        cout<<20<<ed;
                        return;
                    }
                }
            }
        }
    }
    foo(i,0,n){
        if(a[i] == -1) a[i] = rnk[i];
    }
    // foo(i,0,n) cout<<a[i]<<" ";
    // cout<<ed;
    if(a[0] == 2) cout<<0<<ed;
    else{
        int ans = 2;
        foo(i,1,n){
            if(a[i] == 0 && a[i-1] == 1) ans = (ans*2)%mod;
            else if(a[i] == 1 && a[i-1] != 1) ans = (ans*2)%mod;
            else if(a[i] == 2 && a[i-1] == 0) ans = (((ans*2)%mod - 2) + mod) % mod;
            else if(a[i] == 0 && a[i-1] == 2) ans = (ans*2)%mod ;
        }
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

  int tt =1; //cin>>tt;

  while(tt--){

    solve();
  }
  return 0;
}