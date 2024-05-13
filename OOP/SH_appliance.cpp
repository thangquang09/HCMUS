#include <iostream>
#include <vector>
#include <string>


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
    void display() {
        cout << "Employee:\n";
        cout << "\tNumber:\t" << this->getNumber() << endl;
        cout << "\tSalary:\t" << this->getSalary() << endl;
        cout << "\tName:\t" << this->getName() << endl;
    }
};

class Programmer : Employee {
    string language;
public:
    string getLanguage() {
        return this->language;
    }
    void getLanguage(string language) {
        this->language = language;
    }
    // constructor
    Programmer(string number, double salary, string name, string language) : Employee(number, salary, name) {
        this->language = language;
    }
    // display
    void display() {
        // call display of Employee
        Employee::display();
        cout << "\tLanguage:\t" << this->getLanguage() << endl;
    }
};

class ProjectLeader : Programmer {
    vector<Programmer*> team;
public:
    // constructor
    ProjectLeader(string number, double salary, string name, string language) : Programmer(number, salary, name, language) {
        this->team = {};
    }
    void display() {
        // call display of Programmer
        cout << "__________________________________\n";
        Programmer::display();
        if (team.size() == 0) {
            cout << "No teammate\n";
        }
        else {
            cout << "Teammates:\n";
            for (int i = 0; i < team.size(); i++) {
                cout << "\t---Teammate " << i+1 << "---\n";
                team[i]->display();
            }
        }
        cout << "__________________________________\n";
    }
    void addProgrammers(Programmer* pr) {
        team.push_back(pr);
    }
};

class SoftwareHouse {
    string name;
    vector<ProjectLeader*> leaders;
    vector<Programmer*> programmers;
public:
    // getter and setter
    string getName() { return this->name;}
    void setName(string name) { this->name = name;}
    // constructor
    SoftwareHouse(string name) {
        this->setName(name);
        this->leaders = {};
        this->programmers = {};
    }
    // display staff
    void displayStaff() {
        cout << "Staff:\n";
        cout << "\t---Leaders---\n";
        for (auto leader : leaders) {
            leader->display();
        }
        cout << "\t---Programmers---\n";
        for (auto programmer : programmers) {
            programmer->display();
        }
    }
    void addProjectLeader(ProjectLeader* pl) {
        leaders.push_back(pl);
    }
    void addProgrammer(Programmer* pr) {
        programmers.push_back(pr);
    }
};  

int main() {
    SoftwareHouse sh = SoftwareHouse("HCMUS");

    Programmer pr1 = Programmer("123", 2000, "John", "Ada");
    Programmer pr2 = Programmer("234", 2500, "Ken", "C++");
    Programmer pr3 = Programmer("456", 3000, "Peter", "Java");

    ProjectLeader pl1 = ProjectLeader("567", 4000, "Jon", "C");
    ProjectLeader pl2 = ProjectLeader("789", 4000, "Jessie", "Java");

    pl1.addProgrammers(&pr3);
    pl1.addProgrammers(&pr2);
    pl2.addProgrammers(&pr1);

    sh.addProjectLeader(&pl1);
    sh.addProjectLeader(&pl2);
    sh.addProgrammer(&pr1);
    sh.addProgrammer(&pr2);
    sh.addProgrammer(&pr3);

    sh.displayStaff();
}