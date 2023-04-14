#include <bits/stdc++.h>
// #include <bits/extc++.h>//
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
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

// // for fast hashing
// const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
// struct chash { // To use most bits rather than just the lowest ones:
//     const uint64_t C = ll(4e18 * acos(0)) | 71; // large odd number
//     ll operator()(ll x) const { return __builtin_bswap64((x^RANDOM)*C); }
// };
// template<class K,class V> using ht = gp_hash_table<K,V,chash>;
// //__gnu_pbds::gp_hash_table<ll, int, chash> ht({},{},{},{}, {1 << 16});

// //oset<int>s:s.find_by_order(k):Kth element in "s",s.order_of_key(k):Number of item strictly lessthan k
// template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

const int mx = 10000003;
    bool prime[mx];
    int pf[mx];

void solve(){
    int n; cin>>n;
    int a[n]; foo(i,0,n) cin>>a[i];
    int ans1[n],ans2[n];
    foo(i,0,n){
        int first = -1 , cur = 1, rest = 1;
        while(a[i] > 1){
                //cout<<pf[a[i]]<<" "<<a[i]<<ed;
            if(first == -1 || pf[a[i]] == first) {
                first = pf[a[i]];
                cur *= pf[a[i]];
            }
            else rest *= pf[a[i]];
            a[i] /= pf[a[i]];
        }
        if(rest == 1){
            ans1[i] = -1;
            ans2[i] = -1;
        }
        else {
            ans1[i] = cur;
            ans2[i] = rest ;
        }
    }
    foo(i,0,n) cout<<ans1[i]<<" ";
    cout<<ed;
    foo(i,0,n) cout<<ans2[i]<<" ";
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

    foo(i,0,mx) prime[i] = true;
    prime[0] = prime[1] = false;
    foo(i,2,mx){
        if(prime[i]){
            pf[i] = i;
            for(int j = i*i; j < mx; j += i){
                prime[j] = false ;
                pf[j] = i;
            }
        }
    }
  int tt =1; //cin>>tt;

  while(tt--){

    solve();
  }
  return 0;
}
