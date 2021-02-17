#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h> 
#include <time.h>
#include <climits>
#include <cstring>
#include <string.h>
#include <vector>
#include <sstream>
using namespace std;

char encryptChar(char c, int key) {
    int result;
    result = int(c) + key;
    if (isupper(c)) {
        if (result < 65) {
            result = result + 90 - 65 + 1;
        }
        else if (result > 90) {
            result = result - 90 + 65 - 1;
        }
    }
    else {
        if (result < 97) {
            result = result + 122 - 97 + 1;
        }
        else if (result > 122) {
            result = result - 122 + 97 - 1;
        }
    }
    return result;
}

string encryptString(string s, int key) {
    int result = 0;
    char ch;
    for (int i = 0; i < s.length(); i++) {
        ch = s[i];
        if (isupper(ch)) {
            result = int(ch) + key;
            if (result < 65) {
                result = result + 90 - 65 + 1;
            }
            else if (result > 90) {
                result = result - 90 + 65 - 1;
            }
        }
        else if (ch == ' ') {
            result = 32;
        }
        else if (islower(ch)) {
            result = int(ch) + key;
            if (result < 97) {
                result = result + 122 - 97 + 1;
            }
            else if (result > 122) {
                result = result - 122 + 97 - 1;
            }
        }
        s[i] = result;
    }
    return s;
}

int exercice5_1() {
    string s = "Jxu gkysa rhemd ven ZKCFI eluh jxu bqpo tew";
    char c = 'a';
    int key = 10;
    cout << "The letter " << c << " is " << "transformed in " << encryptChar(c, key) << endl;
    cout << "The letter " << s << " is " << "transformed in " << encryptString(s, key);
    return 0;
}

void bubbleSort(vector<string> &v, char order) {
    bool swap = true;
    for (int j = 0; j < v.size(); j++) {
        if (swap == false) {
            break;
        }
        int count = 0;
        for (int i = 0; i < v.size() - 1; i++) {
            string a = v[i];
            string b = v[i + 1];
            if (order == 'a') {
                if (v[i] > v[i + 1]) {
                    v[i] = b;
                    v[i + 1] = a;
                }
                else {
                    count += 1;
                    if (count == (v.size() - 1)) {
                        swap = false;
                    }
                }
            }
            else if (order == 'd') {
                if (v[i] < v[i + 1]) {
                    v[i] = b;
                    v[i + 1] = a;
                }
                else {
                    count += 1;
                    if (count == (v.size() - 1)) {
                        swap = false;
                    }
                }
            }
        }
    }
}

int exercice5_2() {
    int num;
    cout << "How many name you want to write? ";
    cin >> num;
    string name;
    vector<string> v;
    for (int i = 0; i < num; i++) {
        cout << "Write the name " << i + 1 << ": ";
        cin >> name;
        cin.clear();
        cin.ignore(1000, '\n');
        v.push_back(name);
    }
    char order;
    cout << "Do you want an ascending or descending order? (a/d): ";
    cin >> order;
    bubbleSort(v, order);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}

bool sequenceSearch(const string& s, int nc, char c) {
    for (int i = 0; i < s.length(); i++) {
        int num = 1;
        if (s[i] == c) {
            for (int j = i + 1; j < s.length(); j++) {
                if (s[j] != c) {
                    break;
                }
                num += 1;
                if (num == nc) {
                    return true;
                }
            }
        }
    }
    return false;
}

//bool sequenceSearch2(const string& s, int nc, char c) {
  //  size_t found = s.find(c);


//}
int exercice5_4() {
    const string s = "abcddeedddf";
    if (sequenceSearch(s, 4, 'd')) {
        cout << "True";
    }
    else {
        cout << "False";
    }
    return 0;
}

string normalizeName(const string& name) {
    string name1 = name;
    while ((name1.at(0) == ' ') || (name1.at(name1.size() - 1) == ' ')) {
        if (name1.at(0) == ' ') {
            name1.erase(name1.begin());
        }
        if (name1.at(name1.size() - 1) == ' ') {
            name1.erase(name1.begin() + name1.size() - 1);
        }
    }
    string final = "";
    for (int i = 0; i < name1.length(); i++) {
        final += toupper(name1[i]);
    }
    /*vector<string> target = { "DE", "DO", "DA", "DOS", "DAS", "E" };
    for (int i = 0; i < target.size(); i++) {
        int found = -1;
        do {
            found = name1.find(target[i], found + 1);
            if (found != -1) {
                final = name1.substr(0, found) + name1.substr(found + target[i].length());
            }
        } while (found != -1);
    }*/
    cout << final;
    return name1;
}

