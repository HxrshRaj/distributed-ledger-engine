#ifndef LEDGER_H
#define LEDGER_H

#include <string>
#include <vector>
#include <mutex>

struct Transaction {
    std::string data;
};

class Ledger {
private:
    std::vector<Transaction> transactions;
    std::mutex mtx;

public:
    void addTransaction(const std::string& data);
    void printLedger();
};

#endif