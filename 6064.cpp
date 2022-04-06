//
// Created by 최희연 on 2022/04/06.
//

#include <iostream>
using namespace std;
int M, N, x, y;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int T;
    cin>>T;

    while(T--){
        bool flag = false;
        cin>>M>>N>>x>>y;
        x-=1, y-=1;
        for(int k=x; k<(M*N); k+=M){
            if(k%N == y){
                cout<<k+1<<"\n";
                flag = true;
                break;
            }
        }
        if(!flag) cout<<"-1\n";
    }
}