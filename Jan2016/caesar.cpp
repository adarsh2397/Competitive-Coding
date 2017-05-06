#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
  int n;
  cin>>n;
  char arr[101];
  cin>>arr;
  int k;
  cin>>k;
  k = k%26;
  for(int i=0;i<n;i++){
    if((arr[i] >=65 && arr[i]<=90-k) || (arr[i]>=97 && arr[i]<=122-k))
      arr[i] += k;
    else if((arr[i] >=65 && arr[i]<=90) || (arr[i]>=97 && arr[i]<=122)){
      arr[i] += (k-26);
    }
  }
  cout<<arr;
}
