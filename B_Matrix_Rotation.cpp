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
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int s1[4],s2[4],s3[4],s4[4];
    s1[0] = a; s1[1] = b; s1[2] = d; s1[3] = c;  
    s2[0] = c; s2[1] = a; s2[2] = b; s2[3] = d;  
    s3[0] = d; s3[1] = c; s3[2] = a; s3[3] = b;  
    s4[0] = b; s4[1] = d; s4[2] = c; s4[3] = a;  

    if(s1[0] < s1[1] && s1[1] < s1[2] && s1[3] < s1[2] && s1[0] < s1[3]) cout<<"YES"<<ed;
    else if(s2[0] < s2[1] && s2[1] < s2[2] && s2[3] < s2[2] && s2[0] < s2[3]) cout<<"YES"<<ed;
    else if(s3[0] < s3[1] && s3[1] < s3[2] && s3[3] < s3[2] && s3[0] < s3[3]) cout<<"YES"<<ed;
    else if(s4[0] < s4[1] && s4[1] < s4[2] && s4[3] < s4[2] && s4[0] < s4[3]) cout<<"YES"<<ed;
    else cout<<"NO"<<ed;

    
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