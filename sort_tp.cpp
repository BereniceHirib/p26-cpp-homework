#include <iostream>

// implémentez un tri de tableau d'entier

// par exemple l'algotiehme de bubble_sort ou d'insertion_sort
// ou un autre...

void bubble_sort(int tab[], int n)
{
    // tab étant le tableau à trier
    // n étant la taille du tableau
    // on trie dans l'ordre croissant

    // 1) parcourez le tableau tab
    //    si deux éléments adjacents ne sont pas dans l'ordre i.e. si tab[j] > tab[j+1]
    //    alors échangez le contenu des cases j et j+1 du tableau
    // 2) faites cette opération jusqu'à ce que le tableau soit trié
    // 3) éviter de faire du travail en trop
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            if (tab[i]<tab[j]){
                int a=tab[i];
                int b=tab[j];
                tab[j]=a;
                tab[i]=b;;
            }
        }
    }
}

void insertiom_sort(int tab[], int n)
{
    // tab étant le tableau à trier
    // n étant la taille du tableau
    // on trie dans l'ordre croissant

    // on parcours le tableau de 0 à n-1, on trouve le min et on l'échange avec l'élément 0 du tableau
    // on parcours le tableau de 1 à n-1, on trouve le min et on l'échange avec l'élément 1 du tableau
    // on généralise ...
    for (int i=0 ; i<n ; i++){
        int m = tab[i];
        for (int j=i ; j<n ; j++){
            if (tab[j]<m){
                int a=m;
                int b=tab[j];
                tab[j]=a;
                m=b;

            }
        tab[i]=m;
        }
    }
}

// implémentez une fonction qui affiche le tableau tab sur la sortie standard std::cout
// mettez '[' et ']', des ',' entre les entiers et allez à-la-ligne à la fin de l'affichage
void print(int tab[], int n)
// tab est le tableau à trier
// n est la taille du tableau
{
    std::cout << "[ ";
    for (int i = 0 ; i < n-1; i++){
        std::cout << tab[i] << " , ";
    }
    std::cout << tab[n-1] << " ]" << std::endl;
}

int main()
// optionnel passez les entiers sur la ligne de commande
//           pensez à la fonction atoi de la library cstdlib
{
    int n = 12;
    int tab[]{0, 45, 23, 12, 78, -45, 34, 990, 2, 6, 7, -9999};
    std::cout << "before" << std::endl;
    print(tab, n);
    // affiche: 0, 45, 23, 12, 78, -45, 34, 990, 2, 6, 7, -9999,

    // call your sort here:
    bubble_sort(tab, n);

    std::cout << "after" << std::endl;
    print(tab, n);
    // affiche: -9999, -45, 0, 2, 6, 7, 12, 23, 34, 45, 78, 990,
    return 0;
}