struct Fraction {
    int numerator;
    int denominator;
};

bool readFraction(Fraction& fraction) {
    char x;
    bool ValidInput = true;
    cout << "Please give a fraction: ";
    cin >> fraction.numerator;
    if (cin.fail()) {
        ValidInput = false;
        cin.clear();
    }
    x = cin.get();
    if (x != '/') {
        ValidInput = false;
    }
    cin >> fraction.denominator;
    if (cin.fail()) {
        ValidInput = false;
        cin.clear();
    }
    else if (cin.peek() != '\n') {
        ValidInput = false;
    }
    else if (fraction.denominator == 0) {
        ValidInput = false;
    }
    if (!ValidInput) {
        fraction.numerator = 0;
        fraction.denominator = 0;
    }
    return ValidInput;
}

int GCD(int m, int n) {
    if (m % n == 0) {
        return n;
    }
    return GCD(n, m % n);
}

void reduceFraction(Fraction& fraction) {
    int x = GCD(fraction.numerator, fraction.denominator);
    fraction.numerator /= x;
    fraction.denominator /= x;
    cout << fraction.numerator << '/' << fraction.denominator << endl;
}

void FractionsOPertions(Fraction fraction1, Fraction fraction2) {
    Fraction result;
    bool x1, x2, InvalidInput;
    char x;
    string s = "+-/*";
    do {
        x1 = readFraction(fraction1);
        if (!x1) {
            cout << "Invalid input. " << endl;
        }
    } while (!x1);
    do {
        x2 = readFraction(fraction2);
        if (!x2) {
            cout << "Invalid input. " << endl;
        }
    } while (!x2);
    cout << "And what is the operation you want to do? ";
    do {
        InvalidInput = false;
        cin >> x;
        if (cin.fail()) {
            cin.clear;
            InvalidInput = true;
        }
        else {
            if (s.find(x) < s.length() || s.find(x) >= 0) {
                switch (int(x)) {
                case(int('+')):
                    fraction1.numerator *= fraction2.denominator;
                    fraction2.numerator *= fraction1.denominator;
                    result.numerator = fraction1.numerator + fraction2.numerator;
                    result.denominator = fraction1.denominator * fraction1.denominator;
                    break;
                case(int('-')):
                    fraction1.numerator *= fraction2.denominator;
                    fraction2.numerator *= fraction1.denominator;
                    result.numerator = fraction1.numerator - fraction2.numerator;
                    result.denominator = fraction1.denominator * fraction1.denominator;
                    break;
                case(int('*')):
                    result.numerator = fraction1.numerator * fraction2.numerator;
                    result.denominator = fraction1.denominator * fraction1.denominator;
                    break;
                case(int('/')):
                    result.numerator = fraction1.numerator + fraction2.denominator;
                    result.denominator = fraction1.denominator * fraction1.numerator;
                    break;
                }
            }
            else {
                cout << "Invalid input. ";
                InvalidInput = true;
            }
        }
    } while (InvalidInput);
    reduceFraction(result);
    /*    
    Fraction fraction1, fraction2;
    fraction1.numerator = 1;
    fraction2.numerator = 1;
    fraction1.denominator = 1;
    fraction2.denominator = 1;
    while (true) {
        FractionsOPertions(fraction1, fraction2);
    }*/
}

struct Date {
    unsigned int year, month, day;
};

void readDate(Date* d) {
    string y, m, day;
    cout << "Please give a date. [y/m/day] " << endl;
    getline(cin, y, '/');
    getline(cin, m, '/');
    getline(cin, day, '\n');
    (*d).year = atoi(y.c_str());
    (*d).month = atoi(m.c_str());
    (*d).day = atoi(day.c_str());
}

void writeDate(const Date* d) {
    cout << setfill('0');
    cout << << setw(4) << (*d).year << '/' << setw(2) << (*d).month << '/' << setw(2) << (*d).day;
}

int exercice5_7() {

    return 0;
}

int main()
{
    //exercice5_1();
    //exercice5_2();
    //exercice5_4();
    //const string v = "    Maria da Felicidade   dos Reis e Passos Dias de Aguiar  ";
    //normalizeName(v);
    //exercice5_7();
    return 0;
}

/*exercicio 5.3
5.4B
5.5
5.6
*/