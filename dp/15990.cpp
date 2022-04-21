//
// Created by 최희연 on 2022/04/21.
//

#include <iostream>
using namespace std;

long long dp[4][100001];

int main(){
    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[3][3] = 1;
    for(int i=2; i<=100000; i++){
        if(i>1)
            dp[1][i] = (dp[2][i-1] + dp[3][i-1])%1000000009;
        if(i>2)
            dp[2][i] = (dp[1][i-2] + dp[3][i-2])%1000000009;
        if(i>3)
            dp[3][i] = (dp[1][i-3] + dp[2][i-3])%1000000009;
    }
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        long long sum = 0;
        for(int i=1; i<=3; i++){
            sum = (sum+dp[i][n])%1000000009;
        }
        printf("%lld\n", sum);
    }

}