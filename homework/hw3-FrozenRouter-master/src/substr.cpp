#include "substr.h"
#include <iostream>

using namespace std;

// TODO: Implement your "substr" function 

bool substr(const char* s, const char* k, unsigned& n){

    bool flag;

    int length_s = 0;int length_k = 0;                         // Get Length for both strings
    for (int i = 0; s[i] != '\0'; i ++){
        length_s++;
    }
    for (int i = 0; k[i] != '\0'; i ++){
        length_k++;
    }
    
    int length_diff = length_s - length_k;                      // Find the length difference

    for (int offset = 0; offset <= length_diff; offset++){      // Push one offset a time to exam first char in k
                                                                // Check if s Char Starts Equal to first in k
        if (s[offset] == k[0]){                                 // First Match, string may match, need to check in detial
            flag = 1;
            for (int k_i = 0; k_i < length_k; k_i++){           // Check if k match s starting from this point

                if (s[offset+k_i] != k[k_i]){                   // This is not sub string
                    flag = 0;
                }
            }
            if (flag == 1){                                     // Sub String! Output offset N and exit
                n = offset;
                break;
            }
        }

    }

    return flag;
}
