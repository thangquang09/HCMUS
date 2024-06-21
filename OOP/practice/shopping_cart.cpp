#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Product {
private:
    string id;
    string name;
    double price;
public:
    // getter and setter
    string getId() {
        return this->id;
    }
    string getName() {
        return this->name;
    }
    double getPrice() {
        return this->price;
    }
    void setId(string id) {
        this->id = id;
    }
    void setName(string name) {
        this->name = name;
    }
    void setPrice(double price) {
        this->price = price;
    }
    // constructor
    Product(string id, string name, double price) {
        this->setId(id);
        this->setName(name);
        this->setPrice(price);
    }
    // method
    virtual void display() {
        cout << "Product: " << this->getName() << endl;
        cout << "ID: " << this->getId() << endl;
        cout << "Price: " << this->getPrice() << endl;
    }
};

class Book : public Product {
private:
    string author;
    string title;
public:
    // getter and setter
    string getAuthor() {
        return this->author;
    }
    string getTitle() {
        return this->title;
    }
    void setAuthor(string author) {
        this->author = author;
    }
    void setTitle(string title) {
        this->title = title;
    }
    // constructor
    Book(string id, string name, double price, string author, string title) : Product(id, name, price) {
        this->setAuthor(author);
        this->setTitle(title);
    }
    // method
    void display() override {
        // call product's display
        Product::display();
        cout << "Book: " << this->getTitle() << endl;
        cout << "Author: " << this->getAuthor() << endl;
        Product::display();
    }
};

class Pen : public Product {
private:
    string color;
    string type_;
public:
    // getter and setter
    string getColor() {
        return this->color;
    }
    string getType() {
        return this->type_;
    }
    void setColor(string color) {
        this->color = color;
    }
    void setType(string type_) {
        this->type_ = type_;
    }
    // constructor
    Pen(string id, string name, double price, string color, string type_) : Product(id, name, price) {
        this->setColor(color);
        this->setType(type_);
    }
    // method
    void display() override {
        // call product's display
        Product::display();
        cout << "Pen: " << this->getName() << endl;
        cout << "Color: " << this->getColor() << endl;
        cout << "Type: " << this->getType() << endl;
    }
};

class Item {
    Product* product;
    int quantity;
public:
    // getter and setter
    Product* getProduct() {
        return this->product;
    }
    int getQuantity() {
        return this->quantity;
    }
    void setProduct(Product* product) {
        this->product = product;
    }
    void setQuantity(int quantity) {
        this->quantity = quantity;
    }
    // constructor
    Item(Product* product, int quantity) {
        this->setProduct(product);
        this->setQuantity(quantity);
    }
    // method
    void display() {
        this->product->display();
        cout << "Quantity: " << this->quantity << endl;
    }
};

class Cart {
    vector<Item*> items;
public:
    // method
    void addItem(Product* p, int number) {
        Item* item = new Item(p, number);
        this->items.push_back(item);
    }
    void display() {
        for (Item* item : this->items) {
            item->display();
        }
    }
};


int main() {
    Book b1("B001", "The Alchemist", 10.5, "Paulo Coelho", "The Alchemist");
    Pen p1("P001", "Pilot", 1.5, "Black", "Ballpoint");
    Cart c1;
    c1.addItem(&b1, 2);
    c1.addItem(&p1, 3);
    c1.display();    
    return 0;
}