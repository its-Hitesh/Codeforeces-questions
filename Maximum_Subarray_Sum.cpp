#include <bits/stdc++.h>
#define ll            long long
#define pb            push_back
#define ld            long double
#define sz            size()
#define foo(i,a,b)    for (ll i=a;i<b;i++)
#define pll           pair<ll,ll>
#define ed            "\n"
#define ct            cout
#define m_p           make_pair
#define vi            vector<ll>
#define vpll           vector<pll>
#define ff            first
#define ss            second
#define mod           1000000007
#define int long long
using namespace std;
 
void solve(){
    int n; cin>>n;
    int a[n];
    foo(i,0,n) cin>>a[i];
    int current = a[0],ans=a[0];
    int s =0, temp= 0, r = 0;
    foo(i,1,n){
        if(a[i]+current < a[i]) {
            current = a[i];
            temp = i;
            if(ans < current){
                s = temp;
                r = i;
            }
            ans = max(ans,current);
        }
        else{
            current += a[i];
            if(ans < current){
                s = temp;
                r = i;
            }
            ans = max(ans,current);
        }
    }
    cout<<s<<" "<<r<<endl;
    ct<<ans<<ed;
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
 
  int t =1; //cin>>t;
 
  while(t--){
 
    solve();
 
  }
  return 0;
}