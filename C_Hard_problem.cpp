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
#define all(x)         x.begin(),x.end()
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
int const M = 1e18;
void solve(){
    int n ; cin >>n;
    int cost[n]; foo(i,0,n) cin>>cost[i];
    vector<string> s(n);
    foo(i,0,n) cin>>s[i];; 
    vector<vector<int>>dp(n,vector<int>(2,M));
    dp[0][0] = 0;
    dp[0][1] = cost[0];
    foo(i,1,n){
        string rev1 = "";
        string rev2 = "";
        string rev3 = "";
        for(int j=s[i-1].size()-1;j>=0;j--) rev1 +=s[i-1][j];
        for(int j=s[i].size()-1;j>=0;j--) rev2 +=s[i][j];
        // for(int j=s[i+1].size()-1;j>=0;j--) rev3 +=s[i][j];
        if( s[i-1] <= s[i]) {
            dp[i][0] = min(dp[i][0],dp[i-1][0]);
        }
        if(rev1 <= s[i])dp[i][0] = min(dp[i][0],dp[i-1][1]);
        if(s[i-1] <= rev2) {
            dp[i][1] = min(dp[i][1],dp[i-1][0]+ cost[i]) ;
        }
        if(rev1 <= rev2)dp[i][1] = min(dp[i][1],dp[i-1][1]+ cost[i]) ;

        //cout<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<ed;
        if(dp[i][1] == M && dp[i][0] == M) {
            cout<<-1<<ed;
            return ;
        }
    }
    cout <<min(dp[n-1][0],dp[n-1][1])<<ed;
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