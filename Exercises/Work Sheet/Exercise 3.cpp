#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h> 
#include <time.h>
#include <climits>
using namespace std;

//exercício 3_1

double distance(double x1, double y1, double x2, double y2) {
    double calc, d;
    calc = pow(x2 - x1, 2) + pow(y2 - y1, 2);
    d = sqrt(calc);
    return d;
}

double area(double x1, double y1, double x2, double y2, double x3, double y3) {
    double a, b, c, s, calc, area;
    a = distance(x1, y1, x2, y2);
    b = distance(x2, y2, x3, y3);
    c = distance(x3, y3, x1, y1);
    s = (a + b + c) / 2;
    calc = s * (s - a) * (s - b) * (s - c);
    area = sqrt(calc);
    cout << "The area is " << area << "." << endl;
    return 0;
}

//exercício 3_2
double isPrime(int n) {
    bool valid = true;
    int interg;
    interg = sqrt(n);
    for (int i = 2; i < (interg + 1); i++) {
        if (n % i == 0) {
            cout << n << " is not prime." << endl;
            valid = false;
            break;
        }
    }
    if (valid == true) {
        cout << n << " is prime." << endl;
    }
    return 0;
}

double exercicio3_3(double n, double delta, double nMaxIter) {
    double rq, rqn, dif;
    rq = 1;
    while ((nMaxIter > 0) || (dif > delta)) {
        rqn = (rq + n / rq) / 2;
        dif = n - pow(rqn, 2);
        rq = rqn;
        nMaxIter -= 1;
    }
    cout << "The square root is " << rqn << "." << endl;
    return 0;
}

//exercício 3_4
double round(double x, unsigned n) {
    return floor(x * pow(10, n) + 0.5) / pow(10, n);
}

double exercicio3_4() {
    cout << "Choose a number: ";
    double x;
    cin >> x;
    cout << "Choose the number of decimal places: ";
    unsigned n;
    cin >> n;
    cout << "The result is " << round(x, n) << endl;
    return 0;
}

double exercicio3_5(double x1, double x2) {
    if (x1 == x2) {
        cout << "The greatest common divisor is " << x1 << endl;
    }
    else if (x1 == 0) {
        cout << "The greatest common divisor is " << x2 << endl;
    }
    else if (x2 == 0) {
        cout << "The greatest common divisor is " << x1 << endl;
    }
    else if (x2 != x1) {
        while (x1 != x2) {
            if (x1 > x2) {
                x1 = x1 - x2;
            }
            else if (x2 > x1) {
                x2 = x2 - x1;
            }
        }
        cout << "The greatest common divisor is " << x1 << endl;
    }
    return 0;
}

//exercício3_6
double timeElapsed() {
    time_t first = 0;
    return 0;
}

//exercício3_7

bool readInt(int &x) {
    bool status = true;
    if ((cin.fail()) || (cin.peek() != '\n')) {
        status = false;
        return status;
    }
    else {
        return status;
    }
}

int exercicio3_7() {
    int x;
    cout << "Introduce a number: ";
    cin >> x;
    return readInt(x);
}

//exercício3_8
//bool readFraction(int& numerator, int& denominator) {

//}

//exercício3_9
bool leapyear(int year) {
    bool leapyear = true;
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400  == 0)) {
        return leapyear;
    }
    else {
        leapyear = false;
        return leapyear;
    }
}

