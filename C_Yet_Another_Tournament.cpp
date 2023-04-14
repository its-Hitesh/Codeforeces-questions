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
int n, k, cnt;
bool good(int x, int b[], map<int,int> & m, vector<pair<int,int>> &a){
    // cout<<x<<" "<<cnt<<ed;
    if(m[x] == 1) x--;
    if(x <= cnt) return true ;
    else{
        if(m[x] == 1) return false ;
    }
    int t = k, i = 0;
    int cnt2 = 0;
    t -= b[x];
    while(t > 0 && i < n){
        cnt2++;
        t -= a[i].first;
    }
    if(cnt2 >= x-1) return true ;
    return false ;
}
void solve(){
    cin>>n>>k;
    int b[n+1];
    vector<pair<int,int>> a(n);
    foo(i,0,n) cin>>a[i].first, a[i].second = i+1,b[i+1] = a[i].first;
    sort(a.begin(),a.end());
    cnt = 0;
    int t = k,i = 0;
    unordered_map<int,int> m;
    while(t >= 0 && i < n){
        t -= a[i].first;
        if(t >= 0) {
            m[a[i].second] = 1; 
            cnt++;
        }
        i++;
    }
    int l =1, r = n;
    int ans = 0;
    // while(l <= r){
    //     int mid = l +(r-l)/2;
    //     if(good(mid,b,m,a)){
    //         ans = max(ans,mid);
    //         l = mid + 1;
    //     }
    //     else r = mid - 1;
    // }
    if(cnt == 0){
        cout<<n+1<<ed;
        return ;
    } 
    foo(i,cnt,n+1){
        int x = i;
        if(m[i] == 1) x--;
        if(x <= cnt){
            ans = max(ans, i);
            // else ans = max(cnt + 1, ans);
            continue;
        }
        else{
            if(m[i] == 1) break;
        }
        int t = k, j = 0;
        int cnt2 = 0;
        t -= b[i];

        while(t >= 0 && j < n){
            cnt2++;
            t -= a[j].first;
            j++;
        }
        // cout<<cnt<<" "<<cnt2<<" "<<t<<" "<<ans<<" "<<x<<ed;
        if(cnt2 >= x-1 && cnt2 != 0){
            ans = max(i, ans);
            // else ans = max(ans,cnt2 + 1);
        }
        
    }
    cout<< max((int)1,n - ans + 1)<<ed;   

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