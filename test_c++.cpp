#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

int reset_system(int &car_count, double &total_cost, int &cars_in_garge, int &total_cars_served){
    car_count = 0;
    total_cost = 0.0;
    cars_in_garge = 0;
    total_cars_served = 0;
    cout << "System reset successfully." << endl;
}

int display_status(int car_count, double total_cost, int cars_in_garge, int total_cars_served){
    cout << "\n--- Parking Status ---" << endl;
    cout << "Cars in Garage: " << car_count << endl;
    cout << "Total Cars Served: " << total_cars_served << endl;
    cout << "Total Cost: " << total_cost << endl;
}





int main(){
    int MAX_CARS = 3;
    float COST_PER_UNIT = 1.0;
    int car_count = 0;
    float total_cost = 0.0;
    int cars_in_garge = 0;
    int total_cars_served  = 0;
    vector <int> save_car (MAX_CARS);
           int choice;

    while (true)
    {
     
       
    cout<< "choose an option: " << endl;
    cout<< "1. Enter a car" << endl;
    cout<< "2. Exit a car" << endl;
    cout<< "3. Reset system" << endl;
    cout<< "4. Display status" << endl;
    cout<< "5. Exit" << endl;
    cin >> choice;
    if (choice == 5) {
        cout << "Exiting the program." << endl;
        break;
    }
    if (car_count == MAX_CARS) {
        cout << "Garage is full. Cannot enter more cars." << endl;
    } else if (car_count == 0) {
        cout << "Garage is empty. Cannot exit any cars." << endl;
    }

   

    if (choice ==1){  // car entry 
        
      int add_car = 0;
      save_car.push_back(add_car+1);
      car_count++;
       cout << "Car " << car_count << " entered the garage." << endl;
        

    } else if (choice == 2) { // car exit
        int exit_car = car_count;
        save_car.pop_back();
        car_count--;
        cout << "Car " << car_count << " exited the garage." << endl;
    }
  
    }
    return 0;
}
