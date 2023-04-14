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
    string alp = "abcdefghijklmnopqrstuvwxyz";
    vector<char> ans(n, '!');
    vector<int> cnt(26);
    for(auto x : s){
        cnt[(x - 97)]++;
    }
    queue<char> oodchar;
    int l = 0, k = n - 1, cntood = 0;
    foo(i,0,26){
        if(cnt[i] == 0) continue;
        int temp = cnt[i];
        if(temp & 1){
            temp--;
            oodchar.push(alp[i]);
            cnt[i] = 1;
            cntood++;
        }
        // cout<<alp[i]<<" "<<cnt[i]<<" "<<cntood<<" "<<ed;
        while(temp > 1){
            ans[l] = ans[k] = alp[i];
            l++; k--;
            temp /= 2;
        }
        if(cntood % 2 == 0 && cntood > 1){
            ans[l] = oodchar.front();
            oodchar.pop();
            ans[k] = oodchar.front();
            oodchar.pop();
            cntood -= 2;
            l++; k--;
        }
    }
    if(cntood == 1){
        foo(i,0,n){
            if(ans[i] == '!') {
                ans[i] = oodchar.front();
                break;
            }
        }
    }
    for(auto x : ans) cout<<x;
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