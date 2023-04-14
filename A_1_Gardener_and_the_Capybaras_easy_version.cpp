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
    string s; cin>>s;
    int n = s.size();
    if(s[0] == 'a'){
        bool f1 = true, f2 = false ;
        foo(i,1,n){
            if(s[i] == 'b') f1 = false ;  // not all are same 
            if(f1 == false && s[i] == 'a') f2 = true ;   // true a, b, a
        }
        if(f1){
            cout<<s[0]<<" ";
            foo(i,1,n-1) cout<<s[i];
            cout<<" "<<s[n-1]<<ed;
        }
        else if(f1 == false && f2 == true ){
            int i = 0;
            for(i;i<n;i++){
                if(s[i] == 'b') break;
                cout<<s[i];
            }
            cout<<" ";
            for(i;i<n;i++){
                if(s[i] == 'a') break;
                cout<<s[i];
            }
            cout<<" ";
            for(i;i<n;i++) cout<<s[i];
            cout<<ed;
        }
        else{
            int i = 1;
            if(s[i] == 'b'){
                cout<<s[0]<<" ";
                for(i;i<n-1;i++){
                    cout<<s[i];
                }
                cout<<" "<<s[n-1]<<ed;
            }
            else {
                for(i; i<n; i++){
                    if(s[i] == 'b') break;
                    cout<<s[i];
                }
                cout<<" "<<'a'<<" ";
                for(i;i<n;i++) cout<<s[i];
                cout<<ed;
            }
        }
    }
    else{
        bool f1 = true, f2 = false ;
        foo(i,1,n){
            if(s[i] == 'a') f1 = false ;  // not all are same 
            if(f1 == false && s[i] == 'b') f2 = true ;   // true b, a, b
        }
        if(f1){
            cout<<s[0]<<" ";
            foo(i,1,n-1) cout<<s[i];
            cout<<" "<<s[n-1]<<ed;
        }
        else if(f1 == false && f2 == true ){
            int i = 0;
            for(i;i<n;i++){
                if(s[i] == 'a') break;
                cout<<s[i];
            }
            cout<<" ";
            for(i;i<n;i++){
                if(s[i] == 'b') break;
                cout<<s[i];
            }
            cout<<" ";
            for(i;i<n;i++) cout<<s[i];
            cout<<ed;
        }
        else{
            int i = 1;
            if(s[i] == 'a'){
                cout<<s[0]<<" ";
                cout<<" "<<s[n-1]<<" ";
                for(i;i<n-1;i++){
                    cout<<s[i];
                }
                cout<<ed;
            }
            else {
                cout<<'b'<<" ";
                for(i; i<n; i++){
                    if(s[i] == 'a') break;
                    cout<<s[i];
                }
                cout<< " ";
                for(i;i<n;i++) cout<<s[i];
                cout<<ed;
            }
        }
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