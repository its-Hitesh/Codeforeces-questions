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
    int n,maxa=0,idx=0; cin>>n;
    map<int,int> m;
    vector<int> a(n),ans; 
    foo(i,0,n) {
        cin>>a[i];
        if(maxa < a[i]){
            maxa = a[i];
            idx = i;
        }
    }
    ans.pb(maxa);
    m[idx] = 1;
    int andd=0;
    foo(i,0,31){
        if((maxa & (1<<i))==0 && (1<<i <= maxa)) {
            //cout<<"gasfdh"<<ed;
            andd = andd | (1<<i);
        }
    }
    //cout<<andd<<ed;
    if(andd==0){
        for(auto x : ans) cout<<x<<" ";
        foo(i,0,n){
            if(m[i]==0){
                cout<<a[i]<<" ";
            }
        }
        cout<<ed;
        return ;
    }
    int prev = -1;
    while(1){
        //cout<<prev<<" "<<andd<<ed;
        if(prev != andd && andd !=0){
            int temp = 0, tempidx=0;
            foo(i,0,n){
                if(m[i]==0){
                    if(temp < (andd & a[i])){
                        temp = (andd & a[i]);
                        tempidx = i;
                    }
                }
            }
            if(temp != 0){
                ans.pb(a[tempidx]);
                m[tempidx] = 1;
            }
            prev = andd;
            andd ^= temp;
        }
        else break;
    }
    for(auto x : ans) cout<<x<<" ";
    foo(i,0,n){
        if(m[i]==0){
            cout<<a[i]<<" ";            
        }
    }
    cout<<ed;
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
