#include <bits/stdc++.h>
#define ll            long long
#define pb            push_back
#define ld            long double
#define foo(i,a,b)    for (ll i=a;i<b;i++)
#define pll           pair<ll,ll>
#define ed            "\n"
#define ct            cout
#define m_p           make_pair
#define vi            vector<ll>
#define vpll           vector<pll>
#define ff            first
#define ss            second
#define pi            3.14159265359
#define mod           998244353
using namespace std;
#define int long long


void solve(){
    int n;
    cin>>n;
    int a[n];
    foo(i,0,n) cin>>a[i];
    vector<int> prefix1,prefix2;
    prefix1.pb(0);         //  for even indexes
    prefix2.pb(0);         //  for odd
    for(int i=1;i<n;i+=2){
        prefix1.pb(a[i]-a[i-1]);
    }
    for(int i=2;i<n;i +=2) prefix2.pb(a[i-1]-a[i]);
    foo(i,1,prefix1.size()) prefix1[i] += prefix1[i-1];
    foo(i,1,prefix2.size()) prefix2[i] += prefix2[i-1];
    int ans = 0,currsum =prefix1[1],minprefix =0;
    if(prefix1.size()==1) currsum =0;
    for(int i=1;i<prefix1.size();i++){
        currsum = max(currsum,prefix1[i]-minprefix);
        minprefix = min(minprefix,prefix1[i]);
    }
    ans = max((int)0,currsum);
    currsum =prefix2[1];
    minprefix =0;
    if(prefix2.size()==1) currsum =0;
    for(int i=1;i<prefix2.size();i++){
        currsum = max(currsum,prefix2[i]-minprefix);
        minprefix = min(minprefix,prefix2[i]);
    }
    /*for(auto x : prefix1) ct<<x<<" ";
    ct<<ed;
    for(auto x : prefix2) ct<<x<<" ";
    ct<<ed;
    */
    ans = max(ans , currsum);
    for(int i=0;i<n;i+=2) ans += a[i];
    ct<<ans<<ed;
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

   //freopen("input.txt", "r", stdin);
   //freopen("output.txt", "w", stdout);



  int t =1;  cin>>t;

  while(t--){


    solve();

  }
  return 0;
}