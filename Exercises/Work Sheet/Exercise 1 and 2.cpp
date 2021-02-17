#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void exercicio1_1() {
    char c;
    cout << "Character: ";
    cin >> c;
    cout << "ASCII code: " << int(c);
}
void exercicio1_2() {
    float a, b, c, mean;
    cout << "Please, input 3 integer numbers" << endl;
    cout << "A ? ";
    cin >> a;
    cout << "B ? ";
    cin >> b;
    cout << "C ? ";
    cin >> c;
    mean = (a + b + c) / 3;
    cout << "mean   = " << mean << endl;
    cout << "A-mean = " << a - mean << endl;
    cout << "B-mean = " << b - mean << endl;
    cout << "C-mean = " << c - mean << endl;
}
void exercicio1_3() {
    float p, r, M;
    cout << "Introduce the amount of mass of the material from which it is made in Kg/m^3: ";
    cin >> p;
    cout << "Introduce the radius in m: ";
    cin >> r;
    M = 4 / 3 * (p * r * M_PI);
    cout << "The mass os the sphere is " << M << "Kg" << endl;
}
void exercicio1_4() {
    float a, b, c, d, e, f, x, y;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "c: ";
    cin >> c;
    cout << "d: ";
    cin >> d;
    cout << "e: ";
    cin >> e;
    cout << "f: ";
    cin >> f;
    while ((a * e - b * d) == 0) {
        cout << "a: ";
        cin >> a;
        cout << "b: ";
        cin >> b;
        cout << "c: ";
        cin >> c;
        cout << "d: ";
        cin >> d;
        cout << "e: ";
        cin >> e;
        cout << "f: ";
        cin >> f;
    }
    x = (c * e - b * f) / (a * e - b * d);
    y = (a * f - c * d) / (a * e - b * d);
    cout << "x is equal to " << x << " and y is equal to " << y << endl;
}
int exercicio2_1() {
    float a, b, c, d, e, f, x, y;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "c: ";
    cin >> c;
    cout << "d: ";
    cin >> d;
    cout << "e: ";
    cin >> e;
    cout << "f: ";
    cin >> f;
    if ((a * e - b * d) != 0) {
        x = (c * e - b * f) / (a * e - b * d);
        y = (a * f - c * d) / (a * e - b * d);
        cout << "x is equal to " << x << " and y is equal to " << y << endl;
    }
    else
        cerr << "Impossible system\n";
    return 0;
}
void exercicio2_2ab() {
    float f, s, t;
    cout << "First number: ";
    cin >> f;
    cout << "Second number: ";
    cin >> s;
    cout << "Third number: ";
    cin >> t;
    if ((f > s) && (f > t) && (s < t)) {
        cout << "The biggest number is " << f << " and the smallest number is " << s << endl;
        cout << "The descending order is " << f << ", " << t << ", " << s << endl;
    }
    else if ((f > s) && (f > t) && (t < s)) {
        cout << "The biggest number is " << f << " and the smallest number is " << t << endl;
        cout << "The descending order is " << f << ", " << s << ", " << t << endl;
    }
    else if ((s > f) && (s > t) && (t < f)) {
        cout << "The biggest number is " << s << " and the smallest number is " << t << endl;
        cout << "The descending order is " << s << ", " << f << ", " << t << endl;
    }
    else if ((s > f) && (s > t) && (f < t)) {
        cout << "The biggest number is " << s << " and the smallest number is " << f << endl;
        cout << "The descending order is " << s << ", " << t << ", " << f << endl;
    }
    else if ((t > f) && (t > s) && (s < f)) {
        cout << "The biggest number is " << t << " and the smallest number is " << s << endl;
        cout << "The descending order is " << t << ", " << f << ", " << s << endl;
    }
    else if ((t > f) && (t > s) && (f < s)) {
        cout << "The biggest number is " << t << " and the smallest number is " << f << endl;
        cout << "The descending order is " << t << ", " << s << ", " << f << endl;
    }
}
void exercicio2_2c() {
    float f, s, t;
    cout << "First number: ";
    cin >> f;
    cout << "Second number: ";
    cin >> s;
    cout << "Third number: ";
    cin >> t;
    if ((f > s) && (f > t)) {
        if ((s + t) < f) {
            cout << "This is not a triangle." << endl;
        }
        else {
            cout << "The triangle exists." << endl;
        }
    }
    else if ((s > f) && (s > t)) {
        if ((f + t) < s) {
            cout << "This is not a triangle." << endl;
        }
        else {
            cout << "The triangle exists." << endl;
        }
    }
    else if ((t > f) && (t > s)) {
        if ((f + s) < t) {
            cout << "This is not a triangle." << endl;
        }
        else {
            cout << "The triangle exists." << endl;
        }
    }
}
void exercicio2_3() {
    float f, s;
    cout << "First number: ";
    cin >> f;
    cout << "Second number: ";
    cin >> s;
    if ((f + s) > INT_MAX) {
        cout << "Sum overflow." << endl;
    }
    else if ((f + s) < INT_MIN) {
        cout << "Sum underflow." << endl;
    }
    else {
        cout << "The sum of is " << f + s << "." << endl;
    }
}
void exercicio2_4() {
    float w, c;
    cout << "Insert the weight of the merchandise: ";
    cin >> w;
    if (w <= 500) {
        c = 5;
        cout << "The cost is " << c << " euros." << endl;
    }
    else if ((w >= 501) && (w <= 1000)) {
        c = 5 + 1.5 * ((int)((w - 500) / 100));
        cout << "The cost is " << c << " euros." << endl;
    }
    else if (w > 1000) {
        c = 12.5 + 5 * ((int)((w - 1000) / 250));
        cout << "The cost is " << c << " euros." << endl;
    }
}
void exercicio2_5() {
    float a, b, c, calc, first, second;
    cout << "Solution of Ax^2 + Bx + C = 0" << endl;
    cout << "Insert the coefficients (A B C): ";
    cin >> a;
    cin >> b;
    cin >> c;
    calc = pow(b, 2) - 4 * a * c;
    if (calc == 0) {
        first = b / (2 * a);
        cout << "The equation has 2 equal real roots: " << fixed << setprecision(3) << first << " and " << first << endl;
    }
    else if (calc > 0) {
        first = (b + sqrt(calc)) / (2 * a);
        second = (b - sqrt(calc)) / (2 * a);
        cout << "The equation has 2 real roots: " << fixed << setprecision(3) << first << " and " << second << endl;
    }
    else if (calc < 0) {
        first = sqrt(-calc) / (2 * a);
        second = sqrt(-calc) / (2 * a);
        cout << "The equation has 2 complex roots: " << fixed << setprecision(3) << b/(2 * a) << "+"<< first << "i and " << b/(2 * a) << "-" << second << "i." << endl;
    }
}
void exercicio2_6() {
    float n, q, j;
    cout << "Enter the number of years: ";
    cin >> n;
    cout << "Enter the deposit amount: ";
    cin >> q;
    cout << "Enter the annual interest rate: ";
    cin >> j;
}
void exercicio2_7() {
    int i, n;
    cout << "Enter a number: ";
    cin >> n;
    for (i = 0; i < sqrt(n); i++) {
        if ((n % i) == 0) {
            cout << "The number " << n << " is not prime." << endl;
        }
        break;
    }
}
int main()
{
    // exercicio1_1();
    //exercicio1_2();
    //exercicio1_3();
    //exercicio1_4();
    //exercicio2_1();
    //exercicio2_2ab();
    //exercicio2_2c();
    //exercicio2_3();
    //exercicio2_4();
    //exercicio2_5();
    //exercicio2_6();
    exercicio2_7();
    return 0;
}