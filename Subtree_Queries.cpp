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

const int N = 2e5+2;
int treee[4*N];
int val[200005],siz[200005], id[200005], timer = 0;
vector<int> grp[200005];
vector<int> arr;
void build(int node,int st,int en){
    if(st==en){
        treee[node] = arr[st];
        return;
    }
    int mid = (st+en)/2;
    build(2*node,st, mid);
    build(2*node+1,mid+1,en);
 
    treee[node] = treee[2*node] + treee[2*node+1] ;
}
int query(int node,int st,int en,int l, int r){  // ans from l to r
    if(st>r || en < l) return 0 ; // not overlapping at all
    if(l <= st && r >= en) return treee[node];
    int mid = (st+en)/2;
    int q1 = query(2*node,st,mid,l,r);
    int q2 = query(2*node+1,mid+1,en,l,r);
    return q1 + q2 ;
}
void update(int node,int st,int en,int idx, int val){
    if(st==en){
        arr[st] = val;
        treee[node] = val;
        return;
    }
    int mid = (st+en)/2;
    if(idx <= mid) {
        update(2*node,st,mid,idx,val);
    }
    else{
        update(2*node+1,mid+1,en,idx,val);
    }
    treee[node] = treee[2*node]+treee[2*node+1];
}

void dfs(int s, int p){
    int st = timer++;
    arr.pb(val[s]);
    id[s] = arr.size();
    for(auto x : grp[s]){
        if(x != p){
            dfs(x, s);
        }
    }
    siz[s] = timer - st ;
}
void solve(){
    int n, m; cin >>n >>m ;
    foo(i,0,n) cin>>val[i+1];
    foo(i,0,n - 1){
        int x, y; cin>>x>>y;
        grp[x].pb(y);
        grp[y].pb(x);
    }
    dfs(1, -1);
    arr.insert(arr.begin(),0);
    build(1,1,n);
    // foo(i,1,n+1) cout<<siz[i]<<" ";
    // cout<<ed;
    // foo(i,1,n+1) cout<<arr[i]<<" ";
    // cout<<ed;
    foo(i,0,m){
        int x, y, z; cin>>x;
        if( x == 1){
            cin>>y>>z;
            update(1, 1, n, id[y], z);
        }
        else{
            cin>>y;
            // foo(i,1,n+1) cout<<arr[i]<<" ";
            cout<<query(1, 1, n, id[y], id[y] + siz[y] - 1)<<ed;
        }
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