#include<iostream>
#include<string>
#include<vector>
#include<string>
#include<map>

using namespace std;
class Section;
class Student;
class Section;
class Transcript;
class TranscriptEntry;
class PlanOfStudy;

class Person {
private:
    string ssn;
    string name;
public:
    // getter and setter
    string getSSN() {
        return ssn;
    }
    void setSSN(string ssn) {
        this->ssn = ssn;
    }
    string getName() {
        return name;
    }
    void setName(string name) {
        this->name = name;
    }
    // constructor
    Person(string ssn, string name) {
        this->setSSN(ssn);
        this->setName(name);
    }
    virtual void display() = 0;
};

class Professor : public Person {
private:
    string title;
    map<string, Student*> advises;
    map<string, Section*> sections;
public:
    // getter and setter
    string getTitle() {
        return title;
    }
    void setTitle(string title) {
        this->title = title;
    }
    // constructor
    Professor(string ssn, string name, string title, string department) : Person(ssn, name) {
        this->setTitle(title);
    }
    // function
    void display() override;
    void addAdvisee(Student* student);
    void addSection(Section* section);
};

class Student : public Person {
private:
    string major;
    string degree;
    map<string, Section*> sections;
    Professor* advisor;
    Transcript* transcript;
    PlanOfStudy* planOfStudy;
public:
    // getter and setter
    string getMajor() {
        return major;
    }
    void setMajor(string major) {
        this->major = major;
    }
    string getDegree() {
        return degree;
    }
    void setDegree(string degree) {
        this->degree = degree;
    }
    // constructor
    Student(string ssn, string name, string major, string degree) : Person(ssn, name) {
        this->setMajor(major);
        this->setDegree(degree);
    }
    Transcript* getTranscript() {
        return transcript;
    }
    PlanOfStudy* getPlanOfStudy() {
        return planOfStudy;
    }
    // function
    void display() override {
        cout << "Student: " << this->getName() << endl;
        cout << "Major: " << this->getMajor() << endl;
        cout << "Degree: " << this->getDegree() << endl;
        cout << "Advisor: " << this->advisor->getName() << endl;
    }
    void addProfessor(Professor* professor);
    void addSection(Section* section);
    void displaySections();
    void addTranscript(Transcript* transcript);
    void displayTranscript();
    void addPlanOfStudy(PlanOfStudy* planOfStudy);
    void removeSection(Section* section);
};


class Course {
private:
    string CourseNo;
    string CourseName;
    int credits;
    map<string, Section*> sections;
    vector<Course*> prerequisites;
public:
    // getter and setter
    string getCourseNo() {
        return CourseNo;
    }
    void setCourseNo(string CourseNo) {
        this->CourseNo = CourseNo;
    }
    string getCourseName() {
        return CourseName;
    }
    void setCourseName(string CourseName) {
        this->CourseName = CourseName;
    }
    int getCredits() {
        return credits;
    }
    void setCredits(int credits) {
        this->credits = credits;
    }
    // constructor
    Course(string CourseNo, string CourseName, int credits) {
        this->setCourseNo(CourseNo);
        this->setCourseName(CourseName);
        this->setCredits(credits);
    }
    // function
    void addSection(Section* section);
    void addPrerequisite(Course* course);
    vector<Course*> getPrerequisites() {
        return prerequisites;
    }
};

class PlanOfStudy {
private:
    Student* student;
    map<string, Course*> courses;
    map<string, Course*> completedCourses;
public:
    void display() {
        cout << "Student: " << student->getName() << endl;
        for (auto it = courses.begin(); it != courses.end(); it++) {
            cout << it->first << " " << it->second->getCourseName() << endl;
        }
    }
    void addCourse(Course* course) {
        courses[course->getCourseNo()] = course;
    }
    void removeCourse(string courseNo) {
        courses.erase(courseNo);
    }
    bool findCourse(string courseNo);
    bool findCompletedCourse(string courseNo) {
        return completedCourses.find(courseNo) != completedCourses.end();
    }
    void addCompletedCourse(Course* course) {
        completedCourses[course->getCourseNo()] = course;
    }
    void displayCourses() {
        cout << " - Courses:" << endl;
        for (auto it = courses.begin(); it != courses.end(); it++) {
            cout << it->first << " " << it->second->getCourseName() << endl;
        }
    }
    void displayCompletedCourses() {
        cout << " - Completed Courses:" << endl;
        for (auto it = completedCourses.begin(); it != completedCourses.end(); it++) {
            cout << it->first << " " << it->second->getCourseName() << endl;
        }
    }
};

