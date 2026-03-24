#include "ledger.h"
#include "network.h"
#include <thread>
#include <vector>
#include <iostream>

void simulateTransaction(Ledger& ledger, int id) {
    std::string data = "Transaction " + std::to_string(id);
    ledger.addTransaction(data);
}

int main() {
    Ledger ledger;
    Network network;

    // Start server in separate thread
    std::thread serverThread(&Network::startServer, &network, 8080);

    std::vector<std::thread> threads;

    // simulate concurrent transactions
    for (int i = 1; i <= 10; i++) {
        threads.emplace_back(simulateTransaction, std::ref(ledger), i);
    }

    for (auto& t : threads) {
        t.join();
    }

    ledger.printLedger();

    serverThread.join();

    return 0;
}