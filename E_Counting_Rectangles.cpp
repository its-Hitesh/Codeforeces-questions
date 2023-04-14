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
#define int long long
using namespace std;
int mod = 1e9+7;
vector<vector<int> > dp(101,vector<int>(10001,0));
vector<int> a;
int n,x;
int fun(int i,int j){
    if(i > x ) return 0;
    if(i < x && j >= n) return 0;
    if(i==x) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    dp[i][j] = fun(i+a[j],j)+ fun(i,j+1);
    dp[i][j] %= mod;
    return dp[i][j];
 
}
void solve(){
    cin>>n>>x;
    a.resize(n);
    foo(i,0,n) cin>>a[i];
    //sort(a.begin(),a.end());
    vector<vector<int> > previous(2,vector<int>(1000001,0));
    vector<int> current (1000001,0);
    current[x]=1;
    previous[0][x] = 1;
    for(int i=n-1;i>=0;i--){
        for(int j=x-1;j>=0;j--){
            if(j+a[i] <=x ) {
                    current[j] = previous[0][j+a[i]] + previous[1][j];
                    previous[0][j] = current[j]%mod;
            }
 
            //ct<<current[j]<<" ";
        }
        //ct<<ed;
        previous[1]= previous[0];
        //ct<<ed;
    }
    //int ans = fun(0,0);
    ct<<previous[0][0]<<ed;
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