class Section {
private:
    string SectionNo;
    string dayOfWeek;
    string timeOfDay;
    string semester;
    string room;
    int seatingCapacity;
    map<string, Student*> students;
    map<string, TranscriptEntry*> grades;
    Course* course;
    Professor* professor;
public:
    // getter and setter
    string getSectionNo() {
        return SectionNo;
    }
    void setSectionNo(string SectionNo) {
        this->SectionNo = SectionNo;
    }
    string getDayOfWeek() {
        return dayOfWeek;
    }
    void setDayOfWeek(string dayOfWeek) {
        this->dayOfWeek = dayOfWeek;
    }
    string getTimeOfDay() {
        return timeOfDay;
    }
    void setTimeOfDay(string timeOfDay) {
        this->timeOfDay = timeOfDay;
    }
    string getSemester() {
        return semester;
    }
    void setSemester(string semester) {
        this->semester = semester;
    }
    string getRoom() {
        return room;
    }
    void setRoom(string room) {
        this->room = room;
    }
    int getSeatingCapacity() {
        return seatingCapacity;
    }
    void setSeatingCapacity(int seatingCapacity) {
        this->seatingCapacity = seatingCapacity;
    }
    Course* getCourse() {
        return course;
    }
    void setCourse(Course* course) {
        this->course = course;
    }
    // constructor
    Section(string SectionNo, string dayOfWeek, string timeOfDay, string semester, string room, int seatingCapacity) {
        this->setSectionNo(SectionNo);
        this->setDayOfWeek(dayOfWeek);
        this->setTimeOfDay(timeOfDay);
        this->setSemester(semester);
        this->setRoom(room);
        this->setSeatingCapacity(seatingCapacity);
    }
    // function
    void addStudent(Student* student);
    void display();
    void displayStudents();
    void addTranscriptEntry(TranscriptEntry* grade);
    void displayTranscript();
    void addProfessor(Professor* professor);
    void removeStudent(Student* student);
};

class Transcript {
private:
    vector<TranscriptEntry*> entries;
    Student* student;
public:
    Student* getStudent() {
        return student;
    }
    void setStudent(Student* student) {
        this->student = student;
    }
    void addTranscriptEntry(TranscriptEntry* entry);
    void display();
};

class TranscriptEntry {
private:
    string grade;
    Section* section;
    Transcript* transcript;
public:
    // getter and setter
    string getGrade() {
        return grade;
    }
    void setGrade(string grade) {
        this->grade = grade;
    }
    // constructor
    TranscriptEntry(string grade) {
        this->setGrade(grade);
    }
    Section* getSection() {
        return section;
    }
    Transcript* getTranscript() {
        return transcript;
    }
    void setSection(Section* section) {
        this->section = section;
    }
    void setTranscript(Transcript* transcript) {
        this->transcript = transcript;
    }
    void display();
};

void Course::addSection(Section* section) {
    sections[section->getSectionNo()] = section;
    section->setCourse(this);
}

void Course::addPrerequisite(Course* course) {
    prerequisites.push_back(course);
}

void TranscriptEntry::display() {
    cout << "CoNum\tCoName\tSem\tCredit\tGrade\n";
    cout << section->getCourse()->getCourseNo() << "\t" << section->getCourse()->getCourseName() << "\t" << section->getSemester() << "\t" << section->getCourse()->getCredits() << "\t" << grade << endl; 
}

void Transcript::display() {
    cout << " - Transcript:" << endl;
    for (auto entry : entries) {
        entry->display();
    }
}

void Transcript::addTranscriptEntry(TranscriptEntry* entry) {
    entries.push_back(entry);
    int grade = stoi(entry->getGrade());
    Course* course = entry->getSection()->getCourse();

    if (grade >= 5) {
        this->getStudent()->getPlanOfStudy()->addCompletedCourse(course);
    }

    entry->setTranscript(this);
}

void Section::addProfessor(Professor *professor) {
    this->professor = professor;
}

void Section::addTranscriptEntry(TranscriptEntry* grade) {
    grades[grade->getTranscript()->getStudent()->getSSN()] = grade;
    grade->setSection(this);
}

void Section::removeStudent(Student* student) {
    students.erase(student->getSSN());
}

void Section::displayTranscript() {
    cout << " - Transcript:" << endl;
    cout << "StuID\tGrade" << endl;
    for (auto it = grades.begin(); it != grades.end(); it++) {
        cout << it->first << "\t" << it->second->getGrade() << endl;
    }
}

void Section::display() {
    cout << "Section: " << this->getSectionNo() << endl;
    cout << "Day of Week: " << this->getDayOfWeek() << endl;
    cout << "Time of Day: " << this->getTimeOfDay() << endl;
    cout << "Semester: " << this->getSemester() << endl;
    cout << "Room: " << this->getRoom() << endl;
    cout << "Seating Capacity: " << this->getSeatingCapacity() << endl;
}

void Section::displayStudents() {
    cout << " - Students:" << endl;
    for (auto it = students.begin(); it != students.end(); it++) {
        cout << it->first << " " << it->second->getName() << endl;
    }
}

void Section::addStudent(Student* student) {
    this->students[student->getSSN()] = student;
}

