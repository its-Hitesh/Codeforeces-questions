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
int par[100001];
int rnk[100001];
vector<int> maxa(100001),mini(100001);
void build(int n){
    foo(i,0,n+1){
        par[i] = i;
        rnk[i] = 1;
        maxa[i] = i;
        mini[i] = i;
    }
}
int find_set(int x){
    if(par[x] == x) return x;
    par[x] = find_set(par[x]);
    return par[x] ;
}
void merge(int x, int y){
    int p1 = find_set(x);
    int p2 = find_set(y);
    if(p1 != p2){
        if(rnk[p1] > rnk[p2]){
            par[p2] = p1;
            maxa[p1] = max(maxa[p1],maxa[p2]);
            mini[p1] = min(mini[p1],mini[p2]);
            rnk[p1] = rnk[p1] + rnk[p2];
        }
        else{
            par[p1] = p2;
            maxa[p2] = max(maxa[p1],maxa[p2]);
            mini[p2] = min(mini[p1],mini[p2]);
            rnk[p2] += rnk[p1];
        }
    }
}
void solve(){
    int n,q;
    cin>>n>>q;
    build(n);
    while(q--){
        string s; cin>>s;
        if(s == "union"){
            int x,y; cin>>x>>y;
            merge(x,y);
        }
        else{
            int x ; cin>>x;
            int p = find_set(x);
            cout<<mini[p]<<" "<<maxa[p]<<" "<<rnk[p]<<ed;
        }
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