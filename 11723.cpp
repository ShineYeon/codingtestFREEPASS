//
// Created by 최희연 on 2022/04/14.
//

#include <iostream>
#include <string>
using namespace std;
int S = 0;

void empty() {
    S = 0;
}

void all(){
    for(int i=0; i<21; i++){
        S|=(1<<i);
    }
}

void toggle(int x){
    S ^= (1<<x);
}

void check(int x){
    if(S&(1<<x)) cout<<"1\n";
    else cout<<"0\n";
}

void remove(int x){
    S &= ~(1<<x);
}

void add(int x){
    S |= (1<<x);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        string s;
        int n;
        cin>>s;
        if(s=="add") {
            cin>>n;
            add(n);
        }
        else if(s=="check") {
            cin>>n;
            check(n);
        }
        else if(s=="remove") {
            cin>>n;
            remove(n);
        }
        else if(s=="toggle") {
            cin>>n;
            toggle(n);
        }
        else if(s=="all") all();
        else if(s=="empty") empty();
    }


}