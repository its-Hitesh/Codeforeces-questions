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
int mini(int x){
    int mini = 10;
    while(x > 0){
        mini = min(mini,x%10);
        x /= 10;
    }
    return mini;
}
int maxa(int x){
    int maxa = 0;
    while(x > 0){
        maxa = max(maxa,x%10);
        x /= 10;
    }
    return maxa;
}
void solve(){
    int n , m;
    cin>>n>>m;
    if(m >= n * 10){
        int temp = n;
        while(temp >= 10) temp /= 10;
        int temp2 = temp;
        while(temp < n){
            temp*= 10;
            temp += temp2;
        }
        cout<<temp<<ed;
    }
    else{
        int temp = n, temp2 = m;
        while(temp >= 10) temp /= 10, temp2 /= 10;
        if(temp2 - temp > 1){
            temp++;
            int temp2 = temp;
            while(temp < n){
                temp*= 10;
                temp += temp2;
            }
            cout<<temp<<ed;
        }
        else if(temp2 - temp == 0){
            int ans = temp, put = 0;
            int a[18]= {}, b[18] = {};
            temp = 1; int cnt = 0;
            while(temp < n) temp *= 10, cnt++;
            cnt--;
            int num = cnt;
            int f = n, s =m;
            while(cnt >= 0){
                a[cnt] = f % 10;
                f /= 10;
                b[cnt] = s % 10;
                s /= 10;
                cnt--;
            }
            foo(i,1,num){
                
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