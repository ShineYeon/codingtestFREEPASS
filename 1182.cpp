//
// Created by 최희연 on 2022/04/14.
//

#include <iostream>
using namespace std;
int arr[21];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int N, S;
    cin>>N>>S;
    for(int i=0; i<N; i++)
        cin>>arr[i];
    int ans = 0;

    for(int i=1; i<(1<<N); i++){ //0~N-1 비트마스크 중 원소를 하나도 안고르는 0을 뺌
        int sum = 0;
        for(int j=0; j<N; j++){
            if(i & (1<<j)){
                sum+=arr[j];
            }
        }
        if(S==sum){
            ans++;
        }

    }
    cout<<ans<<"\n";
}