//
// Created by 최희연 on 2022/04/14.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main() {


    int N, M; //세로, 가로
    int nums[5][5];

    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%1d", &nums[i][j]);
        }
    }

    int ans = 0;
    for(int i=0; i<(1<<N*M); i++){
        //0이면 가로, 1이면 세로

        int sum=0;
        //가로 계산
        for(int j=0; j<N; j++){
            int tmp=0;
            for(int k=0; k<M; k++){
                if(!(i&(1<<(j*M+k)))){ // 가로임
                    tmp = tmp*10 + nums[j][k];
                }
                else{
                    sum+=tmp;
                    tmp=0;
                }
            }
            sum+=tmp;
        }

        //세로 계산
        for(int k=0; k<M; k++){
            int tmp=0;
            for(int j=0; j<N; j++){
                if(!(i&(1<<(j*M+k)))){ // 가로임
                    sum+=tmp;
                    tmp=0;
                }
                else{
                   tmp=tmp*10+nums[j][k];
                }
            }
            sum+=tmp;
        }
        ans=max(ans, sum);
    }
    printf("%d\n", ans);

}