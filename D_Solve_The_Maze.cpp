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
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int n, m; 
bool in_range(int x, int y){
    if(x >= 0 && y >= 0 && x < n && y < m) return true ;
    return false ;
}
bool dfs(int i, int j, vector<vector<int>> &route, vector<vector<char>> &a, vector<vector<int>> &visited){
    bool f = false;
    // cout<<i<<" "<<j<<ed;
    if(i == n - 1 && j == m -1) return true ;
    if(route[i][j] == 1) return true ;
    route[i][j] = 1;
    visited[i][j] = 1;
    foo(k,0,4){
        int x = i + dx[k];
        int y = j + dy[k];
        // cout<<x<<" x y "<<y<<ed;
        if(in_range(x, y) && a[x][y] != '#' && visited[x][y] == 0){
            f |= dfs(x,y,route, a, visited);
        }
    }
    return f;
}
void solve(){
    cin>>n>>m;
    vector<vector<char>> a(n, vector<char>(m));
    int g = 0;
    foo(i,0,n) foo(j,0,m) cin>>a[i][j], a[i][j] == 'G' ? g = 1 : g = g ;
    if(g == 0){
        cout<<"Yes"<<ed;
        return;
    }
    foo(i,0,n){                                         // blocking all bad people
        foo(j,0,m){
            if(a[i][j] == 'B'){
                foo(k,0,4){
                    int x = i + dx[k];
                    int y = j + dy[k];
                    // cout<<i<<" "<<j<<" "<<x<<" "<<y<<ed;
                    if(in_range(x,y)){
                        if(a[x][y] == 'G'){
                            cout<<"No"<<ed;
                            return ;
                        }
                        if(a[x][y] == '.') a[x][y] = '#';
                    }
                }
            }
        }
    }
    // foo(i,0,n){
    //     foo(j,0,m) cout<<a[i][j];
    //     cout<<ed;
    // }
    vector<vector<int>> route(n, vector<int>(m, -1));                 // keep the track of escape route of bad people 
    foo(i,0,n){
        foo(j,0,m){
            if(a[i][j] == 'G' && route[i][j] == -1){
                // cout<<"sat"<<ed;
                vector<vector<int>> visited(n,vector<int>(m,0));
                bool f = dfs(i,j,route, a, visited);
                if(f == false ){
                    cout<<"No"<<ed;
                    return;
                }
            }
        }
    }
    cout<<"Yes"<<ed;
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