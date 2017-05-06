#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;

int decodeInteger(int arr[],int n,int A[],int B[]){
  for(int i=0;i<n;i++){
    long helper = pow(2,16) - 1;
    int one = arr[i] & helper;
    helper = helper<<16;
    int two = arr[i] & helper;
    two = two>>16;
    A[i] = one;
    B[i] = two;
  }
}

int main(){
  int t;
  cin>>t;
  int k = 1;
  while(k<=t){
    int arr[10000];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }

    cout<<"Case "<<k<<":"<<endl;
    int A[10000],B[10000];
    decodeInteger(arr,n,A,B);
    for(int i=0;i<n;i++){
      cout<<A[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
      cout<<B[i]<<" ";
    }
    cout<<endl;
    k++;
  }
}
