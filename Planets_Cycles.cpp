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
int visited[200005], ans[200005], a[200005], step = 0;
queue<int> q;
void dfs(int x){
  q.push(x);
  if(visited[x]){
    step += ans[x];                         // using queue to store elements of one pass 
    return;
  }
  step++;
  visited[x] = 1;
  dfs(a[x]);
}
void solve(){   
    int n; cin>>n;
    foo(i,0,n) cin>>a[i], a[i]--;
    for(int i = 0 ; i < n; i++){
      if(visited[i] == 0){
        step = 0;
        dfs(i);
        int decre = 1;
        while(!q.empty()){
          if(q.front() == q.back()) decre = 0;
          ans[q.front()] = step ;
          // cout<<q.front()<<" "<<step<<" "<<ans[q.front()]<<ed;
          step -= decre;
          q.pop();
        }
        // cout<<ed;
      }
    }
    foo(i,0,n) cout<<ans[i]<<" ";

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