#ifndef CHAINING_H
#define CHAINING_H

#include "BaseClass.h"
#include <iostream>

using namespace std;

class Chaining : public BaseClass {
public:
    void createAccount(std::string id, int count) override;
    std::vector<int> getTopK(int k) override;
    int getBalance(std::string id) override;
    void addTransaction(std::string id, int count) override;
    bool doesExist(std::string id) override;
    bool deleteAccount(std::string id) override;
    int databaseSize() override;
    int hash(std::string id) override;
    Chaining();
private:
    int sizee=0;
    vector<int>topbalances;
    // Other data members and functions specific to Chaining
};

#endif // CHAINING_H
