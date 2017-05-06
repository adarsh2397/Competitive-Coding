#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;

int main(){
  char a[100000];
  cin>>a;


  int n = strlen(a);

  map<char,int> m;

  for(int i=0;i<n;i++){
    if(m.find(a[i]) == m.end()){
      m[a[i]] = 1;
    }else m[a[i]]++;
  }

  int same = m[a[0]];
  int count = 0;
  int number = 0;
  for(map<char,int>::iterator it=m.begin();it!=m.end();it++){
    if(same!=it->second){
      if(abs(it->second - same)>=2 && it->second != 1){
        number = abs(it->second - same);
      }
      count++;
    }
  }

  if((count == 0)|| (count == 1 && number<=1)|| (count == n-1 && m[a[1]] == m[a[2]])){
    cout<<"YES";
  }else cout<<"NO";
}
