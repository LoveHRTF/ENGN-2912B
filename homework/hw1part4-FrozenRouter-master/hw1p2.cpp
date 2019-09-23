/* File Name   : hw1p2.cpp
*  Author      : Ziwei Chen
*  Date        : 09/11/2018
*  Description : This program was to determine what happens when
*                each combination of signed to unsigned casts are
*                performed.
*/

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main(){
    // Define max value for signed vars.
    char sig_char_max = -127;       short sig_srt_max = -32767;
    int sig_int_max = -2147483647;  long sig_lng_max = 2147483647;

    // Define signed vars. and starting values
    char sig_char; short sig_srt; int sig_int; long sig_lng;

    // Define unsigned vars.
    unsigned char un_char; unsigned short un_srt; 
    unsigned int un_int;   unsigned long un_lng;

    // Cast for Char
    un_char = static_cast<unsigned char>(sig_char_max);
    un_srt  = static_cast<unsigned short>(sig_char_max);
    un_int  = static_cast<unsigned int>(sig_char_max);
    un_lng  = static_cast<unsigned long>(sig_char_max);
    cout << "Cast From Char >>" << endl;
    cout << un_char << endl; cout << un_srt << endl;
    cout << un_int << endl;  cout << un_lng << endl;
    // Case for Short
    un_char = static_cast<unsigned char>(sig_srt_max);
    un_srt  = static_cast<unsigned short>(sig_srt_max);
    un_int  = static_cast<unsigned int>(sig_srt_max);
    un_lng  = static_cast<unsigned long>(sig_srt_max);
    cout << "Cast From Short >>" << endl;
    cout << un_char << endl; cout << un_srt << endl;
    cout << un_int << endl;  cout << un_lng << endl;
    // Cast for int
    un_char = static_cast<unsigned char>(sig_int_max);
    un_srt  = static_cast<unsigned short>(sig_int_max);
    un_int  = static_cast<unsigned int>(sig_int_max);
    un_lng  = static_cast<unsigned long>(sig_int_max);
    cout << "Cast From Int >>" << endl;
    cout << un_char << endl; cout << un_srt << endl;
    cout << un_int << endl;  cout << un_lng << endl;
    // Cast for long
    un_char = static_cast<unsigned char>(sig_lng_max);
    un_srt  = static_cast<unsigned short>(sig_lng_max);
    un_int  = static_cast<unsigned int>(sig_lng_max);
    un_lng  = static_cast<unsigned long>(sig_lng_max);
    cout << "Cast From long >>" << endl;
    cout << un_char << endl; cout << un_srt << endl;
    cout << un_int << endl;  cout << un_lng << endl;

    return 0;
} 
