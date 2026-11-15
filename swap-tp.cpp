// Implémenter ces trois manières d'échanger la valeur (swap) de deux variables entières
// 1) une fonction swap qui prend en argument les adresses des deux entiers
// 2) une fonction swap qui passe les deux entiers par référence
// 3) en utilisant, directement dans le main, la fonction `std::swap` de la librairie standard utility
// https://en.cppreference.com/cpp/algorithm/swap
// les fonctions swap ne renvoient rien (void)

// Je vous donne ci-dessous un exemple d'utilisation des références avec la fonction incr

#include <iostream>
#include <utility> // pour std::swap

void incr(int &ri)
{
    ri = ri + 1;
}

void swapadresse(int* a , int* b)
{
    int c = *b ;
    *b= *a ;
    *a= c;
}

void swapref(int & a , int & b)
{
    int c = b ;
    b=a ;
    a=c;
}


int main()
{
    int a = 11;
    incr(a);
    int b = 81;  

    // swapadresse(&a, &b); //méthode 1 
    // swapref(a, b); //méthode 2
    std::swap(a, b); //méthode 3

    std::cout << a << std::endl ;
    std::cout << b << std::endl ;

    if ((a == 81) and (b == 12))
        std::cout << "Yes !" << std::endl;
    else
        std::cout << "No !" << std::endl;

    return 0;
}

