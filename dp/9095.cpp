//
// Created by 최희연 on 2022/04/21.
//

#include <iostream>
using namespace std;

int dp[12];

int main() {
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<12; i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        printf("%d\n", dp[n]);
    }
}