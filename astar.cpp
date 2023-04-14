#include<bits/stdc++.h>
using namespace std;
struct node {
        int g;
        int ar[3][3];
};

#define p32 pair<int,node>

int fin[3][3];
int done(int ar[3][3]){
        int c = 0 ;
        for(int i = 0 ; i < 3 ;i++)for(int j = 0 ; j < 3 ;j ++)if(ar[i][j] == fin[i][j])c++;
        return 9 - c;
}

void copy_obj_to_arr(int a[3][3] , node &x){
        for(int i = 0 ; i < 3 ; i++ ) for(int j = 0 ; j < 3 ; j++ ) x.ar[i][j] = a[i][j];
}
void copy_arr_to_obj(int a[3][3] , node &x){
        for(int i = 0 ; i < 3 ; i++ ) for(int j = 0 ; j < 3 ; j++ ) a[i][j] = x.ar[i][j];
}
void copy_arr_to_arr(int a[3][3] , int ar[3][3]){
        for(int i = 0 ; i < 3 ; i++ ) for(int j = 0 ; j < 3 ; j++ ) a[i][j] = ar[i][j];
}
int ans = -1;
int dx[]={0,1,0,-1};
int dy[]={-1,0,1,0};

struct comp {
        bool operator() (p32 a , p32 b) {
                if(a.first < b.first)return false;
                else if(a.first > b.first) return true;
                return a.second.g < b.second.g;
        }
};


void go(int start[3][3] ){

        //map<int [3][3] , int>m;
        node xt;
        xt.g = 0;
        int base_h = done(start);
        copy_obj_to_arr(start,xt);

        priority_queue<p32,vector<p32>,comp>pq;
        pq.push({base_h,xt});
        long long two = 2;
        long long kj = two*3*4*5*6*7*8*9*2*2;
        // cout << kj << " ";
        while(!pq.empty()) {
                if(kj-- == 0)break;
                // kj++;
                auto u = pq.top();
                pq.pop();
                int h = done(u.second.ar);
                int temp_g = u.second.g;
                int arr[3][3] ;
                copy_arr_to_obj(arr,u.second);
                //if(m[arr] == 1) continue;
                if(h == 0 ){
                        ans = temp_g;
                        return ;
                }       
                // cout << " " << h ;
                int i = 0, j = 0;
                for(i = 0 ; i < 3 ;i++){
                        int flag = 1;
                        for( j = 0 ; j < 3 ;j ++)if(arr[i][j] == 0) {flag = 0 ;break;}
                        if(flag == 0)break;
                }               

                for(int k = 0 ; k < 4 ; k++ ) {
                        int ni = i + dx[k] , nj = j + dy[k];
                        if(ni >= 0 && nj >= 0 && ni <3 && nj < 3) {
                                int this_a[3][3];
                                copy_arr_to_arr(this_a , arr);
                                swap(this_a[ni][nj],this_a[i][j]);
                                int this_h = done(this_a);
                                int this_g = temp_g + 1;
                                node this_x ;
                                this_x.g = this_g;
                                copy_obj_to_arr( this_a , this_x);
                                pq.push({this_h + this_g , this_x});
                        }
                }
        }

}
int main(){
        int a[3][3];
        for(int i = 0 ; i < 3 ;i++)for(int j = 0 ; j < 3 ;j ++)cin >> a[i][j];

        for(int i = 0 ; i < 3 ;i++)for(int j = 0 ; j < 3 ;j ++) fin[i][j] = i*3 + j + 1;
        fin[2][2] = 0;
        
        go(a);
        cout << '\n';
        if(ans != -1 )cout<<ans<<'\n';
        else cout << "NOT FOUND \n";
}