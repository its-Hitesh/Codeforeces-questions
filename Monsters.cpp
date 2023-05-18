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
int n, m, f = 0;
pair<int,int> start; 
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char dir[4] = {'R','L','D','U'};
int dis[1001][1001], vis[1001][1001];
pair<int,int> parent[1001][1001], stop;
vector<char> ans;
vector<string> a;
 
bool inRange(int x, int y){
    if(x >= 0 && x < n && y < m && y >= 0) return true ;
    return false ;
}
 
void bfs(int i, int j, int d){
    vis[i][j] = 1;
    dis[i][j] = min(dis[i][j], d);
    foo(k,0,4){
        int x = i + dx[k];
        int y = j + dy[k];
        if(inRange(x, y) && a[x][y] !='#' && vis[x][y] == 0 && dis[x][y] > d + 1){
            bfs(x, y, d + 1);
        }
    }
    vis[i][j] = 0;
}   
bool bfs2(int i, int j, int d){
    int visi[1000][1000] = {};
    queue<pair<int,int>> q;
    q.push({i,j});
    visi[i][j] = 1;
    while(!q.empty()){
        int z = q.size();
        d++;
        foo(i,0,z){
            pair<int,int> tt = q.front();
            q.pop();
            foo(k,0,4){
                int x = tt.first + dx[k];
                int y = tt.second + dy[k];
                if(inRange(x, y) && a[x][y] =='.' && visi[x][y] == 0 && dis[x][y] > d){
                    parent[x][y] = {tt.first, tt.second};
                    visi[x][y] = 1;
                    q.push({x,y});
                    if(x == 0 || x == n - 1 || y == 0 || y == m - 1) {stop = {x,y};f = 1;return f;}
                }
            }
        }
    }
    return f;
}
// bool bfs2(int i, int j, int d){
//     vis[i][j] = 1; 
//     if(i == 0 || i == n - 1 || j == 0 || j == m - 1) f = 1;
//     cout<<i<<" "<<j<<" "<<d<<ed;
//     if(f) return f ;
//     foo(k,0,4){ 
//         int x = i + dx[k];
//         int y = j + dy[k];
//         if(inRange(x, y) && a[x][y] =='.' && vis[x][y] == 0 && dis[x][y] > d + 1){
//             ans.pb(dir[k]);
//             // cout<<dir[k]<<ed;
//             bfs2(x, y, d + 1);
//             if(f) return f;
//             ans.pop_back();
//         }
//     }
    
//     return f;
// }
 
void solve(){
    cin>>n>>m;
    f = 0;
    foo(i,0,n){
        string s; cin>>s;
        a.pb(s);
        foo(j,0,m){
            dis[i][j] = 10000;
            if(a[i][j] == 'A') start = {i, j};
            if((i == 0 || i == n - 1 || j == 0 || j == m - 1) && (a[i][j] == '.' || a[i][j] == 'A')) {
                if(a[i][j] == 'A'){
                    cout<<"YES"<<ed;
                    cout<<0<<ed;
                    return;
                }
                f = 1;
            }
        }
    }
    if(!f){
        cout<<"NO"<<ed;
        return ;
    }
    f = 0;
    foo(i,0,n){
        foo(j,0,m){
            if(a[i][j] == 'M'){
                bfs(i, j, 0);
            }
        }
    }
    bfs2(start.first, start.second, 0);
    if(f){
        cout<<"YES"<<ed;
        string ans = "";
        while(stop != start){
            foo(i,0,4){
                if(stop.first  == parent[stop.first][stop.second].first + dx[i] && stop.second == parent[stop.first][stop.second].second + dy[i]){
                    ans += dir[i];
                    break;
                }
            }
            stop = parent[stop.first][stop.second];
        }
        cout<<ans.size()<<ed;
        reverse(ans.begin(), ans.end());
        for(auto x : ans) cout<<x;
    }
    else cout<<"NO"<<ed;
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