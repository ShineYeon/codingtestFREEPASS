//
// Created by 최희연 on 2022/04/12.
//

#include <iostream>
using namespace std;

//첫째 줄에 (A+B)%C, 둘째 줄에 ((A%C) + (B%C))%C, 셋째 줄에 (A×B)%C, 넷째 줄에 ((A%C) × (B%C))%C를 출력한다.


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int a, b, c;
    cin>>a>>b>>c;
    cout<<(a+b)%c<<"\n";
    cout<<((a%c)+(b%c))%c<<"\n";
    cout<<(a*b)%c<<"\n";
    cout<<((a%c)*(b%c))%c<<"\n";
}