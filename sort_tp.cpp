#include <iostream>

// vr:----------
// vr: je mets des commentaires (précédés par vr:---) dans ton code 

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
        for (int j=0 ; j<n-1-i ; j++){
            // vr:----------
            // vr: à l'étape i=1 tu sais que l'élément n-1 est déjà le plus grand : donc inutile de re-tester n-1
            // vr:   (généralise avec i)
            if (tab[j+1]<tab[j]){
                // vr:----------
                // vr: pas besoin de 2 variables intermédiaires : une seule suffit
                int b=tab[j];
                tab[j]=tab[j+1];
                tab[j+1]=b; // vr: second ; inutile
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
        int min = i;
        for (int j=i ; j<n ; j++){
            // vr:----------
            // vr: je me suis mal expliquée
            //    - à l'étape 0 tu parcours tout le tableau, tu trouves le min, dont tu gardes l'indice
            //    - mais tu ne fais aucun échange dans la boucle !!
            //    - c'est quand tu es sortie du for (de celui-là) que tu échanges l'élément de position 0 avec l'élément
            //      à l'indice du min (tu généralises)
            //       
            if (tab[j]<tab[min]){
                // vr:----------
                // vr:  ton algo fonctionne mais il fait des échanges inutiles
                //      et ce n'est pas le tri par insertion... à revoir
                min=j; 
            }
        int b=tab[i];
        tab[i]=tab[min]; 
        tab[min]=b; 
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
    // vr:----------
    // vr: très bien
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
    // bubble_sort(tab, n);  // vr: je commente
    bubble_sort(tab, n);

    std::cout << "after" << std::endl;
    print(tab, n);
    // affiche: -9999, -45, 0, 2, 6, 7, 12, 23, 34, 45, 78, 990,
    return 0;
}