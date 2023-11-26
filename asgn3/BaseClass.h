#ifndef BASECLASS_H
#define BASECLASS_H

#include <string>
#include <vector>
struct Account {
    std::string id;
    int balance;
};

class BaseClass {
public:
    virtual void createAccount(std::string id, int count) = 0;
    virtual std::vector<int> getTopK(int k) = 0;
    virtual int getBalance(std::string id) = 0;
    virtual void addTransaction(std::string id, int count) = 0;
    virtual bool doesExist(std::string id) = 0;
    virtual bool deleteAccount(std::string id) = 0;
    virtual int databaseSize() = 0;
    virtual int hash(std::string id) = 0;

    std::vector<Account> bankStorage1d;
    std::vector<std::vector<Account>> bankStorage2d;
    
};

#endif // BASECLASS_H
