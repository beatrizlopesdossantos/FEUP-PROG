#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h> 
#include <time.h>
#include <climits>
#include <vector>
using namespace std;
const int NE = 5;
void readArray(int a[], size_t nElem) {
    for (int i = 0; i < nElem; i++) {
        cout << "Element number " << i + 1 << ": ";
        cin >> a[i];
    }
}

int findValueInArray(const int a[], size_t nElem, int value, size_t pos1, size_t pos2) {
    for (int i = pos1; i <= pos2; i++) {
        if (a[i] == value) {
            return i;
        }
        else if (i == pos2) {
            return -1;
        }
    }
}

size_t findMultValuesInArray(const int a[], size_t nElem, int value, size_t pos1, size_t pos2, size_t index[]) {
    int size = -1;
    for (int i = pos1; i <= pos2; i++) {
        if (a[i] == value) {
            malloc(1 + size_t(index));
            size += 1;
            index[size];
        }
        else if (i == pos2) {
            return -1;
        }
    }
    return *index;
}

int exercice4_1() {
    const int nElem = 4;
    int index[nElem];
    int a[nElem];
    readArray(a, nElem);
    cout << findValueInArray(a, nElem, 10, 0, 3) << endl;
    cout << findMultValuesInArray(a, nElem, 10, 0, 3, 0) << endl;;
    return 0;
}

void bubbleSort(vector<int>& v, char choice) {
    bool swap = true;
    for (int j = 0; j < v.size(); j++) {
        if (swap ==false) {
            break;
        }
        int count = 0;
        for (int i = 0; i < v.size() - 1; i++) {
            int a = v[i];
            int b = v[i + 1];
            if (choice == 'a') {
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
            else if (choice == 'd') {
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

int exercice4_3() {
    vector<int> v = { 20, 10, 40, 50 };
    char choice;
    cout << "do you want an ascending or descending order? (a/d): ";
    cin >> choice;
    bubbleSort(v, choice);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}

int binarySearch(const vector<int>& v, int value) {
    bool found = false;
    int first, last, middle;
    first = 0;
    last = v.size() - 1;
    while ((found == false) && (first <= last)) {
        middle = (first + last) / 2;
        if (v[middle] == value) {
            found = true;
            return middle;
        }
        else if (value < v[middle]) {
            last = middle - 1;
        }
        else if (value > v[middle]) {
            first = middle + 1;
        }
    }
    return -1;
}

int exercice4_4() {
    vector<int> v = { 1, 5, 10, 20, 50, 100, 150 };
    cout << binarySearch(v, 10);
    return 0;
}

void removeDuplicates(vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size() - 1; j++) {
            if (v[i] == v[j]) {
                int a = j + 1;
                int b = j;
                while (a != v.size() - 1) {
                    v[b] = v[a];
                    a += 1;
                    b += 1;
                }
                v.resize(v.size() - 1);
            }
        }
    }
}

int exercice4_5() {
    vector<int> v = { 20, 1, 5, 10, 10, 50, 10 };
    removeDuplicates(v);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}

void vectorUnion(const vector<int>& v1, const vector<int>& v2, vector<int>& v3) {

}

void localMax(const int a[][NE]) {
    bool greaterThanTarget;
    for (int row = 1; row < NE - 1; row++) {
        for (int collumn = 1; collumn < NE - 1; collumn++) { //Iterates over all the center elements
            greaterThanTarget = false; int TargetValue = a[row][collumn];
            for (int yPosition = row - 1; yPosition < row + 2; yPosition++) {
                for (int xPosition = collumn - 1; xPosition < collumn + 2; xPosition++) {
                    int Value = a[yPosition][xPosition];
                    if (Value > TargetValue) {
                        greaterThanTarget = true;
                        break;
                    }
                }
                if (greaterThanTarget) { break; }
            }
            if (!greaterThanTarget) {
                cout << "The element " << TargetValue << " at index" << "[" << row << "][" << collumn << "] is a local maxima!" << endl;
            }
        }
    }
}

void localMaxvec(vector <vector<int>> b, char decision) {
    bool greaterThanTarget;
    if (decision == 'y') {
        for (int row = 1; row < NE - 1; row++) {
            for (int collumn = 1; collumn < NE - 1; collumn++) { //Iterates over all the center elements
                greaterThanTarget = false; int TargetValue = b[row][collumn];
                for (int yPosition = row - 1; yPosition < row + 2; yPosition++) {
                    for (int xPosition = collumn - 1; xPosition < collumn + 2; xPosition++) {
                        int Value = b[yPosition][xPosition];
                        if (Value > TargetValue) {
                            greaterThanTarget = true;
                            break;
                        }
                    }
                    if (greaterThanTarget) { break; }
                }
                if (!greaterThanTarget) {
                    cout << "The element " << TargetValue << " at index" << "[" << row << "][" << collumn << "] is a local maxima!" << endl;
                }
            }
        }
    }
    else {
        for (int row = 1; row < NE - 1; row++) {
            for (int collumn = 1; collumn < NE - 1; collumn++) {
                greaterThanTarget = false; int TargetValue = b[row][collumn];
                for (int yPosition = row - 1; yPosition < row + 1; yPosition++) {
                    for (int xPosition = collumn - 1; xPosition < collumn + 1; xPosition++) {
                        int Value = b[yPosition][xPosition];
                        if (Value > TargetValue) {
                            greaterThanTarget = true;
                            break;
                        }
                    }
                    if (greaterThanTarget) { break; }
                }
                if (!greaterThanTarget) {
                    cout << "The element " << TargetValue << " at index" << "[" << row << "][" << collumn << "] is a local maxima!" << endl;
                }
            }
        }
    }
}

int exercice4_7() {
    char decision;
    cout << "do you want 8 around or whatever?(y/n) ";
    cin >> decision;
    vector <vector<int>> b{ { 7, 3, 4, 1, 3}, { 2, 9, 6, 2, 1 }, { 1, 3, 5, 1, 4}, {6, 5, 2, 7, 5}, {4, 2, 1, 3, 6} };
    int a[NE][NE] = { 7, 3, 4, 1, 3, 2, 9, 6, 2, 1, 1, 3, 5, 1, 4, 6, 5, 2, 7, 5, 4, 2, 1, 3, 6 };
    localMax(a);
    localMaxvec(b, decision);
    return 0;
}

bool leapyear(int year) {
    bool leapyear = true;
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
        return leapyear;
    }
    else {
        leapyear = false;
        return leapyear;
    }
}

int date(int month, int year) {
    if (month == 0 || month == 2 || month == 4 || month == 6 || month == 7 || month == 9 || month == 11) {
        return 31;
    }
    else if (month == 1) {
        if (leapyear(year)) {
            return 29;
        }
        else {
            return 28;
        }
    }
    else if (month == 3 || month == 5 || month == 8 || month == 10) {
        return 30;
    }
}

vector <vector<int>> vec(int year) {
    vector <vector<int>> pul(12, vector<int>(31));
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < date(i, year); j++) {
            pul[i][j] = rand();
            if (date(i, year) < 31) {
                pul.resize(12, vector<int>(date(i, year)));
            }
        }
    }
    return pul;
}

