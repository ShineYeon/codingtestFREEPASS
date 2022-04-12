//
// Created by 최희연 on 2022/04/12.
//

#include <iostream>
using namespace std;
int N;
int arr[9];
int ans=0; //최종 최댓값

int calc(){
    int sum = 0;
    for(int i=0; i<N-1; i++){
        int tmp = arr[i]-arr[i+1];
        if(tmp<0) tmp=-tmp;
        sum+=tmp;
    }
    return sum;
}

void sol(){
    do{
        ans = max(ans, calc());
    } while(next_permutation(arr, arr+N));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    sort(arr, arr+N);
    sol();
    cout<<ans<<"\n";
}