//
// Created by 최희연 on 2022/04/06.
//

#include <iostream>
#include <algorithm>
using namespace std;
//중복x, 오름차순
int arr[10];
bool selected[10];
int sequence[10];

void print(int M){
    for(int i=0;i<M;i++){
        cout<<sequence[i]<<" ";
    }
    cout<<"\n";
}

void go(int idx, int N, int M){
    if(idx==M){
        print(M);
        return;
    }
    for(int i=0;i<N;i++){
        if(selected[i]) continue;
        selected[i] = true;
        sequence[idx] = arr[i];
        go(idx+1, N, M);
        selected[i] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int N, M;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    sort(arr, arr+N);
    go(0, N, M);
}