#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_CARS 3
#define COST_PER_UNIT 1.0





int main() {
    typedef struct {
        bool occupied;
        time_t entry_time;
        int car_id;
    } ParkingSlot;

    ParkingSlot slots[MAX_CARS];
    int current_count = 0;
    int cars_served = 0;
    double total_time_spent = 0.0;
    int next_car_id = 1;
    int choice;

    for (int i = 0; i < MAX_CARS; i++) {
        slots[i].occupied = false;
        slots[i].entry_time = 0;
        slots[i].car_id = 0;
    }
    printf("System initialized.\n");

    while (1) {
        printf("\n1. Car Entry\n2. Car Exit\n3. Reset System\n4. Display Status\n5. Exit\nChoice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        if (choice == 1) {
            if (current_count == MAX_CARS) {
                printf("Entry denied: Parking full!\n");
            } else {
                for (int i = 0; i < MAX_CARS; i++) {
                    if (!slots[i].occupied) {
                        slots[i].occupied = true;
                        slots[i].entry_time = time(NULL);
                        slots[i].car_id = next_car_id++;
                        current_count++;
                        printf("Car %d entered at slot %d, time %ld\n", 
                                slots[i].car_id, i + 1, slots[i].entry_time);
                        break;
                    }
                }
            }
        } else if (choice == 2) {
            if (current_count == 0) {
                printf("Exit denied: Parking empty!\n");
            } else {
                for (int i = 0; i < MAX_CARS; i++) {
                    if (slots[i].occupied) {
                        time_t now = time(NULL);
                        double time_spent = difftime(now, slots[i].entry_time);
                        double cost = time_spent * COST_PER_UNIT;

                        printf("Car %d exited from slot %d. Time: %.0f sec, Cost: %.2f LE\n",
                                slots[i].car_id, i + 1, time_spent, cost);

                        total_time_spent += time_spent;
                        cars_served++;
                        current_count--;
                        slots[i].occupied = false;
                        break;
                    }
                }
            }
        } else if (choice == 3) {
            for (int i = 0; i < MAX_CARS; i++) {
                slots[i].occupied = false;
                slots[i].entry_time = 0;
                slots[i].car_id = 0;
            }
         
            printf("System reset.\n");
        } else if (choice == 4) {
            printf("\n--- Parking Status ---\n");
            printf("Cars in Garage: %d\n", current_count);
            printf("Total Cars Served: %d\n", cars_served);
            printf("Total Time Spent: %.0f sec\n", total_time_spent);
            if (cars_served > 0) {
                printf("Avg Cost: %.2f LE\n", (total_time_spent / cars_served) * COST_PER_UNIT);
            } else {
                printf("Avg Cost: 0.00 LE\n");
            }

            printf("Occupancy: ");
            for (int i = 0; i < MAX_CARS; i++) {
                printf("%d:%s ", i + 1, slots[i].occupied ? "OCC" : "EMP");
            }
            printf("\n----------------------\n");
        } else if (choice == 5) {
            break;
        } else {
            printf("Invalid choice. Please select 1-5.\n");
        }
    }

    return 0;
}