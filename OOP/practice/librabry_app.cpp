#include <iostream>
#include <string>
#include <vector>
#include "map>

using namespace std;

class Book;
class Reader;
class Library;

class Book {
    private:
    string id;
    string title;
    string author;
    bool status;
    Reader* reader;
    public:
    // getter and setter
    string getId() {
        return this->id;
    }
    string getTitle() {
        return this->title;
    }
    string getAuthor() {
        return this->author;
    }
    bool getStatus() {
        return this->status;
    }
    void setId(string id) {
        this->id = id;
    }
    void setTitle(string title) {
        this->title = title;
    }
    void setAuthor(string author) {
        this->author = author;
    }
    void setStatus(bool status) {
        this->status = status;
    }
    // constructor
    Book(string id, string title, string author, bool status) {
        this->setId(id);
        this->setTitle(title);
        this->setAuthor(author);
        this->setStatus(status);
    }
    // method
    virtual void display() {
        cout << "Book: " << this->getTitle() << endl;
        cout << "ID: " << this->getId() << endl;
        cout << "Author: " << this->getAuthor() << endl;
        cout << "Status: " << this->getStatus() << endl;
    }
    void borrowBook(Reader* reader);
};

class EBook : public Book {
    private:
    float file_size;
    string format;
    public:
    // getter and setter
    float getFileSize() {
        return this->file_size;
    }
    string getFormat() {
        return this->format;
    }
    void setFileSize(float file_size) {
        this->file_size = file_size;
    }
    void setFormat(string format) {
        this->format = format;
    }
    // constructor
    EBook(string id, string title, string author, bool status, float file_size, string format) : Book(id, title, author, status) {
        this->setFileSize(file_size);
        this->setFormat(format);
    }
    // method
    void display() override {
        cout << "EBook: " << this->getTitle() << endl;
        cout << "ID: " << this->getId() << endl;
        cout << "Author: " << this->getAuthor() << endl;
        cout << "Status: " << this->getStatus() << endl;
        cout << "File Size: " << this->getFileSize() << endl;
        cout << "Format: " << this->getFormat() << endl;
    }
}

class PrintedBook : public Book {
    private:
    int pages;
    string cover_type;
    public:
    // getter and setter
    int getPages() {
        return this->pages;
    }
    string getCoverType() {
        return this->cover_type;
    }
    void setPages(int pages) {
        this->pages = pages;
    }
    void setCoverType(string cover_type) {
        this->cover_type = cover_type;
    }
    // constructor
    PrintedBook(string id, string title, string author, bool status, int pages, string cover_type) : Book(id, title, author, status) {
        this->setPages(pages);
        this->setCoverType(cover_type);
    }
    // method
    void display() override {
        cout << "Printed Book: " << this->getTitle() << endl;
        cout << "ID: " << this->getId() << endl;
        cout << "Author: " << this->getAuthor() << endl;
        cout << "Status: " << this->getStatus() << endl;
        cout << "Pages: " << this->getPages() << endl;
        cout << "Cover Type: " << this->getCoverType() << endl;
    }
};


class Reader {
    private:
    string id;
    string name;
    string address;
    vector<Book*> books;
    public:
    // getter and setter
    string getId() {
        return this->id;
    }
    string getName() {
        return this->name;
    }
    string getAddress() {
        return this->address;
    }
    void setId(string id) {
        this->id = id;
    }
    void setName(string name) {
        this->name = name;
    }
    void setAddress(string address) {
        this->address = address;
    }
    // constructor
    Reader(string id, string name, string address) {
        this->setId(id);
        this->setName(name);
        this->setAddress(address);
    }
    // method
    void display() {
        cout << "Reader: " << this->getName() << endl;
        cout << "ID: " << this->getId() << endl;
        cout << "Address: " << this->getAddress() << endl;
    }
    void addBook(Book* book);
    void returnBook(Book* book);
};

class Library {
    string name;
    string address;
    public:
    // getter and setter
    string getName() {
        return this->name;
    }
    string getAddress() {
        return this->address;
    }
    void setName(string name) {
        this->name = name;
    }
    void setAddress(string address) {
        this->address = address;
    }
    // constructor
    Library(string name, string address) {
        this->setName(name);
        this->setAddress(address);
    }
    // method
    void display() {
        cout << "Library: " << this->getName() << endl;
        cout << "Address: " << this->getAddress() << endl;
    }
};

void Book::borrowBook(Reader* reader) {
    if (this->getStatus() == true) {
        cout << "Book is already borrowed" << endl;
    } else {
        this->setStatus(true);
        this->reader = reader;
        reader->addBook(this);
    }
}

void Reader::addBook(Book* book) {
    if (book->getStatus() == true) {
        cout << "Book is already borrowed" << endl;
    } else {
        this->books.push_back(book);
        book->borrowBook(this);
    }
}


int main() {

}