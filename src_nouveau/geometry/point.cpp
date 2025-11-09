#include "point.h"
#include <cmath>   // pour cos, sin
#include <string>


// Crée un point avec les coordonnées données
Point2f MakeP2f(float x, float y) {
    Point2f p;
    p.x = x;
    p.y = y;
    return p;
}

// Déplace un point avec dx et dy
Point2f Translate(const Point2f& p, float dx, float dy) {
    Point2f result;
    result.x = p.x + dx;
    result.y = p.y + dy;
    return result;
}


// Crée un point nul (0,0)
Point2f MakeNullPoint() {
    Point2f p;
    p.x = 0.0f;
    p.y = 0.0f;
    return p;
}

// Comparaison de points

// Vérifie si deux points sont égaux (avec tolérance pour éviter les erreurs d’arrondi)
bool Egal(const Point2f& a, const Point2f& b, float tolerance) {
    return (fabs(a.x - b.x) <= tolerance) && (fabs(a.y - b.y) <= tolerance);
}

// Vérifie si deux points sont différents
bool Different(const Point2f& a, const Point2f& b, float tolerance) {
    return !Egal(a, b, tolerance);
}

// Déplace un point avec un vecteur
Point2f Translate(const Point2f& p, const Vector2f& v) {
    Point2f result;
    result.x = p.x + v.x;
    result.y = p.y + v.y;
    return result;
}

// Met à l’échelle un point avec sx et sy
Point2f Scale(const Point2f& p, float sx, float sy) {
    Point2f result;
    result.x = p.x * sx;
    result.y = p.y * sy;
    return result;
}

// Met à l’échelle un point avec un vecteur
Point2f Scale(const Point2f& p, const Vector2f& s) {
    Point2f result;
    result.x = p.x * s.x;
    result.y = p.y * s.y;
    return result;
}

// Fait tourner un point autour de l’origine
Point2f Rotate(const Point2f& p, float angleDegree) {
    float rad = angleDegree * 3.14159f / 180.0f; // conversion degrés → radians
    Point2f result;
    result.x = p.x * cos(rad) - p.y * sin(rad);
    result.y = p.x * sin(rad) + p.y * cos(rad);
    return result;
}

// Transforme un point en texte simple
std::string ToString(const Point2f& p) {
    return "(" + std::to_string(p.x) + ", " + std::to_string(p.y) + ")";
}
