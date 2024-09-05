//q2)Question 2 : Create a class BankAccount with private attributes accountNumber and balance. Implement public methods deposit(), withdraw(), and getBalance() to manage the account.
#include<iostream>
using namespace std;
class Bankaccount {
private :
  int accountnumber;
  double balance;
public :
Bankaccount ( int accnum , double bal){
  accountnumber = accnum;
  balance = bal;
}
void deposit(double amount){
  balance += amount;
}
void withdraw(double amount){
  if(amount <= balance){
    balance -= amount;
  } else {
    cout << "Not sufficient balance for this withdrawal.\n";
  }
}
double getBalance(){
  return balance;
}
};
int main(){
  Bankaccount myAccount(12345, 500.0);
  myAccount.deposit(150.0);
  myAccount.withdraw(478.0);
  cout << "Current Balance: Rs." << myAccount.getBalance() << endl;
  return 0;
}