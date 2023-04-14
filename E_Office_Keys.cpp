#include <bits/stdc++.h>
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
bool good(int x, int n, int k, int p, vector<int> & pos, vector<int> & key){
    // cout<<x<<ed;
    int m[k]={};
    int z[n]={};
    foo(i,0,n){
        int idx = -1;
        int maxa = -1;
        // int l = 0, r = k-1;
        // while(l <= r){
        //     int mid = l+(r-l)/2;
        //     if(abs(pos[i]-key[mid])+abs(key[mid]-p) <= x && m[mid] == 0){
        //        cout<<mid<<ed;
        //         idx = mid;
        //         l = mid + 1;
        //     }
        //     else r = mid - 1;
        // }
        // cout<<ed;
        foo(j,0,k){
            int t = abs(pos[i]-key[j])+abs(key[j]-p);
            if(t <= x && m[j] == 0){
                if(maxa < t){
                    idx = j;
                    maxa = t ;
                }
            }
        }
        // cout<<idx<<" "<<i<<ed;
        if(idx == -1) return false ;
        m[idx] = 1;
        z[i] = 1;
    }
    foo(i,0,n){
        if(z[i] == 0){
            return false ;
        }
    }
    return true ;
}
void solve(){
    int n,k,p; cin>>n>>k>>p;
    vector<int> pos(n); foo(i,0,n) cin>>pos[i];
    vector<int> key(k); foo(i,0,k) cin>>key[i];
    sort(pos.begin(),pos.end());
    sort(key.begin(),key.end());
    int l = 0 , r = 1e18;
    int ans = 0;
    while(l <= r){
        int mid = l+(r-l)/2;
        if(good(mid,n,k,p,pos,key)){
            ans = mid;
            // cout<<ans<<ed;
            r = mid -1;
        }
        else l = mid + 1 ;
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