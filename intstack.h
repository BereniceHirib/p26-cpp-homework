#include <iostream>

struct Intstack{
    int size;
    int top;
    int* stack;



    Intstack(int s){
        size = s;
        top = 0 ;
        stack = new int [size];
    }
    
    ~ Intstack(){
        delete [] stack;
    }

    void push(int e){
        stack[top]=e;
        top=top+1;
    }

    void print(){
        std::cout << "[ ";
        for (int i = 0 ; i < top ; i++){
             std::cout << stack[i] << " ";
         }
        std::cout << "[" << std::endl;
    }

    bool is_empty(){
        return top==0;
    }

    bool is__full(){
        return top==size;
    }

    int pop(){
        top=top-1;
        return stack[top];
    }
    
};