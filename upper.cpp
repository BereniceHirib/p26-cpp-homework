#include <iostream>

bool is_lower(char c){
    return (c >= 'a') and (c<='z');
}

void to_upper(char* str){
    int i=0;
    char c = str[i];
    int delta = 'a' - 'A';

    while (c != '\0'){
        if (is_lower(c)){
            str[i]=str[i] - delta ;
        }
        else{
            str[i]='a';
        }
        i=i+1;
        c=str[i];
    }
}

int main(int argc, char** argv){

    for (int i =1; i < argc; i++){
        to_upper(argv[i]);
        std::cout << argv[i] << std::endl;
    }
    return 0;
}