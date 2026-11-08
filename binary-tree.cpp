/*

Ne surtout pas poser la question à l'IA : elle vous donne tout de suite le code !
(même/surtout si vous ne l'avez pas demandé).

Réfléchissez avant avec papier/crayon en lisant le texte ci-dessous,
   en dessinant/codant/compilant au fur et à mesure

Implémentation d'un arbre binaire de recherche (binary search tree).

Nous connaissons déjà des structures de données:
   - le tableau d'entiers [1, 2, 3, 4, 5, 6, 7]
   - la pile d'entiers
   - ...

Nous souhaitons maintenant implémenter une nouvelle structure de donnée (elle sera hiérarchique) appelée un arbre binaire de recherche.

Exemple d'un arbre binaire de recherche quelconque:
     3
   /  \
  2     4
 /       \
1         5
           \
            6
             \
              7

Un arbre binaire de recherche est formé de noeuds (node).
   - chaque noeud comporte deux sous-arbres (left, right) (potentiellement vides) et une valeur entière
   - tous les éléments du sous-arbre gauche d'un noeud sont strictement inférieurs à la valeur du noeud
   - tous les éléments du sous-arbre droite d'un noeud sont strictement supérieurs à la valeur du noeud
   - sa hauteur h est le plus long chemin de la racine à une feuille (4 dans notre exemple).

Ces règles permettent que les opérations de recherche, d'insertion et de suppression
   soient de complexité O(h) où h est la hauteur de l'arbre.

La profondeur d'un noeud est le nombre de liens de la racine à ce noeud.
(1 est à la profondeur 2).

Il existe différentes formes d'arbres binaires de recherche contenant les mêmes 7 valeurs:
Cas 1) Celui-là est de hauteur 6, c'est la hauteur maximale: l'arbre est dégénéré - en fait il est comme une liste:
1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
           \
            7
Comment a-t-il été obtenu ? On a inséré 1, 2, 3, 4, 5, 6, 7.

Cas 2) Celui-là est de hauteur 2, c'est la hauteur minimale : l'arbre est dit équilibré (balanced binary tree):
        4
      /   \
    2       6
   / \     / \
  1   3   5   7
Comment a-t-il été obtenu ? On a inséré 4, 2, 6, 1, 3, 5, 7.

Quand on insère un élément dans l'arbre:
   - on l'insère de manière à ce que l'arbre reste un arbre binaire de recherche
   - on ne ré-équilibre pas l'arbre (algos trop complexes pour de l'apprentissage de la programmation)

Quand on s'intéresse à la recherche d'un élément dans un arbre binaire de recherche,
   on préfère franchement que la hauteur de l'arbre soit la plus petite possible :
  Ainsi,
      - la recherche dans un arbre binaire dégénéré sera en O(n)             - cas 1
      - là où la recherche dans un arbre binaire équilibré sera en O(log(n)) - cas 2

Question: Cet arbre est-il un arbre binaire de recherche ?
        4
      /   \
    2       6
   / \     / \
  1   5   3   7
Oui : retourner au début
Non : continuer la lecture

Construisons un arbre bianire de recherche:
   - l'arbre initial est créé vide (aucun noeud donc pas de noeud racine)
     (réfléchir puis si besoin voir indice 1 très en bas dans le fichier)
   - la méthode insérer (insert) ajoute une valeur à l'arbre "à la bonne place"
     on se déplace dans l'arbre:
         + si la valeur est strictement plus grande que la valeur de la racine de l'arbre (ou d'un noeud)
             on lance l'insertion sur le fils droit (réfléchir puis si besoin voir indice 2 très en bas dans le fichier)
         + sinon si elle est strictement inférieure
                 je lance l'insertion sur son fils gauche
              sinon la valeur est égale
                 je ne fais rien (la valeur est déjà dans l'arbre)
     + quand on est "bloqué"
     + on crée un nouveau noeud et on le raccorde

Parcourons l'arbre:
   - la méthode depth() parcourt l'arbre en profondeur en affichant ses valeurs
   - très franchement ça ressemble à l'insertion mais on n'insère rien, on affiche simplement les valeurs...
Notez que lors de ce parcours, on peut afficher la valeur des noeuds à plusieurs endroits:
   - si on l'affiche en début de l'appel du parcours sur un noeud: on a un affichage dit préfixe
   - si on l'affiche entre les appels à gauche et à droite on a un affichage dit infixe
   - si on l'affiche à la fin de l'appel de la méthode sur un noeud: on a un affichage dit postfixe

Remarquez que les méthodes sont en fait implémentées dans la struct Node
les méthodes de BinarySearchTree sont juste là pour appeler "correctement" les méthodes de No
*/

