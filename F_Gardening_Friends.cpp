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

void bfs(vector<int> grp[], int st, int &fend, int n){
    queue<int> q;
    vector<int> v(n, 0);
    q.push(st);
    v[st] = 1;                                       // finding diameters of the tree using 2bfs
    while(!q.empty()){
        int t = q.front();
        fend = t;
        q.pop();
        for(auto x : grp[t]){
            if(v[x] == 0){
                v[x] = 1;
                q.push(x);
            }
        }
    }
}
void disbfs(vector<int> grp[], int st, int n, int dis1[]){
    queue<int> q;
    vector<int> v(n, 0);
    q.push(st);
    int d = -1;
    v[st] = 1;
    while(!q.empty()){
        int s = q.size();                                   //finding distance of each node from diameters  
        d++;
        for(int i = 0; i < s; i++){
            int t = q.front();
            dis1[t] = d;
            q.pop();
            for(auto x : grp[t]){
                if(v[x] == 0){
                    v[x] = 1;
                    q.push(x);
                }
            }
        }    
    }
}
void solve(){
    int n, m, c; cin>>n>>m>>c;
    vector<int> grp[n];
    foo(i, 0, n - 1){
        int x, y; cin>>x>>y;
        x--; y--;
        grp[x].pb(y);
        grp[y].pb(x);
    }
    int dis1[n] = {}, dis2[n] = {}, dis3[n] ={}, a = 0, b = 0;
    bfs(grp, 0, a, n);
    bfs(grp, a, b, n);
    disbfs(grp, 0, n, dis1);
    disbfs(grp, a, n, dis2);
    disbfs(grp, b, n, dis3);
    int ans = 0;
    foo(i,0,n){
        ans = max(ans, max(dis2[i],dis3[i])*m - dis1[i] * c);
    }
    cout<<ans<<ed;
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