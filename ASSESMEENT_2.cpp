#include<iostream>
#include <ctime>

using namespace std;

class ATM
 {
    private:
      int pin;
      double balance;
      
    public:
   
     ATM(int pin, double balance) : pin(pin), balance(balance) {}

    void displayWelcomeScreen()
     {
        time_t now = time(0);
        tm* ltm = localtime(&now);

        cout << "Welcome to ATM Banking Application" << endl;
        cout << "Current Date and Time: " << ltm->tm_mday << "/" << ltm->tm_mon + 1 << "/" << ltm->tm_year + 1900 << " " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;
        cout << "Menu:" << endl;
        cout << "1. Enter to access your account via PIN NO" << endl;
        cout << "2. Enter to get Help" << endl;
        cout << "3. Exit" << endl;
    }

    bool authenticatePIN(int pin)
     {
        if (pin == this->pin) 
        {
            return true;
        }
        return false;
    }

    void displayMenu()
    {
        cout << "Menu:" << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Exit" << endl;
    }

    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposit successful. Your new balance is: " << balance << endl;
    }

    void withdraw(double amount)
     {
        if (amount > balance)
         {
            cout << "Insufficient balance." << endl;
        }
         else 
        {
            balance -= amount;
            cout << "Withdrawal successful. Your new balance is: " << balance << endl;
        }
    }

    void checkBalance() 
    {
        cout << "Your current balance is: " << balance << endl;
    }
};
int main()
 {
    int pin = 12345;
    double balance = 20000.0;
    ATM atm(pin, balance);

    int choice;
    int attempt = 0;
    int enteredPin;

    atm.displayWelcomeScreen();
    cin >> choice;

    switch (choice)
     {
        case 1:
            cout << "Enter your PIN: ";
            cin >> enteredPin;

            if (atm.authenticatePIN(enteredPin)) 
            {
                do {
                    atm.displayMenu();
                    cin >> choice;

                    switch (choice) {
                        case 1:
                            double depositAmount;
                            cout << "Enter amount to deposit: ";
                            cin >> depositAmount;
                            atm.deposit(depositAmount);
                            break;
                        case 2:
                            double withdrawAmount;
                            cout << "Enter amount to withdraw: ";
                            cin >> withdrawAmount;
                            atm.withdraw(withdrawAmount);
                            break;
                        case 3:
                            atm.checkBalance();
                            break;
                        case 4:
                            cout << "Thank you for using our ATM services." << endl;
                            break;
                        default:
                            cout << "Invalid choice. Please try again." << endl;
                    }
                } while (choice != 4);
            } else {
                attempt++;
                cout << "Incorrect PIN. Please try again." << endl;
            }
            break;
        case 2:
            cout << "Help Screen:" << endl;
            cout << "1. Enter your PIN to access your account." << endl;
            cout << "2. Use the menu options to deposit, withdraw, or check your balance." << endl;
            break;
        case 3:
            cout << "Thank you for using our ATM services." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}
