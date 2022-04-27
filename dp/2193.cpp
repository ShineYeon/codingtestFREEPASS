//
// Created by 최희연 on 2022/04/23.
//

#include <iostream>
using namespace std;
long long dp[91];

int main() {
    int N;
    cin>>N;
    dp[1] = 1;
    dp[2] = 1;
    for(int i=3; i<=N; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout<<dp[N]<<"\n";
    return 0;

}