#include <iostream>
#include <chrono>
#include <thread>

using namespace std;


int withHelpCount = 0;


void packSequential(){
	for(int i = 1; i <= 5; i++){ //executing steps sequentially
		cout<<"Alone: Packing, step "<<i<<"... "<<endl;
        this_thread::sleep_for(chrono::milliseconds(400)); //task takes 400 millisecond
	}
    cout<<"Alone: Packing Complete."<<endl;
}

void packParallel(int start, int interval) {
    for(int i = start; i <= 5; i += interval){
        cout<<"With Help: Packing, step "<<i<<"... "<<endl;
        this_thread::sleep_for(chrono::milliseconds(400)); //task takes 400 millisecond
        if(i == 5) cout<<"With Help: Packing Complete."<<endl;
    }
    
}

void packingBoxes(){
    

    //you
    thread t1(packSequential);
    //friends
    thread t2(packParallel,1,2);
    thread t3(packParallel,2,2);

    //wait for threads to end
    t1.join();
    t2.join();
    t3.join();
    
}

int main(){
    cout<<"Sequential vs Parallel Comparison"<<endl;

    packingBoxes();
    return 0;
}
