//
// Created by 최희연 on 2022/04/12.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int weight[11][11];
int ans = 98765432; //최종 리턴 최소 비용


void sol() {
    vector<int> vi;
    for(int i=0; i<=N; i++){
        vi.push_back(i);
    }

    do{
        bool ok = true;
        int sum =0;
        for(int i=0; i<N-1; i++){
            if(weight[vi[i]][vi[i+1]] == 0) {
                ok = false;
            }
            else sum+=weight[vi[i]][vi[i+1]];
        }
        if(ok && weight[vi[N-1]][vi[0]]!=0) {
            sum += weight[vi[N - 1]][vi[0]];
            ans = min(sum, ans);
        }
    }while(next_permutation(vi.begin()+1, vi.end()));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>N;
    for(int i=0;i<N; i++){
        for(int j=0; j<N; j++){
            cin>>weight[i][j];
        }
    }
    sol();
    cout<<ans<<"\n";
    return 0;
}