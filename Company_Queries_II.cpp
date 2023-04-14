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

int depth[200005];
void dfs(int s, vector<int> grp[]){
    for(auto x : grp[s]){
        depth[x] = depth[s] + 1;
        dfs(x, grp);
    }
}
void solve(){
    int n,m ; cin>>n>>m;
    vector<int> grp[n + 2];
    int par[n+2]={};
    foo(i,1,n){
        int x; cin>>x;
        par[i+1] = x;
        grp[x].pb(i+1);
    }
    int parent[n+1][30] = {};
    foo(i,1,n+1){
        parent[i][0] = par[i];
    }
    foo(i,1,n+1){
        foo(j,1,29){
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }
    dfs(1, grp);
    foo(i,0,m){
        int x, y; cin>>x>>y;
        if(depth[x] < depth[y]) swap(x,y);
        int up = depth[x] - depth[y];
        for(int j = 29; j >= 0; j--){
            if(up & (1 << j)){
                x = parent[x][j];
                up -= (1 << j);
            }
        }
        if(x == y) cout<<x<<ed; 
        else{
            for(int j = 29; j >= 0; j--){
                if(parent[x][j] != parent[y][j]){
                    x = parent[x][j];
                    y = parent[y][j];
                }
            }
            cout<<parent[x][0]<<ed;
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