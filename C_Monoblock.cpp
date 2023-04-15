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
    int n, m; cin>> n>> m;
    int a[n]; foo(i,0,n) cin>>a[i];
    int ans = 1;
    foo(i,1,n) if(a[i] != a[i - 1]) ans++;
    foo(i,0,m){
        int x, y;
        cin>>x>>y;
        x--;
        if(x == 0){
            if(n > 1){
                if(a[x] == a[x + 1]){
                    if(a[x] != y) ans += n - 1;
                }
                else{
                    if(a[x] != y && y == a[x + 1]) ans -= n - 1; 
                }
            }
            cout<<ans<<ed;
        }
        else if(x == n - 1){
            if(n > 1){
                if(a[x] == a[x - 1]){
                    if(a[x] != y) ans += n - 1;
                }
                else{
                    if(a[x] != y && y == a[x - 1]) ans -= n - 1; 
                }
            }
            cout<<ans<<ed;
        }
        else{
            if(a[x - 1] == a[x + 1]){
                if(a[x] != a[x - 1] && y == a[x - 1]){
                    ans -=  x*((n - x)*2 - 1);
                }
                else if(a[x] == a[x - 1] && y != a[x - 1]){
                    ans += x*((n - x)*2 - 1);
                }
            }
            else{
                if(a[x] != a[x - 1] && a[x] != a[x + 1] && (y == a[x - 1] || y == a[x + 1])){
                    ans -= x*(n - x);
                }
                else if(a[x] == a[x - 1] || a[x] == a[x + 1]){
                    if(y == a[x + 1]) ans += x;
                    else if(y == a[x - 1]) ans -= x;
                }
            }
            cout<<ans<<ed;
        }
        a[x] = y;
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