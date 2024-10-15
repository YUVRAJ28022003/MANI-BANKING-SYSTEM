

![Screenshot 2024-10-15 211211](https://github.com/user-attachments/assets/a50cb759-b035-48e1-a0e7-7940a2b89f7d)
![Screenshot 2024-10-15 211221](https://github.com/user-attachments/assets/f2fb2b13-b9fb-4a69-a378-5dd8141f4aff)
![Screenshot 2024-10-15 211241](https://github.com/user-attachments/assets/74a7930a-1cce-478a-868f-f0354ed12469)
![Screenshot 2024-10-15 211259](https://github.com/user-attachments/assets/203a82cc-8aaf-4888-9e9d-0fa226d1e2c1)
![Screenshot 2024-10-15 211319](https://github.com/user-attachments/assets/b4ebc9f8-a8d5-4b2f-9761-9ac7b2081a2a)
![Screenshot 2024-10-15 211334](https://github.com/user-attachments/assets/43686a87-1205-40cf-a1d1-4b175e1db548)
![Screenshot 2024-10-15 211351](https://github.com/user-attachments/assets/88f29b12-14c7-47e3-8061-272f22d49865)
![Screenshot 2024-10-15 211406](https://github.com/user-attachments/assets/65aa8f76-6e22-418b-930e-08bcc3c43e2c)
![Screenshot 2024-10-15 211430](https://github.com/user-attachments/assets/d07618dc-f840-4493-8db6-b45cb2d6974a)
![Screenshot 2024-10-15 211420](https://github.com/user-attachments/assets/bca08ba6-82d4-405d-bf8b-8c85a0616442)
# MANI-BANKING-SYSTEM
This project is a simple Banking Application built in C++. It simulates the operations of a bank, allowing users to create accounts, deposit or withdraw funds, change PINs, and check account balances. The application supports both savings and current accounts. 
This project is a simple Banking Application built in C++. It simulates the operations of a bank, allowing users to create accounts, deposit or withdraw funds, change PINs, and check account balances. The application supports both savings and current accounts. It incorporates basic error handling and ensures data integrity through multiple validation checks.

Features :
----------
Account Creation:
--------------------

Users can create either single-holder or joint-holder accounts.
Both Savings and Current Accounts are supported.

Initial balance requirement:
----------------------------
Minimum of 1000 for savings accounts.
Minimum of 10000 for current accounts.

PIN Setup:
----------
Users must set up a 4-digit numeric PIN to secure their accounts.
PIN validation is enforced throughout the application.

Deposits and Withdrawals:
---------------------------
Deposit or withdraw money, with the following constraints:
Amount must be a multiple of 100.
Withdrawal cannot reduce the balance below 1000.

Account Operations:
--------------------
View account details.
Change PIN securely by entering the old PIN.
Close an account if desired.

Admin Operations:
------------------
Admin can view the total number of savings and current accounts.
Admin can check account details using the account number.


User Menu:
----------
Create an Account:
-------------------
Enter your name.
Choose to create a single or joint holder account.
Set a 4-digit numeric PIN.
Choose account type (Savings or Current).
Deposit the initial balance (must meet the minimum requirement).

Change PIN:
-----------
Enter your account number.
Enter your current PIN.
Set a new 4-digit numeric PIN.

Deposit Funds:
---------------
Enter your account number and PIN.
Specify the amount to deposit (must be a multiple of 100).

Withdraw Funds:
---------------
Enter your account number and PIN.
Specify the amount to withdraw (must be a multiple of 100, and cannot reduce balance below 1000).

View Account Details:
---------------------
Enter your account number to view your balance and other details.

Close Account:
--------------
Enter your account number to close your account permanently.

Admin Menu:
-----------
View total number of Savings and Current accounts.
View specific account details using the account number.

Constraints
------------
PIN must be exactly 4 digits and numeric.
Deposits and withdrawals must be in multiples of 100.
Minimum balance of 1000 must be maintained at all times in the account.
Future Improvements
