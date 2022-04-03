#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int a, b, c, d, e;
int classroom[21][21];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
int nearX, nearY, near;
int familiar[401][4];

#define INF 98765432

//인접한 자리 친구 수 리턴
int nearFriend(int x, int y){
    int count = 0;
    for(int k=0;k<4;k++) {
        nearX = x + dx[k], nearY = y + dy[k];
        if (nearX <= 0 || nearY <= 0 || nearX > N || nearY > N) continue;
        near = classroom[nearX][nearY];
        if (near == b || near == c || near == d || near == e) {
            count++; //좋아하는 학우 증가
        }

    }
    return count;
}

//인접한 빈 자리 수 리턴
int nearEmpty(int x, int y){
    int count = 0;
    for(int k =0;k<4;k++) {
        nearX = x + dx[k], nearY = y + dy[k];
        if (nearX <= 0 || nearY <= 0 || nearX > N || nearY > N) continue;

        near = classroom[nearX][nearY];
        if (near == 0) {
            count++; //인접 빈자리 증가
        }

    }
    return count;
}

void sol(){
    int retX=INF, retY=INF;
    int maxFriend = 0, maxEmpty = 0;
    int friends = 0, empties = 0; //근처 친구 수, 근처 빈자리 수
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(classroom[i][j] == 0){ //빈칸일때 상하좌우 탐색
                friends = nearFriend(i, j);
                if(maxFriend < friends){ //인접 친구 수가 지금까지 max 보다 많으면
                    maxFriend = friends;
                    retX=i, retY=j;
                }
                else if(maxFriend == friends){ //인접 친구수가 지금까지 max와 동일하면
                    empties = nearEmpty(i, j);
                    if(maxEmpty < empties) { //인접 빈자리수가 지금까지 max보다 많으면
                        maxEmpty = empties;
                        retX=i, retY=j;
                    }
                    else if(maxEmpty == empties){ //동일하면
                        if(retX > i) {
                            retX=i, retY=j;
                        }
                        else if(retX == i){
                            if(retY > j){
                                retX=i, retY=j;
                            }
                        }
                    }
                    if(friends==0 && empties==0){
                        if(retX > i) {
                            retX=i, retY=j;
                        }
                        else if(retX == i){
                            if(retY > j){
                                retX=i, retY=j;
                            }
                        }
                    }

                }

            }
        }
    }
    classroom[retX][retY] = a;
}

//만족도 계산
int score(){
    int ret=0;
    int cnt=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cnt = 0;
            for(int k=0;k<4;k++) {
                nearX = i + dx[k], nearY = j + dy[k];
                if (nearX <= 0 || nearY <= 0 || nearX > N || nearY > N) continue;

                near = classroom[nearX][nearY];
                for (int l = 0; l < 4; l++) {
                    if(familiar[classroom[i][j]][l] == near){
                        cnt++;
                    }
                }

            }
            if(cnt == 0) ret+=0;
            else if(cnt==1) ret+=1;
            else if(cnt==2) ret+=10;
            else if(cnt==3) ret+=100;
            else if(cnt==4) ret+=1000;
        }
    }
    return ret;
}

int main() {
    scanf("%d", &N);
    for(int i=1;i<=pow(N, 2);i++){
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
        familiar[a][0]=b;
        familiar[a][1]=c;
        familiar[a][2]=d;
        familiar[a][3]=e;
        sol();
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cout<<classroom[i][j];
        }
        cout<<endl;
    }
    printf("%d\n", score());
}
