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
vector<int> grp[100005];
int par[100005];
void bfs(int s, int n){
    vector<int> vis(n, 0);
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    while(!q.empty()){
        int z = q.size();
        foo(i,0,z){
            int tt = q.front();
            q.pop();
            for(auto x : grp[tt]){
                if(x == n - 1){
                    par[x + 1] = tt + 1;                             // storing parent for path
                    return;
                }
                if(vis[x] == 0){
                // cout<<x + 1<<" "<<tt + 1<<ed;
                    par[x + 1] = tt + 1;
                    vis[x] = 1;
                    q.push(x);
                }
            }
        }
    }
}

void solve(){
    int n, m; cin>>n>>m;
    foo(i,0,m){
        int x, y; cin>>x>>y;
        x--; y--; 
        grp[x].pb(y);
        grp[y].pb(x);
    }
    bfs(0,n);
    vector<int> ans;
    int tt = n;
    while(par[n] != 1){
        if(par[n] == 0){
            cout<<"IMPOSSIBLE"<<ed;
            return;
        }
        ans.pb(par[n]);
        n = par[n];
    }
    cout<<ans.size() + 2<<ed;
    cout<<1<<" ";
    for(int i = ans.size() - 1; i >= 0; i--) cout<<ans[i]<<" ";
    cout<<tt<<ed;
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