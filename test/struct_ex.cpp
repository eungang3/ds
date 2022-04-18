#include <iostream>
#include <stdio.h>

using namespace std;

struct Employee
{
  string name;
  int age;
  float salary;
}e1;

struct Student
{
    char name[50];
    int age;
};

int main() {
  // string으로 정의한 경우 dot notation 사용 가능
  e1.name = "Albert";
  e1.age = 32;
  e1.salary = 4200;
  cout<< "E1 Name: " << e1.name <<endl;

 // char array로 정의한 경우 initialization만 가능 
  struct Student s1 = {"John", 16};
  cout << "S1 Name: " << s1.name <<endl;
}