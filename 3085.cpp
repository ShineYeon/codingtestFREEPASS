//
// Created by 최희연 on 2022/04/01.
//
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;
string candy[51];
// 빨간색은 C, 파란색은 P, 초록색은 Z, 노란색은 Y

int countCandy(int startRow, int endRow, int startCol, int endCol){
    int max = 0;
    int cnt = 1;
    for(int i=startRow; i<=endRow; i++){
        cnt = 1;
        for(int j=1; j<N; j++){
            if(candy[i][j] == candy[i][j-1])
                cnt++;
            else
                cnt=1;
            if(max<cnt)
                max=cnt;
        }

    }
    for(int i=startCol; i<=endCol; i++){
        cnt=1;
        for(int j=1; j<N; j++){
            if(candy[j][i] == candy[j-1][i])
                cnt++;
            else
                cnt=1;
            if(max<cnt)
                max=cnt;
        }
    }
    return max;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>N;
    for(int i=0; i<N; i++) {
        cin>>candy[i];
    }

    int tmpCnt = 0;
    int ans = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i+1 < N) {
                swap(candy[i][j], candy[i + 1][j]);
                tmpCnt = countCandy(i, i+1, j, j);
                if(tmpCnt>ans) ans=tmpCnt;
                swap(candy[i][j], candy[i+1][j]);
            }
            if(j+1 < N){
                swap(candy[i][j], candy[i][j+1]);
                tmpCnt = countCandy(i, i, j, j+1);
                if(tmpCnt>ans) ans=tmpCnt;
                swap(candy[i][j], candy[i][j+1]);
            }
        }
    }
    cout<<ans<<"\n";
}