void Student::addProfessor(Professor* professor) {
    this->advisor = professor;
}

void Student::addPlanOfStudy(PlanOfStudy* planOfStudy) {
    this->planOfStudy = planOfStudy;
}

void Student::removeSection(Section* section) {
    sections.erase(section->getSectionNo());
    section->removeStudent(this);
}

void Student::addSection(Section* section) {
    string courseNo = section->getCourse()->getCourseNo();
    if (!this->planOfStudy->findCourse(courseNo)) {
        cout << "Student " << this->getName() << " is not allowed to take this course" << endl;
        return;
    }

    Course *course = section->getCourse();
    for (auto it : course->getPrerequisites()) {
        if (!this->planOfStudy->findCompletedCourse(it->getCourseNo())) {
            cout << "Student " << this->getName() << " has not completed the prerequisites for this course" << endl;
            return;
        }
    }

    this->sections[section->getSectionNo()] = section;
    section->addStudent(this);
    cout << "Student " << this->getName() << " has been added to section " << section->getSectionNo() << endl;
}


void Student::displayTranscript() {
    this->getTranscript()->display();
}

void Student::displaySections() {
    cout << "Student: " << this->getName() << endl;
    cout << "SecNo\tCourseName\n";
    for (auto it = sections.begin(); it != sections.end(); it++) {
        cout << it->first << "\t" << it->second->getCourse()->getCourseName() << endl;
    }
}

void Student::addTranscript(Transcript* transcript) {
    this->transcript = transcript;
    transcript->setStudent(this);
}

bool PlanOfStudy::findCourse(string courseNo) {
    return courses.find(courseNo) != courses.end();
}

void Professor::addAdvisee(Student* student) {
    advises[student->getSSN()] = student;
    student->addProfessor(this);
}

void Professor::display() {
    cout << "Professor: " << this->getName() << endl;
    cout << "Title: " << this->getTitle() << endl;
    
    for (auto it = advises.begin(); it != advises.end(); it++) {
        cout << it->first << " " << it->second->getName() << endl;
    }
}

void Professor::addSection(Section* section) {
    sections[section->getSectionNo()] = section;
    section->addProfessor(this);
}

int main() {
    // create student and professor
    Professor p1 = Professor("123", "John", "Professor", "Computer Science");
    Student s1 = Student("456", "Alice", "Computer Science", "Bachelor");
    Student s2 = Student("789", "Bob", "Computer Science", "Bachelor");
    p1.addAdvisee(&s1);
    // create sections
    Section sec1 = Section("1", "Monday", "10:00", "1", "Room 1", 30);
    Section sec2 = Section("2", "Tuesday", "11:00", "1", "Room 2", 30);
    Section sec3 = Section("3", "Wednesday", "12:00", "1", "Room 3", 30);
    Section sec4 = Section("4", "Thursday", "13:00", "1", "Room 4", 30);

    p1.addSection(&sec1);
    p1.addSection(&sec2);
    p1.addSection(&sec3);
    p1.addSection(&sec4);
    // create courses
    Course c1 = Course("1", "Co so lap trinh", 3);
    Course c2 = Course("2", "Ky thuat lap trinh", 4);
    Course c3 = Course("3", "Cau truc du lieu", 3);
    Course c4 = Course("4", "Lap trinh huong doi tuong", 3);
    // add prerequisites
    c2.addPrerequisite(&c1);
    c3.addPrerequisite(&c2);
    c4.addPrerequisite(&c3);
    // add sections to courses
    c1.addSection(&sec1);
    c2.addSection(&sec2);
    c3.addSection(&sec3);
    c4.addSection(&sec4);
    // create plan of study
    PlanOfStudy pos1 = PlanOfStudy();
    pos1.addCourse(&c1);
    pos1.addCourse(&c2);
    pos1.addCourse(&c3);

    // add plan of study to student 1
    s1.addPlanOfStudy(&pos1);
    // create transcript
    Transcript t1 = Transcript();
    s1.addTranscript(&t1);
    // student 1 add section 1
    cout << "Adding section 1...\n";
    s1.addSection(&sec1);
    // sec 1 has been completed and student 1 has grade 5 (enough to pass)
    TranscriptEntry te1 = TranscriptEntry("5");
    te1.setSection(&sec1);
    t1.addTranscriptEntry(&te1);

    // student 1 try to add section 2 which have course prerequisite is course 1
    cout << "Adding section 2...\n";
    s1.addSection(&sec2);

    // student 1 try to add section 3 when he has not completed  course 2
    cout << "Adding section 3 when he has not completed course 2...\n";
    s1.addSection(&sec3);

    // student 1 try to add section 4 when course 4 is not in his plan
    cout << "Adding section 4 when course 4 is not in his plan...\n";
    s1.addSection(&sec4);

    s1.removeSection(&sec1);

    sec1.display();
    return 0;
}