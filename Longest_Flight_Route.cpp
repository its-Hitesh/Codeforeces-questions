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
vector<int> grp[100001] ;
int vis[100001], par[100001],dis[100001];
stack<int> st;
int f = 0;
int n, m; 
vector<int> topolo;
void dfs(int s){
    vis[s] = 1;
    for(auto x : grp[s]){
        if(vis[x] == 0) dfs(x);
    }
    st.push(s);
}
void solve(){
    cin>>n>>m;
    foo(i,0,m){
        int x, y; cin>>x>>y;
        x--; y--;
        grp[x].pb(y);
    }
    dfs(0);
    while (!st.empty())
    {
        topolo.pb(st.top());
        st.pop();
    }
    // reverse(topolo.begin(), topolo.end());
    for(auto x : topolo){
        for(auto z : grp[x]){                                            // traversing the graph in topological order 
            if(dis[x] + 1 > dis[z]){
                dis[z] = dis[x] + 1;
                par[z + 1] = x + 1;
            }
        }
    }
    int x = n;
    vector<int> ans;
    if(dis[n - 1] == 0){
        cout<<"IMPOSSIBLE"<<ed;
        return ;
    }
    while(x != 1){
        ans.pb(x);
        x = par[x];
    }
    ans.pb(1);
    reverse(ans.begin(), ans.end());
    cout<<ans.size()<<ed;
    for(auto z : ans) cout<<z<<" ";
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