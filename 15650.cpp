//
// Created by 최희연 on 2022/04/06.
//

#include <iostream>
using namespace std;

bool selected[10];
int sequence[10];

void print(int M){
    for(int i=0;i<M; i++){
        cout<<sequence[i]<<" ";
    }
    cout<<"\n";
    return;
}

void fill(int idx, int start, int N, int M){
    if(idx==M){
        print(M);
        return;
    }
    for(int i=start; i<=N; i++){
        if(selected[i]) continue;
        selected[i] = true;
        sequence[idx] = i;
        fill(idx+1, i+1, N, M);
        selected[i] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int N, M;
    cin>>N>>M;
    fill(0, 1, N, M);


}