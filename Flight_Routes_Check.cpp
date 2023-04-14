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
#define mod           1000000007
#define int long long
using namespace std;
int dfs1[100005],dfs2[100005];
void dfs11(int a, vector<vector<int>> &grp){
    dfs1[a]=1;
    for(auto x : grp[a]){
        if(dfs1[x]==0){
            dfs11(x,grp);
        }
    }
}
void dfs22(int a, vector<vector<int>> &grp){
    dfs2[a]=1;
    for(auto x : grp[a]){
        if(dfs2[x]==0){
            dfs22(x,grp);
        }
    }
}
void solve(){
        int n,e;
        cin>>n>>e;
        vector<vector<int> > grp(n),grpr(n);
        foo(i,0,e){
            int a,b;
            cin>>a>>b;
            a--;b--;
            grp[a].pb(b);
            grpr[b].pb(a);
        }
        dfs11(0,grp);
        dfs22(0,grpr);
        foo(i,1,n){
                if(dfs1[i]==0){
                    ct<<"NO"<<ed;
                    ct<<1<<" "<<i+1<<ed;
                    return;
                }
                else if(dfs2[i]==0){
                    ct<<"NO"<<ed;
                    ct<<i+1<<" "<<1<<ed;
                    return;
                }
        }
        ct<<"YES"<<ed;
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