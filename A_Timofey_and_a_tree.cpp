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
void dfs(int x,vector<vector<int>> &grp,vector<int> &color,vector<int> &visited ,int c,vector<pair<int,int>> &differ){
    visited[x] = 1;
    for(auto u : grp[x]){
        // cout<<x<<" "<<color[u]<<" "<<c<<ed;
        if(color[u] != c) {
            differ.pb(m_p(x,u));
        }
        else if(visited[u] == 0){
            dfs(u,grp,color,visited,c,differ);
        }
    }
    
}
void solve(){
    int n; cin>>n;
    vector<vector<int>> grp(n);
    foo(i,0,n-1){
        int x,y; cin>>x>>y;
        x--;y--;
        grp[x].pb(y);
        grp[y].pb(x);
    }
    vector<int> color(n);
    foo(i,0,n) cin>>color[i];
    // cout<<ed;
    vector<int> visited(n,0);
    vector<pair<int,int>> differ;
    foo(i,0,n){
        if(visited[i] == 0){
            dfs(i,grp,color,visited,color[i],differ);
            // cout<<cnt<<ed;
        }
    }
    map<int,int> m;
    // cout<<differ.size()<<ed;
    for(auto x : differ){
        m[x.first]++;m[x.second]++;
    }
    foo(i,0,n){
        if(m[i] == differ.size()) {
            cout<<"YES"<<ed;
            cout<<i+1<<ed;
            return;
        }
    }
    cout<<"NO"<<ed;
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