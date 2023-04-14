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
int dx[4] = {1,-1,-1,1};
int n, m;
int st = 0;
bool ff = 0;
int dy[4] = {1,1,-1,-1};
string dd[4] = {"DR","UR","UL","DL"};
vector<int> vd(10000,0), vu(10000,0), vl(10000,0), vr(10000,0);
int dfs(int i, int j, int c, int d, string s){
    cout<<i<<" "<<j<<" "<<c<<" "<<d<<ed;
    if(i == c && j == d){
        ff = true;
        return 0;
    }
    int f = 0;
    if(s == "DR"){
        if(i == n-1 && j == m-1 && st != 0){
            return f;
        }
        else if(i == n - 1 && st != 0){
            if(vd[j] == 1) return f;
            vd[j] = 1;
            f  += dfs(i + dx[1] , j + dy[1], c, d, "UR") + 1;
        }
        else if(j == m - 1 && st != 0){
            if(vr[i] == 1) return f;
            vr[i] = 1;
            f += dfs(i + dx[3], j + dy[3], c, d, "DL") + 1;
        }
        else{
            st = 1;
           f += dfs(i + dx[0], j + dy[0], c, d, "DR");
        }
    }
    else if(s == "DL"){
        if(i == n - 1 && j == 0 && st != 0){
            return f;
        }
        else if(i == n - 1 && st != 0){
            if(vd[j] == 1) return f;
            vd[j] = 1;
            f  += dfs(i + dx[2] , j + dy[2], c, d, "UL") + 1;
        }
        else if(j == 0 && st != 0){
            if(vl[i] == 1) return f;
            vl[i] = 1;
            f += dfs(i + dx[0], j + dy[0], c, d, "DR") + 1;
        }
         else{
            st = 1;
           f += dfs(i + dx[3], j + dy[3], c, d, "DL");
        }
    }
    else if(s == "UR"){
        if(i == 0 && j == m - 1 && st != 0){
            return f;
        }
        else if(i == 0 && st != 0){
            if(vu[j] == 1) return f;
            vu[j] = 1;
            f  += dfs(i + dx[0] , j + dy[0], c, d, "DR") + 1;
        }
        else if(j == m - 1 && st != 0){
            if(vr[i] == 1) return f;
            vr[i] = 1;
            f += dfs(i + dx[2], j + dy[2], c, d, "UL") + 1;
        }
         else{
            st = 1;
           f += dfs(i + dx[1], j + dy[1], c, d, "UR");
        }
    }
    else if(s == "UL"){
        if(i == 0 && j == 0 && st != 0){
            return f;
        }
        else if(i == 0 && st != 0){
            if(vu[j] == 1) return f;
            vu[j] = 1;
            f  += dfs(i + dx[3] , j + dy[3], c, d, "DL") + 1;
        }
        else if(j == 0 && st != 0){
            if(vl[j] == 1) return f;
            vl[j] = 1;
            f += dfs(i + dx[1], j + dy[1], c, d, "UR") + 1;
        }
         else{
            st = 1;
           f += dfs(i + dx[2], j + dy[2], c, d, "UL");
        }
    }
    return f;
}
void solve(){
    int a, b, c, d;
    cin>>n>>m>>a>>b>>c>>d;
    a--;b--;c--;d--;
    string s ; cin>>s;
    foo(i,0,m) vu[i] = vd[i] = 0;

    foo(i,0,n) vl[i] = vr[i] = 0;
    // cout<<"ARSGEh"<<ed;
    st = 0;
    ff= 0 ;
    int f = dfs(a, b, c, d, s);
    cout<< (ff ? f: -1) <<ed;
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