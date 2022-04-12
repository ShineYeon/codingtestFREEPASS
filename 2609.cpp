//
// Created by 최희연 on 2022/04/13.
//

#include <iostream>
using namespace std;

int lcm(int a, int b, int g){
    a /= g;
    b /= g;
    return a*b*g;
}

int gcd(int a, int b){ //최대공약수
    if(b==0) return a;
    return gcd(b, a%b);

}

int main(){
    int a, b;
    cin>>a>>b;
    int great;
    if(a<b)
        great=gcd(a, b);
    else
        great = gcd(b, a);
    int least = lcm(a, b, great);
    cout<<great<<"\n"<<least<<"\n";
}