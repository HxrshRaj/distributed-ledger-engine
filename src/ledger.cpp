#include "ledger.h"
#include <iostream>

void Ledger::addTransaction(const std::string& data) {
    std::lock_guard<std::mutex> lock(mtx);

    Transaction tx;
    tx.data = data;
    transactions.push_back(tx);
}

void Ledger::printLedger() {
    std::lock_guard<std::mutex> lock(mtx);

    std::cout << "Ledger Transactions:\n";
    for (const auto& tx : transactions) {
        std::cout << tx.data << std::endl;
    }
}