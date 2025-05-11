#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_CARS 3
#define COST_PER_UNIT 1.0

typedef struct {
    bool occupied;
    time_t entry_time;
    int car_id;
} ParkingSlot;

void initializeSlots(ParkingSlot slots[]);
void handleCarEntry(ParkingSlot slots[], int *current_count, int *next_car_id);
void handleCarExit(ParkingSlot slots[], int *current_count, int *cars_served, double *total_time_spent);
void resetSystem(ParkingSlot slots[], int *current_count, int *cars_served, double *total_time_spent);
void displayStatus(ParkingSlot slots[], int current_count, int cars_served, double total_time_spent);

int main() {
    ParkingSlot slots[MAX_CARS];
    int current_count = 0;
    int cars_served = 0;
    double total_time_spent = 0.0;
    int next_car_id = 1;
    int choice;

    initializeSlots(slots);
    printf("System initialized.\n");

    while (1) {
        printf("\n1. Car Entry\n2. Car Exit\n3. Reset System\n4. Display Status\n5. Exit\nChoice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                handleCarEntry(slots, &current_count, &next_car_id);
                break;
            case 2:
                handleCarExit(slots, &current_count, &cars_served, &total_time_spent);
                break;
            case 3:
                resetSystem(slots, &current_count, &cars_served, &total_time_spent);
                break;
            case 4:
                displayStatus(slots, current_count, cars_served, total_time_spent);
                break;
            case 5:
                printf("Exiting system. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please select 1-5.\n");
        }
    }
}

void initializeSlots(ParkingSlot slots[]) {
    for (int i = 0; i < MAX_CARS; i++) {
        slots[i].occupied = false;
        slots[i].entry_time = 0;
        slots[i].car_id = 0;
    }
}

void handleCarEntry(ParkingSlot slots[], int *current_count, int *next_car_id) {
    if (*current_count == MAX_CARS) {
        printf("Entry denied: Parking full!\n");
        return;
    }

    for (int i = 0; i < MAX_CARS; i++) {
        if (!slots[i].occupied) {
            slots[i].occupied = true;
            slots[i].entry_time = time(NULL);
            slots[i].car_id = (*next_car_id)++;
            (*current_count)++;

            char time_buf[26];
            strftime(time_buf, sizeof(time_buf), "%H:%M:%S", localtime(&slots[i].entry_time));
            printf("Car %d entered at slot %d, time %s\n", 
                   slots[i].car_id, i + 1, time_buf);
            break;
        }
    }
}

void handleCarExit(ParkingSlot slots[], int *current_count, int *cars_served, double *total_time_spent) {
    if (*current_count == 0) {
        printf("Exit denied: Parking empty!\n");
        return;
    }

    for (int i = 0; i < MAX_CARS; i++) {
        if (slots[i].occupied) {
            time_t now = time(NULL);
            double time_spent = difftime(now, slots[i].entry_time);
            double cost = time_spent * COST_PER_UNIT;

            printf("Car %d exited from slot %d. Time: %.0f sec, Cost: %.2f LE\n",
                   slots[i].car_id, i + 1, time_spent, cost);

            *total_time_spent += time_spent;
            (*cars_served)++;
            (*current_count)--;
            slots[i].occupied = false;
            break;
        }
    }
}

void resetSystem(ParkingSlot slots[], int *current_count, int *cars_served, double *total_time_spent) {
    initializeSlots(slots);
    *current_count = 0;
    *cars_served = 0;
    *total_time_spent = 0.0;
    printf("System reset.\n");
}

void displayStatus(ParkingSlot slots[], int current_count, int cars_served, double total_time_spent) {
    printf("\n--- Parking Status ---\n");
    printf("Cars in Garage: %d\n", current_count);
    printf("Total Cars Served: %d\n", cars_served);
    printf("Total Time Spent: %.0f sec\n", total_time_spent);

    if (cars_served > 0)
        printf("Avg Cost: %.2f LE\n", (total_time_spent / cars_served) * COST_PER_UNIT);
    else
        printf("Avg Cost: 0.00 LE\n");

    
}