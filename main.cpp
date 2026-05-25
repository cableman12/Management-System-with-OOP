#include<iostream>
#include<vector>
#include<string>
using namespace std;


class Student{
private:
    int ID, age;
    string name;
public:
    Student(int ID, string name, int age);    
    void setID(int id);
    int getID();
    void setName(string name);
    string getName();
    void setAge(int age);
    int getAge();
    void displayStudent();
};

Student::Student(int ID, string name, int age)
{ 
    this->ID = ID;
    this->name=name;
    this->age=age;
}

void Student::setID(int id)
{
    this->ID = id;
}

int Student::getID()
{
    return this->ID;
}

void Student::setName(string name)
{
    this->name = name;
}

string Student::getName()
{
    return this->name;
}

void Student::setAge(int age)
{
    this->age = age;
}

int Student::getAge()
{
    return this->age;
}

void Student::displayStudent()
{
    cout << "ID: " << ID << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
}


// creating an add new student function
void addStudent(vector<Student> &s)
{
    int age, id;
    string name;

    cout << "Enter student Name: " << endl;
    cin.ignore();
    getline(cin, name);

    cout << "Enter student ID: " << endl;
    cin >> id;

    for(size_t i = 0; i < s.size(); i++)
    {
        if(s[i].getID() == id)
        {
            cout << "Student already exists." << endl;
            return;
        }
    }

    cout << "Enter student Age: " << endl;
    cin >> age;

    Student newStudent(id, name, age);
    s.push_back(newStudent);

    cout << "Student added successfully." << endl;
}

// display all students
void displayStudents(vector<Student> &s)
{
    if(s.empty())
    {
        cout << "No students found." << endl;
        return;
    }

    for(size_t i = 0; i < s.size(); i++)
    {
        s[i].displayStudent();
        cout << "-----------------------------" << endl;
    }
}

// search student
void searchStudent(vector<Student> &s)
{
    int id;

    cout << "Enter student ID to search: " << endl;
    cin >> id;

    for(size_t i = 0; i < s.size(); i++)
    {
        if(s[i].getID() == id)
        {
            cout << "-----------------------------" << endl;
            cout << "Student found." << endl;
            s[i].displayStudent();
            cout << "-----------------------------" << endl;
            return;
        }
    }

    cout << "Student not found." << endl;
}

// update student
void updateStudent(vector<Student> &s)
{
    int id;
    int option;

    cout << "Enter student ID to update: " << endl;
    cin >> id;

    for(size_t i = 0; i < s.size(); i++)
    {
        if(s[i].getID() == id)
        {
            cout << "Student found." << endl;
            cout << "1. Update ID" << endl;
            cout << "2. Update Name" << endl;
            cout << "3. Update Age" << endl;
            cout << "Enter your option: " << endl;
            cin >> option;

            switch(option)
            {
                case 1:
                {
                    int newID;
                    cout << "Enter new ID: " << endl;
                    cin >> newID;
                    s[i].setID(newID);
                    break;
                }

                case 2:
                {
                    string newName;
                    cout << "Enter new Name: " << endl;
                    cin.ignore();
                    getline(cin, newName);
                    s[i].setName(newName);
                    break;
                }

                case 3:
                {
                    int newAge;
                    cout << "Enter new Age: " << endl;
                    cin >> newAge;
                    s[i].setAge(newAge);
                    break;
                }

                default:
                    cout << "Invalid option." << endl;
            }

            cout << "Student updated successfully." << endl;
            return;
        }
    }

    cout << "Student not found." << endl;
}

// delete student
void deleteStudent(vector<Student> &s)
{
    int id;

    cout << "Enter student ID to delete: " << endl;
    cin >> id;

    for(size_t i = 0; i < s.size(); i++)
    {
        if(s[i].getID() == id)
        {
            s.erase(s.begin() + i);
            cout << "Student deleted successfully." << endl;
            return;
        }
    }

    cout << "Student not found." << endl;
}

int main()
{
    vector<Student> students;
    students.push_back(Student(1, "Alice", 20));
    students.push_back(Student(2, "Bob", 22));

    int options;

    do
    {
        cout << "\t\t ----------------------------------" << endl;
        cout << "\t\t| Welcome to Student Management System |" << endl;
        cout << "\t\t ----------------------------------" << endl;
        cout << "\t1. Add new Student" << endl;
        cout << "\t2. Display all Students" << endl;
        cout << "\t3. Search Student" << endl;
        cout << "\t4. Update Student" << endl;
        cout << "\t5. Delete Student" << endl;
        cout << "\t6. Exit program" << endl;
        cout << "Enter your option: " << endl;
        cin >> options;

        switch(options)
        {
            case 1:
                addStudent(students);
                break;

            case 2:
                displayStudents(students);
                break;

            case 3:
                searchStudent(students);
                break;

            case 4:
                updateStudent(students);
                break;

            case 5:
                deleteStudent(students);
                break;

            case 6:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }

    } while(options != 6);

    return 0;
}