# devoir-geometry
devoir de geometry en c++
 # Description
Ce projet est une petite bibliothèque en C++ qui permet de manipuler des points et des vecteurs en 2D. L’objectif est d’apprendre les bases de la programmation en C++ à travers des opérations géométriques simples : création, translation, mise à l’échelle, rotation, comparaison et affichage.

# Structure du projet
main.cpp → contient les tests pour vérifier le bon fonctionnement des fonctions.

geometry/point.h → déclarations des fonctions liées aux points.

geometry/point.cpp → implémentations des fonctions liées aux points.

geometry/vector.h → déclarations des fonctions liées aux vecteurs.

geometry/vector.cpp → implémentations des fonctions liées aux vecteurs.


# Fonctions principales
Points (Point2f)
**Créer un point** : MakeP2f(x, y)

**Créer le point nul (0,0)** : MakeNullPoint()

**Déplacer un point** : Translate(p, dx, dy) ou Translate(p, v)

**Mettre à l’échelle** : Scale(p, sx, sy) ou Scale(p, v)

**Faire une rotation** : Rotate(p, angle)

**Comparer deux points**:Egal(a, b, epsilon) / Different(a, b, epsilon)

**Afficher un point** : ToString(p)

# Vecteurs (Vector2f)
**Créer un vecteur** : MakeV2f(x, y)

**Créer un vecteur entre deux points** : MakeV2f(a, b)

**Créer le vecteur nul (0,0)** : MakeNullVector()

**Addition / Soustraction** : Add(a, b) / Sub(a, b)

**Mise à l’échelle** : Scale(v, s)

**Produit scalaire** : Dot(a, b)

**Longueur** : Length(v)

**Normalisation** : Normalize(v)

**Interpolation linéaire** : Lerp(a, b, t)

**Déterminant** : Determinant(a, b)

**Afficher un vecteur** : ToString(v)

# Compilation et exécution
Pour compiler et lancer les tests :
**g++ main.cpp geometry/point.cpp geometry/vector.cpp -o geometry
./geometry**

# Objectif
Comprendre la différence entre un point (position) et un vecteur (direction/déplacement).

S’entraîner à manipuler des structures et fonctions en C++.

Vérifier le code avec des tests automatiques pour progresser pas à pas.

