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
#define mod           998244353
#define int  long long
using namespace std;
const int mode=1e9+7;
//const double mode2=1e9+7;
void soln()
{
 int n,m;
 cin>>n>>m;
 int arr[n];
 foo(i,0,n)cin>>arr[i];
 sort(arr,arr+n);
 foo(i,0,m)
 {
   int a,b,c;
   cin>>a>>b>>c;
   int l=0,r=n-1;
   int ans=INT_MAX;
   while(l<=r)
   {
     int md=l-(l-r)/2;
     
     if((b-arr[md])*(b-arr[md]) < 4*a*c)
     {
       ans=min(ans,arr[md]);
       l=md+1;
     }
     else
     {
       r=md-1;
     }
   }
   if(ans==INT_MAX)
   {
     ct<<"NO"<<endl;
   }
   else
   {
     ct<<"YES"<<endl;
     ct<<ans<<endl;
   }
 
 }
 
}
  
 
 
int32_t main()
{
  
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);
  // #ifndef ONLINE_JUDGE
  //   freopen("input.txt","r",stdin);
  //   freopen("accept.txt","w",stdout);
  // #endif 
   int t; cin>>t;
  while(t--)
    {
    soln();
 
    }
   return 0;
}