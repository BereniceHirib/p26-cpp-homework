// On va utiliser votre IntStack pour évaluer une expression arithmétique écrite en notation polonaise inversée
// voir https://fr.wikipedia.org/wiki/Notation_polonaise_inverse

// En fin de fichier vous avez:
//  - des rappels de cours (et des indices sur ce sujet mais réfléchissez avant...

// 1) La notation polonaise inversée (RPN)
// ---------------------------------------

//    Elle permet d'écrire de façon non ambiguë les formules arithmétiques:
//      - sans utiliser de parenthèses
//      - sans que la priorité des opérateurs n'intervienne.
//    comme par exemple:
//       3 x (10 + 5) est 3 10 5 + *
//       (4 x (1 + 2)) - 3  est 4 1 2 + * 3 -
//    et donc de pouvoir les évaluer facilement !

//    Les opérandes sont des entiers
//    Les opérateurs sont:
//        '+' (plus binaire)
//        '-' (moins binaire)
//        'x' (multiplier binaire) et pas '*' car c'est un caractère spécial dans les terminaux bash !!!
//        '/' (diviser binaire)
//        '!' (moins unaire) et pas '-' car c'est déjà utilisé pour le moins binaire

// 2) Passez l'expression RPN "sur la ligne de commande"
// -----------------------------------------------------

// par exemple, polish étant votre exécutable
//    $ ./polish 3 10 5 + x
//    45
// dans votre main :
//    argc est 6
//    argv est ["./polish", "3", "10", "5", "+", "x"]
//    $ g++ file.cpp -o expr
//    $ ./expr 3 10 5 + x
//    45
//    $ ./expr 4 1 2 + x 3 -
//    9

// 3) Comment faire ?
// ------------------

//    Commencez par réfléchir avec un papier et un crayon
//    sur ce que votre code doit faire en voyant dans argv "3" puis "10" puis "5", "+", "x"
//     je vois "3"
//     je teste que c'est un nombre
//     je transforme la chaîne de caractère "3" en un nombre
//        (soit à-la-main, soit avec la fonction atoi de la cstdlib, ou stoi de string...)
//     je stocke 3 quelque part...
//     ...
//    Je vous donne des indices en annexe en fin de ce fichier

// 4) utilisez votre IntStack
// --------------------------

// Vous devrez ranger les opérandes et les résultats intermédiaires quelque part.
// Essayez pour cela utilisez votre pile:
//    si elle ne convient pas ou si il lui manque des fonctions corrigez là !

//  mettez le code de votre IntStack dans un fichier intstack.h
//     i.e. la struct avec ses méthodes définies à l'intérieur du bloc de la struct

// 5) Utilisez la stack de la librairie standard C++
// -------------------------------------------------
// mais attention elle ne fonctionne pas exactement comme la vôtre
// regardez https://cplusplus.com/reference/stack/stack/
// ou https://en.cppreference.com/cpp/container/stack

// je vous donne un exemple où on l'utilise sur des int

#include <iostream>
#include "intstack.cpp" //pour include votre intstack
#include <stack>
#include <cstring>

int main(int argc, char *argv[])
{
    // votre code avec votre IntStack
    int s = argc;
    Intstack st(s);
    for (int i = 1 ; i < s ; i++){
        int delta = 0 ;
        int j=0;
        while ((argv[i][j] != '\0') and ('0'<= argv[i][j]) and (argv[i][j] <='9')){
            delta = delta * 10 + (argv[i][j] - '0');
            j=j+1;
        }
        if ((j>0) and (argv[i][j]=='\0')){
            st.push(delta);
        }

        if (std::strcmp(argv[i], "!") == 0 ){// ou argv[i][0]=='!')
            int a = st.pop() ;
            st.push(-a);
        } 
        else if (std::strcmp(argv[i], "+")==0){
            int a = st.pop() ;
            int b = st.pop() ;
            st.push(a+b);
        }
        else if (std::strcmp(argv[i], "-")==0){
            int a = st.pop() ;
            int b = st.pop() ;
            st.push(b-a);
        }
        else if (std::strcmp(argv[i], "x")==0){
            int a = st.pop() ;
            int b = st.pop() ;
            st.push(a*b);
        }
        else if (std::strcmp(argv[i], "/")==0){
            int a = st.pop() ;
            int b = st.pop() ;
            if (a==0){
                std::cerr << "Divison par 0";
                return -1;
            }
            st.push(b/a);
        }
    }
    //st.print();
    std::cout << "le résultat avec mon IntStack est " << st.pop() << std::endl;

    
    // votre code avec la std::stack<int>
    // Notez que pop ne teste pas si la pile est vide pour des raisons de performances de code
    //    (possible segmentation fault si problème)
    // see https://cplusplus.com/reference/deque/deque/back/
    // exemple de std::stack avec des int
    // int est passé comme argument de type au template de la class stack
    std::stack<int> stack;
    // stack.push(12);
    // stack.push(17);
    // std::cout << stack.top() << std::endl;
    // stack.pop();
    // std::cout << stack.top() << std::endl;
    for (int i = 1 ; i < s ; i++){
        int delta = 0 ;
        int j=0;
        while ((argv[i][j] != '\0') and ('0'<= argv[i][j]) and (argv[i][j] <='9')){
            delta = delta * 10 + (argv[i][j] - '0');
            j=j+1;
        }
        if ((j>0) and (argv[i][j]=='\0')){
            stack.push(delta);
        }

        if (std::strcmp(argv[i], "!") == 0 ){// ou argv[i][0]=='!')
            int a = stack.top() ;
            stack.pop() ;
            stack.push(-a);
        } 
        else if (std::strcmp(argv[i], "+")==0){
            int a = stack.top() ;
            stack.pop() ;
            int b = stack.top() ;
            stack.pop() ;
            stack.push(a+b);
        }
        else if (std::strcmp(argv[i], "-")==0){
            int a = stack.top() ;
            stack.pop() ;
            int b = stack.top() ;
            stack.pop() ;
            stack.push(b-a);
        }
        else if (std::strcmp(argv[i], "x")==0){
            int a = stack.top() ;
            stack.pop() ;
            int b = stack.top() ;
            stack.pop() ;
            stack.push(a*b);
        }
        else if (std::strcmp(argv[i], "/")==0){
            int a = stack.top() ;
            stack.pop() ;
            int b = stack.top() ;
            stack.pop() ;
            if (a==0){
                std::cerr << "Divison par 0";
                return -1;
            }
            stack.push(b/a);
        }
    }
    std::cout << "le résultat avec la std::stack<int> est " << stack.top() << std::endl;

    return 0;
}

