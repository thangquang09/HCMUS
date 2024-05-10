#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Major;

class Student{
    string name;
    string id;
    vector<Major*> majors;
    // getter and setter
    public:
    string getName(){
        return this->name;
    }
    void setName(string name){
        this->name = name;
    }

    string getId(){
        return this->id;
    }
    void setId(string id){
        this->id = id;
    }

    // constructor
    Student(string name, string id){
        this->setId(id);
        this->setName(name);
    }
    // function
    void display();
    void registerMajor(Major *major);
};

class Major{
    string name;
    vector<Student*> students;
    public:
    // getter and setter
    string getName(){
        return this->name;
    }
    void setName(string name){
        this->name = name;
    }
    // constructor
    Major(string name){
        this->setName(name);
    }
    // function
    void display();
    void registerStudent(Student *student);
};

void Major::display(){
    cout << "____________________________\n";
    cout << "Name: " << this->getName() << endl;
    for (int i = 0; i < this->students.size(); i++){
        cout << "Student " << i+1 << ": " << this->students[i]->getName() << " | Id: " << this->students[i]->getId() << endl;
    }
}

void Major::registerStudent(Student *student){
    // nganh dc sinh vien dang ky
    this->students.push_back(student);
}

void Student::display(){
    cout << "____________________________\n";
    cout << "Name: " << this->getName() << endl;
    cout << "ID: " << this->getId() << endl;
    cout << "Majors: ";
    for(int i = 0; i < this->majors.size(); i++){
        cout << this->majors[i]->getName() << " | ";
    }
    cout << endl;
}

void Student::registerMajor(Major *major){
    // sinh vien dang ky nganh
    this->majors.push_back(major);
    major->registerStudent(this);
}

int main() {
    Student student1 = Student("Nguyen Van A", "123");
    Student student2 = Student("Nguyen Van B", "124");
    Student student3 = Student("Nguyen Van C", "125");
    Major major1 = Major("Khoa hoc may tinh");
    Major major2 = Major("Toan-tin");
    // sinh vien dang ky nganh hoc
    student1.registerMajor(&major1);
    student1.registerMajor(&major2);

    student2.registerMajor(&major1);
    student2.registerMajor(&major2);

    student3.registerMajor(&major2);

    cout << "\n----Thong tin sinh vien----\n";
    student1.display();
    student2.display();
    student3.display();
    cout << "\n----Thong tin nganh hoc----\n";
    major1.display();
    major2.display();

    return 0;
}