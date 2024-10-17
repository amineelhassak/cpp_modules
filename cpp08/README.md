# cpp08
Containers templates
## Comparaison des conteneurs en C++

| Conteneur            | Description                                                                                  | Accès aléatoire | Insertion/Suppression en tête | Insertion/Suppression en queue | Insertion/Suppression au milieu | Complexité d'accès | Complexité d'insertion/suppression |
|----------------------|----------------------------------------------------------------------------------------------|-----------------|-------------------------------|-------------------------------|-------------------------------|--------------------|----------------------------------|
| `std::vector`        | Tableau dynamique contigu en mémoire.                                                        | Oui             | Non                           | Oui                           | Oui                           | O(1)               | O(n) pour insertion/suppression au milieu |
| `std::deque`         | Tableau double-ended avec accès aléatoire, utilisant des blocs pour gérer la mémoire.        | Oui             | Oui                           | Oui                           | Oui                           | O(1)               | O(1) pour insertion/suppression en tête et en queue, O(n) pour le milieu |
| `std::list`          | Liste doublement chaînée, où chaque élément contient des pointeurs vers les éléments voisins. | Non             | Oui                           | Oui                           | Oui                           | O(n)               | O(1) pour insertion/suppression au milieu |
| `std::forward_list`  | Liste simplement chaînée, où chaque élément contient un pointeur vers l'élément suivant.   | Non             | Oui                           | Non                           | Non                           | O(n)               | O(1) pour insertion/suppression en tête |

### Explications :

- **Accès aléatoire** : Permet d'accéder directement à un élément par son indice (comme un tableau).
- **Insertion/Suppression en tête** : Efficacité d'ajout ou de suppression d'éléments au début du conteneur.
- **Insertion/Suppression en queue** : Efficacité d'ajout ou de suppression d'éléments à la fin du conteneur.
- **Insertion/Suppression au milieu** : Efficacité d'ajout ou de suppression d'éléments au milieu du conteneur.
- **Complexité d'accès** : Temps nécessaire pour accéder à un élément par son indice.
- **Complexité d'insertion/suppression** : Temps nécessaire pour ajouter ou supprimer un élément (en fonction de la position).


La classe std::stack de la bibliothèque standard C++ est une adaptation conteneur, ce qui signifie qu'elle est construite sur un autre conteneur sous-jacent (comme un std::vector, std::deque, ou std::list) pour fournir une interface de pile (LIFO - Last In, First Out).

container adapter

container_type dans std::stack est un alias de type qui représente le conteneur sous-jacent utilisé pour stocker les éléments de la pile. Ce conteneur peut être de n'importe quel type de conteneur de la bibliothèque standard C++ qui prend en charge les opérations nécessaires, telles que push_back, pop_back, et l'accès aux éléments par itérateur.

#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#include <list>
c++```
int main() {
    // Utilisation de std::deque comme conteneur sous-jacent (par défaut)
    std::stack<int> stackAvecDeque;

    // Utilisation de std::vector comme conteneur sous-jacent
    std::stack<int, std::vector<int>> stackAvecVector;

    // Utilisation de std::list comme conteneur sous-jacent
    std::stack<int, std::list<int>> stackAvecList;

    // Ajouter des éléments
    stackAvecDeque.push(10);
    stackAvecVector.push(20);
    stackAvecList.push(30);

    // Afficher les éléments
    std::cout << "Element au sommet (deque): " << stackAvecDeque.top() << std::endl; // Affiche : 10
    std::cout << "Element au sommet (vector): " << stackAvecVector.top() << std::endl; // Affiche : 20
    std::cout << "Element au sommet (list): " << stackAvecList.top() << std::endl; // Affiche : 30

    return 0;
}
```

typename est nécessaire pour indiquer que ce qui suit est un type, particulièrement dans les contextes de modèles (templates). Dans cet exemple, typename est utilisé pour informer le compilateur que std::stack<T>::container_type::iterator est un type, et non autre chose