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

const int MAX = 1005;
int dp[MAX][MAX]; // initialise all values to -1 in main()
int fac[MAX];
void fact(){
    fac[0] =1;
    foo(i,1,MAX){
        fac[i] = (fac[i-1]*i);
    }
}

int nCr(int n, int r)
{
    if(r>n)
        return 0;
    if(r==0 || r==n) 
	    return 1;
    if(dp[n][r]!=-1)
        return dp[n][r];
    return dp[n][r]=(nCr(n-1,r) + nCr(n-1,r-1));
}

void solve(){
    int n,k ; cin>>n>>k;
    foo(i,0,MAX){
        foo(j,0,MAX) dp[i][j] = -1;
    }
    fact();
    int ans = 0;
    foo(i,n-k,n+1){            // i is the number of elements on their place 
        int derange = fac[n-i];
        int f = -1;
        foo(j,1,n-i+1){
            derange += (f*fac[n-i]/fac[j]);
            f = -f ;
        }
        int combination = nCr(n,i);
        // cout<<i<<" "<<derange<<" V "<<combination<<ed;
        ans += combination * derange ;    
    }
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

  int tt =1; //cin>>tt;

  while(tt--){

    solve();
  }
  return 0;
}