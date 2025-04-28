#include <iostream>
#include <thread>
#include <chrono>
#include <mutex> // Include mutex for synchronization

using namespace std;

mutex coutMutex; // Create a mutex for console output

void dishWashing() {
    for (int i = 5; i >= 0; i--) {
        {
            lock_guard<mutex> guard(coutMutex); // Lock the mutex for this scope
            cout << "\nDish Washing will be done in " << i;
        }
        this_thread::sleep_for(chrono::milliseconds(200)); // Simulate work
    }
}

void foldingLaundry() {
    for (int j = 5; j >= 0; j--) {
        {
            lock_guard<mutex> guard(coutMutex); // Lock the mutex for this scope
            cout << "\nFolding laundry will be done in " << j;
        }
        this_thread::sleep_for(chrono::milliseconds(200)); // Simulate work
    }
}

void parallelComputing() {
    cout << "\n=== Parallel Computing ===\n";
    thread t1(dishWashing);
    thread t2(foldingLaundry);
    
    t1.join(); // Wait for thread t1 to finish
    t2.join(); // Wait for thread t2 to finish
}

int main() {
    parallelComputing();
    cout<< "\n\n Paralell tasks done! folding and dishwashing finished successfully.";
    return 0;
}