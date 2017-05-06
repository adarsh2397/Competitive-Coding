#include<stdio.h>
#include<iostream>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;

  while(t--){
    double b;
    cin>>b;

    long x = log2(b);
    long y = (pow(2,x));;
    double answer = b/y;;
    answer *= (y-1);
    cout<<answer/2<<endl;
  }
}
