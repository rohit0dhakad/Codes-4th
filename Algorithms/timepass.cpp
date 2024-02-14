#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, map<string, double>> items;
map<pair<int, int>, string> names;

void fillItems() {
    // Initialize available items and their prices
    items["Mobile"]["Samsung"] = 15000;
    items["Mobile"]["Redmi"] = 12000;
    items["Mobile"]["Apple"] = 100000;
    items["Laptop"]["HP"] = 40000;
    items["Laptop"]["Lenovo"] = 35000;
    items["Laptop"]["Macbook"] = 250000;
    items["Course"]["C"] = 1000;
    items["Course"]["C++"] = 3000;
    items["Course"]["Java"] = 4000;
    items["Course"]["Python"] = 3500;

    // Initialize item names for display
    names[{1, 1}] = "Apple";
    names[{1, 2}] = "Redmi";
    names[{1, 3}] = "Samsung";
    names[{2, 1}] = "HP";
    names[{2, 2}] = "Lenovo";
    names[{2, 3}] = "Macbook";
    names[{3, 1}] = "C";
    names[{3, 2}] = "C++";
    names[{3, 3}] = "Java";
    names[{3, 4}] = "Python";
}

class Customer {
    map<string, map<string, int>> selected_items;
    string name;

public:
    Customer() {
        cout << "Enter your name: ";
        string customer_name;
        getline(cin, customer_name);
        name = customer_name;
        cout << "HI ";
        for (int i = 0; i < customer_name.length(); i++) {
            cout << char(toupper(customer_name[i]));
        }
        cout << "\n\n\n";
    }

    void addToCart(string category, string model) {
        selected_items[category][model]++;
    }

    void printBill() {
        int total_amount = 0;
        cout << "Category\tItem\tQuantity\tCost\n";
        for (auto itr = selected_items.begin(); itr != selected_items.end(); itr++) {
            for (auto ptr = itr->second.begin(); ptr != itr->second.end(); ptr++) {
                string category = itr->first;
                string model = ptr->first;
                int quantity = ptr->second;
                int temp = quantity * items[category][model];
                cout << category << "\t\t" << model << "\t" << quantity << "\t\t" << temp << endl;
            }
        }
    }
};

int main() {
    fillItems();
    Customer customer;
    string category, model;
    while (true) {
        cout << "\nAvailable Categories:\n1. Mobile\n2. Laptop\n3. Course\n";
        cout << "Enter the category number (1/2/3) or '0' to checkout: ";
        int choice;
        cin >> choice;
        if (choice == 0) {
            customer.printBill();
            break;
        }
        cout << "Enter the model number (1/2/3/4): ";
        int model_choice;
        cin >> model_choice;
        category = (choice == 1) ? "Mobile" : (choice == 2) ? "Laptop" : "Course";
        model = names[{choice, model_choice}];
        customer.addToCart(category, model);
    }
    return 0;
}
