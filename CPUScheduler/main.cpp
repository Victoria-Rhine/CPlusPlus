#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

// global variable to represent minimum burst time
const int MIN_BURST = 2;

// global variable to represent max arrival time
const int MAX_ARRIVAL_TIME = 20;

// global constant to set number of processes
const int NUM_PROCESSES = 10;

// ****C++ program to implement Shortest Job First Scheduling (Preemptive)****
struct Process
{
    int processID; // Process ID
    int burstTime; // Burst Time
    int arrivalTime; // Arrival Time
};

// Function to find the waiting time for all processes
void findWaitingTime(Process proc[], int wt[])
{
    int rt[NUM_PROCESSES];

    // Copy the burst time into rt[]
    for (int i = 0; i < NUM_PROCESSES; i++)
        rt[i] = proc[i].burstTime;

    int complete = 0, t = 0, minm = INT_MAX;
    int shortest = 0, finish_time;
    bool check = false;

    // Process until all processes gets completed
    while (complete != NUM_PROCESSES)
    {
        // Find process with minimum remaining time among the
        // processes that arrives till the current time`
        for (int j = 0; j < NUM_PROCESSES; j++)
        {
            if ((proc[j].arrivalTime <= t) &&
                    (rt[j] < minm) && rt[j] > 0)
            {
                minm = rt[j];
                shortest = j;
                check = true;
            }
        }

        if (check == false)
        {
            t++;
            continue;
        }

        // Reduce remaining time by one
        rt[shortest]--;

        // Update minimum
        minm = rt[shortest];
        if (minm == 0)
            minm = INT_MAX;

        // If a process gets completely executed
        if (rt[shortest] == 0)
        {
            // Increment complete
            complete++;
            check = false;

            // Find finish time of current process
            finish_time = t + 1;

            // Calculate waiting time
            wt[shortest] = finish_time -
                    proc[shortest].burstTime -
                    proc[shortest].arrivalTime;

            if (wt[shortest] < 0)
                wt[shortest] = 0;
        }
        // Increment time
        t++;
    }
}

// Function to calculate turn around time
void findTurnAroundTime(Process proc[], int wt[], int tat[])
{
    // calculating turnaround time by adding bt[i] + wt[i]
    for (int i = 0; i < NUM_PROCESSES; i++)
        tat[i] = proc[i].burstTime + wt[i];
}

// Function to calculate running time
void findRunningTime(int wt[], int tat[], int rt[])
{
    // calculating running time by subtracting wt[i] - tat[i]
    for (int i = 0; i < NUM_PROCESSES; i++)
        rt[i] = tat[i] - wt[i];
}

// Function to calculate average job time
int findAverageJobTime(int wt[], int tat[], int rt[])
{
    int total_averageJobTime = 0;
    findRunningTime(wt, tat, rt);
    for (int i = 0; i < NUM_PROCESSES; i++)
        total_averageJobTime = total_averageJobTime + rt[i];

    return total_averageJobTime / NUM_PROCESSES;
}

// Function to calculate average times
void findAllTimes(Process proc[])
{
    int wt[NUM_PROCESSES], tat[NUM_PROCESSES], total_wt = 0,
            total_tat = 0;

    // Function to find waiting time of all processes
    findWaitingTime(proc, wt);

    // Function to find turn around time for all processes
    findTurnAroundTime(proc, wt, tat);

    // Display processes along with all details
    std::cout << "Processes "
              << " Arrival Time "
              << " Burst time "
              << " Waiting time "
              << " Turn around time\n";

    // Calculate total waiting time and total turnaround time
    for (int i = 0; i < NUM_PROCESSES; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        std::cout << " " << proc[i].processID << "\t\t"
                  << proc[i].arrivalTime << "\t    "
                  << proc[i].burstTime << "\t\t " << wt[i]
                     << "\t\t " << tat[i] << std::endl;
    }

    int rt[NUM_PROCESSES];
    int total_art = findAverageJobTime(wt, tat, rt);

    std::cout << "\nAverage waiting time = "
              << static_cast<float>(total_wt) / NUM_PROCESSES;
    std::cout << "\nAverage turn around time = "
              << static_cast<float>(total_tat) / NUM_PROCESSES;
    std::cout << "\nAverage job time = "
              << static_cast<float>(total_art) / NUM_PROCESSES << std::endl;
}

// *****END Shortest Job First Scheduling (Preemptive)*****

// *****C++ program to implement priority scheduling*****
struct PriorityProcess
{
    int pid; // Process ID
    int bt; // CPU Burst time required
    int priority; // Priority of this process
};

// Function to sort the Process acc. to priority
bool comparison(PriorityProcess a, PriorityProcess b)
{
    return (a.priority > b.priority);
}