int date(int month, int year) {
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        return 31;
    }
    else if (month == 2) {
        if (leapyear(year)) {
            return 29;
        }
        else {
            return 28;
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
}

int dayweek(int year, int month, int day) {
    int ds, c, s, ds1, year1;
    double f;
    int len = 1;
    year1 = year;
    if (year1 > 0) {
        for (len = 0; year1 > 0; len++) {
            year1 = year1 / 10;
        }
    }
    switch (month) {
    case 3: c = 3;
        break;
    case 4: c = 6;
        break;
    case 5: c = 1;
        break;
    case 6: c = 4;
        break;
    case 7: c = 6;
        break;
    case 8: c = 2;
        break;
    case 9: c = 5;
        break;
    case 10: c = 0;
        break;
    case 11: c = 3;
        break;
    case 12: c = 5;
        break;
    }
    if (leapyear) {
        switch (month) {
        case 1: c = 6;
            break;
        case 2: c = 2;
            break;
        }
    }
    else {
        switch (month) {
        case 1: c = 9;
            break;
        case 2: c = 3;
            break;
        }
    }
    f = (5 * (year % 100)) / 4;
    s = year / pow(10, (len - 2));
    ds1 = (floor(f) + c + day - 2 * (s % 4) + 7);
    ds = ds1 % 7;
    return ds;
}

int month(int year, int month) {
    int days;
    switch (month) {
    case 1: cout << "January/" << year << endl;
        break;
    case 2: cout << "February/" << year << endl;
        break;
    case 3: cout << "March/" << year << endl;
        break;
    case 4: cout << "April/" << year << endl;
        break;
    case 5: cout << "May/" << year << endl;
        break;
    case 6: cout << "June/" << year << endl;
        break;
    case 7: cout << "July/" << year << endl;
        break;
    case 8: cout << "August/" << year << endl;
        break;
    case 9: cout << "September/" << year << endl;
        break;
    case 10: cout << "October/" << year << endl;
        break;
    case 11: cout << "November/" << year << endl;
        break;
    case 12: cout << "December/" << year << endl;
        break;
    }
    days = date(month, year);
    cout << "Sun" << setw(5) << "Mon" << setw(5) << "Tue" << setw(5) << "Wed" << setw(5) << "Thu" << setw(5) << "Fri" << setw(5) << "Sat" << endl;
    for (int i = 1; i <= days; i++) {
        if (i == 1) {
            switch (dayweek(year, month, i)) {
            case 0: cout << setfill(' ') << setw(32) << i << endl;
                break;
            case 1: cout << " " << i;
                break;
            case 2: cout << setw(7) << i;
                break;
            case 3: cout << setw(12) << i;
                break;
            case 4: cout << setw(17) << i;
                break;
            case 5: cout << setw(22) << i;
                break;
            case 6: cout << setw(27) << i;
                break;
            }
        }
        else if (i < 10) {
            switch (dayweek(year, month, i)) {
            case 0: cout << setw(4) << " " << i << endl;
                break;
            case 1: cout << " " << i;
                break;
            case 2: cout << setw(4) << " " << i;
                break;
            case 3: cout << setw(4) << " " << i;
                break;
            case 4: cout << setw(4) << " " << i;
                break;
            case 5: cout << setw(4) << " " << i;
                break;
            case 6: cout << setw(4) << " " << i;
                break;
            }
        }
        else {
        switch (dayweek(year, month, i)) {
        case 0: cout << setw(5) << i << endl;
            break;
        case 1: cout << i;
            break;
        case 2: cout << setw(5) << i;
            break;
        case 3: cout << setw(5) << i;
            break;
        case 4: cout << setw(5) << i;
            break;
        case 5: cout << setw(5) << i;
            break;
        case 6: cout << setw(5) << i;
            break;
        }
        }

    }
    return 0;
}

int checkday(int year, int month, int day) {
    switch (dayweek(year, month, day)) {
    case 0: cout << "Saturday" << endl;
        break;
    case 1: cout << "Sunday" << endl;
        break;
    case 2: cout << "Monday" << endl;
        break;
    case 3: cout << "Tuesday" << endl;
        break;
    case 4: cout << "Wednesday" << endl;
        break;
    case 5: cout << "Thursday" << endl;
        break;
    case 6: cout << "Friday" << endl;
        break;
    }
    return 0;
}

int exercicio3_9(int year) {
    if (exercicio3_9(year)) {
        cout << year << " is a leap year" << endl;
    }
    else {
        cout << year << " is not a leap year" << endl;
    }
    return 0;
}

int calendar(int year) {
    int i = 1;
    while (i <= 12) {
        month(year, i);
        cout << endl << endl;
        i++;
    }
    return 0;
}

//exercício3_10
int factorial_ite(unsigned int n) {
    unsigned long long largest, factorial = 1;
    largest = ULLONG_MAX;
    int largestnum = 1;
    long long int fact = 1;
    while (fact != 0)
    {
        largestnum++;
        fact *= largestnum;
    }
    for (int i = 1; i <= n; ++i) {
        factorial *= i;
    }
    cout << "The largest number that can be represented in factorial way is " << largestnum - 1 << endl;
    cout << "The factorial number of " << n << " is " << factorial << endl;
    return 0;
}

unsigned long long factorial_rec(unsigned int n) {
    unsigned long long factorial = 1;
    if (n == 0) {
        return 1;
    }
    return n * factorial_rec(n - 1);
}

int call_rec(unsigned int n) {
    cout << "The factorial number of " << n << " is " << factorial_rec(n);
    return 0;
}

//exercício3_11
int GCD(int m, int n) {
    if (m % n == 0) {
        return n;
    }
    return GCD(n, m%n);
}

int call_GCD(int m, int n) {
    cout << "The greatest common divisor is " << GCD(m, n);
    return 0;
}

//exercício3_12
//int area() {

//}

//exercício3_13

// exercício3_14
double integrateTR(double f(double), double a, double b, int n) {
    double h, result = 0;
    h = (b - a) / n;
    for (int i = 1; i <= n; i++) {
        result += ((h / 2) * (f(a + (i - 1) * h) + f(a + i * h)));
    }
    return result;
}

double g(double x) {
    return pow(x, 2);
}

double h(double x) {
    double calc;
    calc = 4 - pow(x, 2);
    return sqrt(calc);
}

int calculate() {
    double x;
    cout << "g(x) is equal to " << integrateTR(g, 0, 10, 365) << endl;
    cout << "h(x) is equal to " << integrateTR(h, -2, 2, 365) << endl;
    return 0;
}
int main()
{
    //area(4, 10, 5, 5, 20, 50);
    //isPrime(77);
    //exercicio3_3(60, 4, 100);
    //exercicio3_4();
    //exercicio3_5(108, 72);
    //timeElapsed();
    //exercicio3_7();
    //month(2002, 3);
    //calendar(1968);
    //factorial_ite(65);
    //call_rec(65);
    //call_GCD(1232, 94234564);
    //calculate();
    return 0;
}

/*
EXERCICIO 3_6
EXERCICIO 3_7
EXERCICIO 3_8
EXERCICIO 3_12
EXERCICIO 3_13
*/