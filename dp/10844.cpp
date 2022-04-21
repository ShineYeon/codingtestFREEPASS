//
// Created by 최희연 on 2022/04/21.
//

#include <iostream>
using namespace std;

long long dp[101][10];

int main() {
    for(int i=1; i<=9; i++){
        dp[1][i] = 1;
    }

    int n;
    scanf("%d", &n);
    for(int i=2; i<=n; i++){
        for(int j=0; j<=9; j++){
            if(j==0)
                dp[i][j] = dp[i-1][j+1];
            else if(j==9)
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%1000000000;
        }

    }
    long long answer = 0;
    for(int i=0; i<=9; i++){
        answer = (answer+dp[n][i])%1000000000;
    }
    printf("%lld\n", answer%1000000000);
}