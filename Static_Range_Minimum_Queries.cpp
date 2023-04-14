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
const int MAXK = 32;
void solve(){
    int n , q; cin>>n>>q;
    int a[n];
    foo(i,0,n){
        cin>>a[i];
    }
    int st[n][MAXK+1], lg[n];
    foo(i,0,n){
        st[i][0] = a[i];
    } 
    for(int k=1; k <= MAXK ; k++)
    {
        for(int i=0; (i + (1<<k)) < n; i++)
        { // To prevent segmentation fault,
        // Loop goes until the range is within the array
            // st[i][k] = st[i][k-1] + st[ i + (1<<(k-1)) ][k-1];
            cout<<"fubck"<<ed; 
        }
    }

    lg[1] = 0;
    foo(i,2,n){
        lg[i] = lg[i/2] +1;
    }
    cout<<"asrg"<<ed;

    while(q--){
        int x, y ; cin>>x>>y;
        // int j = lg[y - x + 1];
        // cout<<min(st[x][j],st[y - (1 << j + 1)][j])<<ed;
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