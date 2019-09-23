#include "concat.h"
#include <iostream>

using namespace std;

// TODO: Implement your "concat" function 

char* concat(char* string_1, char* string_2){

    int len1 = 0;int len2 = 0;
    for (int i = 0; string_1[i] != '\0'; i ++){
        len1++;
    }
    for (int i = 0; string_2[i] != '\0'; i ++){
        len2++;
    }

    // Create string to store result DMA
    char* string_result = new char[len1 + len2 + 1];
    
    int i; int j;
    // Assign input string 1 to result
    for (i = 0; string_1[i] != 0; i++){
        string_result[i] = string_1[i];
    }

    // Assign input string 2 to result
    for (j = 0; string_2[j] != 0; j++){
        string_result[i] = string_2[j];
        i++;
    }

    // i already increased to i + 1 when exit the loop
    string_result[i] = '\0'; 

    char* store = &string_result[0];

    //delete [] string_result;

    return store; 
}
