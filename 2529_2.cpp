//
// Created by 최희연 on 2022/04/09.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int k;
char ready[20];
bool selected[10];
vector<string> vs;

bool check(char x, char y, char op){
   if(op == '<'){
       if(x>y) return false;
   }
   if(op == '>'){
       if(x<y) return false;
   }
    return true;
}

void sol(int idx, string s) {
    if(idx == k+1){
        vs.push_back(s);
        return;
    }
    for(int i=0; i<=9; i++){
        if(selected[i]) continue;
        if(idx==0 || check(s[idx-1], i+'0', ready[idx-1])) {
            selected[i] = true;
            sol(idx + 1, s + to_string(i));
            selected[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>k;
    for(int i=0; i<k; i++){
        cin>>ready[i];
    }
    sol(0, "");
    auto p = minmax_element(vs.begin(), vs.end());
    cout<<*p.second<<"\n"<<*p.first<<"\n";
}