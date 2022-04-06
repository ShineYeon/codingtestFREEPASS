//
// Created by 최희연 on 2022/04/06.
//

#include <iostream>
using namespace std;
//N개 중 M개 고르는데 중복허용, 오름차순
int sequence[10];

void print(int M){
    for(int i=0;i<M;i++){
        cout<<sequence[i]<<" ";
    }
    cout<<"\n";
}

void go(int idx, int start, int N, int M){
    if(idx==M){
        print(M);
        return;
    }
    for(int i=start; i<=N; i++){
        sequence[idx] = i;
        go(idx+1, i, N, M);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int N, M;
    cin>>N>>M;
    go(0, 1, N, M);
}