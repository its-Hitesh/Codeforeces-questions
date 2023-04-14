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
vector<vector<int>> dp(16,vector<int>(2,-1));
vector<pair<int,int> > p(16);
int n,m,cnt=0;
int fun(int x, int prev){
    // cout<<p[x].first<<" "<<x<<ed;
    if(x == 0) return p[0].first+ abs(p[x].first+p[x].second - m - 1);
    if(dp[x][prev] != -1) return dp[x][prev];
    dp[x][prev] = 0;
    if(prev == 0) {
        if(p[x].first != 0) 
            {
                dp[x][prev] = p[x].first + p[x-1].first +1+cnt;
                cnt =0;
            }
        else{
            cnt++;
        }
    }
    if(prev == 1) {
        if(p[x].first != 0 )
        {
            dp[x][prev] = p[x].second + p[x-1].second +1+cnt;
            cnt=0;
        }
        else{
            cnt++;
        }
    }
    int temp = min(fun(x-1,0),fun(x-1,1)) + abs(p[x].first+p[x].second - m - 1);
    // cout<<x<<" "<<prev<<" "<<temp<<" "<<dp[x][prev]<<ed; 
    dp[x][prev] += temp;
    return dp[x][prev]; 

}
void solve(){
     cin>>n>>m;
    vector<string> s(n);
    for(int i= n-1; i >= 0; i--) cin>>s[i];
    
    
    foo(i,0,n){
        int l= 0, r = m+1;
        foo(j,0,m+2){
            if(s[i][j] == '1'){
                l= j;
                break;
            }
        }
        for(int j = m+1 ; j >= 0 ; j--){
            if(s[i][j] == '1'){
                r = m+1 - j;
                break;
            }
        }
        p[i] = m_p(l,r);
    }

    // foo(i,0,n) cout<<p[i].first<<" "<<p[i].second<<ed;
    int ans = min(fun(n-1,0),fun(n-1,1));
    cout<<ans<<ed;


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

  int tt =1;// cin>>tt;

  while(tt--){

    solve();
  }
  return 0;
}