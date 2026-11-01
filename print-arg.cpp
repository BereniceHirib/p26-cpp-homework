#include <iostream>

int main(int argc, char** argv){
    std::cout << "Tu as tapé " << argc << " arguments sur la ligne de commande." << std::endl;
    std::cout << "Les voici :" << std::endl;
    for (int i=0 ; i< argc ; i++){
        std::cout << argv[i] << std::endl;
    }
    return 0;
}