#include <iostream>
#include <ctime>

using namespace std;

class ATM {
private:
    int pin;
    double balance;

public:
    // Constructor
    ATM(int p, double b) {
        pin = p;
        balance = b;
    }

    // Function to display welcome screen
    void displayWelcomeScreen() {
        time_t now = time(0);
        tm* ltm = localtime(&now);

        cout << "Welcome to ATM Banking Application!" << endl;
        cout << "Current Date and Time: " << ltm->tm_mday << "/" << ltm->tm_mon + 1 << "/" << ltm->tm_year + 1900 << " " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;
    }

    // Function to display menu
    void displayMenu() {
        cout << "Menu:" << endl;
        cout << "1. Enter ATM PIN" << endl;
        cout << "2. Help" << endl;
        cout << "Enter your choice: ";
    }

    // Function to verify ATM PIN
    bool verifyPIN(int p) {
        if (p == pin) {
            return true;
        } else {
            return false;
        }
    }

    // Function to display help screen
    void displayHelpScreen() {
        cout << "Help Screen:" << endl;
        cout << "This ATM Banking Application allows you to perform the following operations:" << endl;
        cout << "1. Check account balance" << endl;
        cout << "2. Deposit money" << endl;
        cout << "3. Withdraw money" << endl;
    }

    // Function to deposit money
    void depositMoney(double amount) {
        balance += amount;
        cout << "Deposit successful. New balance: " << balance << endl;
    }

    // Function to withdraw money
    void withdrawMoney(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance. Withdrawal unsuccessful." << endl;
        } else {
            balance -= amount;
            cout << "Withdrawal successful. New balance: " << balance << endl;
        }
    }

    // Function to check account balance
    void checkBalance() {
        cout << "Account balance: " << balance << endl;
    }
};

int main() {
    int choice, pin;
    double amount;

    // Create an object of the ATM class
    ATM atm(12345, 20000);

    atm.displayWelcomeScreen();

    while (true) {
        atm.displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter your ATM PIN: ";
                cin >> pin;

                if (atm.verifyPIN(pin)) {
                    cout << "PIN verified successfully." << endl;

                    while (true) {
                        cout << "Menu:" << endl;
                        cout << "1. Check account balance" << endl;
                        cout << "2. Deposit money" << endl;
                        cout << "3. Withdraw money" << endl;
                        cout << "4. Exit" << endl;
                        cout << "Enter your choice: ";
                        cin >> choice;

                        switch (choice) {
                            case 1:
                                atm.checkBalance();
                                break;
                            case 2:
                                cout << "Enter the amount to deposit: ";
                                cin >> amount;
                                atm.depositMoney(amount);
                                break;
                            case 3:
                                cout << "Enter the amount to withdraw: ";
                                cin >> amount;
                                atm.withdrawMoney(amount);
                                break;
                            case 4:
                                exit(0);
                            default:
                                cout << "Invalid choice. Please try again." << endl;
                        }
                    }
                } else {
                    cout << "Invalid PIN. Please try again." << endl;
                    exit(0);
                }
                break;
            case 2:
                atm.displayHelpScreen();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

