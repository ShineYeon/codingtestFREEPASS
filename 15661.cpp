//
// Created by 최희연 on 2022/04/09.
//

#include <iostream>
#include <vector>
using namespace std;

int N;
int S[21][21];

int sol(int idx, vector<int> v1, vector<int> v2) {
    if(idx == N){
        if(v1.size() == 0) return -1;
        if(v2.size() == 0) return -1;

        int t1=0, t2=0;
        for(int i=0; i<v1.size(); i++){
            for(int j=0; j<v1.size(); j++){
                t1 += S[v1[i]][v1[j]];
            }
        }
        for(int i=0; i<v2.size(); i++){
            for(int j=0; j<v2.size(); j++){
                t2 += S[v2[i]][v2[j]];
            }
        }
        int diff=t1-t2;
        if(diff<0) diff=-diff;
        return diff;
    }

    int ans =-1;
    v1.push_back(idx);
    int tmp1 = sol(idx+1, v1, v2);
    if(ans==-1 || (tmp1!=-1 && ans>tmp1)){
        ans = tmp1;
    }
    v1.pop_back();

    v2.push_back(idx);
    int tmp2 = sol(idx+1, v1, v2);
    if(ans==-1 || (tmp2!=-1 && ans>tmp2)){
        ans = tmp2;
    }
    v2.pop_back();

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
    vector<int> t1, t2;
    cout<<sol(0, t1, t2)<<"\n";
}