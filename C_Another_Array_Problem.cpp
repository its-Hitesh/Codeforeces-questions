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
    ll n;cin>>n;
   ll a[n];
   for(ll i=0;i<n;i++) cin>>a[i];
   ll mx=0;
   ll c;
   if(n==2)
   {
      c=a[0]-a[1];
      if(c<0)  
         c=-c;
      cout<<max(a[0]+a[1],c*2)<<'\n';
      return;
   }
   if(n==3)
   {
      ll ans=0;
      ans=max(max(ans,a[0]+a[1]+a[2]),max(max(ans,a[0]*3),max(ans,a[2]*3)));
      c=a[0]-a[1];
      if(c<0)
         c*=-1;
      ans=max(max(ans,c*2+a[2]),max(ans,c*3));
      c=a[1]-a[2];
      if(c<0)
         c*=-1;
      ans=max(max(ans,c*2+a[0]),max(ans,c*3));
      cout<<ans<<'\n';
      return;
   }
   mx=0;
   for(ll i=0;i<n;i++)
      mx=max(mx,a[i]);
   cout<<mx*n<<'\n';
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