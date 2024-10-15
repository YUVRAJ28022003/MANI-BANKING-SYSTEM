#include<bits/stdc++.h>
using namespace std;

int total_saving_accounts = 0;
int total_current_accounts = 0;

class account {
public:
    string name_of_account_holder;
    string name_of_joint_account_holder;
    long long int account_number;
    int balance;
    string type_of_account;
    string pin;

    // Single holder account constructor
    account(string accholdername, int bal, string typeofacc, string pc) {
        account_number = rand() % 100000 + 1000000000;
        name_of_account_holder = accholdername;
        balance = bal;
        type_of_account = typeofacc;
        pin = pc;
        name_of_joint_account_holder = "No Joint Holder in this account";
    }

    // Joint holder account constructor
    account(string accholdername, string jointholdername, int bal, string typeofacc, string pc) {
        account_number = rand() % 100000 + 1000000000;
        name_of_account_holder = accholdername;
        name_of_joint_account_holder = jointholdername;
        balance = bal;
        type_of_account = typeofacc;
        pin = pc;
    }
};

vector<account> accts;

bool is_valid_pin(string pin) {
    if (pin.length() != 4) {
        cout << "PIN must be exactly 4 digits.\n";
        return false;
    }
    for (char c : pin) {
        if (!isdigit(c)) {
            cout << "PIN must contain only digits.\n";
            return false;
        }
    }
    return true;
}

void display_details(long long int accnum) {
    bool acc_exists = false;
    for (auto &it : accts) {
        if (it.account_number == accnum) {
            acc_exists = true;
            cout << "\nAccount Number: " << it.account_number;
            cout << "\nAccount Holder Name: " << it.name_of_account_holder;
            cout << "\nJoint Holder Name: " << it.name_of_joint_account_holder;
            cout << "\nBalance in your account: " << it.balance;
            cout << "\nType of Account: " << it.type_of_account;
            break;
        }
    }
    if (!acc_exists) {
        cout << "Account doesn't exist with the given Account Number.\n";
    }
}

bool create_account(vector<account> &accts) {
    system("cls");
    string accholder_name;
    cout << "\nENTER YOUR DETAILS HERE: ";
    cout << "\nName of Account Holder: ";
    cin >> accholder_name;

    string joint_holder, pin, typeofacc;
    int choice;

    cout << "\nDo you want to have a joint holder account? Type YES/NO: ";
    string is_joint;
    cin >> is_joint;

    if (is_joint == "YES") {
        cout << "Enter the name of Joint Holder: ";
        cin >> joint_holder;
    }

    do {
        cout << "\nEnter a 4-digit pin: ";
        cin >> pin;
    } while (!is_valid_pin(pin));  // Validate PIN input

    cout << "\nEnter the type of account: ";
    cout << "1 - Savings Account\n";
    cout << "2 - Current Account\n";
    cout << "Enter your choice here: ";
    cin >> choice;

    if (choice == 1)
        typeofacc = "Savings";
    else
        typeofacc = "Current";

    int balance;
    cout << "\nEnter the balance you want to have initially in your account (minimum 1000): ";
    cin >> balance;

    if (balance < 1000) {
        cout << "\t\t|-----------------------------------------------|\n";
        cout << "\t\t|     INSUFFICIENT BALANCE (Balance must be >= 1000)  |\n";
        cout << "\t\t|-----------------------------------------------|\n";
        return false;
    }

    if (typeofacc == "Current" && balance < 10000) {
        cout << "\t\t|-----------------------------------------------|\n";
        cout << "\t\t|     INSUFFICIENT BALANCE (Current Accounts need 10000+) |\n";
        cout << "\t\t|-----------------------------------------------|\n";
        return false;
    }

    if (is_joint == "YES") {
        account ob(accholder_name, joint_holder, balance, typeofacc, pin);
        accts.push_back(ob);
    } else {
        account ob(accholder_name, balance, typeofacc, pin);
        accts.push_back(ob);
    }

    if (typeofacc == "Savings")
        total_saving_accounts++;
    else
        total_current_accounts++;

    cout << "\t\t|-----------------------------------------------|\n";
    cout << "\t\t|     ACCOUNT CREATED SUCCESSFULLY              |\n";
    cout << "\t\t|-----------------------------------------------|\n";
    display_details(accts.back().account_number);
    return true;
}

bool change_pin() {
    long long int accnum;
    cout << "Enter your account number: ";
    cin >> accnum;

    for (auto &it : accts) {
        if (it.account_number == accnum) {
            string oldpin, newpin;
            cout << "Enter the old pin: ";
            cin >> oldpin;
            if (oldpin == it.pin) {
                do {
                    cout << "Enter a new 4-digit pin: ";
                    cin >> newpin;
                } while (!is_valid_pin(newpin));  // Validate new PIN

                it.pin = newpin;
                cout << "Pin changed successfully.\n";
                display_details(it.account_number);
                return true;
            } else {
                cout << "Invalid Pin. Try Again.\n";
                return false;
            }
        }
    }

    cout << "Account doesn't exist with the given Account Number.\n";
    return false;
}

