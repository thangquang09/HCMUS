#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person;
class Immunization;
class Vaccine;

class Person {
    string id;
    string name;
    string date;
    vector<Immunization*> immunizations;
public:
    // getter and setter
    string getId() {
        return this->id;
    }
    string getName() {
        return this->name;
    }
    string getDate() {
        return this->date;
    }
    void setId(string id) {
        this->id = id;
    }
    void setName(string name) {
        this->name = name;
    }
    void setDate(string date) {
        this->date = date;
    }
    // constructor
    Person(string id, string name, string date) {
        this->setId(id);
        this->setName(name);
        this->setDate(date);
    }
    // method
    void addImmunization(Immunization* immunization);
    void displayCertificate();
};

class Vaccine {
private:
    string id;
    string date;
    Immunization* immunization = NULL;
    //getter and setter
public:
    string getId() {
        return this->id;
    }
    string getDate() {
        return this->date;
    }
    virtual string getName() {
        return "";
    }
    void setId(string id) {
        this->id = id;
    }
    void setDate(string date) {
        this->date = date;
    }
    // constructor
    Vaccine(string id, string date) {
        this->setId(id);
        this->setDate(date);
    }
    // method
    void setImmunization(Immunization* immunization);
};


class Pfizer : public Vaccine {
    string name;
    // getter and setter
public:
    string getName() override{
        return this->name;
    }
    void setName(string name) {
        this->name = name;
    }
    // constructor
    Pfizer(string id, string date, string name) : Vaccine(id, date) {
        this->setName(name);
    }
};

class Moderna : public Vaccine {
    string name;
public:
    // getter and setter
    string getName() override{
        return this->name;
    }
    void setName(string name) {
        this->name = name;
    }
    // constructor
    Moderna(string id, string date, string name) : Vaccine(id, date) {
        this->setName(name);
    }
};

class Immunization {
    string dose;
    string date;
    Person* person = NULL;
    Vaccine* vaccine = NULL;
public:
    // getter and setter
    string getDose() {
        return this->dose;
    }
    string getDate() {
        return this->date;
    }
    void setDose(string dose) {
        this->dose = dose;
    }
    void setDate(string date) {
        this->date = date;
    }
    Vaccine* getVaccine() {
        return this->vaccine;
    }
    // constructor
    Immunization(string dose, string date) {
        this->setDose(dose);
        this->setDate(date);
    }
    // method
    void setPerson(Person* person) {
        this->person = person;
    }
    void setVaccine(Vaccine* vaccine) {
        this->vaccine = vaccine;
        vaccine->setImmunization(this);
    }
};

void Person::displayCertificate() {
    cout << "Name: " << this->getName() << endl;
    cout << "Date of Birth: " << this->getDate() << endl;
    cout << "Immunization Certificate" << endl;
    for (int i = 0; i < this->immunizations.size(); i++) {
        cout << "Dose: " << this->immunizations[i]->getDose() << endl;
        cout << "Date: " << this->immunizations[i]->getDate() << endl;
        cout << "Vaccine: " << this->immunizations[i]->getVaccine()->getName() << endl;
    }
}

void Person::addImmunization(Immunization* immunization) {
    this->immunizations.push_back(immunization);
    immunization->setPerson(this);
}

void Vaccine::setImmunization(Immunization* immunization) {
    this->immunization = immunization;
}

int main() {
    Person p1 ("1", "John", "2021-01-01");
    Person p2 ("2", "Jane", "2021-01-02");

    Pfizer pf1 ("1", "2021-01-01", "Pfizer");
    Moderna m1 ("1", "2021-01-02", "Moderna");

    Immunization i1 ("1", "2021-01-01");
    Immunization i2 ("2", "2021-01-02");
    Immunization i3 ("1", "2021-01-02");
    Immunization i4 ("2", "2021-01-01");

    i1.setVaccine(&pf1);
    i2.setVaccine(&pf1);

    i3.setVaccine(&m1);
    i4.setVaccine(&pf1);

    p1.addImmunization(&i1);
    p1.addImmunization(&i2);

    p2.addImmunization(&i3);
    p2.addImmunization(&i4);

    p1.displayCertificate();

    cout << "=====================" << endl;

    p2.displayCertificate();
    return 0;
}
