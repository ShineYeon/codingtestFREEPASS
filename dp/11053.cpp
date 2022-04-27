//
// Created by 최희연 on 2022/04/26.
//

#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001]; //i자리에서 가장 긴 증가하는 부분수열의 길이
int answer = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    int arr[1001];

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    dp[0] = 1;
    for(int i=0; i<n; i++){
        dp[i] = 1;
        for(int j=i-1; j>=0; j--){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[j]+1, dp[i]);
            }
        }
    }

    for(int i=0; i<n; i++){
        answer = max(answer, dp[i]);
    }

    cout<<answer<<"\n";

}