#include <iostream>

int func(int i){
    return i*i;
}

int main(int argc, char* argv[]){
    int i = atoi(argv[1]);

    i = func(i);
    i = func(i);
    i = func(i);

    std::cout << i << std::endl;

    return 0;
}
