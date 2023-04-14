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
#define MAX           200005
#define int long long
inline long long  MAX2(long long  a, long long  b){return (a)>(b)?(a):(b);}
inline long long  MAX3(long long  a, long long  b,long long  c){return (a)>(b)?((a)>(c)?(a):(c)):((b)>(c)?(b):(c));}
inline long long  MIN2(long long  a, long long  b){return (a)<(b)?(a):(b);}
inline long long  MIN3(long long  a, long long b,long long c){return (a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c));}
int dp[MAX][2];
vector<int> grp[MAX];

void dfs (int src,int par){
            int leaf=1;
            dp[src][1]=0;
            dp[src][0]=0;
 
            for(auto child:grp[src]){
                    if(child!=par){
                        leaf=0;
                         dfs(child,src);
                    }
            }
        if(leaf==1)return ;
 
        for(auto child:grp[src]){
               if(child!=par){
               dp[src][0]+=MAX2(dp[child][0],dp[child][1]);           // if node is not selected
 
               }
        }
 
        for(auto child:grp[src]){                   // if node is selected 
            if(child!=par) {
                 dp[src][1]=MAX2(dp[src][1],1+ dp[child][0]+( dp[src][0]-MAX2(dp[child][0],dp[child][1])));
            }
        }
 }

void solve(){
    int n; cin>>n;
    foo(i,0,n-1){
        int x, y; cin>>x>>y;
        x--; y--;
        grp[x].pb(y);
        grp[y].pb(x);
    }
    dfs(0, -1);
    cout<<max(dp[0][0],dp[0][1])<<ed;
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