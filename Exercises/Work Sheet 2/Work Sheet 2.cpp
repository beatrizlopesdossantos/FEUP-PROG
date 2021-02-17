#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h> 
#include <time.h>
#include <climits>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Date
{
public:
    Date();
    Date(unsigned int year, unsigned int month, unsigned int day);
    Date(string yearMonthDay); // yearMonthDay must be in format "yyyy/mm/dd"
    void setYear(unsigned int year);
    void setMonth(unsigned int month);
    void setDay(unsigned int day);
    void setDate(unsigned int year, unsigned int month, unsigned int day);
    unsigned int getYear() const;
    unsigned int getMonth() const;
    unsigned int getDay() const;
    string getDate() const; // returns the date in format "yyyy/mm/dd"
    void show() const; // shows the date on the screen in format "yyyy/mm/dd"
    bool isValid() const;
    bool isEqualTo(const Date& date) const;
    bool isNotEqualTo(const Date& date) const;
    bool isAfter(const Date& date) const;
    bool isBefore(const Date & date) const;
private:
    unsigned int year;
    unsigned int month;
    unsigned int day;
    int DaysofMonth() const;
};

Date::Date() {
    time_t mytime = time(0);
    struct tm data_atual;
    localtime_s(&data_atual, &mytime);
    this->year = data_atual.tm_year + 1900;
    this->month = data_atual.tm_mon + 1;
    this->day = data_atual.tm_mday;
}
Date::Date(unsigned int year, unsigned int month, unsigned int day) {
    this->year = year;
    this->month = month;
    this->day = day;
}
Date::Date(string YearMonthDay) {
    this->year = stoi(YearMonthDay.substr(0, 4));
    this->month = stoi(YearMonthDay.substr(5, 2));
    this->day = stoi(YearMonthDay.substr(8, 2));
}
unsigned int Date::getYear() const {
    return this->year;
}
unsigned int Date::getMonth() const {
    return this->month;
}
unsigned int Date::getDay() const {
    return this->day;
}
void Date::setYear(unsigned int year) {
    this->year = year;
}
void Date::setMonth(unsigned month) {
    this->month = month;
}
void Date::setDay(unsigned int day) {
    this->day = day;
}
void Date::setDate(unsigned int year, unsigned int month, unsigned int day) {
    this->year = year;
    this->month = month;
    this->day = day;
}
string Date::getDate() const {
    string y = to_string(year), m = to_string(month), d = to_string(day);
    while (y.length() != 4) {
        y = '0' + y;
    }
    while (m.length() != 2) {
        m = '0' + m;
    }
    while (d.length() != 2) {
        d = '0' + d;
    }
    return y + "/" + m + "/" + d;
}
void Date::show() const {
    cout << setfill('0');
    cout << setw(4) << year << "/" << setw(2) << month << "/" << setw(2) << day << endl;
}
int Date::DaysofMonth() const{
    bool ValidOperation = true;
    switch (month) {
    case (1): 
        return 31;
    case (3):
        return 31;
    case (4):
        return 30;
    case (5):
        return 31;
    case (6):
        return 30;
    case (7):
        return 31;
    case(8):
        return 31;
    case (9):
        return 30;
    case (10):
        return 31;
    case (11):
        return 30;
    case (12):
        return 31;
    }
    if (month == 2) {
        if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
            return 29;
        }
        else {
            return 28;
        }
    }
}
bool Date::isValid() const {
    if (year < 0) {
        return false;
    }
    else if (month < 1 || month > 12) {
        return false;
    }
    else if (day < 0 || day > DaysofMonth()) {
        return false;
    }
    else {
        return true;
    }
}
bool Date::isEqualTo(const Date& date) const{
    if (this->year == int(date.getYear()) && this->month == int(date.getMonth()) && this->day == int(date.getDay())) {
        return true;
    }
    else {
        return false;
    }
}
bool Date::isNotEqualTo(const Date& date) const {
    return !isEqualTo(date);
}
bool Date::isAfter(const Date& date) const {
    if (year != date.getYear()) {
        if (year > date.getYear()) {
            return true;
        }
        else {
            return false;
        }
    }
    else if (month != date.getMonth()) {
        if (month > date.getMonth()) {
            return true;
        }
        else {
            return false;
        }
    }
    else if (day != date.getDay()) {
        if (day > date.getDay()) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return 0;
    }
}
bool Date::isBefore(const Date& date) const {
    return !isAfter(date);
}

