//
// Created by 최희연 on 2022/04/06.
//

#include <iostream>
using namespace std;
bool selected[10];
int a[10];

void print(int M){
    for(int i=0;i<M;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}

void go(int index, int N, int M){
    if(index == M) {
        print(M);
        return;
    }
    for(int i=1; i<=N; i++){
        if(selected[i]) continue;
        selected[i]= true;
        a[index] = i;
        go(index+1, N, M);
        selected[i] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int N, M;
    cin>>N>>M;
    go(0, N, M);
}