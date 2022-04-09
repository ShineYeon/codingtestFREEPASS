//
// Created by 최희연 on 2022/04/09.
//

#include <iostream>
#include <vector>
using namespace std;
int N;
int S[21][21];

int calculate(vector<int> t1p, vector<int> t2p) {
    int t1=0, t2=0;
    for(int i=0; i<t1p.size(); i++){
        for(int j=0; j<t1p.size(); j++){
            t1 += S[t1p[i]][t1p[j]];
        }
    }
    for(int i=0; i<t2p.size(); i++){
        for(int j=0; j<t2p.size(); j++){
            t2 += S[t2p[i]][t2p[j]];
        }
    }
    int diff=t1-t2;
    if(diff<0) diff=-diff;
    return diff;

}

int pick(int n, vector<int> t1p, vector<int> t2p) { //n:현재까지뽑은 팀1의 인원수
    if(n == N){ //팀원뽑은것까진 완료, 이제 계산해야 함
        if(t1p.size() != n/2) return -1;
        if(t2p.size() != n/2) return -1;
        return calculate(t1p, t2p);

    }

    int ans = -1;
    t1p.push_back(n);
    int tmp2 = pick(n+1, t1p, t2p);
    if((ans==-1) || (tmp2!=-1 && ans>tmp2)){
        ans = tmp2;
    }
    t1p.pop_back();
    t2p.push_back(n);
    int tmp3 = pick(n+1, t1p, t2p);
    if((ans==-1) || (tmp3!=-1 && ans>tmp3)){
        ans = tmp3;
    }
    t2p.pop_back();
    return ans;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>S[i][j];
        }
    }
    vector<int> t1;
    vector<int> t2;
    int ret = pick(0, t1, t2);
    cout<<ret<<"\n";
}