#include "vector.h"
#include <cmath>   // pour sqrt, fabs, cos, sin

#include <string>

// Création d’un vecteur à partir de coordonnées x et y
// Cette fonction construit un vecteur avec les composantes données.
// Exemple : MakeV2f(3, 4) → vecteur (3, 4).
Vector2f MakeV2f(float x, float y) {
    Vector2f v;
    v.x = x;
    v.y = y;
    return v;
}

// Création d’un vecteur entre deux points
// Construit un vecteur allant du point a vers le point b.
// Formule : (b.x - a.x, b.y - a.y).
// Exemple : a = (1,1), b = (4,5) → vecteur (3,4).
Vector2f MakeV2f(const Point2f& a, const Point2f& b) {
    Vector2f v;
    v.x = b.x - a.x;
    v.y = b.y - a.y;
    return v;
}

// Création d’un vecteur nul
// Retourne le vecteur (0,0).
// Utile pour tester les cas où il n’y a pas de déplacement.
Vector2f MakeNullVector() {
    Vector2f v;
    v.x = 0.0f;
    v.y = 0.0f;
    return v;
}

// Vérification d’égalité entre deux vecteurs
// Compare deux vecteurs avec une tolérance epsilon (pour éviter les erreurs
// dues aux calculs en virgule flottante).
// Exemple : (2.00001, 3.00001) ≈ (2,3) si epsilon = 0.001.
bool Egal(const Vector2f& a, const Vector2f& b, float epsilon) {
    return (fabs(a.x - b.x) <= epsilon) && (fabs(a.y - b.y) <= epsilon);
}

// Addition de deux vecteurs
// Formule : (a.x + b.x, a.y + b.y).
// Exemple : (1,2) + (3,4) → (4,6).
Vector2f Add(const Vector2f& a, const Vector2f& b) {
    Vector2f result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    return result;
}

// Soustraction de deux vecteurs
// Formule : (a.x - b.x, a.y - b.y).
// Exemple : (3,4) - (3,4) → (0,0).
Vector2f Sub(const Vector2f& a, const Vector2f& b) {
    Vector2f result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    return result;
}

//  Mise à l’échelle d’un vecteur par un scalaire
// Multiplie chaque composante par un nombre.
// Exemple : (3,4) * 2 → (6,8).
Vector2f Scale(const Vector2f& v, float scalar) {
    Vector2f result;
    result.x = v.x * scalar;
    result.y = v.y * scalar;
    return result;
}

//  Produit scalaire (dot product)
// Formule : a.x * b.x + a.y * b.y.
// Sert à mesurer l’angle entre deux vecteurs.
// Exemple : (1,0) · (0,1) = 0 → vecteurs perpendiculaires.
float Dot(const Vector2f& a, const Vector2f& b) {
    return a.x * b.x + a.y * b.y;
}

//  Longueur (norme) d’un vecteur
// Formule : sqrt(x² + y²).
// Exemple : (3,4) → longueur = 5.
float Length(const Vector2f& v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

// Normalisation d’un vecteur
// Transforme un vecteur en vecteur unitaire (longueur = 1).
// Formule : (x/len, y/len).
// Si le vecteur est nul, on retourne (0,0).
Vector2f Normalize(const Vector2f& v) {
    float len = Length(v);
    if (len == 0.0f) {
        return MakeNullVector(); // éviter division par zéro
    }
    Vector2f result;
    result.x = v.x / len;
    result.y = v.y / len;
    return result;
}

// Interpolation linéaire (LERP)
// Calcule un point intermédiaire entre a et b selon t (0 ≤ t ≤ 1).
// Formule : a + (b - a) * t.
// Exemple : Lerp((0,0), (10,10), 0.5) → (5,5).
Vector2f Lerp(const Vector2f& a, const Vector2f& b, float t) {
    Vector2f result;
    result.x = a.x + (b.x - a.x) * t;
    result.y = a.y + (b.y - a.y) * t;
    return result;
}

//Déterminant de deux vecteurs
// Formule : a.x * b.y - a.y * b.x.
// Sert à savoir si deux vecteurs sont orientés dans le sens horaire ou anti-horaire.
// Exemple : (1,0) et (0,1) → déterminant = 1.
float Determinant(const Vector2f& a, const Vector2f& b) {
    return a.x * b.y - a.y * b.x;
}


// Conversion en chaîne de caractères

// Transforme un vecteur en texte lisible.
// Exemple : (3,4) → "(3, 4)".
std::string ToString(const Vector2f& v) {
    return "(" + std::to_string(v.x) + ", " + std::to_string(v.y) + ")";
}
