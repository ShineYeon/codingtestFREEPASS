//
// Created by 최희연 on 2022/04/21.
//

#include <iostream>
#include <algorithm>
using namespace std;
int dp[3][1000001];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int N;
    cin>>N;
    for(int i=0; i<3; i++){
        for(int j=0; j<=N; j++){
            dp[i][j] = 98765432;
        }
    }
    for(int i=0; i<3; i++){
        dp[i][N] = 0;
    }

    int i=N;
    for(int i=N; i>=1; i--){
        if(i%3 == 0){
            dp[0][i/3] = min(dp[0][i], min(dp[1][i], dp[2][i])) + 1;
        }
        if(i%2 == 0){
            dp[1][i/2] = min(dp[0][i], min(dp[1][i], dp[2][i])) + 1;
        }
        dp[2][i-1] = min(dp[0][i], min(dp[1][i], dp[2][i])) + 1;

    }

    int ans=98765432;
    for(int i=0; i<3; i++){
        ans =min(dp[i][1], ans);
    }
    cout<<ans<<"\n";
}