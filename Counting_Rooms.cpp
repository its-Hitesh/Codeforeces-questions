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

int dx[4] = {0,1,-1,0};
int dy[4] = {1,0,0,-1};
int n,m,rooms = 0; 
bool inrange(int x, int y){
    if( x >= 0 && x < n && y >= 0 && y < m) return true ;
    return false ;
}
void dfsrec(int i, int j, vector<vector<bool>> & visited, vector<string> & a){
    visited[i][j] = true ;
    foo(k,0,4){
        if(inrange(i+dx[k],j+dy[k]) && a[i+dx[k]][j+dy[k]] == '.' && visited[i+dx[k]][j+dy[k]] == false ){
            dfsrec(i+dx[k], j+dy[k],visited,a);
        }
    }
}

void dfs(vector<string> & a){
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    foo(i,0,n){
        foo(j,0,m){
            if(visited[i][j] == false && a[i][j] == '.'){
                rooms++;
                dfsrec(i,j,visited,a);
            }
        }
    }
}

void solve(){

    // number of disconnected components in the grid ;

    cin>>n>>m;
    vector<string> a(n);
    foo(i,0,n) cin>>a[i];

    dfs(a);

    cout<<rooms<<ed;

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