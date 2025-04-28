
#include <iostream>
#include <thread>
#include <chrono> // For simulating delays
using namespace std;

void p1Packing() {
    for (int j = 1; j <= 10; j ++) {
        cout << "Person 1 packing box: " << j << "\n";
        this_thread::sleep_for(chrono::milliseconds(200)); // Simulate work
    }
}

void p2Packing() {
    for (int i = 1; i <= 10; i ++) {
        cout << "Person 2 packing box: " << i << "\n";
        this_thread::sleep_for(chrono::milliseconds(200)); // Simulate work
    }
}

void parallelComputing() {
    cout << "\n=== Packing box with a friend===\n";
    thread t1(p1Packing);
    thread t2(p2Packing);
    
    t1.join(); // Wait for thread t1 to finish
    t2.join(); // Wait for thread t2 to finish
}

void sequentialComputing(){
    cout<< "\n===Packing box alone===\n";
    for (int i=1; i<=10; i++){
        cout<< "Solo person packing box: " << i << "\n";
    }
}

int main() {
    parallelComputing();
    sequentialComputing();
    return 0;
}