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
#define int long long
int parent[500005];
void bfs(int x, map<int,set<int>> &m, vector<int> &a){
    vector<int> visited(x + 1, 0);
    queue<int> q;
    q.push(x);
    visited[x] = 1;
    while(!q.empty()){
        int tt = q.front();
        // cout<<tt<<" ";
        q.pop();
        if(visited[tt - 1] == 0){
            visited[tt - 1] = 1;
            q.push(tt - 1);
            parent[tt - 1] = tt;
        }
        for(auto z : m[a[tt]]){
            if(visited[z] == 0){
                visited[z] = 1;
                parent[z] = tt;
                q.push(z);
            }
        }
    }
}
void solve(){   
    int n; cin>>n;
    vector<pair<char,int>> p;
    vector<int> a;
    a.pb(0);
    foo(i,0,n){
        char x; 
        int y;
        cin>>x>>y;
        p.pb({x,y});
        int z = a.size();
        if(i == 0) {
            a.pb(y);
        }
        else if(x == '|'){
            a.pb(a[z - 1] | y);
        }
        else if(x == '^'){
            a.pb(a[z - 1] ^ y);
        }
        else{
            a.pb(a[z - 1] & y);
        }
    }
    map<int,set<int>> m;
    for(int i = n; i >=0; i--){
        m[a[i]].insert(i);
    }
    bfs(n, m, a);
    int tt = 0;
    vector<pair<char,int>> ans;
    int cnt = 0;
    foo(i,0,n+1){
        if(parent[tt] == n){
            if(m[a[parent[tt]]].size() > 1) break;
            ans.pb(p[parent[tt] - 1]);
            cnt++;
            break;
        }
        cnt++;
        // cout<<tt<<ed;
        ans.pb(p[parent[tt] - 1]);
        tt = parent[tt];
    }
    cout<<cnt<<ed;
    for(auto z : ans) cout<<z.first<<" "<<z.second<<ed;

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