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
int cnt =0;
int n; 
int fun(int r1, int r0, int w1, int w0,int chk){
    int cnt =0 ;
    foo(i,0,n+1){
        if(w1==0 && w0==0) return cnt;
        if(chk){
            if(r1!=0){
                int temp=r1;
                r1 = w0+1;
                swap(r0,w1);
                w0 = temp - 1;
                cnt++;
            }
            else break;
        }
        else{
            if(w1!=0){
                int temp = w1;
                w1 = r0 +1;
                swap(w0,r1);
                r0 = temp - 1;
                cnt++;
            }
            else break;
        }
        chk = 1- chk;
    }
    if(w1!=0 || w0!=0) return -1;
    return cnt;
}
void solve(){
    cin>>n;
    string a,b; cin>>a>>b;
    int r0=0,r1=0,w0=0,w1=0;
    foo(i,0,n){
        if(a[i]==b[i]){
            if(a[i]=='1') r1++;
            else r0++;
        }
        else{
            if(a[i]=='0') w0++;
            else w1++;
        }
    }
    int cnt1 =0,cnt2=0;
    cnt1 = fun(r1,r0,w1,w0,1);
    cnt2 = fun(r1,r0,w1,w0,0);
    if(cnt1!=-1 && cnt2 !=-1) cout<<min(cnt1,cnt2)<<ed;
    else {
        if(cnt1 != -1) cout<<cnt1<<ed;
        else if(cnt2 != -1) cout<<cnt2<<ed;
        else cout<<-1<<ed; 
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

  int tt =1; cin>>tt;

  while(tt--){

    solve();
  }
  return 0;
}