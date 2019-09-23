/* File Name   : hw1p4.cpp
*  Author      : Ziwei Chen
*  Date        : 09/11/2018
*  Description : This program was to 
*/
#include <iostream>
#include <string>
using namespace std;

int main(){
    char sig_char = -123;         short sig_srt = 122;
    int sig_int = 123;           long sig_lng = 122;
    unsigned char un_char = 122; unsigned short un_srt = 122; 
    unsigned int un_int = 122;   unsigned long un_lng = 122;
    float flt = 123.00;          double dub = 122;
    cout << "SB??" << endl;
    // All Char
    if (flt != sig_int){
        cout << "flt != sig_int" << endl;
    } else {
        cout << "0Pass!" << endl;
    }
    if (sig_char != sig_srt){
        cout << "sig_char != sig_srt" << endl;
    } else {
        cout << "1Pass!" << endl;
    }
    if (sig_char != sig_int){
        cout << "sig_char != sig_int" << endl;
    } else {
        cout << "2Pass!" << endl;
    }
    if (sig_char != sig_lng){
        cout << "sig_char != sig_lng" << endl;
    } else {
        cout << "3Pass!" << endl;
    }
    if (sig_char != un_char){
        cout << "sig_char != un_char" << endl;
    } else {
        cout << "4Pass!" << endl;
    }
    if (sig_char != un_srt){
        cout << "sig_char != un_srt" << endl;
    } else {
        cout << "5Pass!" << endl;
    }
    if (sig_char != un_int){
        cout << "sig_char != un_int" << endl;
    } else {
        cout << "6Pass!" << endl;
    }
    if (sig_char != un_lng){
        cout << "sig_char != un_lng" << endl;
    } else {
        cout << "7Pass!" << endl;
    }
    // All Srt
    if (sig_srt != sig_int){
        cout << "sig_srt != sig_int" << endl;
    } else {
        cout << "8Pass!" << endl;
    }
    if (sig_srt != sig_lng){
        cout << "sig_srt != sig_lng" << endl;
    } else {
        cout << "9Pass!" << endl;
    }
    if (sig_srt != un_char){
        cout << "sig_srt != un_char" << endl;
    } else {
        cout << "10Pass!" << endl;
    }
    if (sig_srt != un_srt){
        cout << "sig_srt != un_srt" << endl;
    } else {
        cout << "11Pass!" << endl;
    }
    if (sig_srt != un_int){
        cout << "sig_srt != un_int" << endl;
    } else {
        cout << "12Pass!" << endl;
    }
    if (sig_srt != un_lng){
        cout << "sig_srt != un_lng" << endl;
    } else {
        cout << "13Pass!" << endl;
    }
    // All int
    if (sig_int != sig_lng){
        cout << "sig_int != sig_lng" << endl;
    } else {
        cout << "14Pass!" << endl;
    }
    if (sig_int != un_char){
        cout << "sig_int != un_char" << endl;
    } else {
        cout << "15Pass!" << endl;
    }
    if (sig_int != un_srt){
        cout << "sig_int != un_srt" << endl;
    } else {
        cout << "16Pass!" << endl;
    }
    if (sig_int != un_int){
        cout << "sig_int != un_int" << endl;
    } else {
        cout << "17Pass!" << endl;
    }
    if (sig_int != un_lng){
        cout << "sig_int != un_lng" << endl;
    } else {
        cout << "18Pass!" << endl;
    }
    // All lng
    if (sig_lng != un_char){
        cout << "sig_lng != un_char" << endl;
    } else {
        cout << "Pass!" << endl;
    }
    if (sig_lng != un_srt){
        cout << "sig_lng != un_srt" << endl;
    } else {
        cout << "Pass!" << endl;
    }
    if (sig_lng != un_int){
        cout << "sig_lng != un_int" << endl;
    } else {
        cout << "Pass!" << endl;
    }
    if (sig_lng != un_lng){
        cout << "sig_lng != un_lng" << endl;
    } else {
        cout << "Pass!" << endl;
    }
    // All un Char
    if (un_char != un_srt){
        cout << "un_char != un_srt" << endl;
    } else {
        cout << "Pass!" << endl;
    }
    if (un_char != un_int){
        cout << "un_char != un_int" << endl;
    } else {
        cout << "Pass!" << endl;
    }
    if (un_char != un_lng){
        cout << "un_char != un_lng" << endl;
    } else {
        cout << "Pass!" << endl;
    }
    // All un Srt
    if (un_srt != un_int){
        cout << "un_srt != un_int" << endl;
    } else {
        cout << "Pass!" << endl;
    }
    if (un_srt != un_lng){
        cout << "un_srt != un_lng" << endl;
    } else {
        cout << "Pass!" << endl;
    }
    // All un Int
    if (un_int != un_lng){
        cout << "un_int != un_lng" << endl;
    } else {
        cout << "Pass!" << endl;
    }
    // All un lng
    cout << "SB!!" << endl;
    return 0;
} 
