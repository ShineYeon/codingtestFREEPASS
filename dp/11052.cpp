//
// Created by 최희연 on 2022/04/21.
//

#include <iostream>
using namespace std;
int N;
int P[1001];
int dp[1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>N;
    for(int i=1; i<=N; i++){
        cin>>P[i];
    }
    dp[0] = 0;
    dp[1] = P[1];
    for(int i=2; i<=N; i++){
        for(int j=1; j<=i; j++){
            dp[i] = max(dp[j] + P[i-j], dp[i]);
        }
        dp[i] = max(dp[i], P[i]);
    }
    cout<<dp[N]<<"\n";
}