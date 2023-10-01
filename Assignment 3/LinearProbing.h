#ifndef LINEARPROBING_H
#define LINEARPROBING_H

#include "BaseClass.h"
#include <iostream>
using namespace std;
class LinearProbing : public BaseClass {
public:

    void createAccount(std::string id, int count) override;
    std::vector<int> getTopK(int k) override;
    int getBalance(std::string id) override;
    void addTransaction(std::string id, int count) override;
    bool doesExist(std::string id) override;
    bool deleteAccount(std::string id) override;
    int databaseSize() override;
    int hash(std::string id) override;
    LinearProbing();
    
private:
    int sizee=0;
    // vector<int>topbalances;
    vector <int>indices;
    // Other data members and functions specific to Linear Probing
};

#endif // LINEARPROBING_H
