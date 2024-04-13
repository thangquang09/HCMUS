#include<string>
#include<iostream>
#include<vector>
using namespace std;

// Declare class
class Book;
class BorrowerRecord;

class Book {
	// atts
private:
	string theCatalogueNumber;
	string theAuthor;
	string theTitle;
	// getters and setter
public:
	string getTheCatalogueNumber() {
		return this->theCatalogueNumber;
	}
	string getTheAuthor() {
		return this->theAuthor;
	}
	string getTheTitle() {
		return this->theTitle;
	}
	void setTheCatalogueNumber(string theCatalogueNumber) {
		this->theCatalogueNumber = theCatalogueNumber;
	}
	void setTheAuthor(string theAuthor) {
		this->theAuthor = theAuthor;
	}
	void setTheTitle(string theTitle) {
		this->theTitle = theTitle;
	}
	// contructors
	Book(string theCatalogueNumber, string theAuthor, string theTitle) {
		this->setTheCatalogueNumber(theCatalogueNumber);
		this->setTheAuthor(theAuthor);
		this->setTheTitle(theTitle);
	}
 
	Book(string number) : Book(number, "", "") {}
 
	void display() {	
		cout << "_____________________________________________\n";
		cout << "The title: " << this->getTheTitle() << endl;
		cout << "The author: " << this->getTheAuthor() << endl;
		cout << "The catalogue number: " << this->getTheCatalogueNumber() << endl;
	}
};
 
class BorrowerRecord {
private:
	// atts
	string theName;
public:
	// getter and setter
	string getTheName() {
		return this->theName;
	}
	void setTheName(string theName) {
		this->theName = theName;
	}
	// constructors
	BorrowerRecord(string theName) {
		this->setTheName(theName);
	}
	
	void display() {
		cout << "The borrower: " << this->getTheName() << endl;
	}
};


class Library {
private:
	// atts
	string theName;
	vector<Book *> stock;
	vector<BorrowerRecord *> Borrowers;
public:
	// getter and setter
	string getTheName() {
		return this->theName;
	}
	void setTheName(string theName) {
		this->theName = theName;
	}
	// contructors
	Library(string theName) {
		this->setTheName(theName);
	}
	// add book
	void addBook(Book *book) {
		this->stock.push_back(book);
	}
	
	void registerOneBorrower(string aBorrowerName) {
		this->Borrowers.push_back(new BorrowerRecord(aBorrowerName));
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
	cout << "The Library Application\n";
	cout << "_____________________________________________\n";
	Library HCMUSLAB = Library("HCMUS Lib");
	Book bookA = Book("1", "Huynh Quang Vu", "Giai tich 3A");
	Book bookB = Book("2", "Dang Duc Trong", "Giai tich Ham");
	Book bookC = Book("3", "Ong Thanh Hai", "Giai tich so");
	HCMUSLAB.addBook(&bookA);
	HCMUSLAB.addBook(&bookB);
	HCMUSLAB.addBook(&bookC);
	HCMUSLAB.display();
	HCMUSLAB.registerOneBorrower("Nguyen Van A");
	HCMUSLAB.~Library();
	return 0;}
