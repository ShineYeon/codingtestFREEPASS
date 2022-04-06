//
// Created by 최희연 on 2022/04/06.
//

#include <iostream>
using namespace std;
int sequence[10];

void print(int M){
    for(int i=0; i<M ;i++){
        cout<<sequence[i]<<" ";
    }
    cout<<"\n";
}

void go(int index, int start, int N, int M){
    if(index == M){
        print(M);
        return;
    }
    for(int i=1;i<=N;i++){
        sequence[index] = i;
        go(index+1, i, N, M);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int N, M;
    cin>>N>>M;
    go(0, 1, N, M);

}