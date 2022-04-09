//
// Created by 최희연 on 2022/04/09.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int k; // 부등호 개수
char ready[20];
bool selected[10];
vector<string> ret; //정답

bool check(string s){
    for(int i=0; i<k; i++){
        if(ready[i] == '<'){
            if(s[i] > s[i+1]) return false;
        }
        if(ready[i] == '>') {
            if(s[i]<s[i+1]) return false;
        }
    }
    return true;
}

void sol(int idx, string s) {
    if(idx == k+1) {
        if(check(s))
            ret.push_back(s);
        return;
    }
    for(int i=0; i<=9; i++){
        if(selected[i]) continue;
        selected[i] = true;
        sol(idx+1, s+ to_string(i));
        selected[i] = false;
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>k;
    for(int i=0; i<k; i++){
        cin>>ready[i];
    }
    sol(0, "");
    auto p = minmax_element(ret.begin(), ret.end());
    cout<<*p.second<<"\n"<<*p.first<<"\n";
}