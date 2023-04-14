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


void dijkstra(int source, vector<int> &dis, vector<vector<pair<int,int>>>  &grp, int n){
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int>visited(n, 0);
    pq.push({0,source});
    dis[source]  = 0;
    while(!pq.empty()){
        pair<int,int> p = pq.top();
        pq.pop();
        if(visited[p.second] == 1) continue;
        visited[p.second] = 1;
        for(auto x : grp[p.second]){
            int v = x.first;
            int u = p.second, w = x.second ;
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                pq.push({dis[v],v});
            }
        }
    }
}
void solve(){
    int n, m, k; cin>>n>>m>>k;
    int a[n]; foo(i,0,n) cin>>a[i];
    vector<vector<pair<int,int>>>grp(n+1);
    foo(i,0,m){
        int x, y, w; cin>>x>>y>>w;
        x--; y--;
        grp[x].pb({y,w});
        grp[y].pb({x,w});
    }
    foo(i,0,n){                                  // creating the virtual node with weight equal to the vertx value 
        grp[n].pb({i,a[i]});
        grp[i].pb({n,a[i]});
    }
    n++;
    foo(i,0,k){
        int b; cin>>b;
        vector<int> dis(n+1, LONG_MAX);
        dijkstra(b - 1, dis, grp, n);

        for(int i = 0; i < n - 1 ; i++){
            cout<<dis[i]<<" ";
        }
        cout<<ed;
    }

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