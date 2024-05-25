#include <iostream>
#include <vector>
#include <string>
#include <map>


using namespace std;

class Employee {
    string number;
    double salary;
    string name;
public:
    // getter and setter
    string getNumber() { return this->number;}
    double getSalary() { return this->salary;}
    string getName() { return this->name;}
    
    void setNumber(string number) {this->number = number;}
    void setSalary(double salary) { this->salary = salary;}
    void setName(string name) { this->name = name;}

    // constructor
    Employee(string number, double salary, string name) {
        this->setNumber(number);
        this->setSalary(salary);
        this->setName(name);
    }

    // display
    virtual void display() = 0;
};

class Programmer : public Employee {
private:
    string language;
public:
    string getLanguage() {
        return this->language;
    }
    void getLanguage(string language) {
        this->language = language;
    }
    void setLanguage(string language) {
        this->language = language;
    }
    // constructor
    Programmer(string number, double salary, string name, string language) : Employee(number, salary, name) {
        this->setLanguage(language);
    }
    // display
    void display() override {
        cout << "Programmer:\n";
        cout << "\tNumber:\t" << this->getNumber() << endl;
        cout << "\tSalary:\t" << this->getSalary() << endl;
        cout << "\tName:\t" << this->getName() << endl;
        cout << "\tLanguage:\t" << this->getLanguage() << endl;
    }
};

class ProjectLeader : public Programmer {
    map<string, Programmer*> team;
public:
    // constructor
    ProjectLeader(string number, double salary, string name, string language) : Programmer(number, salary, name, language) {

    }
    void display() {
        // call display of Programmer
        cout << "\t---Project Leader:---\n";
        Programmer::display();
        cout << "\t---Team:---\n";
        for (auto programmer : team) {
            programmer.second->display();
        }
    }
    void addProgrammer(Programmer* pr) {
        this->team[pr->getNumber()] = pr;
    }
};

class Administrator : public Employee {
private:
    string department;
public:
    string getDepartment() {
        return this->department;
    }
    void setDepartment(string department) {
        this->department = department;
    }
    // constructor
    Administrator(string number, double salary, string name, string department) : Employee(number, salary, name) {
        this->setDepartment(department);
    }

    void display() {
        cout << "Administrator:\n";
        cout << "\tNumber:\t" << this->getNumber() << endl;
        cout << "\tSalary:\t" << this->getSalary() << endl;
        cout << "\tName:\t" << this->getName() << endl;
        cout << "\tDepartment:\t" << this->getDepartment() << endl;
    }
};

class SoftwareHouse {
    private:
        string name;
        map<string, Employee*> staff;
    public:
        void setName(string aName)
        {
            this->name = aName;
            this->staff.clear();
            //this->staff = {};
        }
        string getName() {
            return this->name;
        }

        SoftwareHouse(string aName) {
            this->setName(aName);
        }

        void addStaff(Employee *aStaff) {
            this->staff[aStaff->getNumber()] = aStaff;
        }
        void displayStaff() {
            cout << "Staff of " << this->getName() << ":\n";
            for (auto emp : this->staff) {
                emp.second->display();
                cout << "\n";
            }
        }
};

int main() {
    SoftwareHouse sh("Objects-R-Us");

    Programmer p1("123", 2000, "John", "Ada");
    Programmer p2("234", 2500, "Ken", "C++");
    Programmer p3("456", 3000, "Peter", "Java");

    ProjectLeader pl1("567", 4000, "Jon", "C");
    ProjectLeader pl2("789", 4000, "Jessie", "Java");

    Administrator a1("111", 5000, "Sue", "HR");

    // Assign each programmer to a project leader
    pl1.addProgrammer(&p3);
    pl1.addProgrammer(&p2);
    pl2.addProgrammer(&p1);

    // Hire each programmer and project leader
    sh.addStaff(&p1);
    sh.addStaff(&p2);
    sh.addStaff(&p3);
    sh.addStaff(&pl1);
    sh.addStaff(&pl2);
    sh.addStaff(&a1);

    // Display some details of the staff.
    sh.displayStaff();
}