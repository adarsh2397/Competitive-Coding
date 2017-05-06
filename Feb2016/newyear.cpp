#include<stdio.h>
#include<iostream>
using namespace std;


int main(){
  int t;
  cin>>t;
  while(t--){
    int a[100000],m[100000];

    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
      cin>>a[i];
      m[i] = i;
    }
    int count = 0,flag = 0;
    for(int i=1;i<=n;i++){
      if(a[i]>i){
        if(a[i]-i == 1){
          count++;
          int temp = m[i];
          m[i] = m[i+1];
          m[i+1] = temp;
        }else if(a[i]-i == 2){
          count += 2;
          int temp = m[i+2];
          m[i+2] = m[i+1];
          m[i+1] = m[i];
          m[i] = temp;
        }else{
          flag = 1;
        }
      }else if(a[i]>m[i]){
        if(m[i+1] == a[i]){
          count++;
          int temp = m[i];
          m[i] = m[i+1];
          m[i+1] = temp;
        }else if(m[i+2] == a[i]){
          count += 2;
          int temp = m[i+2];
          m[i+2] = m[i+1];
          m[i+1] = m[i];
          m[i] = temp;
        }else{
          //cout<<"Hello";
           flag = 1;
        }
      }
    }

    if(flag){
      cout<<"Too chaotic"<<endl;
    }else cout<<count<<endl;
  }

}
