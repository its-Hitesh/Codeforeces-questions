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

void solve(){


    // dijkstra algo for shortest path on directed graph without negitive edge weights 

    int n,m; cin>>n>>m;
    vector<vector<pair<int,int>>> grp(n);
    foo(i,0,m){
        int x,y,z ; cin>>x>>y>>z;
        x--; y--;
        grp[x].pb(m_p(y,z));
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p;
    vector<int>dist(n,LONG_MAX);
    dist[0] = 0;
    vector<int> visited(n,0);
    p.push(m_p(0,0));
    while(!p.empty()){
        int t = p.top().second;
        // cout<<t<<grp[t].size()<<ed;
        p.pop();
        if(visited[t]) continue;
        visited[t] = 1; 
        for(auto u : grp[t]){
            int v = u.first;
            int w = u.second;
            // cout<<t<<" "<<v<<" "<<dist[t]<<" "<<dist[v]<<" "<<w<<" "<<visited[v]<<ed;
            if(visited[v] == 0 && dist[v] > dist[t] + w){
                dist[v] = dist[t] + w;
                p.push(m_p(dist[v] , v));
            }
        }
    }
    foo(i,0,n) cout<<dist[i]<<" ";

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