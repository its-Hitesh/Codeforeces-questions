#include<bits/stdc++.h>
using namespace std;
using ll= long long;
using ull=unsigned long long;
#define Monkey ios_base::sync_with_stdio(false);
#define D cin.tie(NULL);
#define Luffy cout.tie(NULL);
#define pb push_back
#define umap unordered_map
#define uset unordered_set
#define all(c) (c).begin(), (c).end()
#define srt(v) sort(v.begin(),v.end())
#define rsrt(v) sort(v.rbegin(),v.rend())
#define nl "\n"
typedef vector<int>     vi;     typedef vector<ll>      vll;
typedef map<int, int>   mi;     typedef map<ll, ll>     mll;
typedef vector<bool>    vb;     typedef vector<char>    vc;

void ans()
{
   ll n,m;cin>>n>>m;
   ll arr[n];
   for(ll i=0;i<n;i++) cin>>arr[i];
   ll ans=0,sum=0;
   priority_queue<ll,vector<ll>,greater<ll>> pq;
   for(ll i=m;i<n;i++)
   {
      if(arr[i]<0) pq.push(arr[i]);
      sum+=arr[i];
      while(sum<0)
      {
         ll t=pq.top();
         pq.pop();
         ans++;
         t=-t;
         sum+=(2*t);
         // cout<<sum<<" "<<i<<endl;
      }
   }
   // cout<<ans<<" ";
   if(arr[m-1] > 0 && m!=1)
   {
      ans++;
      sum=(0-arr[m-1]);
   }
   else if(arr[m-1] <= 0 )
      sum+=arr[m-1];
   priority_queue<ll> pq2;
   for(ll i=m-2;i>=1;i--)
   {
      if(arr[i]>0) pq2.push(arr[i]);
      sum+=arr[i];
      while(sum>0)
      {
         ll t=pq2.top();
         pq2.pop();
         t=-t;
         sum+=(2*t);
         ans++;
      }
   }
   cout<<ans<<endl;
}
int32_t main()
{
   Monkey D Luffy
   //io_file();
   // CODE........................................................................
   int t;cin>>t;
//    cout<<"rga"<<endl;
   while(t--); 
      ans();
}