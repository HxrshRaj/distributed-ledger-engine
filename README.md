# Distributed Transaction Ledger Engine

A high-performance C++ system that simulates a distributed ledger capable of handling concurrent transactions using multithreading and socket-based communication.

##  Features

- Multithreaded transaction processing using `std::thread`
- Thread-safe ledger using mutex synchronization
- TCP socket-based server for transaction communication
- Simulated distributed system behavior
- Modular C++ architecture (header/source separation)

##  Architecture

The system consists of:

1. **Ledger Engine**
   - Stores transactions in a thread-safe structure

2. **Concurrent Processing Layer**
   - Multiple threads simulate high-volume transaction handling

3. **Network Module**
   - TCP server to receive and process external transaction requests

##  How It Works

1. Multiple threads generate transactions concurrently  
2. Mutex locks ensure thread-safe updates  
3. TCP server listens for incoming connections  
4. Received transactions are processed and stored  

##  Tech Stack

- C++
- Multithreading (`std::thread`, `mutex`)
- Socket Programming (TCP/IP)
- System-level programming concepts

## 📂 Project Structure
src/
├── main.cpp
├── ledger.cpp
├── network.cpp
include/
├── ledger.h
├── network.h

##  How to Run

```bash
g++ src/main.cpp src/ledger.cpp src/network.cpp -Iinclude -lws2_32 -o ledger_app
ledger_app

## Future Improvements
Full distributed node-to-node communication
Persistent storage for transactions
Performance benchmarking and optimization
Multi-client network simulation

👨‍💻 Author
Harsh Raj
