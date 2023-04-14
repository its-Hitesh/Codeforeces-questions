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
bool dfs(int x, int color, vector<vector<int>> &grp, vector<int> & visited, vector<int> &colortype){
    visited[x] = 1;
    colortype[x] = color;
    for(auto z : grp[x]){
        // cout<<"parent "<<x<<" "<<colortype[x]<<" child "<<z<<" "<<colortype[z]<<ed;
        if(colortype[x] == colortype[z]) return false ;
        if(visited[z] == 0){
            bool temp = dfs(z,3 - color,grp,visited,colortype);
            if(temp == false) return false ;
        }
    }
    return true ;
}
void solve(){
    int n; cin>>n;
    vector<vector<int>> grp(n+1);
    bool f = false ;
    foo(i,0,n){
        int x,y;
        cin>>x>>y;
        grp[x].pb(y);
        grp[y].pb(x);
        if(x == y || grp[x].size() > 2 || grp[y].size() > 2) f = true;
    }
    if(f){
        cout<<"NO"<<ed;
        return ;
    }
    vector<int> visited(n+1,0), cololtype(n+1,0);
    foo(i,1,n+1){
        if(visited[i]==0){
            if(dfs(i,1,grp,visited,cololtype) == false){
                cout<<"NO"<<ed;
                return ;
            }
        }
    }
    cout<<"YES"<<ed;
        
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