#include <bits/stdc++.h>
#define foo(i,a,b)  for(int i=a;i<b;i++)
#define ct          cout

using namespace std;

int main(){
    int n = 5;
    vector<pair<int,int> > time(n);
    int arrival_time[] = {2,5,1,0,4};
    int burst_time[] = {6,2,8,3,4};
    foo(i,0,n) time[i].first = arrival_time[i] , time[i].second = burst_time[i];
    float wt[n],total;
    sort(time.begin(),time.end());

    wt[0] = 0;
    total = time[0].second;
    foo(i,1,n){
        wt[i] = total - time[i].first;
        if(wt[i] < 0) wt[i] =0;
        total += time[i].second;
    }
    float avg = 0;
    foo(i,0,n) ct<< wt[i]<<endl;
    ct<<setprecision(3)<<avg/n<<endl;
}
