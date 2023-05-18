#include <bits/stdc++.h>
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
int f = 0;
vector<int> cycle;
vector<int> vis(100005, 0), golvis(100005, 0);
vector<int> grp[100005];
bool dfs(int s){
    vis[s] = 1;
    golvis[s] = 1;
    cycle.pb(s);
    for(auto x : grp[s]){
            if(vis[x] == 1){
                cycle.pb(x);
                f = 1;
                return f;
            }
            if(f == 1) return true;
            if(golvis[x] == 0)dfs(x);
        
        if(f == 1) return true;                          // breaking cycle after finding cycle 
    }
    vis[s] = 0;
    cycle.pop_back();
    return f;
}
void solve(){
    int n, m; cin>>n>>m;
    
    foo(i,0,m){
        int x, y; cin>>x>>y;
        x--; y--;
        grp[x].pb(y);
    }
    foo(i,0,n){
        if(golvis[i] == 0){
            bool d = 0;
            d = dfs(i);
            if(d){
                int d = cycle.size() - 2;
                while(cycle[d] != cycle[cycle.size() - 1]) d--;
                cout<<cycle.size() - d<<ed;
                for(int i = d; i < cycle.size(); i++) cout<<cycle[i] + 1<<" ";
                return;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<ed;
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