#include <iostream>
#include <chrono> //delays time computation
#include <thread> //this_thread::sleep_for
using namespace std;

void prepareCoffeeAndToast(){
    cout << "Concurrent Computing \n";
    int coffee = 1, toast = 2;
    int count1 =5;
    int count2 = 5;
    while(coffee <= 9 || toast <= 10) {
        if (coffee <=9) {
            cout << "Coffee will be done in " << count1 << "\n";
            coffee += 2;
            count1-=1;
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
        }
        if (toast <= 10) {
            cout << "Toast will be done in " << count2 << "\n";
            toast += 2;
            count2-=1;
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
        }
    }
}


int main(){
    prepareCoffeeAndToast();
    cout<< "Coffee and toast done!";
    return 0;
}