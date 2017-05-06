#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

int main(){
  char str[1000000];
  long n,k;
  cin>>n>>k;
  cin>>str;
  long req = 0;
  for(long i=0;i<n/2;i++){
    if(str[i] != str[n-i-1]){
      req++;
    }
  }

  if(req>k){
    cout<<-1<<endl;
    return 0;
  }
  req = k - req;

  for(long i=0;i<n/2;i++){
    if(str[i] != str[n-i-1]){
      if(req>0){
        str[i] = str[n-i-1] = '9';
        req--;
      }else{
        str[i] = str[i]>str[n-i-1]?str[i]:str[n-i-1];
        str[n-i-1] = str[i]>str[n-i-1]?str[i]:str[n-i-1];
      }
    }else if(req > 1 && str[i] != '9'){
      str[i] = str[n-i-1] = '9';
      req = req - 2;
    }
  }

  if(req >= 1 && n%2 !=0){
    str[n/2] = '9';
  }

  cout<<str<<endl;
  cout<<strlen(str)<<endl;
}
