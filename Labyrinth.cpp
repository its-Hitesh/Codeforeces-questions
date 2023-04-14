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
#define ff            first
#define ss            second
#define mod           1000000007
#define int long long
using namespace std;
int n,m;
vector<vector<int> > g(1001,vector<int> (1001,-1));
map <pair<int,int>,pair<int,int> > parent;
int dist = 0;
pair<int,int> start, finish;
int xaxix[4] = {0,0,1,-1};
int yaxix[4] = {1,-1,0,0};
bool inrange(int a, int b){
    if(a>=0 && b >=0 && a <n && b <m) return true;
    return false ;
}
vector<char>path;
void trace(pair<int,int> p){
    if(parent.find(p)== parent.end()){
        return;
    }
    foo(i,0,4){
        if(inrange(p.first+xaxix[i],p.second+yaxix[i]) && parent[p] == m_p(p.first+xaxix[i],p.second+yaxix[i])){
            if(i==0) path.push_back('L');
            else if(i==1) path.push_back('R');
            else if(i==2) path.push_back('U');
            else if(i==3) path.push_back('D');
            trace(m_p(p.first+xaxix[i],p.second+yaxix[i]));
        }
    }
    //ct<<p.first<<" trace "<<p.second<<ed;
}
void solve(){
 
    
    cin>>n>>m;
    foo(i,0,n) {
        foo(j,0,m){
            char t ; cin>>t;
            if(t=='.') g[i][j] = 1;
            if(t=='A') start=m_p(i,j);
            if(t=='B') finish=m_p(i,j);
        }
    }
    queue<pair<int,int>> q;
    bool visited[n][m];
    foo(i,0,n) foo(j,0,m) visited[i][j] = false;
    q.push(start);
    visited[start.first][start.second] = true;
    bool finished = false;
    while(!q.empty())
    {   
        dist++;
        for(int f=0;f<q.size();f++){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            //ct<<x<<" x queue y "<<y<<ed;
            foo(i,0,4){
                if(inrange(x+xaxix[i],y+yaxix[i]) && g[x+xaxix[i]][y+yaxix[i]]==1 && visited[x+xaxix[i]][y+yaxix[i]]==false){
                    q.push(m_p(x+xaxix[i],y+yaxix[i]));
                    visited[x+xaxix[i]][y+yaxix[i]] = true ;
                    parent[m_p(x+xaxix[i],y+yaxix[i])] = m_p(x,y);
                }
                if(finish==m_p(x+xaxix[i],y+yaxix[i])){
                    parent[finish] = m_p(x,y);
                    finished=true;
                    break;   
                }
            }    
        }
        if(finished) break;
    }
    if(!finished){
        ct<<"NO"<<ed;
        return;
    }
    ct<<"YES"<<ed;
        trace(finish);
        reverse(path.begin(),path.end());
        ct<<path.size()<<ed;
        for(auto z : path ) ct<<z;
        ct<<ed;
 
}
 
 
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  
  int t =1; //cin>>t;
 
  while(t--){
 
    solve();
 
  }
  return 0;
}