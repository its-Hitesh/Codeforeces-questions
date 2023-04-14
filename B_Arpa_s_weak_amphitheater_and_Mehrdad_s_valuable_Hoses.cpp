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


void solve(){
    int n,x;
    cin>>n>>x;
 
    vector<int> page(n),price(n);
    int a,b;
 
    for(int&i : price)
    cin>>i;
 
    for(int&i : page)
    cin>>i;
 
    vector<int> dp(n+1,0);
 
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            //option1 = book number i-1 is not included, hence no pages added.
            //option2 = book number i-1 is included, hence pages are added.
            //option1 = dp[i-1][j] ...book not included so total price(j) remains same.
            //option2 = dp[i-1][j-price[i-1]] + page[i-1]....total price(j) decreased and pages are counted for book i-1.
 
            dp[j] = dp[i-1];
            if(j >= price[i-1])
            {
                dp[j] = max (dp[j],dp[j-price[i-1]] + page[i-1]); //max of both the boxes included in dp[i][j].
            }
        }
    }
 
    cout<< dp[x]<<endl;
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