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
    int n; cin>>n;
    vector<int> b;
    int a[n]; foo(i,0,n) cin>>a[i], b.emplace_back(a[i]);
    int mex = 0;
    sort(b.begin(), b.end());
    foo(i,0,n) if(b[i] == mex) mex++;
    mex++;
    int l = -1, r = -1;
    foo(i,0,n){
        if(a[i] == mex){
            if(l == -1) l = i, r = i;
            else r = i;
        }
    } 

    if(l == -1){
            if(mex - 1== n) cout<<"NO"<<ed;
            else cout<<"YES"<<ed;
            return;
    }
    vector<int> gt;
    foo(i,0,l) gt.emplace_back(a[i]);
    foo(i,r + 1, n) gt.emplace_back(a[i]);
    sort(gt.begin(),gt.end());
    int newmex1 = 0, newmex2 = 0;
    foo(i,0,gt.size()){
        if(gt[i] == newmex1) newmex1++;
    }
    // cout<<ed<<mex<<" "<<newmex1<<ed;
    if(newmex1 == mex) {
        cout<<"YES"<<ed;
        return;
    }
    gt.emplace_back(newmex1);
    sort(gt.begin(),gt.end());
    // for(auto x : gt) cout<<x<<" ";
    foo(i,0,gt.size()){
        // cout<<gt[i]<<" "<<newmex2<<ed;
        if(gt[i] == newmex2) newmex2++;
    }
    // cout<<ed<<newmex2<<ed;
    if(newmex2 == mex) {
        cout<<"YES"<<ed;
    }
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