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
vector<int> primes;
bool is_Prime[40000];
void solve(){
    int n; cin>>n;
    int a[n]; foo(i,0,n) cin>>a[i];
    map<int,int> m;
    foo(i,0,n) {
        for(auto x : primes){
            if(a[i] % x == 0){
                // cout<<a[i]<<" "<<x<<" "<<m[x]<<ed;
                m[x]++;
                if(m[x] > 1){
                    cout<<"YES"<<ed;
                    return ;
                }
            }
            while(a[i] % x == 0){
                a[i] /= x;
            }
        }
        if(a[i] > 1) m[a[i]]++;
        if(m[a[i]] > 1){
            cout<<"YES"<<ed;
            return ;
        }
    }
    cout<<"NO"<<ed;
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
    for(int i=0;i<=40000;i++) is_Prime[i]=true;
    is_Prime[0]=false;
    is_Prime[1]=false;
    for(int i=2;i*i<=40000;i++){
        if(is_Prime[i]==true){
            for(int j=i*i;j<=40000;j+=i) is_Prime[j]=false;
        }
    }
    foo(i,2,40000){
        if(is_Prime[i]) primes.pb(i);
    }
    int l = primes.size();
  int tt =1; cin>>tt;

  while(tt--){

    solve();
  }
  return 0;
}