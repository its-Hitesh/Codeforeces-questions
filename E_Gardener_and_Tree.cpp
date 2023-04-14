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

void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> degree(n + 1, 0);
    vector<pair<int,int>> edges(n - 1);
    vector<vector<int>>grp(n +1);
    foo(i,0,n-1){
        int x, y; cin>>x>>y;
        edges[i] = {x,y};
        grp[x].pb(y);
        grp[y].pb(x);
        degree[x]++;
        degree[y]++;
    }
    priority_queue<pair<int*,int>, vector<pair<int*,int>>, greater<pair<int*,int>>> q;
    foo(i,1,n+1){
        q.push({degree[i],i});
    }
    while(k--){
        vector<int> one;
        while(!q.empty()){
            if(q.top().first <= 1){
                one.emplace_back(q.top().second);
                q.pop();
            }
            else break;
        }
        for(auto x : one){
            for(auto z : grp[x]){
                degree[z]-=1;
            }
        }
    }
    cout<<q.size()<<ed;

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

  int tt =1; cin>>tt;

  while(tt--){

    solve();
  }
  return 0;
}