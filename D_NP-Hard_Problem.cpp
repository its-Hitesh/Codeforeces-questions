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
bool dfs(int n, vector<int> &a, vector<int> &b, vector<int> &visited, vector<vector<int>> &grp, int put){
    visited[n] = put;
    if(put == 2) a.pb(n+1);
    else b.pb(n+1);
    for(auto u :  grp[n]){
        if(visited[u] == put) return false ;
        else if(visited[u] == 0){
            bool f = dfs(u,a,b,visited,grp,1 - put);
            if(f == false ) return false ;
        }
    }
    return true ; 
}
void solve(){
    cin>>n>>m;
    vector<vector<int>> grp(n);
    while(m--){
        int x,y; cin>>x>>y;
        x--; y--;
        grp[x].pb(y);
        grp[y].pb(x);
    }
    vector<int> visited(n,0);
    vector<int> a,b;
    foo(i,0,n){
        if(visited[i] == 0){
            bool f = dfs(i, a, b, visited, grp, 2);
            if(f == false) {
                cout<<-1<<ed;
                return;
            }
        }
    }
    cout<<a.size()<<ed;
    for(auto x : a) cout<<x<<" ";
    cout<<ed;
    cout<<b.size()<<ed;
    for(auto x : b) cout<<x<<" ";



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