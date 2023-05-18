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
const int N = 1001;
int bit[N][N];
int n, q; 
void update(int x, int y, int val){
    while(x <= n){
        int y1 = y;
        while(y1 <= n){
            bit[x][y1] += val;
            y1 += (y1 & (-y1));
        }
        x += (x & (-x));
    }
}

int sum(int x, int y){
    int res = 0;
    while(x > 0){
        int y1 = y ;
        while(y1 > 0){
            res += bit[x][y1];
            y1 -= (y1 & (-y1));
        }
        x -= (x & (-x));
    }
    return res;
}

void solve(){
    cin>>n>>q;
    int a[n + 1][n + 1];
    string s[n]; foo(i,0,n) cin>>s[i];
    foo(i,0,n) foo(j,0,n) {
        if(s[i][j] == '*')  a[i + 1][j + 1] = 1, update(i + 1, j + 1, 1); 
        else a[i + 1][j + 1] = 0;
    }
    foo(i,0,q){
        int ty; cin>>ty;
        if(ty == 1){
            int x ,y; cin>>x>>y;
            if(a[x][y] == 1){
                a[x][y] = 0;
                update(x, y, -1);
            }
            else{
                a[x][y] = 1;
                update(x, y, 1);
            }
        }
        else{
            int x1, x2, y1, y2; cin>>x1>>y1>>x2>>y2;
            cout<<sum(x2,y2) - sum(x2 ,y1 - 1) - sum(x1 - 1, y2) + sum(x1 - 1, y1- 1)<<ed;
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