# Distributed Transaction Ledger Engine

A high-performance C++ system that simulates a distributed ledger capable of handling concurrent transactions using multithreading and socket-based communication.

##  Features

- Multithreaded transaction processing using `std::thread`
- Thread-safe ledger using mutex synchronization
- Simulated distributed system via TCP socket communication
- Modular C++ architecture (header/source separation)
- High concurrency handling

##  Architecture

The system consists of:

1. **Ledger Engine**
   - Stores transactions in a thread-safe structure

2. **Thread Pool Simulation**
   - Multiple threads simulate concurrent transactions

3. **Network Module**
   - TCP server to receive external transaction data

##  How It Works

1. Multiple threads generate transactions concurrently  
2. Transactions are safely stored using mutex locks  
3. A TCP server listens for incoming transaction requests  
4. All transactions are recorded in the ledger  

## 🛠 Tech Stack

- C++
- Multithreading (`std::thread`, `mutex`)
- Socket Programming (TCP)
- System-level Programming

## 📂 Project Structure
src/
├── main.cpp
├── ledger.cpp
├── network.cpp
include/
├── ledger.h
├── network.h

## ▶ How to Run

```bash
g++ src/main.cpp src/ledger.cpp src/network.cpp -Iinclude -lws2_32 -o ledger_app
ledger_app
## Future Improvements
Implement full distributed node communication
Add persistent storage
Improve transaction throughput benchmarking
Add client-server multi-node simulation
👨‍💻 Author
Harsh Raj