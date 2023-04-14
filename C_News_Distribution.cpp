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
int parent[500001], rnk[500001];
void build(){
    foo(i,0,n){
        parent[i] = i;
        rnk[i] = 1;
    }
}
int find_set(int a){
    if(parent[a] == a){
        return a;
    }
    parent[a] = find_set(parent[a]);
    return parent[a];
}
void merge(int a, int b){
    int p1 = find_set(a);
    int p2 = find_set(b);
    if(p1 != p2){
        if(rnk[p1] > rnk[p2]){
            parent[p2] = p1;
            rnk[p1] += rnk[p2];
        }
        else{
            parent[p1] = p2;
            rnk[p2] += rnk[p1];
        }
    }
}
void solve(){
    cin>>n>>m;
    build();
    foo(i,0,m){
        int x,a; cin>>x;
        if(x >= 1) cin>>a, x--; 
        while(x--){
            int b;
            cin>>b;
            // cout<<" saghpq "<<a<<" "<<b<<ed;
            merge(a,b);
        }
    }
    foo(i,1,n+1) cout<<rnk[find_set(i)]<<" ";
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