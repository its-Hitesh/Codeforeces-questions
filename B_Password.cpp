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
    string s ; cin>>s;
    int n = s.size();
    // vector<int> z(n);
    // for(int i = 1, l = 0, r = 0; i < n; ++i){
    //     if( i <= r)
    //          z[i] = min(r - i + 1, z[i - l]);
    //     while(i + z[i] < n && s[z[i]] == s[i + z[i]]) 
    //         ++z[i];
    //     if(i + z[i] - 1 > r)
    //         l = i , r = i + z[i] - 1;    
    // }

    vector<int> lps(n);

    foo(i,1,n){
        int j = lps[i-1];
        while(j > 0 && s[i] != s[j]) j = lps[j - 1];
        if(s[i] == s[j]) j++;
        lps[i] = j;
    }

    foo(i,0,n) cout<<lps[i]<<" ";

    if(lps[n-1] == 0){
        cout<<"Just a legend"<<ed;
    }
    else{
        foo(i,1,n-1) if(lps[i] == lps[n-1]) {
            foo(i,0,lps[n-1]) cout<<s[i];
            return;
        }
        if(lps[lps[n-1]-1] == 0){
            cout<<"Just a legend"<<ed;   
        }   
        else{
            foo(i,0,lps[lps[n-1]-1]) cout<<s[i];
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

  int tt =1; //cin>>tt;

  while(tt--){

    solve();
  }
  return 0;
}