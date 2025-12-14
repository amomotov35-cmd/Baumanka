#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class BankAccount {
protected:
    string accountNumber;
    string ownerName;
    double balance;

public:
    BankAccount(const string& accNum, const string& owner, double initialBalance = 0.0)
        : accountNumber(accNum), ownerName(owner), balance(initialBalance) {
        if (initialBalance < 0) {
            cout << "Внимание: начальный баланс отрицательный!" << endl;
        }
    }

    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Успешно пополнено: " << amount << " руб." << endl;
            cout << "Новый баланс: " << balance << " руб." << endl;
        } else {
            cout << "Ошибка: сумма для пополнения должна быть положительной!" << endl;
        }
    }

    virtual bool withdraw(double amount) {
        if (amount <= 0) {
            cout << "Ошибка: сумма для снятия должна быть положительной!" << endl;
            return false;
        }
        
        if (amount <= balance) {
            balance -= amount;
            cout << "Успешно снято: " << amount << " руб." << endl;
            cout << "Остаток на счете: " << balance << " руб." << endl;
            return true;
        } else {
            cout << "Ошибка: недостаточно средств на счете!" << endl;
            cout << "Запрошено: " << amount << " руб., доступно: " << balance << " руб." << endl;
            return false;
        }
    }

    double getBalance() const {
        return balance;
    }

    virtual void displayInfo() const {
        cout << "\n=== Информация о банковском счете ===" << endl;
        cout << "Номер счета: " << accountNumber << endl;
        cout << "Владелец: " << ownerName << endl;
        cout << "Баланс: " << fixed << setprecision(2) << balance << " руб." << endl;
    }

    virtual ~BankAccount() {}
};

class SavingsAccount : public BankAccount {
private:
    double interestRate; 

public:
    SavingsAccount(const string& accNum, const string& owner, 
                   double initialBalance = 0.0, double rate = 5.0)
        : BankAccount(accNum, owner, initialBalance), interestRate(rate) {
        if (rate < 0) {
            cout << "Внимание: процентная ставка отрицательная!" << endl;
        }
    }

    void applyInterest() {
        double interest = balance * (interestRate / 100.0);
        balance += interest;
        cout << "Начислены проценты: " << fixed << setprecision(2) 
             << interest << " руб. (ставка: " << interestRate << "%)" << endl;
        cout << "Новый баланс: " << balance << " руб." << endl;
    }

    void displayInfo() const override {
        cout << "\n=== Информация о сберегательном счете ===" << endl;
        cout << "Номер счета: " << accountNumber << endl;
        cout << "Владелец: " << ownerName << endl;
        cout << "Баланс: " << fixed << setprecision(2) << balance << " руб." << endl;
        cout << "Процентная ставка: " << interestRate << "%" << endl;
        cout << "Доход за год: " << fixed << setprecision(2) 
             << (balance * interestRate / 100.0) << " руб." << endl;
    }

    double getInterestRate() const {
        return interestRate;
    }

    
    void setInterestRate(double newRate) {
        if (newRate >= 0) {
            interestRate = newRate;
            cout << "Процентная ставка изменена на " << newRate << "%" << endl;
        } else {
            cout << "Ошибка: процентная ставка не может быть отрицательной!" << endl;
        }
    }
};


void demonstrateBankOperations() {
    cout << "=== ДЕМОНСТРАЦИЯ РАБОТЫ БАНКОВСКОЙ СИСТЕМЫ ===\n" << endl;

    
    cout << "1. СОЗДАНИЕ ОБЫЧНОГО БАНКОВСКОГО СЧЕТА:" << endl;
    BankAccount regularAccount("40817810099910004321", "Слюсаренко Григорий Андреевич", 50000.0);
    regularAccount.displayInfo();

    
    cout << "\n2. ОПЕРАЦИИ С ОБЫЧНЫМ СЧЕТОМ:" << endl;
    regularAccount.deposit(15000.50);
    regularAccount.withdraw(10000.75);
    regularAccount.withdraw(60000.0); 

    cout << "\n3. СОЗДАНИЕ СБЕРЕГАТЕЛЬНОГО СЧЕТА:" << endl;
    SavingsAccount savingsAccount("42301810712345678901", 
                                  "Волкова Александра Сергеевна", 
                                  100000.0, 7.5);
    savingsAccount.displayInfo();

   
    cout << "\n4. ОПЕРАЦИИ СО СБЕРЕГАТЕЛЬНЫМ СЧЕТОМ:" << endl;
    savingsAccount.deposit(50000.0);
    
    cout << "\n5. НАЧИСЛЕНИЕ ПРОЦЕНТОВ:" << endl;
    savingsAccount.applyInterest();
    
    cout << "\n6. СНЯТИЕ СРЕДСТВ:" << endl;
    savingsAccount.withdraw(20000.0);
    
    cout << "\n7. ИЗМЕНЕНИЕ ПРОЦЕНТНОЙ СТАВКИ:" << endl;
    savingsAccount.setInterestRate(8.2);
    savingsAccount.displayInfo();
    
    cout << "\n8. ЕЩЕ ОДНО НАЧИСЛЕНИЕ ПРОЦЕНТОВ:" << endl;
    savingsAccount.applyInterest();
    
    cout << "\n9. ДЕМОНСТРАЦИЯ ПОЛИМОРФИЗМА:" << endl;
    vector<BankAccount*> accounts;
    accounts.push_back(&regularAccount);
    accounts.push_back(&savingsAccount);
    
    for (size_t i = 0; i < accounts.size(); ++i) {
        accounts[i]->displayInfo();
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    
    demonstrateBankOperations();
    
    cout << "\n=== ПРОГРАММА ЗАВЕРШЕНА ===" << endl;
    
    return 0;
}