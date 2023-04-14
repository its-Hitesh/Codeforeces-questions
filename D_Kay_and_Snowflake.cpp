#include <bits/stdc++.h>
#include <bits/extc++.h>//
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using ll = long long ;
#define pb            push_back
#define ld            long double
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
vector<int> grp[300005];
int par[300005], sz[300005];
int worst[300005];
int ans[300005];

void dfs(int n, int p){
    sz[n] = 1;
    worst[n] = 0;
    for(auto x : grp[n]){
        dfs(x, n);
        sz[n] += sz[x];
        worst[n] = max(worst[n], sz[x]);
    }
    int req = sz[n] / 2;
    if(worst[n] <= req) ans[n] = n;                             // n is the centroid 
    else{
        for(auto x : grp[n]){
            if(sz[x] == worst[n]){
                int targ = ans[x];
                while(1){                                      // one of the ancestor of the centroid of the n will be the centeroid of the n
                    int above = sz[n] - sz[targ];
                    int below = worst[targ];
                    if(max(above, below) <= req) break;
                    targ = par[targ];
                }
                ans[n] = targ;
                break;
            }
        }
    }
    // cout<<n<<" "<<worst[n]<<" "<<sz[n]<<" "<<ans[n]<<ed;
}
void solve(){
    int n, q;
    cin>>n>>q;
    foo(i,0,n-1){
        int x ; cin>> x;
        x--;
        par[i+1] = x;
        grp[x].pb(i+1);
    }

    dfs(0, -1);

    foo(i,0,q){
        int b; cin>>b;
        cout<<ans[b-1]+1<<ed;
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