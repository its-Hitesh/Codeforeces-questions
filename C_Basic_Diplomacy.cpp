#include <bits/stdc++.h>
#include <bits/extc++.h>//
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using ll = long long ;
#define pb            push_back
#define ld            long double
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
int cnt[200005];
bool comp(int &a, int &b){
    if(cnt[a] <= cnt[b]) return true ;
    return false ;
}
void solve(){
    int n, m; cin>>n>>m;
    memset(cnt, 0, sizeof(cnt));
    vector<vector<int>> frd(n+5);
    foo(i,0,m){
        int x ; cin>>x;
        foo(j,0,x){                                 // runtime error is coming just check it once
            cnt[i+1] += 1;
            int y ; cin>>y;
            frd[y].pb(i+1);
        }
    }
    foo(i,1,n+1){
        sort(frd[i].begin(),frd[i].end(), comp);
    }
    vector<int> ans(m, -1);
    foo(i,1,n+1){
        int sz = frd[i].size();
        int j = 0, cntt = 0;
        // cout<<"size"<<" "<<sz<<ed;
        while(j < sz && cntt < m/2){
            if(ans[frd[i][j]] == -1){
                cntt++;
                ans[frd[i][j]] = i;
            // cout<<frd[i][j]<<" ";
            }
            j++;    
        }
        // cout<<ed;
    }
    bool f = true ;
    foo(i,1,m+1){
        if(ans[i] == -1){
            f = false ;
            break;
        }
    }
    if(f){
        cout<<"YES"<<ed;
        foo(i,1,m+1) cout<<ans[i]<<" ";
        cout<<ed;
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