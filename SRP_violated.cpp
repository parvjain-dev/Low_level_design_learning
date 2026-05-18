#include <iostream>
#include <vector>

using namespace std;

class Product
{
public:
    string name;
    double price;

    Product(string name, double price)
    {
        this->name = name;
        this->price = price;
    }
};

class ShoppingCart
{
private:
    vector<Product *> products;

public:
    void addproduct(Product *p)
    {
        products.push_back(p);
    }
    const vector<Product *> &getProducts()
    {
        return products;
    }
    double calculateTotal()
    {
        double total = 0;
        for (auto p : products)
        {
            total += p->price;
        }
        return total;
    }

    

};

class ShoppingCartPrinter{
private: 
    ShoppingCart* cart;

public:
    ShoppingCartPrinter(ShoppingCart* cart){
        this->cart= cart;
    }
    void printInvoice()
    {
        cout << "Shopping cart" << endl;
        for (auto p : cart->getProducts())
        {
            cout << p->name << " " << p->price << endl;
        }
        cout << cart->calculateTotal() << endl;
    }
};

class ShoppingCartStorage{
private:
    ShoppingCart* cart;

public:
    ShoppingCartStorage(ShoppingCart* cart){
        this->cart =cart;
    }
    void saveToDB()
    {
        cout << "Savign to db" << endl;
    }
};
int main()
{
    ShoppingCart* cart= new ShoppingCart();
    cart->addproduct(new Product("Laptop", 1500));
    cart->addproduct(new Product("mouse", 20));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    ShoppingCartStorage* storage = new ShoppingCartStorage(cart);
    storage->saveToDB();
    return 0;
}