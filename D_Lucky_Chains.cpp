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
const int N = 10000010;
int is_Prime[N];
int GCD(int a,int b){
    if(b==0) return a;
    return GCD(b,a%b);
}
void solve(){
    int xx,y; cin>>xx>>y;
    int differ = abs(xx-y);
    int temp = differ ;
    if(differ == 1){
        cout<<-1<<ed;
        return ;
    }
    if(GCD(xx,y) > 1){
        cout<<0<<ed;
        return ;
    }
    set<int> factors;
    while (differ != 1)
    {
        factors.insert(is_Prime[differ]);
        differ = differ / is_Prime[differ];
    }
    if(differ > 1) factors.insert(differ);
    int ans = INT_MAX;
    for(auto z : factors){
        if(xx%z == 0) ans = 0;
        ans = min((z - (xx%z)), ans);
        // cout<<ans<<ed;
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

  int tt =1; cin>>tt;
    for(int i=0;i<=N;i++) is_Prime[i]=i;
    for(int i=2;i*i<=N;i++){
        if(is_Prime[i]==i){
            for(int j=i*i;j<=N;j+=i) is_Prime[j]=i;
        }
    }
  while(tt--){

    solve();
  }
  return 0;
}   