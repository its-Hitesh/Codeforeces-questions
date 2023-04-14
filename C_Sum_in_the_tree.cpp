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
// int vis[100005];
bool dfs(int i, vector<int> &mini, vector<vector<int>> &grp, int s[]){
    // vis[i] = 1;
    bool f = true ;
    if(grp[i].size() == 0){
        if(s[i] != -1) mini[i] = s[i];
        else mini[i] = LONG_MAX;
        return f ;
    }
    // cout<<i<<" "<<s[i]<<" "<<mini[i]<<ed;
    if(s[i] != -1) mini[i] = s[i];
    for(auto x : grp[i]){
        f &= dfs(x, mini, grp, s);
        if(s[i] > mini[x]){
            // cout<<i<<" "<<x<<" "<<s[i]<<" "<<mini[x]<<ed;
            f = false;
        }
        else mini[i] = min(mini[i], mini[x]);
    }
    return f;
}
void dfs1(int i, vector<vector<int>> &grp, vector<int> &mini, vector<int> &a){

    for(auto x: grp[i]){
        dfs1(x, grp, mini, a);
        if(i == 1)a[i] = mini[i];
        if(mini[x] >= LONG_MAX) a[x] = 0;
        else a[x] = mini[x] - mini[i] ;
    }

}
void solve(){
    int n ; cin>>n;
    vector<vector<int>> grp(n+1);
    foo(i,1,n){
        int x ; cin>>x;
        grp[x].pb(i+1);
    }
    int s[n+1]; foo(i,1,n+1) cin>>s[i]; 
    vector<int> mini(n+1,LONG_MAX);
    bool f = dfs(1, mini, grp, s);
    if(f == false){
        cout<<-1<<ed;
        return ;
    }
    // foo(i,0,n) cout<<mini[i+1]<<ed;
    // memset(vis, 0 , sizeof(vis));
    vector<int> a(n+1,0);
    dfs1(1, grp, mini, a);
    int ans = 0;
    foo(i,0,n) ans += a[i+1];
    cout<<ed<<ans<<ed;
    
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