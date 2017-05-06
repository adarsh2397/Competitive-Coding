  #include<stdio.h>
  #include<iostream>
  #include<string.h>
  using namespace std;

  int main(){
    string str;
    cin>>str;
    int count = 0;
    int n = str.size();
    for(int i=0;i<n;i=i+3){
      if(str[i] != 'S'){
        count++;
      }
      if(str[i+1] != 'O')
        count++;
      if(str[i+2] != 'S')
        count++;
    }
    cout<<count;
  }
