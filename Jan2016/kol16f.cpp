#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

int findMax(char *a){
  int n = strlen(a);
  if(n==1){
    cout<<1<<endl;
    return 0;
  }
  int max = 0;
  int max2 = -1;
  int max2i = -1;
  int k = 1;
  int i=0;
  for(i=1;i<n;i++){
    if(a[i] == a[i-1]){
      k++;
    }else{
      if(k>=max){
        max2i = i;
        max2 = max;
        max = k;
      }
       k = 1;
    }
  }
  i--;
  if(k>=max){
    max2i = -2;
    max2 = max;
    max = k;
  }

  for(int j=0;j<n;j++){
    if(a[j] == a[i]){
      k++;
    }else{
      if(k>=max){
        if(max2i != j || max2i != -2){
          max2 = max;
        }else{
          max2 = -1;
          max2i = -1;
        }
        max = k;
      }
      break;
    }
  }

  if(max == 2){
    if(n==2){
      cout<<1<<endl;
    }else cout<<2<<endl;
  }else if(max == 1){
    if(n==2){
      cout<<2<<endl;
    }else cout<<3<<endl;
  }else if(max/2 >= max2){
    cout<<(max/2)<<endl;
  }else cout<<max2<<endl;
}

int main(){
  int t;
  cin>>t;
  int k = 1;
  while(k<=t){
    char *a = new char;
    cin>>a;

    cout<<"Case "<<k<<": ";

    findMax(a);

    k++;
  }
}
