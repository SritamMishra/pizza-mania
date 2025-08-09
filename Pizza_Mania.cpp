#include <iostream>
#include <vector>
#include <iomanip> 
using namespace std;

// Storage of menu items
struct MenuItem {
    string name;
    double price;
};

struct Order {
    string pizzaSize;
    vector<string> toppings;
    vector<MenuItem> drinks;
    double total;
};

// Menu Data
vector<MenuItem> pizzaSizes = {
    {"Small", 199.00},
    {"Medium", 299.00},
    {"Large", 399.00}
};

vector<MenuItem> availableToppings = {
    {"Cheese", 50.00},
    {"Pepperoni", 70.00},
    {"Mushrooms", 40.00},
    {"Onions", 30.00},
    {"Paneer", 60.00},
    {"Chicken", 80.00}
};

vector<MenuItem> drinksMenu = {
    {"Coke", 40.00},
    {"Pepsi", 40.00},
    {"Water", 20.00}
};

// Functions
void displayMainMenu();
void displayPizzaSizes();
void displayToppings();
void displayDrinks();
Order takeOrder();
void checkout(const Order &order);
void lineBreak();


int main() {
    vector<Order> orderHistory;
    int choice;
    double totalSales = 0.0;

    do {
        displayMainMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                { 
    Order newOrder = takeOrder();
    orderHistory.push_back(newOrder);
    checkout(newOrder);

    // Add to total sales
    double tax = newOrder.total * 0.05;
    totalSales += newOrder.total + tax;

    char again;
    cout << "Would you like to place another order? (y/n): ";
    cin >> again;

    if (again == 'n' || again == 'N') {
        cout << "Thank you for visiting Pizza Mania! Goodbye!\n";
        cout << "Total Sales Today: ₹" << fixed << setprecision(2) << totalSales << "\n";
        return 0; // Exit program
    }
    break; // Continue to menu if 'y'
}

            

            }
            case 2: {
                cout << "\n=== Order History ===\n";
                if (orderHistory.empty()) {
                    cout << "No orders yet.\n";
                } else {
                    for (int i = 0; i < orderHistory.size(); i++) {
                        cout << "Order #" << i+1 << " - Total: ₹" << orderHistory[i].total << "\n";
                    }
                }
                break;
            }
            case 3:
            cout << "Thank you for visiting Pizza Mania! Goodbye!\n";
            cout << "Total Sales Today: ₹" << fixed << setprecision(2) << totalSales << "\n";
    break;


            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);

    return 0;

    cout<<"******* EXIT *******";
}

// Display main menu
void displayMainMenu() {
    lineBreak();
    cout << "      Welcome to Pizza Mania Backend System\n";
    lineBreak();
    cout << "1. Place a New Order\n";
    cout << "2. View Order History\n";
    cout << "3. Exit\n";
    lineBreak();
}

// Display Pizza Sizes
void displayPizzaSizes() {
    cout << "\nPizza Sizes:\n";
    for (int i = 0; i < pizzaSizes.size(); i++) {
        cout << i+1 << ". " << pizzaSizes[i].name << " - ₹" << pizzaSizes[i].price << "\n";
    }
}

// Display Toppings
void displayToppings() {
    cout << "\nAvailable Toppings:\n";
    for (int i = 0; i < availableToppings.size(); i++) {
        cout << i+1 << ". " << availableToppings[i].name << " - ₹" << availableToppings[i].price << "\n";
    }
}

// Display Drinks
void displayDrinks() {
    cout << "\nDrinks Menu:\n";
    for (int i = 0; i < drinksMenu.size(); i++) {
        cout << i+1 << ". " << drinksMenu[i].name << " - ₹" << drinksMenu[i].price << "\n";
    }
}

// Take a new order
Order takeOrder() {
    Order order;
    order.total = 0.0;

    // Choose Pizza Size
    displayPizzaSizes();
    int sizeChoice;
    cout << "Choose pizza size: ";
    cin >> sizeChoice;
    if (sizeChoice >= 1 && sizeChoice <= pizzaSizes.size()) {
        order.pizzaSize = pizzaSizes[sizeChoice - 1].name;
        order.total += pizzaSizes[sizeChoice - 1].price;
    } else {
        cout << "Invalid size, defaulting to Medium.\n";
        order.pizzaSize = "Medium";
        order.total += pizzaSizes[1].price;
    }

    // Choose Toppings
    displayToppings();
    int toppingCount;
    cout << "How many toppings would you like? ";
    cin >> toppingCount;
    for (int i = 0; i < toppingCount; i++) {
        int toppingChoice;
        cout << "Choose topping #" << i+1 << ": ";
        cin >> toppingChoice;
        if (toppingChoice >= 1 && toppingChoice <= availableToppings.size()) {
            order.toppings.push_back(availableToppings[toppingChoice - 1].name);
            order.total += availableToppings[toppingChoice - 1].price;
        } else {
            cout << "Invalid choice, skipping.\n";
        }
    }

    // Choose Drinks
    displayDrinks();
    int drinkCount;
    cout << "How many drinks would you like? ";
    cin >> drinkCount;
    for (int i = 0; i < drinkCount; i++) {
        int drinkChoice;
        cout << "Choose drink #" << i+1 << ": ";
        cin >> drinkChoice;
        if (drinkChoice >= 1 && drinkChoice <= drinksMenu.size()) {
            order.drinks.push_back(drinksMenu[drinkChoice - 1]);
            order.total += drinksMenu[drinkChoice - 1].price;
        } else {
            cout << "Invalid choice, skipping.\n";
        }
    }

    return order;
}

// Checkout & Print Bill
void checkout(const Order &order) {
    lineBreak();
    cout << "        PIZZA MANIA - BILL\n";
    lineBreak();
    cout << "Pizza Size: " << order.pizzaSize << "\n";

    if (!order.toppings.empty()) {
        cout << "Toppings: ";
        for (auto &t : order.toppings) cout << t << " ";
        cout << "\n";
    }

    if (!order.drinks.empty()) {
        cout << "Drinks: ";
        for (auto &d : order.drinks) cout << d.name << " ";
        cout << "\n";
    }

    double tax = order.total * 0.05; // 5% tax
    cout << fixed << setprecision(2);
    cout << "Subtotal: ₹" << order.total << "\n";
    cout << "Tax (5%): ₹" << tax << "\n";
    cout << "Total: ₹" << order.total + tax << "\n";
    lineBreak();
}

// Print line break
void lineBreak() {
    cout << "----------------------------------------\n";
    
}


// g++ -std=c++17 toppings_choose.cpp -o toppings_choose
// ./toppings_choose

// START THE CODE BY WRITING THIS IN THE TERMINAL FIRST

