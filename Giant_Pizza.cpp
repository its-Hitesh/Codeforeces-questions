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

// 2 SAT  

int n, m;
vector<vector<int>> adj(500002), adj_t(500002);
vector<bool> used(500002, false);
vector<int> order, comp(500002, -1);
vector<bool> assignment(500002, false);

void dfs1(int v) {
    used[v] = true;
    for (int u : adj[v]) {
        if (!used[u])
            dfs1(u);
    }
    order.push_back(v);
}

void dfs2(int v, int cl) {
    comp[v] = cl;
    for (int u : adj_t[v]) {
        if (comp[u] == -1)
            dfs2(u, cl);
    }
}

bool solve_2SAT() {
    order.clear();
    for (int i = 0; i < 2*n; ++i) {
        if (!used[i])
            dfs1(i);
    }

    for (int i = 0, j = 0; i < 2*n; ++i) {
        int v = order[2*n - i - 1];
        if (comp[v] == -1)
            dfs2(v, j++);
    }

    
    for (int i = 0; i < 2*n; i += 2) {
        if (comp[i] == comp[i + 1])
            return false;
        assignment[i / 2] = comp[i] > comp[i + 1];
    }
    return true;
}

void add_disjunction(int a, bool na, int b, bool nb) {
    // na and nb signify whether a and b are to be negated 
    a = 2*a ^ na;
    b = 2*b ^ nb;
    int neg_a = a ^ 1;
    int neg_b = b ^ 1;
    adj[neg_a].push_back(b);
    adj[neg_b].push_back(a);
    adj_t[b].push_back(neg_a);
    adj_t[a].push_back(neg_b);
}

void solve(){
    cin>>m>>n;
    foo(i,0,m){
        int x, y;
        char a, b;
        cin>>a>>x>>b>>y;
        x--; y--;
        bool f = 0, f2 = 0;
        if(a == '-') f = 1;
        if(b == '-') f2 = 1;
        add_disjunction(x, f, y, f2);
    }
    bool f = solve_2SAT();
    // cout<<"Solved"<<ed;
    if(!f){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    foo(i,0,n) cout << (assignment[i] ? '+' : '-')<<" ";
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