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

void findNums(int X, int Y)
{
 
    // Initialize the two numbers
    int A, B;
 
    // Case 1: X < Y
    if (X < Y) {
        A = -1;
        B = -1;
    }
 
    // Case 2: X-Y is odd
    else if (abs(X - Y) & 1) {
        A = -1;
        B = -1;
    }
 
    // Case 3: If both Sum and XOR
    // are equal
    else if (X == Y) {
        A = 0;
        B = Y;
    }
 
    // Case 4: If above cases fails
    else {
 
        // Update the value of A
        A = (X - Y) / 2;
 
        // Check if A & Y value is 0
        if ((A & Y) == 0) {
 
            // If true, update B
            B = (A + Y);
        }
 
        // Otherwise assign -1 to A,
        // -1 to B
        else {
            A = -1;
            B = -1;
        }
    }
 
    // Print the numbers A and B
    if(A == -1) cout<<-1<<ed;
    else cout << A << " " << B<<ed;
}

void solve(){
    int n; cin>>n;
    findNums(n*2, n);
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