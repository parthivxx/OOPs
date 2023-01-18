#include <bits/stdc++.h>
#define SIZE 200
using namespace std;

bool compare(char ac1[], char ac2[])
{
  for (int i = 0; i < 10; i++)
  {
    if (ac1[i] != ac2[i])
      return false;
  }
  return true;
}
class Account
{
  int balance;
  char ac_number[10];

public:
  Account() {}
  void set_data(char ac_number[], int balance)
  {
    for (int i = 0; i < 10; i++)
    {
      this->ac_number[i] = ac_number[i];
    }
    this->balance = balance;
  }
  void display()
  {
    cout << "Your account number is " << ac_number << "\n";
    cout << "Your current balance is " << balance << "\n";
  }
  char *get_ac_number()
  {
    return ac_number;
  }
  int get_balance()
  {
    return balance;
  }
  void update_balance(int money)
  {
    if (balance < money)
    {
      cout << "Insufficient balance\n";
      return;
    }
    balance -= money;
    cout << money << " Rupees in is debited from your account. You current balance is " << balance << " Rupees\n";
    return;
  }
};

class Withdraw;
class System
{
  Account account_list[SIZE];
  static int cur;
  friend class Withdraw;

public:
  static void update_cur() { cur++; }
  static int get_cur() { return cur; }
  void add_account(char new_ac[], int new_balance)
  {
    for (int i = 0; i < cur; i++)
    {
      if (!strcmp(new_ac, account_list[i].get_ac_number()))
      {
        cout << "An account with this account number already exists!\n";
        return;
      }
    }
    account_list[cur].set_data(new_ac, new_balance);
    update_cur();
    cout << "Your account has been added to the system successfully!\n";
    return;
  }
  void display()
  {
    for (int i = 0; i < cur; i++)
    {
      cout << i + 1 << "th account-->\n";
      account_list[i].display();
    }
  }
};

class Withdraw
{
  char account_number[10];
  int withdraw_ammount;

public:
  void set_data(char ac[], int money)
  {
    for(int i=0;i<10;i++){
      this->account_number[i] = ac[i];
    }
    this->withdraw_ammount = money;
  }
  void update_balance(System &s)
  {
    for (int i = 0; i < System::get_cur(); i++)
    {
      if (compare(account_number, s.account_list->get_ac_number()))
      {
        s.account_list[i].update_balance(withdraw_ammount);
      }
    }
  }
};

class Bank
{
public:
  void operation()
  {
    System s;
    while (1)
    {
      int choice;
      cout << "Enter the number corresponeding to a operation you want to do.\n";
      cout << "1. to add a new account\n";
      cout << "2. withdraw money from a account.\n";
      cout << "3. To display data of all account.\n";
      cout << "-1. to end operations.\n";
      cin >> choice;
      if (choice == -1)
      {
        break;
      }
      System s;
        char __ac[10];
        int __bal;
       if(choice==1){
        cout << "Enter the account number you want to add ";
        scanf("%s", __ac);
        cout << "Enter the ammount of money you want to put ";
        cin >> __bal;
        s.add_account(__ac, __bal);
       }
      else if(choice==2){
        cout << "Enter the account number you want to add ";
        scanf("%s", __ac);
        cout << "Enter the ammount of money you want to put ";
        cin >> __bal;
        Withdraw w;
        w.set_data(__ac,__bal);
        w.update_balance(s);
      }
      else if(choice==3)
        s.display();
    }
  }
};
int System ::cur = 0;
int main()
{
  Bank sbi;
  sbi.operation();
  return 0;
}