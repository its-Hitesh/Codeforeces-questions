#include <bits/stdc++.h>
// #include <bits/extc++.h>//
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
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

// // for fast hashing
// const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
// struct chash { // To use most bits rather than just the lowest ones:
//     const uint64_t C = ll(4e18 * acos(0)) | 71; // large odd number
//     ll operator()(ll x) const { return __builtin_bswap64((x^RANDOM)*C); }
// };
// template<class K,class V> using ht = gp_hash_table<K,V,chash>;
// //__gnu_pbds::gp_hash_table<ll, int, chash> ht({},{},{},{}, {1 << 16});

// //oset<int>s:s.find_by_order(k):Kth element in "s",s.order_of_key(k):Number of item strictly lessthan k
// template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

void solve(){
    int n; cin>>n;
    map<int,int> m,used;
    bool f = true , f2 = false ;
    int a[n]; 
    foo(i,0,n) {
        cin>>a[i];
        m[a[i]]++;
        if(m[a[i]] > 2){
            f2 = true ;
        }
        if(m[a[i]] > 1) f = false ;
    }

//     set<int> st;
//     for(int i=1;i<=n;i++)
// {
//     if(m[i]==0)st.insert(i);
// }    // if(f){
    //     cout<<"YES"<<ed;
    //     foo(i,0,n) cout<<a[i]<<" ";
    //     cout<<ed;
    //     foo(i,0,n) cout<<a[i]<<" ";
    //     cout<<ed;
    //     return;
    // }
    // vector<int> sortage(n+1,0);
    // int a1[n],a2[n];
    // map<int,int>an;
    // for(int i=0;i<n;i++){
    //     if(m[a[i]]==1){
    //         a1[i]=a[i];
    //         a2[i]=a[i];
    //     }else if(m[a[i]]==2){
    //         auto j = upper_bound(st.begin(),st.end(),a[i]);
    //         if(j==st.begin()){
    //             cout<<"NO\n";
    //             return;
    //         }
    //         j--;
    //         a1[i]=a[i];
    //         a2[i]=*j;
    //         an[a[i]]=*j;
    //         m[a[i]]=0;3
    //     }else{
    //         a2[i]=a[i];
    //         a1[i]=an[a[i]];
    //     }
    // }
    // cout<<"YES\n";
    // for(int i=0;i<n;i++)cout<<a1[i]<<" ";
    // cout<<'\n';
    // for(int i=0;i<n;i++)cout<<a2[i]<<" ";
    // cout<<'\n';

    if(f2){
            cout<<"NO"<<ed;
            return ;
    }
    vector<int> ans(n+1);
    queue<int> s;
    foo(i,1,n+1){
        if(m[i] == 0){
            // sortage[i] = sortage[i-1] + 1;
            s.push(i);
        }
        else if(m[i] == 2){
            if(s.empty()){
                cout<<"NO"<<ed;
                return;
            }
            else{
                ans[i] = s.front();
                // ans2[s.front()] = i;
                s.pop();
            }
        }
    }
    cout<<"YES"<<ed;
    vector<int> show(n),show2(n);
    foo(i,0,n){
        if(m[a[i]] == 1){
            show[i] = show2[i] = a[i];
            m[a[i]] = -1;
        }
    }
    foo(i,0,n){
        if(m[a[i]] == 2){
            show[i] = a[i];
            m[a[i]]--;
        }
        else if(m[a[i]] == 1){
            show2[i] = a[i];
        }
    }
    foo(i,0,n){
        if(show[i] == 0){
            show[i] = ans[a[i]];
        }
        if(show2[i] == 0){
            show2[i] = ans[a[i]];
        }
    }
    foo(i,0,n) cout<<show[i]<<" ";
    cout<<ed;
    foo(i,0,n) cout<<show2[i]<<" ";
    cout<<ed;
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