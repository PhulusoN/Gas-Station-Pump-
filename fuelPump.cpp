#include <iostream>
using namespace std;

const double PRICE_PER_LITER = 21.50; // price in rands

void viewFuel(double* fuelLevel) {
    cout << "Fuel remaining in tank: " << *fuelLevel << " liters\n";
}

void buyFuel(double* fuelLevel) {
    double amountPaid;

    cout << "Price per liter: R " << PRICE_PER_LITER << "\n";
    cout << "Enter amount: R ";

    while (!(cin >> amountPaid)) {
        cout << "Invalid amount. Please enter a number: R ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    double litersRequested = amountPaid / PRICE_PER_LITER;

    if (litersRequested > *fuelLevel) {
        cout << "Sorry, not enough fuel in the pump.\n";
        cout << "We only have " << *fuelLevel << " liters left, "
             << "which costs R " << (*fuelLevel * PRICE_PER_LITER) << "\n";
        return;
    }

    *fuelLevel = *fuelLevel - litersRequested;

    cout << "You paid R " << amountPaid << "\n";
    cout << "You received " << litersRequested << " liters of fuel.\n";
    cout << "Fuel remaining in pump: " << *fuelLevel << " liters\n";
}

int main() {
    double fuelLevel = 10000.0; // how much fuel we have  in the pump, in liters
    int choice;

    do {
        cout << "--------------------------------------\n";
        cout << "Welcome to the Fuel Pump System\n";
        cout << "1. View fuel remaining\n";
        cout << "2. Buy fuel\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (choice) {
            case 1:
                viewFuel(&fuelLevel);
                break;
            case 2:
                buyFuel(&fuelLevel);
                break;
            case 3:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }

    } while (choice != 3);

    return 0;
}