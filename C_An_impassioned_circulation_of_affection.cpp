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
vector<vector<int>> dp(26,vector<int>(1501,-1));
void solve(){
    int n; cin>>n; 
    string s; cin>>s;
    int k; cin>>k;
    foo(i,0,26){
        bool f = false ;
        foo(j,0,n){
            int cnt = 0;
            if(s[j]-'a' == i){
                f = true ;
                foo(k,j+1,n){
                    if(s[k]-'a' == i){
                        dp[i][k-j-1-cnt] = max(dp[i][k-j-1-cnt],k-j+1);
                        // cout<<i<<" "<<j<<" "<<k<<" "<<k-j-1-cnt<<" "<<k-j+1<<ed;
                        // cout<<k-j-1-cnt<<" "<<dp[i][k-j-1-cnt]<<ed;
                        cnt++;
                    }
                }
            }
        }
        if(f && dp[i][0] == -1)dp[i][0] = 1;
        else if(!f && dp[i][0] == -1) dp[i][0] = 0; 
    }

    foo(i,0,26){
        foo(j,1,n+1){
            dp[i][j] = min(n,max(dp[i][j],dp[i][j-1] + 1));
            // cout<<dp[i][j]<<ed;
        }
    }
    while(k--){
        int x;cin>>x;
        char y; cin>>y;
        cout<<dp[y-'a'][x]<<ed;
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