// Function to find the waiting time for all processes
void findWaitTime(PriorityProcess proc[], int wt[])
{
    // waiting time for first process is 0
    wt[0] = 0;

    // calculating waiting time
    for (int i = 1; i < NUM_PROCESSES ; i++ )
        wt[i] = proc[i-1].bt + wt[i-1] ;
}

// Function to calculate turn around time
void findTAT( PriorityProcess proc[], int wt[], int tat[])
{
    // calculating turnaround time by adding bt[i] + wt[i]
    for (int i = 0; i < NUM_PROCESSES ; i++)
        tat[i] = proc[i].bt + wt[i];
}

// Function to calculate running time
void findRunTime(int wt[], int tat[], int rt[])
{
    // calculating running time by subtracting wt[i] - tat[i]
    for (int i = 0; i < NUM_PROCESSES; i++)
        rt[i] = tat[i] - wt[i];
}

// Function to calculate average job time
int findAvgJobTime(int wt[], int tat[], int rt[])
{
    int total_averageJobTime = 0;
    findRunTime(wt, tat, rt);
    for (int i = 0; i < NUM_PROCESSES; i++)
        total_averageJobTime = total_averageJobTime + rt[i];

    return total_averageJobTime / NUM_PROCESSES;
}

//Function to calculate average time
void findavgTime(PriorityProcess proc[])
{
    int wt[NUM_PROCESSES], tat[NUM_PROCESSES], total_wt = 0, total_tat = 0;

    //Function to find waiting time of all processes
    findWaitTime(proc, wt);

    //Function to find turn around time for all processes
    findTAT(proc, wt, tat);

    //Display processes along with all details
    std::cout << "\nProcesses "<< " Burst time "
              << " Waiting time " << " Turn around time " << " Priority\n";

    // Calculate total waiting time and total turn around time
    for (int i = 0; i< NUM_PROCESSES; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        std::cout << " " << proc[i].pid << "\t\t"
                  << proc[i].bt << "\t " << wt[i]
                     << "\t\t " << tat[i]
                        << "\t\t " << proc[i].priority << std::endl;
    }

    int rt[NUM_PROCESSES];
    int total_art = findAvgJobTime(wt, tat, rt);

    std::cout << "\nAverage waiting time = "
              << static_cast<float>(total_wt) / NUM_PROCESSES;
    std::cout << "\nAverage turn around time = "
              << static_cast<float>(total_tat) / NUM_PROCESSES;
    std::cout << "\nAverage job time = "
              << static_cast<float>(total_art) / NUM_PROCESSES << std::endl;
}

void priorityScheduling(PriorityProcess proc[])
{
    // Sort processes by priority
    std::sort(proc, proc + NUM_PROCESSES, comparison);

    std::cout<< "Order in which processes gets executed \n";
    for (int i = 0 ; i < NUM_PROCESSES; i++)
        std::cout << proc[i].pid <<" " ;

    findavgTime(proc);
}

// function to generate processes
void generateJobs(Process proc[])
{
    int randBurstTime = 0;
    int randArrivalTime = 0;
    srand(static_cast<unsigned int>(time(nullptr)));

    for (int i = 0; i < NUM_PROCESSES; i++)
    {
        // randomly generates burst time between 0 - 40
        randBurstTime = rand() % 40 + 0;
        // randomly generates arrival time between 0 - 20
        randArrivalTime = rand() % MAX_ARRIVAL_TIME + 0;
        proc[i].processID = i;
        // set burst time using rand function + min burst of 2
        proc[i].burstTime = randBurstTime + MIN_BURST;
        // set arrival time using rand function
        proc[i].arrivalTime = randArrivalTime;
    }
}

// Driver code
int main()
{
    std::cout << "\t-----Simulating Shortest Job First (Preemptive)-----\n" << std::endl;

    Process proc[NUM_PROCESSES];

    generateJobs(proc);
    findAllTimes(proc);

    std::cout << "\n\t-----Simulating Priority Scheduling-----\n" << std::endl;

    PriorityProcess proc2[NUM_PROCESSES];

    // copying process id and burst time used in SJF
    // instead of arrival time processes use priority number
    for (int i = 0; i < NUM_PROCESSES; i++)
    {
        proc2[i].pid = proc[i].processID;
        proc2[i].bt = proc[i].burstTime;
        proc2[i].priority = i;
    }

    priorityScheduling(proc2);

    // simulate CPU usage
    int CPU = 0;
    for (int i = 0; i < NUM_PROCESSES; i++)
    {
        CPU += proc[i].burstTime;
    }

    std::cout << "\nCPU utilization: "  << CPU
              << " ms of CPU time." << std::endl;

    return 0;
}
