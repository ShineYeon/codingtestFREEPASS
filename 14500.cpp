//
// Created by 최희연 on 2022/04/02.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int N, M;
int board[501][501];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

vector<vector<string>> shapes = {
        {"1111"},
        {"11",
         "11"},
        {"10",
         "10",
         "11"},
        {"10",
         "11",
         "01"},
        {"111",
         "010"}
};

vector<string> mirror(vector<string> shape) {
    vector<string> ans(shape.size());
    for(int i=0;i<shape.size();i++){
        string tmp = shape[i];
        reverse(tmp.begin(), tmp.end());
        ans[i] = tmp;
    }
    return ans;
}

vector<string> rotate(vector<string> shape) {
    vector<string> ans(shape[0].size());
    for(int i=0; i<shape[0].size(); i++){
        for(int j=shape.size()-1; j>=0; j--){
            ans[j] += shape[i][j];
        }
    }
    return ans;
}

int calc(vector<string> shape, int x, int y){
    int sum = 0;
    for(int i=0; i<shape.size(); i++){
        for(int j=0; j<shape[0].size(); j++){
            if(shape[i][j] == '0') continue;
            int nx = x+i, ny=y+j;
            if(0<=nx && nx<N && 0<=ny&& ny<M){
                sum += board[nx][ny];
            } else return -1;
        }
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M; //N:세로, M:가로
    for(int i=0;i<N; i++){
        for(int j=0;j<M; j++){
            cin>>board[i][j];
        }
    }

    int ret = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            for(auto &shape: shapes){
                vector<string> s = shape;
                for(int mir = 0; mir<2; i++){
                    for(int rot=0; rot<4;rot++){
                        int cur = calc(s, i, j);
                        if(cur!=-1 && cur>ret) ret=cur;
                        s=rotate(s);
                    }
                    s=mirror(s);
                }
            }
        }
    }
    cout<<ret<<"\n";

 }
