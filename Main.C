
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CARS      3
#define COST_PER_SEC  1.0   

typedef struct {
    bool   occupied;
    time_t entry_time;
    int    car_id;
} ParkingSlot;


void   initializeSlots  (ParkingSlot slots[]);
void   handleCarEntry   (ParkingSlot slots[], int *current_count, int *next_car_id);
void   handleCarExit    (ParkingSlot slots[], int *current_count,
                         int *cars_served, double *total_time_spent,
                         double *total_cost);
void   resetSystem      (ParkingSlot slots[], int *current_count,
                         int *cars_served, double *total_time_spent,
                         double *total_cost, int *next_car_id);
void   displayStatus    (const ParkingSlot slots[], int current_count,
                         int cars_served, double total_time_spent,
                         double total_cost);
int    selectOccupiedSlot(const ParkingSlot slots[]);   
void   flushInput       (void);


int main(void)
{
    ParkingSlot slots[MAX_CARS];
    int    current_count    = 0;
    int    cars_served      = 0;
    int    next_car_id      = 1;
    double total_time_spent = 0.0;
    double total_cost       = 0.0;   
    int    choice;

    initializeSlots(slots);
    printf(" Parking Management System \n");
    printf("System initialized. Max slots: %d\n", MAX_CARS);

    while (1) {
        printf("  1. Car Entry           \n");
        printf("  2. Car Exit            \n");
        printf("  3. Display Status      \n");
        printf("  4. Reset System        \n");
        printf("  5. Exit Program        \n");
        printf("Choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1-5.\n");
            flushInput();
            continue;
        }
        flushInput();   

        switch (choice) {
            case 1:
                handleCarEntry(slots, &current_count, &next_car_id);
                break;
            case 2:
                handleCarExit(slots, &current_count, &cars_served,
                              &total_time_spent, &total_cost);
                break;
            case 3:
                displayStatus(slots, current_count, cars_served,
                              total_time_spent, total_cost);
                break;
            case 4:
                resetSystem(slots, &current_count, &cars_served,
                            &total_time_spent, &total_cost, &next_car_id);
                break;
            case 5:
                printf("Exiting system. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please select 1-5.\n");
        }
    }
}