int dailypul(vector <vector<int>> pul, int year) {
    int sum, totdays;
    float av;
    sum = 0;
    if (leapyear(year)) {
        totdays = 366;
    }
    else {
        totdays = 365;
    }
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < date(i, year); j++) {
            sum += pul[i][j];
        }
    }
    av = sum / totdays;
    return av;
}

int monthlypul(vector <vector<int>> pul, int year) {
    int sum;
    float av;
    for (int i = 0; i < 12; i++) {
        sum = 0;
        for (int j = 0; j < date(i, year); j++) {
            sum += pul[i][j];
        }
        av = sum / date(i, year);
        switch (i) {
        case 0: cout << "The average of January is " << av << endl;
            break;
        case 1: cout << "The average of February is " << av << endl;
            break;
        case 2: cout << "The average of March is " << av << endl;
            break;
        case 3: cout << "The average of April is " << av << endl;
            break;
        case 4: cout << "The average of May is " << av << endl;
            break;
        case 5: cout << "The average of June is " << av << endl;
            break;
        case 6: cout << "The average of July is " << av << endl;
            break;
        case 7: cout << "The average of August is " << av << endl;
            break;
        case 8: cout << "The average of September is " << av << endl;
            break;
        case 9: cout << "The average of October is " << av << endl;
            break;
        case 10: cout << "The average of November is " << av << endl;
            break;
        case 11: cout << "The average of December is " << av << endl;
            break;
        }
    }
    return 0;
}

int aboveav(vector <vector<int>> pul, int year) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < date(i, year); j++) {
            if (pul[i][j] > dailypul(pul, year)) {
                cout << i + 1 << "/" << j + 1 << " (" << pul[i][j] << ")" << endl;
            }
        }
    }
    return 0;
}

int exercice4_8() {
    int year;
    year = 20001;
    cout << "The daily pluviosity is " << dailypul(vec(year), year) << endl;
    monthlypul(vec(year), year);
    cout << "The days with pluviosity were above the average daily pluviosity are: " << endl;
    aboveav(vec(year), year);
    return 0;
}

void qsort(void* base, size_t num, size_t size, int (*comparator)(const void*, const void*)) {


}
int main() {
    //exercice4_1();
    //exercice4_3();
    //exercice4_4();
    //exercice4_5();
    //exercice4_7();
    //exercice4_8();
    return 0;
}

/*VER 4.1D, E, F
FAZER 4.2
4.3E
4.5
4.6
4.7(acabar com vetores)
4.11 para a frente
*/