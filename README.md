# cpp09## Exemple de Tri avec la Fonction `sort`

Prenons l'exemple suivant pour illustrer le fonctionnement de la fonction `sort` :

**`data` = [4, 2, 7, 1, 3, 6, 5]**

### Trier `left` :

- **`left`** = [4, 2, 7]
  - Divisé en `left` = [4] et `right` = [2, 7]
  - **Trier les sous-parties** :
    - **`left`** = [4] (déjà trié)
    - **`right`** = [2, 7]
      - Divisé en `left` = [2] et `right` = [7]
      - **Fusionner [2] et [7]** pour obtenir [2, 7]
  - **Fusionner [4] et [2, 7]** pour obtenir [2, 4, 7]

### Trier `right` :

- **`right`** = [1, 3, 6, 5]
  - Divisé en `left` = [1, 3] et `right` = [6, 5]
  - **Trier les sous-parties** :
    - **`left`** = [1, 3]
      - Divisé en `left` = [1] et `right` = [3]
      - **Fusionner [1] et [3]** pour obtenir [1, 3]
    - **`right`** = [6, 5]
      - Divisé en `left` = [6] et `right` = [5]
      - **Fusionner [6] et [5]** pour obtenir [5, 6]
  - **Fusionner [1, 3] et [5, 6]** pour obtenir [1, 3, 5, 6]

### Fusionner les Deux Moitiés Triées

Finalement, la fonction fusionne les deux moitiés triées `left` et `right` :

- **`left`** = [2, 4, 7]
- **`right`** = [1, 3, 5, 6]

**Fusionner [2, 4, 7] et [1, 3, 5, 6]** :

- Compare 2 et 1 : 1 est plus petit, donc ajouter 1 à `merged`
- Compare 2 et 3 : 2 est plus petit, donc ajouter 2 à `merged`
- Compare 4 et 3 : 3 est plus petit, donc ajouter 3 à `merged`
- Compare 4 et 5 : 4 est plus petit, donc ajouter 4 à `merged`
- Compare 7 et 5 : 5 est plus petit, donc ajouter 5 à `merged`
- Compare 7 et 6 : 6 est plus petit, donc ajouter 6 à `merged`
- Ajouter le reste : 7 à `merged`

**Résultat Final** :

- **`merged`** = [1, 2, 3, 4, 5, 6, 7]

Après la fusion finale, **`data`** = [1, 2, 3, 4, 5, 6, 7], qui est maintenant trié.