bool deposit_into_account() {
    long long int accnum;
    cout << "Enter your account number: ";
    cin >> accnum;

    for (auto &it : accts) {
        if (it.account_number == accnum) {
            string pin;
            cout << "Enter the pin: ";
            cin >> pin;
            if (pin == it.pin) {
                int deposit_amount;
                cout << "Enter the amount you want to deposit: ";
                cin >> deposit_amount;

                if (deposit_amount < 0) {
                    cout << "Invalid deposit amount!\n";
                    return false;
                }

                if (deposit_amount % 100 != 0) {
                    cout << "Deposit amount must be a multiple of 100.\n";
                    return false;
                }

                it.balance += deposit_amount;
                cout << "Deposit successful.\n";
                display_details(it.account_number);
                return true;
            } else {
                cout << "Invalid Pin. Try Again.\n";
                return false;
            }
        }
    }

    cout << "Account doesn't exist with the given Account Number.\n";
    return false;
}

bool withdraw_from_account() {
    long long int accnum;
    cout << "Enter your account number: ";
    cin >> accnum;

    for (auto &it : accts) {
        if (it.account_number == accnum) {
            string pin;
            cout << "Enter the pin: ";
            cin >> pin;
            if (pin == it.pin) {
                int withdrawal_amount;
                cout << "Enter the amount you want to withdraw: ";
                cin >> withdrawal_amount;

                if (withdrawal_amount < 0) {
                    cout << "Invalid withdrawal amount!\n";
                    return false;
                }

                if (withdrawal_amount % 100 != 0) {
                    cout << "Withdrawal amount must be a multiple of 100.\n";
                    return false;
                }

                if (it.balance - withdrawal_amount < 1000) {
                    cout << "Withdrawal failed. Balance cannot be less than 1000.\n";
                    return false;
                }

                if (it.balance >= withdrawal_amount) {
                    it.balance -= withdrawal_amount;
                    cout << "Withdrawal successful.\n";
                    display_details(it.account_number);
                    return true;
                } else {
                    cout << "Insufficient Balance.\n";
                    return false;
                }
            } else {
                cout << "Invalid Pin. Try Again.\n";
                return false;
            }
        }
    }

    cout << "Account doesn't exist with the given Account Number.\n";
    return false;
}

bool close_account() {
    long long int accnum;
    cout << "Enter your account number: ";
    cin >> accnum;

    auto it = find_if(accts.begin(), accts.end(), [accnum](const account &acc) {
        return acc.account_number == accnum;
    });

    if (it != accts.end()) {
        accts.erase(it);
        cout << "Account closed successfully.\n";
        return true;
    }

    cout << "Account doesn't exist with the given Account Number.\n";
    return false;
}

void admin_menu() {
    int option;
    system("cls");
    cout << "\t\t|-----------------------------------------------|\n";
    cout << "\t\t|   Choose your option:                         |\n";
    cout << "\t\t|-----------------------------------------------|\n";
    cout << "\t\t|     1) View Total Number of Accounts          |\n";
    cout << "\t\t|     2) View Account Details                   |\n";
    cout << "\t\t|     3) Exit                                   |\n";
    cout << "\t\t|-----------------------------------------------|\n";
    cout << "Choose your option: ";
    cin >> option;

    switch (option) {
    case 1:
        cout << "Total number of Savings Accounts: " << total_saving_accounts << "\n";
        cout << "Total number of Current Accounts: " << total_current_accounts << "\n";
        break;

    case 2: {
        long long int accnum;
        cout << "Enter account number: ";
        cin >> accnum;
        display_details(accnum);
        break;
    }
    case 3:
        exit(0);
        break;
    default:
        cout << "Invalid option!\n";
        break;
    }
}

void user_menu() {
    int choice;
    do {
        cout<<endl;
        cout << "\t\t|-----------------------------------------------|\n";
        cout << "\t\t|   Choose your option:                         |\n";
        cout << "\t\t|-----------------------------------------------|\n";
        cout << "\t\t|   1) Create an account                        |\n";
        cout << "\t\t|   2) Change your pin                          |\n";
        cout << "\t\t|   3) Deposit into account                     |\n";
        cout << "\t\t|   4) Withdraw from account                    |\n";
        cout << "\t\t|   5) View Account Details                     |\n";
        cout << "\t\t|   6) Close your account                       |\n";
        cout << "\t\t|   7) Exit                                     |\n";
        cout << "\t\t|-----------------------------------------------|\n";
        cout << "Choose your option: ";
        cin >> choice;

        switch (choice) {
        case 1:
            create_account(accts);
            break;
        case 2:
            change_pin();
            break;
        case 3:
            deposit_into_account();
            break;
        case 4:
            withdraw_from_account();
            break;
        case 5: {
            long long int accnum;
            cout << "Enter your account number: ";
            cin >> accnum;
            display_details(accnum);
            break;
        }
        case 6:
            close_account();
            break;
        case 7:
            exit(0);
            break;
        default:
            cout << "Invalid Option.\n";
            break;
        }
    } while (choice != 7);
}

int main() {
    user_menu();
    return 0;
}
