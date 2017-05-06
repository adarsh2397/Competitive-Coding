//Hamming Distance
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    string a,b;
    cin>>a;
    cin>>b;
    int n = a.size();
    int sum = 0;
    for(int i=0;i<n;i++){
      sum += abs(b[i]-a[i]);
    }

    cout<<sum<<endl;
  }
}
