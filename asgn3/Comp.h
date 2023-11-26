#ifndef COMP_H
#define COMP_H

#include "BaseClass.h"
#include <iostream>
#include <vector>

class Comp : public BaseClass {
public:
    void createAccount(std::string id, int count) override;
    std::vector<int> getTopK(int k) override;
    int getBalance(std::string id) override;
    void addTransaction(std::string id, int count) override;
    bool doesExist(std::string id) override;
    bool deleteAccount(std::string id) override;
    int databaseSize() override;
    int hash(std::string id) override;
    Comp();
private:
    int size;
    int hash2(std::string id);
    int get_idx2(std::string id);
};

#endif // COMP_H