// ANNEXES

// 1) Rappel sur La ligne de commande
// ----------------------------------
//    En C++, la fonction main stocke les éléments passés "sur de la lignes de commande"
//    dans le tableau de chaînes de caractère argv et la taille du tableau dans la variable argc.

//    Dans notre exemple, les entiers et les opérateurs sont donc reçu par le main dans le tableau argv
//    comme par exemple pour:
//      $ ./polish 3 10 5 + x
//    argc est 6
//    argv est ["./polish", "3", "10", "5", "+", "x"]

//    2) Rappel sur le format des caractères

//    Pour représenter les caractères en mémoire, on utilise un format d'encodage des caractères
//    (chaque caractère est représenté par un entier)

//    En C++ (en C) pour encoder les caractères, on utilise le format ascii.
//    où chaque caractère est représenté par un entier compris entre 0 et 127.

//    On n'en a pas besoin dans cet exercice, mais si vous voulez afficher le code ascii d'un caractère,
//    (comme afficher le caractère l'affichera lui et non son code ascii)
//    vous devez demander à C++ la représentation de ce caractère en tant qu'entier
//    (un caractère est de type char, on veut le convertir en entier donc on fait :
//       char c = '+';
//       std::cout << (int)c << std::endl; // affichera 43

// 2) Rappel sur les chaînes de caractères
// ---------------------------------------
//    En C++, une chaîne de caractères est représentée par un tableau de caractères (de char).
//    Par exemple :P ranger les opérandes et les résultats intermédiaires ?
//    Faites une deuxi
//       la chaîne de caractères "+" est représentée par le tableau de caractères  ['+', '\0']
//      la chaîne de caractères "15" est représentée par le tableau de caractères ['1', '5', '\0']
//    Notez le caractère '\0' à la fin de chaque tableau,
//    c'est le caractère ascii nul qui indique la fin de la chaîne de caractères.

// 3) Indices pour le sujet
// ------------------------

// Les opérateurs et les opérandes

// Certaines chaînes de caractères contiendront des opérandes et d'autres des opérateurs.
// Pour analyser le contenu des chaînes de caractères,
// on se base sur la représentation de chaque caractère dans le format ascii.

// On distingue deux chaînes de caractères différentes dans notre exercice:

// 1) les opérateurs (la chaîne de caractère "+" représente l'opérateur somme)
// 2) les opérandes (la chaîne de caractère "15" commence par un caractère qui est un entier
//       donc, a priori, elle représente un nombre (sauf que "15A" n'est pas un nombre)

// Notons que, dans la table ascii, les codes des chiffres ('0', '1', ..., '9') sont adjacents, ainsi
//      - la valeur du code du caractère représentant le 0 est '0'
//      - la valeur du code du caractère représentant le 1 est '1' (qui est '0'+1)
// donc : une variable c de type char contiendra un chiffre si la valeur de c est comprise entre '0' et '9'

// sur ce que votre code va faire en voyant dans argv ["./expr", "3", "10", "5", "+", "x"]
//       1) vous voyez 3
//             c'est un nombre, vous ne savez pas quoi en faire : vous le mettez de côté...
//       2) vous voyez 10 idem
//       3) vous voyez 5  idem
//       4) ah ! vous voyez un opérateur ici +
//             vous savez le nombre d'opérandes dont il a besoin
//               (+ est binaire)
//             vous savez où les trouver (ce sont les deux derniers nombres mis de côté, 10 et 5)
//             vous les additionnez
//             vous mettez le résultat de côté
//    ...
