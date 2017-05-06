#include<iostream>
#include<string.h>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string>
using namespace std;

int main(){
  std::vector<char> word;
  for (std::istreambuf_iterator<char> it(std::cin), end;
     it != end && *it != '\n'; ++it)
      {
          word.push_back(*it);
      }

cout<<word.size();
}
