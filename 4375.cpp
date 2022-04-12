//
// Created by 최희연 on 2022/04/12.
//

#include <iostream>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        int x=1;
        int cnt = 1;
        int pr = x%n;
        while(pr!=0){
            cnt++;
            pr = (pr*10+1)%n;
        }
        cout<<cnt<<"\n";
    }
}