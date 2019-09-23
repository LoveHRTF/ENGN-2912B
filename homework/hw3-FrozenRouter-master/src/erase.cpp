#include "erase.h"
#include <iostream>
#include <stdio.h>

using namespace std;
// TODO: Implement your "erase" function 
char* erase(const char* sb,const char* k){
    
    bool flag;

    int length_s = 0;int length_k = 0;                          // Get Length for both strings
    for (int i = 0; sb[i] != '\0'; i ++){
        length_s++;
    }
    for (int i = 0; k[i] != '\0'; i ++){
        length_k++;
    }

    int length_diff = (length_s - length_k);                    // Find the length difference
    
    char* s = new char[length_diff + 1]();
    for (int i = 0; sb[i] != '\0'; i++){
        s[i] = sb[i];
    }
    

    for (int offset = 0; offset <= length_diff; offset++){      // Push one offset a time to exam first char in k
                                                                // Check if s Char Starts Equal to first in k
        if (s[offset] == k[0]){                                 // First Match, string may match, need to check in detial
            flag = 1;
            for (int k_i = 0; k_i < length_k; k_i++){           // Check if k match s starting from this point
                if (s[offset + k_i] != k[k_i]){                 // This is not sub string
                    cout << s[offset+k_i] << endl;
                    flag = 0;
                }
            }
            if (flag == 1){                                     // Sub String! Erase!
                int k_i;

                for (k_i = 0; k_i < length_diff; k_i++){
                    s[offset + k_i] = s[offset + length_k + k_i];
                }
                s[k_i + offset - 1] = '\0';
                break;
            }
        }

    }

    return s;
}