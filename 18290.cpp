//
// Created by 최희연 on 2022/04/06.
//

#include <iostream>
using namespace std;
int ready[11][11];
bool selected[11][11];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
int N, M, K;
int ans = -98765432;

void go(int sum, int num) {
    if(num == K){
        if(sum>ans)
            ans=sum;
        return;
    }

    for(int x=0; x<N; x++){
        for(int y=0; y<M; y++){
            if(selected[x][y]) continue;
            bool ok = true;
            for(int i=0; i<4; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(0<=nx && nx<N && 0<=ny && ny<M){
                    if(selected[nx][ny]){
                        ok = false;
                    }
                }
            }
            if(ok){
                selected[x][y] = true;
                go(sum+ready[x][y], num+1);
                selected[x][y] = false;
            }
        }
    }



}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>N>>M>>K;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>ready[i][j];
        }
    }
    go(0, 0);
    cout<<ans<<"\n";
    return 0;
}