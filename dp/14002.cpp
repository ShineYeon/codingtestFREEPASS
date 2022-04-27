//
// Created by 최희연 on 2022/04/26.
//

#include <iostream>
#include <vector>
using namespace std;
int dp[1001][2];
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

    dp[0][0] = 1;
    dp[0][1] = 0;
    for(int i=0; i<n; i++){
        dp[i][0] = 1;
        dp[i][1] = -1;
        for(int j=i-1; j>=0; j--){
            if(arr[i] > arr[j] && dp[j][0]+1 > dp[i][0]){
                dp[i][0] = dp[j][0]+1;
                dp[i][1] = j;
            }
        }
    }

    int idx = 0;
    for(int i=0; i<n; i++){
        answer = max(answer, dp[i][0]);
        idx = i;
    }

    vector<int> ret;
    while(dp[idx][1]!=-1){

        ret.push_back(arr[idx]);
        idx = dp[idx][1];

    }
    cout<<answer<<"\n";
    reverse(ret.begin(), ret.end());
    for(int i=0; i<ret.size(); i++){
        cout<<ret[i]<<" ";
    }
    cout<<"\n";
}