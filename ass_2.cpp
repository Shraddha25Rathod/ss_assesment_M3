#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class ATM 
{
private:
    int pin;
    double balance;
    const double initialBalance = 60000; 
    const double accountBalance = 20000; 

public:
    ATM(int atmPin)
    {
        pin = atmPin;
        balance = accountBalance;  
    }

    void displayCurrentDateTime()
     {
        time_t now = time(0);
        char* dt = ctime(&now);
        cout << "\n\n\t-----------WELCOME TO ATM----------";
        cout << "\n\n\t Current Date and Time: " << dt << endl; 
     }
        
        void displayHelp()
 {
    cout << "\n\n\t---------ATM ACCOUNT STATUS----------";
    cout << "\n\n\t You must have the correct PIN number to access this account.\n";
    cout << "\n\n\t See your bank representative for assistance during bank opening hours.\n";
    cout << "\n\n\t Thanks for your choice today!!\n";
    cout << "\n\n\t Press any key to continue.\n";
    cin.ignore(); 
    cin.get();
}

  
    void displayMenu() 
    {
        cout<<"\n\n\t -----------ATM ACCOUNT STATUS-------";
        cout<<"\n\n\t yoy must have the correct pin number to access this account. see your bank representative for assistance during bank opening hours thanks for, your choice today!!";
        cout << "\n\n\t ATM Main Menu\n";
        cout << "\n\n\t Enter [1] to Deposit Cash";
        cout << "\n\n\t Enter [2] to Withdraw Cash";
        cout << "\n\n\t Enter [3] to Check Balance";
        cout << "\n\n\t Enter [0] to Exit ATM";
        cout << "\n\n\t Please Enter a Selection and Press Return Key: ";
    }

    bool verifyPin(int enteredPin)
     {
        if (enteredPin == pin)
         {
            return true;
        }
        return false;
    }
   

    void depositAmount()
     {
        double deposit;
        cout << "\n\n\tATM ACCOUNT DEPOSIT SYSTEM--------";
        cout << "\n\n\t The name of the account holder: Rakesh Kharva";
        cout << "\n\n\t The account holder's address: Mumbai";
        cout << "\n\n\t Branch location: Andheri";
        cout << "\n\n\t Account number: 5678";
        cout << "\n\n\t Available balance: Rs. " << balance << endl;
        cout << "\n\n\t Enter the amount to be deposited: Rs. ";
        cin >> deposit;
        
        balance += deposit; 
        cout << "\n\n\t Your new available balance is: Rs. " << balance << endl;
        cout << "\n\n\t THANK YOU! Press any key to return to the main menu.";
        cin.ignore();  
        cin.get();
    }

    void withdrawAmount()
     {
        double withdrawal;
        cout << "\n\n\t-----ATM ACCOUNT WITHDRAWAL SYSTEM---------";
        cout << "\n\n\t Available balance: Rs. " << balance << endl;
        cout << "\n\n\t Enter the amount to withdraw: Rs. ";
        cin >> withdrawal;

        if (withdrawal > balance) 
        {
            cout << "\n\n\t Insufficient balance for the withdrawal!";
            cout << "\n\n\t Thank you! Press any key to return to the main menu.";
            cin.ignore();  
            cin.get();
        } else
         {
            balance -= withdrawal;  
            cout << "\n\n\t Withdrawal successful! Remaining balance: Rs. " << balance << endl;
            cout << "\n\n\t Press any key to return to the main menu.";
            cin.ignore(); 
            cin.get();
        }
    }

    void checkBalance()
     {
        cout << "\n\n\t-----ATM ACCOUNT BALANCE INQUIRY-----";
        cout << "\n\n\t Your current balance is: Rs. " << balance << endl;
        cout << "\n\n\t Press any key to return to the main menu.";
        cin.ignore(); 
        cin.get();
    }
};

int main() 
{
    int enteredPin;
    int choice;
    const int correctPin = 12345; 
    ATM atm(correctPin);  

    atm.displayCurrentDateTime();
    
    cout << "\n\n\t Press [1] and then press Enter to access our account via PIN number.\n";
    cout << "\n\n\t Press [0] and press Enter to get help.";
    cout << "\n\n\t Enter your choice: ";
    cin >> choice;

    if (choice == 1)
     {
        cout << "\n\n\t ATM ACCOUNT ACCESS";
        cout << "\n\n\t Enter your PIN (only one attempt is allowed): ";
        cin >> enteredPin;

        if (!atm.verifyPin(enteredPin))
         {
            cout << "\n\n\t THANK YOU! You had made your attempt which failed!";
            cout << "\n\n\t No more attempts allowed! Sorry!!!";
            cout << "\n\n\t Press any key to continue.";
            cin.ignore(); 
            cin.get();
            return 0;  
        } else
         {
          
            do
             {
                atm.displayMenu();
                cin >> choice;

                switch (choice)
                 {
                    case 1:  
                        atm.depositAmount();
                        break;
                    case 2:  
                        atm.withdrawAmount();
                        break;
                    case 3: 
                        atm.checkBalance();
                        break;
                    case 0:  
                        cout << "\n\n\t Exiting the ATM session.";
                        break;
                    default:
                        cout << "\n\n\t Invalid choice! Please try again.";
                }
            } while (choice != 0);  
        }
    } else if (choice == 0)
     {
        
        atm.displayHelp();
    } else 
    {
        cout << "\n\n\t Invalid choice! Exiting...";
    }

    return 0;
}
