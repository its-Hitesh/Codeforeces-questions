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
const int N = 2e5+2;
int a[N],treee[4*N];
void build(int node,int st,int en){
    if(st==en){
        treee[node] = a[st];
        return;
    }
    int mid = (st+en)/2;
    build(2*node,st, mid);
    build(2*node+1,mid+1,en);
 
    treee[node] = max(treee[2*node] , treee[2*node+1]);
}
int query(int node,int st,int en,int l, int r){  // ans from l to r
    if(st>r || en < l) return INT_MIN ; // not overlapping at all
    if(l <= st && r >= en) return treee[node];
    int mid = (st+en)/2;
    int q1 = query(2*node,st,mid,l,r);
    int q2 = query(2*node+1,mid+1,en,l,r);
    return max(q1,q2) ;
}
void solve(){
    int n, m; cin>>n>>m;
    foo(i,0,m){
        cin>>a[i];      
    }
    build(1,0,m-1);
    int q ; cin >> q ;
    foo(i,0,q){
        int x1, y1, x2, y2, k;
        cin>> x1 >> y1 >> x2 >> y2 >> k;
        if(y1 > y2) swap(y1,y2), swap(x1,x2);
        // cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<k<<ed;
        int req = x1 + (n - x1) % k ;
        int maxa = query(1,0,m-1,y1-1,y2-1);
        // cout<<req<<" "<<maxa<<ed;
        if(((x2 - x1) % k == 0) && ((y2 - y1) % k == 0) && (maxa < req)){
            cout<<"YES"<<ed;
        }
        else cout<<"NO"<<ed;
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