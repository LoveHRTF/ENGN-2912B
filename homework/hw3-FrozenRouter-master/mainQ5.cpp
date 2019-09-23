#include <iostream>
#include "concat.h"
#include "substr.h"
#include "erase.h"

using namespace std;

// TODO: 1) Add declarations in src/concat.h, src/substr.h, and src/erase.h
//       2) Add implementations in src/concat.cpp, src/substr.cpp, and src/erase.cpp
//       3) Write tests for your code below.

int main(){
//************************ P1 ************************
  cout << endl;
  cout <<"Problem 1 ->"<< endl;
  cout <<"Expect: BrownUni"<< endl;
  cout <<"Actual:"<< endl;

  char my_string_1[6] = {'B','r','o','w','n','\0'};
  char my_string_2[4] = {'U','n','i','\0'};
  char* my_result;
  
  my_result = concat(my_string_1, my_string_2);

  for(int i = 0; my_result[i] != '\0'; i++){
    cout << my_result[i] << endl;
  }

//************************ P2 ************************
  cout << endl;
  cout <<"Problem 2 ->"<< endl;
  cout <<"Expect ->"<< endl;
  cout <<"flag = 1, n = 5 ->"<< endl;
  unsigned n;
  bool flag;
  const char* my_string_3 = "ILoveAMDDDamnAMd";
  const char* my_string_4 = "AMD";

  flag = substr(my_string_3 , my_string_4 , n);

  cout <<"Actual:"<< endl;
  cout <<"Flag = "<< flag << endl;
  cout <<"n = "<< n << endl;

  
//************************ P3 ************************
  cout << endl;
  cout <<"Problem 3 ->"<< endl;
  cout <<"Expect: YesAMD! ->"<< endl;
  cout <<"Actual:"<<endl;
  char my_string_5[11] = {'Y','e','s','A','M','D','!','O','M','G','\0'};
  char my_string_6[4] = {'O','M','G','\0'};
  char* my_result2;
  my_result2 = erase(my_string_5, my_string_6);
    for(int i = 0; my_result2[i] != '\0'; i++){
    //  cout << i << endl;
    cout << my_result2[i] << endl;
  }


}
