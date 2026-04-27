#include <iostream>
using namespace std;

struct Student{
    int sid;
    string sname;
    float scgpa;
    string sdept;

    Student *next;
};

Student *head = NULL;

void addStudent(int id, string name, float cgpa, string dept){
    Student *newitem = NULL;
    newitem = new Student();
    newitem -> sid = id;
    newitem -> sname = name;
    newitem -> scgpa = cgpa;
    newitem -> sdept = dept;

    newitem -> next = NULL;

    if(head == NULL){
        head = newitem;
    }

    else{
        Student *temp = NULL;
        temp = head;

        while(temp -> next != NULL){
            temp = temp -> next;
        }

        temp -> next = newitem;
    }

}


int main(){
    int key;

    while(true){
        cout << endl << "If you want to add a student, press 1 otherwise, press 0: ";
        cin >> key;

        if(key == 1){
            int id;
            cout << endl << "Insert ID: ";
            cin >> id;

            string name;
            cout << endl << "Insert name: ";
            cin.ignore();
            getline(cin, name);

            float cgpa;
            cout << endl << "Insert CGPA: ";
            cin >> cgpa;

            string dept;
            cout << endl << "Insert Dept.: ";
            cin.ignore();
            getline(cin, dept);

            addStudent(id, name, cgpa, dept);

        }

        else{
            break;
        }
    }

    Student *temp = NULL;
    temp = head;

    cout<<endl<<"Insert an ID to get info: ";
    int src;
    cin >> src;
    int flag = 0;

    while(temp != NULL){
        if(temp -> sid == src){
            cout << endl << "Name: " << temp -> sname;
            cout << endl << "ID: " << temp -> sid;
            cout << endl << "CGPA: " << temp -> scgpa;
            cout << endl << "Dept.: " << temp -> sdept;
            flag = 1;
        }

        temp = temp -> next;
    }

    if(flag == 0){
        cout<< endl << "Invalid ID!";
    }

}