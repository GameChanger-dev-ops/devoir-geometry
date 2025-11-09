


#ifndef VECTOR_H
#define VECTOR_H

#include <string>
#include <cmath>
#include "point.h"
#include "vector.h"

struct Point2f;
struct Vector2f {
    float x;
    float y;
};
Vector2f MakeNullVector();
Vector2f MakeV2f(float x, float y);
Vector2f MakeV2f(const Point2f& a, const Point2f& b);
Vector2f Add(const Vector2f& a, const Vector2f& b);
Vector2f Sub(const Vector2f& a, const Vector2f& b);
Vector2f Scale(const Vector2f& v, float scalar);
float Dot(const Vector2f& a, const Vector2f& b);
float Length(const Vector2f& v);
Vector2f Normalize(const Vector2f& v);
Vector2f Lerp(const Vector2f& a, const Vector2f& b, float t);
float Determinant(const Vector2f& a, const Vector2f& b);
// Comparaison de vecteurs
bool Egal(const Vector2f& a, const Vector2f& b, float tolerance = 0.0001f);
bool Different(const Vector2f& a, const Vector2f& b, float tolerance = 0.0001f);

std::string ToString(const Vector2f& v);

#endif