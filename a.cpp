// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         sort(begin(nums), end(nums));
//         return kSum(nums, target, 0, 4);
//     }
	
//     vector<vector<int>> kSum(vector<int>& nums, long long target, int start, int k) {
//         vector<vector<int>> res;
        
//         // If we have run out of numbers to add, return res.
//         if (start == nums.size()) {
//             return res;
//         }
        
//         // There are k remaining values to add to the sum. The 
//         // average of these values is at least target / k.
//         long long average_value = target / k;
        
//         // We cannot obtain a sum of target if the smallest value
//         // in nums is greater than target / k or if the largest 
//         // value in nums is smaller than target / k.
//         if  (nums[start] > average_value || average_value > nums.back()) {
//             return res;
//         }
            
//         if (k == 2) {
//             return twoSum(nums, target, start);
//         }
    
//         for (int i = start; i < nums.size(); ++i) {
//             if (i == start || nums[i - 1] != nums[i]) {
//                 for (vector<int>& subset : kSum(nums, static_cast<long long>(target) - nums[i], i + 1, k - 1)) {
//                     res.push_back({nums[i]});
//                     res.back().insert(end(res.back()), begin(subset), end(subset));
//                 }
//             }
//         }
                                            
//         return res;
//     }
	
//     vector<vector<int>> twoSum(vector<int>& nums, long long target, int start) {
//         vector<vector<int>> res;
//         int lo = start, hi = int(nums.size()) - 1;
    
//         while (lo < hi) {
//             int curr_sum = nums[lo] + nums[hi];
//             if (curr_sum < target || (lo > start && nums[lo] == nums[lo - 1])) {
//                 ++lo;
//             } else if (curr_sum > target || (hi < nums.size() - 1 && nums[hi] == nums[hi + 1])) {
//                 --hi;
//             } else {
//                 res.push_back({ nums[lo++], nums[hi--] });
//             }
//         }
                                                           
//         return res;
//     }
// };
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
    // vector<vector<int>> ans ;
    // vector<int> a(2,-1);
    // foo(i,0,3){
    //     ans.pb({i});
    //     ans.back().insert(end(ans.back()), begin(a), end(a));
    //     foo(j,0,ans.back().size())
    //         cout<<ans.back()[j]<<" ";
    //     cout<<ed;    
    // }
    char a , b;
    (a,b) = {'a', 'b'};
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