//
// Created by 최희연 on 2022/04/21.
//

#include <iostream>
using namespace std;
long long dp[1001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=n; i++){
        dp[i] = (dp[i-1] + dp[i-2])%10007;
    }
    cout<<dp[n]%10007<<"\n";

}