void flushInput(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

/* Format a time_t into HH:MM:SS in a caller-supplied buffer (thread-safe) */
static void format_time(time_t t, char *buf, size_t bufsz)
{
    struct tm tm_info;
#ifdef _WIN32
    localtime_s(&tm_info, &t);         
#else
    localtime_r(&t, &tm_info);          
#endif
    strftime(buf, bufsz, "%H:%M:%S", &tm_info);
}


void initializeSlots(ParkingSlot slots[])
{
    for (int i = 0; i < MAX_CARS; i++) {
        slots[i].occupied   = false;
        slots[i].entry_time = 0;
        slots[i].car_id     = 0;
    }
}

void handleCarEntry(ParkingSlot slots[], int *current_count, int *next_car_id)
{
    if (*current_count == MAX_CARS) {
        printf("Entry denied: Parking is full! (%d/%d slots occupied)\n",
               *current_count, MAX_CARS);
        return;
    }

    for (int i = 0; i < MAX_CARS; i++) {
        if (!slots[i].occupied) {
            slots[i].occupied   = true;
            slots[i].entry_time = time(NULL);
            slots[i].car_id     = (*next_car_id)++;
            (*current_count)++;

            char time_buf[32];
            format_time(slots[i].entry_time, time_buf, sizeof(time_buf));

            printf("Car #%d entered → Slot %d  |  Entry time: %s\n",
                   slots[i].car_id, i + 1, time_buf);
            printf("  Slots used: %d/%d\n", *current_count, MAX_CARS);
            break;
        }
    }
}

int selectOccupiedSlot(const ParkingSlot slots[])
{
    printf("\n  Occupied slots:\n");
    printf("  %-8s %-10s %-12s\n", "Slot", "Car ID", "Entry Time");
    printf("  %-8s %-10s %-12s\n", "----", "------", "----------");

    int occupied_count = 0;
    for (int i = 0; i < MAX_CARS; i++) {
        if (slots[i].occupied) {
            char time_buf[32];
            format_time(slots[i].entry_time, time_buf, sizeof(time_buf));
            printf("  %-8d %-10d %-12s\n", i + 1, slots[i].car_id, time_buf);
            occupied_count++;
        }
    }

    if (occupied_count == 0) {
        return -1;   /* caller already guards this, but be safe */
    }

    int slot_choice;
    printf("\n  Enter slot number to exit (1-%d): ", MAX_CARS);

    if (scanf("%d", &slot_choice) != 1) {
        flushInput();
        printf("  Invalid input.\n");
        return -1;
    }
    flushInput();

    /* Convert to 0-based index and validate */
    int idx = slot_choice - 1;
    if (idx < 0 || idx >= MAX_CARS) {
        printf("  Slot %d does not exist.\n", slot_choice);
        return -1;
    }
    if (!slots[idx].occupied) {
        printf("  Slot %d is already empty.\n", slot_choice);
        return -1;
    }

    return idx;
}

void handleCarExit(ParkingSlot slots[], int *current_count,
                   int *cars_served, double *total_time_spent,
                   double *total_cost)
{
    if (*current_count == 0) {
        printf("Exit denied: Parking is empty!\n");
        return;
    }

    /* BUG FIX: let the user SELECT which car/slot exits */
    int idx = selectOccupiedSlot(slots);
    if (idx == -1) {
        printf("  Exit cancelled.\n");
        return;
    }

    time_t now        = time(NULL);
    double time_spent = difftime(now, slots[idx].entry_time);
    double cost       = time_spent * COST_PER_SEC;

    char entry_buf[32], exit_buf[32];
    format_time(slots[idx].entry_time, entry_buf, sizeof(entry_buf));
    format_time(now, exit_buf, sizeof(exit_buf));

    printf("  Car ID   : #%d\n",     slots[idx].car_id);
    printf("  Slot     : %d\n",      idx + 1);
    printf("  Entry    : %s\n",      entry_buf);
    printf("  Exit     : %s\n",      exit_buf);
    printf("  Duration : %.0f sec\n", time_spent);
    printf("  Cost     : %.2f LE\n", cost);

    /* Update totals */
    *total_time_spent += time_spent;
    *total_cost       += cost;          /* BUG FIX: accumulate real cost */
    (*cars_served)++;
    (*current_count)--;

    /* Clear the slot */
    slots[idx].occupied   = false;
    slots[idx].entry_time = 0;
    slots[idx].car_id     = 0;
}

void resetSystem(ParkingSlot slots[], int *current_count, int *cars_served,
                 double *total_time_spent, double *total_cost, int *next_car_id)
{
    initializeSlots(slots);
    *current_count    = 0;
    *cars_served      = 0;
    *total_time_spent = 0.0;
    *total_cost       = 0.0;
    *next_car_id      = 1;    /* BUG FIX: was never reset before */
    printf("System reset. All slots cleared.\n");
}

void displayStatus(const ParkingSlot slots[], int current_count,
                   int cars_served, double total_time_spent, double total_cost)
{
    printf("\n Parking Status \n");
    printf("  Slots occupied : %d / %d\n", current_count, MAX_CARS);
    printf("  Cars served    : %d\n",       cars_served);
    printf("  Total duration : %.0f sec\n", total_time_spent);
    printf("  Total revenue  : %.2f LE\n",  total_cost);

    if (cars_served > 0) {
        printf("  Avg duration   : %.0f sec\n",
               total_time_spent / cars_served);
        printf("  Avg cost       : %.2f LE\n",
               total_cost / cars_served);        /* BUG FIX: use real total_cost */
    } else {
        printf("  Avg duration   : 0 sec\n");
        printf("  Avg cost       : 0.00 LE\n");
    }

    printf("\n  Slot Details\n");
    printf("  %-6s %-10s %-12s %-10s\n",
           "Slot", "Status", "Car ID", "Entry Time");
    printf("  %-6s %-10s %-12s %-10s\n",
           "----", "------", "------", "----------");

    for (int i = 0; i < MAX_CARS; i++) {
        if (slots[i].occupied) {
            char time_buf[32];
            format_time(slots[i].entry_time, time_buf, sizeof(time_buf));
            printf("  %-6d %-10s %-12d %-10s\n",
                   i + 1, "OCCUPIED", slots[i].car_id, time_buf);
        } else {
            printf("  %-6d %-10s %-12s %-10s\n",
                   i + 1, "FREE", "-", "-");
        }
    }
}