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
struct Node
{
    /* data */
    int frq;
    unordered_map<int,Node*> child;
    Node(){
        frq = 0;
    }
};

void solve(){
    int n; cin>>n;
    Node * root = new Node();
    Node * temp;
    while(n--){
        string c, s;
        cin>>c>>s;
        temp = root;
        if(c == "add"){
            foo(i,0,s.size()){
                if(temp->child[s[i] - 'a'] == NULL) {
                    Node * z = new Node();
                    temp->child[s[i] - 'a'] = z;
                }
                temp = temp->child[s[i] - 'a'];
                temp->frq += 1;
            }
        }
        else{
            int ans = 0;
            foo(i,0,s.size()){
                if(temp->child[s[i] - 'a'] == NULL){
                    ans = 0 ;
                    break;
                }
                temp = temp->child[s[i] - 'a'];
                ans = temp->frq;
            }
            cout<<ans<<ed;
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