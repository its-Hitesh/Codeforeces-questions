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
int cycle = 1, whichCycle[200005], cycleLength[200005], toWhichEle[200005], numInCycle[200005], eleid[200005];
int n, m, par[200005], vis[200005], localvis[200005], isCycle[200005];
bool f = 0;
int elecycle = 0, eletowhich = 0, elenumincycle = -1, id = 0;
int firstEle(int s){
    int a = par[s];
    int b = par[a];
    localvis[a] = 1;
    while( a != b){
        a = par[a];
        localvis[a] = 1;
        b = par[par[b]];
    }
    a = s;
    while(a != b){
        a = par[a];
        b = par[b];
    }
    return a;
}
void fun(int s){
    if(vis[s] == 1){
        f = 1;
        // elecycle = whichCycle[s];
        eletowhich = toWhichEle[s]; 
        if(toWhichEle[s] != s) elenumincycle = numInCycle[s] - 1, id = eleid[s];
        return;
    }
    fun(par[s]);
    vis[s] = 1;
    if(f){
        toWhichEle[s] = eletowhich;
        numInCycle[s] = elenumincycle;
        eleid[s] = id;
        elenumincycle--;
    }
}
void solve(){
    cin>>n>>m;
    foo(i, 1, n + 1){
        cin>>par[i];
    }
    foo(i, 1, n + 1){
        if(localvis[i] == 0){
            int first = firstEle(i);
            if(vis[first] == 0){
                int len = 0;
                while (vis[first] == 0)
                {
                    vis[first] = 1;
                    first = par[first];
                    len++;
                }
                cycleLength[cycle] = len;
                foo(i,0,len){
                    numInCycle[first] = i + 1;
                    toWhichEle[first] = first;
                    whichCycle[first] = cycle;
                    first = par[first];
                }
                cycle++;
            }
        }
    }
    foo(i ,1 ,n + 1){
        if(vis[i] == 0){
            f = 0; elenumincycle = 0, id++;
            // cout<<i<<ed;
            fun(i);
        }
    }
    // foo(i,1,n + 1){
    //     cout<<whichCycle[i]<<" "<<toWhichEle[i]<<" "<<numInCycle[i]<<" "<<cycleLength[whichCycle[i]]<<ed;
    // }
    foo(i,0,m){
        int x, y;
        cin>>x>>y;
        if(whichCycle[toWhichEle[x]] != whichCycle[toWhichEle[y]]) cout<<-1<<ed;
        else{
            if(numInCycle[x] > 0 && numInCycle[y] <= 0) cout<<-1<<ed;
            else if(numInCycle[x] <= 0 && numInCycle[y] <= 0 
            && (eleid[x] != eleid[y] || numInCycle[x] > numInCycle[y])) cout<<-1<<ed;
            else{
                if(numInCycle[x] > 0 && numInCycle[y] > 0){
                    if(numInCycle[x] > numInCycle[y]){
                        cout<<cycleLength[whichCycle[x]] - numInCycle[x] + numInCycle[y]<<ed;
                    }
                    else{
                        cout<<numInCycle[y] - numInCycle[x]<<ed;
                    }
                }
                else{
                    cout<<numInCycle[y] - numInCycle[x]<<ed;
                }
            }
            
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