class Student {
public:
    Student();
    Student(const string& code, const string& name);
    void setGrades(double shortExam, double project, double exam);
    string getCode() const;
    string getName() const;
    int getFinalGrade() const;
    bool isApproved() const; // is the student approved or not ?
    void show() const;
    static int weightShortExam, weightProject, weightExam; // weights in percentage (ex:20,30,50)
private:
    string code; // student code
    string name; // student complete name
    double shortExam, project, exam; // grades obtained by the student in the different components
    int finalGrade;
};

Student::Student() {
    cout << "Student code? ";
    cin >> code;
    cin.ignore(1000, '\n');
    cout << "Student name? ";
    getline(cin, name);
    cout << "Short exam grade? ";
    cin >> shortExam;
    cout << "Project grade? ";
    cin >> project;
    cout << "Exam grade? ";
    cin >> exam;
    cout << endl;
    finalGrade = (weightShortExam / 100 * shortExam) + (weightProject / 100 * project) + (weightExam / 100 * exam);
    finalGrade = round(finalGrade);
}
Student::Student(const string& code, const string& name) {
    this->code = code;
    this->name = name;
}
void Student::setGrades(double shortExam, double project, double exam) {
    this->shortExam = shortExam;
    this->project = project;
    this->exam = exam;
    finalGrade = round((weightShortExam / 100 * shortExam) + (weightProject / 100 * project) + (weightExam / 100 * exam));
}
string Student::getCode() const {
    return code;
}
string Student::getName() const {
    return name;
}
int Student::getFinalGrade() const {
    return finalGrade;
}
bool Student::isApproved() const {
    if (finalGrade >= 10) {
        return true;
    }
    else {
        return false;
    }
}
int Student::weightShortExam = 20;
int Student::weightProject = 30;
int Student::weightExam = 50;


void showAboveAverageStudents(ostream& of, vector<Student> v) {
    double average = 0;
    for (int i = 0; i < v.size(); i++) {
        average += v[i].getFinalGrade();
    }
    average = average / v.size();
    for (int i = 0; i < v.size(); i++) {
        if (v[i].getFinalGrade() > average) {
            of << v[i].getName() << "-" << v[i].getCode() << endl << "Final Grade: " << v[i].getFinalGrade() << endl << endl;
        }
    }
}
void showAboveAverageStudents(vector <Student> v) {
    double average = 0;
    for (int i = 0; i < v.size(); i++) {
        average += v[i].getFinalGrade();
    }
    average = average / v.size();
    cout << "STUDENTS ABOVE AVERAGE: " << endl;
    for (int i = 0; i < v.size(); i++) {
        if (v[i].getFinalGrade() > average) {
            cout << v[i].getName() << " - " << v[i].getCode() << endl << "Final Grade : " << v[i].getFinalGrade() << endl << endl;
        }
    }
}
void showStudents(ofstream& of, vector<Student> v) {
    for (int i = 0; i < v.size(); i++) {
        of << v[i].getCode() << ";" << v[i].getName() << ";" << v[i].getFinalGrade() << endl;
    }
}
void studentvector() {
    int students;
    vector<Student>v;
    cout << "How many students took the course? ";
    cin >> students;
    for (int i = 0; i < students; i++) {
        Student s;
        v.push_back(s);
    }
    showAboveAverageStudents(v);
}
int files() {
    ifstream in("studentsinfo.txt");
    ofstream of("Studentsof.txt");
    string student;
    if (in.fail()) {
        cerr << "Error opening";
        return 1;
    }
    vector<Student> v;
    getline(in, student);
    while (!in.eof()) {
        string code = student.substr(0, 11);
        int index1 = student.find_first_of(";", 12);
        string nome = student.substr(12, index1);
        int index2 = student.find_first_of(";", index1 + 1);
        double shorte = stod(student.substr(index1 + 1, index2));
        int index3 = student.find_first_of(";", index2 + 1);
        double proj = stod(student.substr(index2 + 1, index3));
        int index4 = student.find_first_of(";", index3 + 1);
        double exam = stod(student.substr(index3 + 1, index4));
        Student s1(code, nome);
        s1.setGrades(shorte, proj, exam);
        v.push_back(s1);
    }
    showStudents(of, v);
}

int main()
{
    //exercicio 1
    //const Date d1(2001, 10, 27);
    //d1.show;

    //exercicio 2
    //Student c;
    //c.show();
    //studentvector();
    cout << int('Z') << int('A');
}
