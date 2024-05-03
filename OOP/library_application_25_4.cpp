#include <iostream>
#include <string>
#include <vector>

using namespace std;
// Just declare class.
class Book;
class BorrowerRecord;

class Book {
    string theCatalogueNumber;
	string theAuthor;
	string theTitle;
    BorrowerRecord* borrower = NULL;
public:
// getter
    string getCatalogueNumber();
    string getAuthor();
    string getTitle();
    BorrowerRecord* getBorrowers();
// setter
    void setCatalogueNumber(string theCatalogueNumber);
    void setAuthor(string theAuthor);
    void setTitle(string theTitle);
// function
    void attachBorrower(BorrowerRecord* br);
    void detachBorrower();
// display
    void display();
    // constructor
    Book(string theCatalogueNumber, string theAuthor, string theTitle);
};

class BorrowerRecord {
    string theName;
    vector<Book*> books;
public:
    // getter
    string getName();
    // setter
    void setName(string theName);
    // function
    void attachBook(Book* book);
    void detachBook(string catalogueNumber);
    void display();
    // constructor
    BorrowerRecord(string theName);
};

// Define function of class
    // Books
string Book::getCatalogueNumber() {
    return this->theCatalogueNumber;
}
string Book::getAuthor() {
    return this->theAuthor;
}
string Book::getTitle() {
    return this->theTitle;
}
void Book::setAuthor(string theAuthor) {
    this->theAuthor = theAuthor;
}
void Book::setCatalogueNumber(string CatalogueNumber) {
    this->theCatalogueNumber = CatalogueNumber;
}
void Book::setTitle(string Title) {
    this->theTitle = Title;
}
void Book::attachBorrower(BorrowerRecord* br) {
    this->borrower = br;
}
void Book::detachBorrower() {
    this->borrower = NULL;
}
void Book::display() {
    cout << "Book: " << endl;
    cout << " - Number: " << this->getCatalogueNumber() << endl;
    cout << " - Title: " << this->getTitle() << endl;
    cout << " - Author: " << this->getAuthor() << endl;
    if (this->getBorrowers()) 
        cout << " - Borrower Name: " << this->getBorrowers()->getName() << endl;
}
Book::Book(string CataLogueNumber, string Title, string Author) {
    this->setAuthor(Author);
    this->setCatalogueNumber(CataLogueNumber);
    this->setTitle(Title);
}
BorrowerRecord* Book::getBorrowers() {
    return this->borrower;
}

    // Borrower Record
string BorrowerRecord::getName() {
    return this->theName;
}
void BorrowerRecord::setName(string theName) {
    this->theName = theName;
}
void BorrowerRecord::attachBook(Book* book) {
    this->books.push_back(book);
}
void BorrowerRecord::detachBook(string catalogueNumber) {
    for (auto it = this->books.begin(); it != this->books.end(); it++) {
        if ((*it)->getCatalogueNumber() == catalogueNumber) {
            this->books.erase(it);
            break;
        }
    }
}
BorrowerRecord::BorrowerRecord(string theName) {
    this->setName(theName);
}
void BorrowerRecord::display() {
    cout << "Borrower: " << this->getName() << endl;
}

// Library
class Library {
private:
	// atts
	string theName;
	vector<Book*> stock;
	vector<BorrowerRecord*> Borrowers;
public:
	// getter and setter
	string getTheName() {
		return this->theName;
	}
	void setTheName(string theName) {
		this->theName = theName;
	}
	// constructors
	Library(string theName) {
		this->setTheName(theName);
	}
	// add book
	void addOneBook(Book *book) {
		this->stock.push_back(book);
	}
	
	void registerOneBorrower(string aBorrowerName) {
		this->Borrowers.push_back(new BorrowerRecord(aBorrowerName));
	}

    void lenOneBook(string number, string BorrowerName) {
        Book* tmp_book = NULL;
        for (auto book : this->stock) {
            if (book->getCatalogueNumber() == number && !book->getBorrowers()) {
                tmp_book = book;
                break;
            } 
        }

        if (!tmp_book) {
            cout << "Can not find book or is was rented\n";
            return;
        }

        BorrowerRecord * tmp_br = NULL;
        for (auto borrower : Borrowers) {
            if(borrower->getName() == BorrowerName) {
                tmp_br = borrower;
                break;
            }
        } 

        if (!tmp_br) {
            cout << "Borrower is not exist\n";
            return;
        }
        // book and borrower were found
        tmp_br->attachBook(tmp_book);
        tmp_book->attachBorrower(tmp_br);
    }

    void returnOneBook(string aCatalogueNumber) {
        for (auto book : this->stock) {
            if (book->getCatalogueNumber() == aCatalogueNumber) {
                BorrowerRecord* tmp_borrower = book->getBorrowers();
                tmp_borrower->detachBook(aCatalogueNumber);
                book->detachBorrower();
                break;
            }
        }
    }
	// display function
	void display() {
		cout << this->getTheName() << "'s stock:" << "\n";
		for (auto book : stock) {
			book->display();
		}
	}
    
	// destructor	
	~Library() {
		for (auto borrower : Borrowers) {
			delete borrower;
		}
		Borrowers.clear();
	}
};


int main() {
    // create lib
    Library hcmus_lib("HCMUS Library");
    // add books
    Book book_1 = Book("1", "Giai tich ham", "DDT");
    Book book_2 = Book("2", "Lap trinh huong doi tuong", "HVT");
    Book book_3 = Book("3", "Cau truc du lieu va giai thuat", "HVT");

    hcmus_lib.addOneBook(&book_1);
    hcmus_lib.addOneBook(&book_2);
    hcmus_lib.addOneBook(&book_3);
    // borrower registers 
    hcmus_lib.registerOneBorrower("Thang Quang");
    hcmus_lib.registerOneBorrower("Tan Dao");

    hcmus_lib.lenOneBook("1", "Thang Quang");
    hcmus_lib.lenOneBook("2", "Tan Dao");


    hcmus_lib.display();
    hcmus_lib.returnOneBook("1");
    hcmus_lib.display();
    return 0;
}