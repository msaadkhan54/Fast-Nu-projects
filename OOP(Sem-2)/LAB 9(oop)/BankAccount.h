#ifndef BANKACCOUNT
#define BANKACCOUNT
class BankAccount {  
  private:
    double balance;
  public:
    BankAccount(double initial_balance);
    void deposit (double amount);
    withdraw(double amount);
    double getBalance() const;
};
#endif
