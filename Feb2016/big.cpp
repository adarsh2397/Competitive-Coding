#include<stdio.h>
#include<iostream>
#include<cstdio>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;

void display(std::vector<char> a){
  for(std::vector<char>::const_iterator i = a.begin();i != a.end();i++){
    cout<<*i;
  }
}

int main(){
  int t;
  cin>>t;

  while(t--){
    std::vector<char> a;
    char ch[100];
    cin>>ch;
    for(int i=0;i<strlen(ch);i++){
      a.push_back(ch[i]);
    }
    //a.push_back('\0');

    int n = a.size();
    /*
    int x = n-1;
    int i=0;
    int flag = 0;
    while(i<n){
      int val = a[n-i-1];
      x = n-i-1;
      while(x>=0){
        if(a[x] < val){
          a[n-i-1] = a[x];
          flag = 1;
          break;
        }
        x--;
      }
      if(flag){
        a[x] = val;
        break;
      }
      i++;
    }

    if(flag){
      sort(a.begin()+x+1,a.end());
          display(a);
    }else cout<<"no answer";
    cout<<endl;
    */

    int x = n-1;
    int i = 0,j=1;
    int flag = 0;
    while(i<n){
      x = n-1;
      while(x>=(0+j)){
        if(a[x-j] < a[x]){
          char temp = a[x];
          a[x] = a[x-j];
          a[x-j] = temp;
          flag = 1;
          break;
        }
        x--;
      }

      if(flag){
        break;
      }
      i++;
      j++;
    }

    sort(a.begin()+x+1,a.end());
    if(flag){
      display(a);
    }else cout<<"no answer";
    cout<<endl;
  }
}
