#include "geometry/point.h"
#include "geometry/vector.h"
#include "geometry/utils.h"
#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

// ============================================================================
// 🧪 TESTS UNITAIRES FROM SCRATCH
// ============================================================================

void RunTests() {
    cout << "🧪 LANCEMENT DES TESTS UNITAIRES\n" << endl;
    int testsReussis = 0;
    int testsTotal = 0;

    // Macro de test maison
    #define TEST(nom, condition) \
        do { \
            testsTotal++; \
            if (condition) { \
                testsReussis++; \
                cout << "✅ " << nom << endl; \
            } else { \
                cout << "❌ " << nom << " - ÉCHEC" << endl; \
            } \
        } while(0)

    // ==================== TESTS POINTS ====================
    cout << "📍 TESTS DES POINTS" << endl;
    
    // Test création
    Point2f p1 = MakeP2f(2.0f, 3.0f);
    TEST("Création point", p1.x == 2.0f && p1.y == 3.0f);
    
    Point2f zero = MakeNullPoint();
    TEST("Point nul", zero.x == 0.0f && zero.y == 0.0f);
    
    // Test égalité
    Point2f p2 = MakeP2f(2.0f, 3.0f);
    TEST("Égalité points identiques", Egal(p1, p2));
    
    Point2f p3 = MakeP2f(2.00001f, 3.00001f);
    TEST("Égalité avec tolérance", Egal(p1, p3, 0.001f));
    TEST("Différence avec précision", Different(p1, p3, 0.000001f));
    
    // Test translation
    Point2f p4 = Translate(p1, 1.0f, -1.0f);
    Point2f expected1 = MakeP2f(3.0f, 2.0f);
    TEST("Translation point", Egal(p4, expected1));
    
    // Test translation avec vecteur
    Vector2f v = MakeV2f(2.0f, 0.0f);
    Point2f p5 = Translate(p1, v);
    Point2f expected2 = MakeP2f(4.0f, 3.0f);
    TEST("Translation avec vecteur", Egal(p5, expected2));
    
    // Test mise à l'échelle
    Point2f p6 = Scale(p1, 2.0f, 3.0f);
    Point2f expected3 = MakeP2f(4.0f, 9.0f);
    TEST("Mise à l'échelle point", Egal(p6, expected3));
    
    // Test rotation
    Point2f p7 = Rotate(MakeP2f(1.0f, 0.0f), 90.0f);
    Point2f expected4 = MakeP2f(0.0f, 1.0f);
    TEST("Rotation 90°", Egal(p7, expected4, 0.001f));

    // ==================== TESTS VECTEURS ====================
    cout << "\n📐 TESTS DES VECTEURS" << endl;
    
    // Test création
    Vector2f v1 = MakeV2f(3.0f, 4.0f);
    TEST("Création vecteur", v1.x == 3.0f && v1.y == 4.0f);
    
    Vector2f vZero = MakeNullVector();
    TEST("Vecteur nul", vZero.x == 0.0f && vZero.y == 0.0f);
    
    // Test création depuis points
    Vector2f v2 = MakeV2f(MakeP2f(1.0f, 1.0f), MakeP2f(4.0f, 5.0f));
    Vector2f expected5 = MakeV2f(3.0f, 4.0f);
    TEST("Vecteur entre points", Egal(v2, expected5));
    
    // Test addition
    Vector2f v3 = Add(v1, v2);
    Vector2f expected6 = MakeV2f(6.0f, 8.0f);
    TEST("Addition vecteurs", Egal(v3, expected6));
    
    // Test soustraction
    Vector2f v4 = Sub(v1, v2);
    Vector2f expected7 = MakeV2f(0.0f, 0.0f);
    TEST("Soustraction vecteurs", Egal(v4, expected7));
    
    // Test multiplication scalaire
    Vector2f v5 = Scale(v1, 2.0f);
    Vector2f expected8 = MakeV2f(6.0f, 8.0f);
    TEST("Multiplication scalaire", Egal(v5, expected8));
    
    // Test produit scalaire
    Vector2f v6 = MakeV2f(1.0f, 0.0f);
    Vector2f v7 = MakeV2f(0.0f, 1.0f);
    float dot = Dot(v6, v7);
    TEST("Produit scalaire perpendiculaires", dot == 0.0f);
    
    float dot2 = Dot(v6, v6);
    TEST("Produit scalaire même vecteur", dot2 == 1.0f);
    
    // Test longueur
    float len = Length(v1);
    TEST("Longueur vecteur", abs(len - 5.0f) < 0.0001f);
    
    float lenZero = Length(vZero);
    TEST("Longueur vecteur nul", lenZero == 0.0f);
    
    // Test normalisation
    Vector2f v8 = Normalize(v1);
    float lenNorm = Length(v8);
    TEST("Normalisation vecteur", abs(lenNorm - 1.0f) < 0.0001f);
    
    Vector2f v9 = Normalize(vZero);
    TEST("Normalisation vecteur nul", Egal(v9, vZero));
    
    // Test interpolation
    Vector2f v10 = MakeV2f(0.0f, 0.0f);
    Vector2f v11 = MakeV2f(10.0f, 10.0f);
    Vector2f v12 = Lerp(v10, v11, 0.5f);
    Vector2f expected9 = MakeV2f(5.0f, 5.0f);
    TEST("Interpolation linéaire", Egal(v12, expected9));
    
    // Test déterminant
    float det = Determinant(v6, v7);
    TEST("Déterminant vecteurs perpendiculaires", det == 1.0f);

    // ==================== TESTS INTÉGRATION ====================
    cout << "\n🔗 TESTS D'INTÉGRATION" << endl;
    
    // Test transformation complète
    Point2f p = MakeP2f(2.0f, 0.0f);
    Point2f result = Translate(Scale(Rotate(p, 90.0f), 2.0f, 2.0f), 1.0f, 1.0f);
    TEST("Transformation complexe", !Egal(p, result));
    
    // Test cohérence vecteur-point
    Point2f a = MakeP2f(0.0f, 0.0f);
    Point2f b = MakeP2f(3.0f, 4.0f);
    Vector2f ab = MakeV2f(a, b);
    Point2f b_calc = Translate(a, ab.x, ab.y);
    TEST("Cohérence point-vecteur", Egal(b, b_calc));
    
    // Test propriété vecteur nul
    Vector2f nullVec = MakeNullVector();
    Point2f p_unchanged = Translate(p, nullVec);
    TEST("Translation par vecteur nul", Egal(p, p_unchanged));

    // ==================== RAPPORT FINAL ====================
    cout << "\n📊 RAPPORT DES TESTS" << endl;
    cout << "Tests réussis: " << testsReussis << "/" << testsTotal << endl;
    
    if (testsReussis == testsTotal) {
        cout << "🎉 TOUS LES TESTS SONT RÉUSSIS !" << endl;
    } else {
        cout << "⚠️  Certains tests ont échoué" << endl;
    }

    #undef TEST
}

// ============================================================================
// 🎯 FONCTION PRINCIPALE
// ============================================================================

int main() {
    cout << "=========================================" << endl;
    cout << "       📐 MATH - TESTS UNITAIRES" << endl;
    cout << "=========================================" << endl;
    
    RunTests();
    
    cout << "\n=========================================" << endl;
    cout << "           🏁 TESTS TERMINÉS" << endl;
    cout << "=========================================" << endl;
    
    return 0;
}