#include <iostream>

struct Node
{
    // votre code là avec des attributs et des méthodes...
   int n;
   Node* gauche;
   Node* droite;

   Node(int e){
      n = e;
      gauche = nullptr ; 
      droite = nullptr ;
   }

   static Node* insertnode(Node* root, int e){
      if (root==nullptr){
         return new Node(e);
      }
      else if ((*root).n>e){
         (*root).gauche = insertnode((*root).gauche,e);
      }
      else if ((*root).n<e){
         (*root).droite = insertnode((*root).droite,e);
      }
      return root;
   }

   static void parc_prof(Node* root){
      if (root==nullptr){
         return;
      }
      parc_prof((*root).gauche) ;
      std::cout << (*root).n << "";
      parc_prof((*root).droite) ;
   }
   
   static bool recherche(Node* root,int e){
      if (root==nullptr){
         return false;
      }
      else if ((*root).n==e){
         return true;
      }
      else if ((*root).n>e){
         return recherche((*root).gauche,e);
      }
      return recherche((*root).droite,e);
   }

   static void affiche(Node* root, int prof){
      if (root==nullptr){
         return;
      }
      affiche((*root).droite, prof+1) ;
      for (int i=0 ; i<prof ; i++){
         std::cout << "    ";
      }
      std::cout << (*root).n << std::endl ;
      affiche((*root).gauche, prof+1) ;
   }

   static void liberer(Node* root) {
      if (root == nullptr) return;    
      liberer((*root).gauche);          
      liberer((*root).droite);         
      delete root;                     
   }

};

struct BinaryTree
{
   Node* root ;
   // votre code là
   // je vous laisse implémenter les méthodes genre constructeur...
   BinaryTree(){
      root = nullptr ;
   }

   // méthodes spécifiques à implémenter
   void insert(int e) {
      root = Node :: insertnode(root,e);
   }
   void depth_infix() {
      Node :: parc_prof(root);
   }
   bool search(int v) { 
      return Node :: recherche(root,v); 
   }

   // ah celle là est plus difficile...
   void print() {
      Node :: affiche(root,0);
   }

   ~ BinaryTree(){
      Node :: liberer(root) ;
   }
};

int main()
{
   BinaryTree b;

   // oh le beau for-python !
   for (int e : {4, 2, 6, 1, 3, 5, 7})
   {
      std::cout << "j'insère " << e << std::endl;
      b.insert(e);
   }
   std::cout << std::boolalpha // pour avoir true ou false
             << "12 est-t-il dans l'arbre ? " << b.search(12) << std::endl
             << "5 est-il dans l'arbre ? " << b.search(5) << std::endl;

   b.depth_infix();
   std::cout << std::endl ;
   b.print();
   return 0;
}
/*
Résultats attendus :
$ g++ binary-search-tree-tp.cpp
$ ./a.out
j'insère 4
j'insère 2
j'insère 6
j'insère 1
j'insère 3
j'insère 5
j'insère 7
12 est-t-il dans l'arbre ? false
5 est-il dans l'arbre ? true
1 2 3 4 5 6 7
          1
     2
          3
4
          5
     6
          7

Pour dessiner cet arbre remarquez que ça ressemble à un parcours
  lors duquel vous affichez, avant d'afficher l'élément,
  autant de "  " que sa profondeur:
   - rien devant 4               qui est  à la profondeur 0
   - un seul "   " devant 2 et 6 qui sont à la profondeur 1
   - deux devant 1, 3, 5 et 7    qui sont à la profondeur 2
(donc passez le niveau lors de l'appel print (0 pour root) et ensuite level+1
 à chaque appel de print à gauche ou à droite)
|
|
|
V
vers les INDICES


































































INDICES C++:
1) pensez : la racine n'est pas l'adresse d'un objet existant de type noeud donc elle vaut nullptr)
2) pensez : je fais un appel récursif sur le sous-arbre (gauche ou droit)
   ma récursion terminera donc un jour
3) pensez : où vais-je l'allouer si je veux qu'il existe en sortant de la fonction ?
   mais alors vous allez devoir supprimer les noeuds à la fin de la vie de l'arbre 
*/
