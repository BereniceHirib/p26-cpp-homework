#include <iostream>

// Nous allons implémenter une pile d'entiers de manière très basique.
// Nous la complexifierons par la suite.

// La pile est constituée :
//   - d'un tableau d'entier (stack), avec sa taille (size)
//   - du nombre des d'éléments empilés (top)
//     ce qui vous donne l'indice du prochain élément à empiler
//   - des fonctions :
//     - push (empile un élément dans la pile)
//     - pop (renvoie l'élement en haut de la pile
//            et considère que cet élément n'est plus dans la pile)
//     - print (affiche les éléments empilés) [ 12 67 23 [
// Les cas d'erreur :
//     - is_empty (teste si la pile est vide :
//                 on ne dépile pas une pile vide)
//     - is_full (testent si la pile est pleine
//                on n'empile pas sur une pile pleine)
//    en cas d'erreur pour l'instant on ne fait pas l'opération
//    (notre pile est potentiellement fausse avec des éléments non empilés et/ou non dépilés)

// Voici les entêtes des fonctions où vous devez passer les arguments :

void print(int p[], int t)
// cette fonction affiche les entiers empilés
// elle a besoin de la pile et du nombre d'éléments empilés
{
    std::cout << " [";
    for (int i = 0 ; i < t ; i++){
        std::cout << p[i] << " ";
    }
    std::cout << "[" << std::endl;
}

// renvoie true si la pile est vide, false sinon
bool is_empty(int p[], int t)
{
    if (t==0){
        return true; // pour compiler/exécuter l'exemple
    }
    else {
        return false;
    }
}

// renvoie true si la pile est pleine, false sinon
bool is_full(int p[], int t, int s)
{
    if (t==s){
        return true; // pour compiler/exécuter l'exemple
    }
    else {
        return false;
    }
}

void push(int p[], int& t, int s, int e) // e est l'élément à empiler
// cette fonction ajoute un entier à la pile passé en argument
// elle vérifie que la pile n'est pas pleine avant d'empiler
// et ne fait rien sinon
{
    if (not is_full(p,t,s)){
        p[t]=e;
        t=t+1;
    }
    else{
         std::cerr << "Pile pleine\n";
    }
}

int pop(int p[], int& t, int s) // (cette fonction dépile)
// cette fonction retourne l'entier en haut de la pile (le dernier empilé)
// à la sortie de cette fonction l'élément retourné n'est plus compté dans la pile
// elle doit s'assurer que la pile n'est pas vide avant de la dépiler
{
    if (not is_empty(p,t)){
        t=t-1;
        return p[t];
    }
    else{
         std::cerr << "Pile vide\n";
         return -1;
    }
}

int main()
{

    // on définit ici les 3 variables qui constituent la pile
    int size = 5;
    int stack[size];
    int top = 0;

    print(stack, top); // affiche [ [
    push(stack, top, size, -17);
    print(stack, top); // affiche [ -17 [

    // on affiche l'élément en haut de pile
    std::cout << pop(stack, top, size) << std::endl; // affiche -17

    push(stack, top, size, 28);
    push(stack, top, size, 62);

    print(stack, top); // affiche [ 28 62 [

    int e = pop(stack, top, size);
    std::cout << e << std::endl; // affiche 62

    print(stack, top);                         // affiche [ 28 [
    std::cout << pop(stack, top, size) << std::endl; // affiche 28
    pop(stack, top, size);                           // affiche cannot pop, the stack is empty
    // à partir d'ici la stack n'est plus correcte :
    //    l'utilisateur croit avoir un élément à dépiler or il n'en a pas...
    //    on verra les exceptions qui avertissent l'utilisateur d'un problème
    return 0;
}