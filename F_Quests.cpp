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
bool good(int x, vector<int> a, int coin, int days){
    int day = 0,total=0;
    for(int i=0; i< a.size() && i < x+1 ; i++){
        total += a[i];
    }
    day = coin/total;
    if(coin%total==0) day--;
    day *= (x+1);
    if(coin%total==0)day += min(x+1,(int)a.size());
    total *= (coin/total);
    int i =0;
    while(total < coin){
        total += a[i];
        day++;
        i++;
    }
    return day <= days ;

}
void solve(){
    int n; cin>>n;
    int coins,days; cin>>coins>>days;
    vector<int> a(n); foo(i,0,n) cin>>a[i];
    sort(a.rbegin(),a.rend());
    if(a[0] >= coins){
        ct<<"Infinity"<<ed;
        return ;
    }
    int l = 0, r = 2e5;
    int ans =-1;
    while(l<=r){
        int mid = l+(r-l)/2;
        if(good(mid,a,coins,days)){
            ans = max(ans,mid);
            //ct<<ans<<" "<<mid<<ed;
            l = mid+1;
        }
        else r = mid -1 ;
    }
    if(ans == 2e5) ct<<"Infinity"<<ed;
    else if(ans == -1) ct<<"Impossible"<<ed;
    else ct<<ans<<ed;
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


  int t =1; cin>>t;

  while(t--){

    solve();

  }
  return 0;
}

