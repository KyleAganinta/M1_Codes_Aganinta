#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

//global variables 
bool food = false;
bool decor = false;
bool ready = false;


void checkProgress(){
    while(!ready){
        cout<<"Checking if food and decor is finished..."<<endl;
        if(food && decor) //check if food and decor are both finished
            ready = true;
        this_thread::sleep_for(chrono::milliseconds(600)); //sleep for 600 millisecond and check again
    }
    cout<<"Party is ready!"<<endl;
}

void prepFood() {
    for (int i = 1; i < 5; i++){
        cout<<"Friend 1: Preparing food..."<<endl;
        this_thread::sleep_for(chrono::milliseconds(400)); //task takes 400 millisecond
    }
    food = true; //make food status to ready when compeleted.
}

void decorate(){
    for (int i = 1; i < 5; i++){
        cout<<"Friend 2: Decorating... "<<endl;
        this_thread::sleep_for(chrono::milliseconds(200)); //task takes 200 millisecond
    }
    decor = true; //make food status to ready when compeleted.
}

void organizeParty(){
    

    //you
    thread t1(checkProgress);
    //friends
    thread t2(prepFood);
    thread t3(decorate);

    //wait for friends thread to end
    t2.join();
    t3.join();

    //wait for your thread to end
    t1.join();

}

int main(){
    cout<<"Organize a Party (Concurrent and Parallel)"<<endl;

    organizeParty();
    return 0;
}
