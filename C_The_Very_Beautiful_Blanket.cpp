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
// you dumb
void solve(){
    int n, m; cin>>n>>m;
    int a[n][m];
    int cnt = 4;
    for(int i = 0; i < n - 1; i += 2){
        for(int j = 0; j < m - 1; j+= 2){
            a[i][j] = cnt;
            a[i][j+1] = cnt + 1;
            a[i+1][j] = cnt + 2;
            a[i+1][j+1] = cnt + 3;
            cnt += 4;
        }
    }
    if(n % 2 == 1){
        for(int i = 0; i < m - 1; i+=2){
            a[n-1][i] = cnt;
            a[n-1][i + 1] = cnt + 1;
            cnt += 4;
        }
    }
    if(m % 2 == 1){
        for(int i = 0; i < n - 1; i+= 2){
            a[i][m - 1] = cnt;
            a[i + 1][m - 1] = cnt + 2;
            cnt += 4;
        }
    }
    if(n % 2 == 1 && m % 2 == 1){
        a[n-1][m-1] = a[n-1][m-2] ^ a[n-2][m-2] ^ a[n-2][m-1];
    } 
    bool f = 1;
    foo(i,0,n){
        foo(j,0,m){
            if(a[i][j] == a[n-1][m-1]){
                if(i != n - 1 || j != m - 1){
                        f = 0;
                }
            }
        }
    }
    cout<<n*m - (f ? 0 : 1)<<ed;
    foo(i,0,n){
        foo(j,0,m) cout<<a[i][j]<<" ";
        cout<<ed;
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