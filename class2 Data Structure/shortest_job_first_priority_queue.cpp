// https://www.geeksforgeeks.org/implementation-of-non-preemptive-shortest-job-first-using-priority-queue/

// C++ implementation of SJF
#include <bits/stdc++.h>
using namespace std;

// number of process
#define SIZE 4

// Structure to store the
// process information
typedef struct proinfo {
    string pname; // process name
    int atime; // arrival time
    int btime; // burst time
} proinfo;

// This structure maintains the
// wait queue, using burst
// time to compare.
typedef struct cmpBtime {
    int operator()(const proinfo& a,
                   const proinfo& b)
    {
        return a.btime > b.btime;
    }
} cmpBtime;

// This function schedules the
// process according to the SJF
// scheduling algorithm.
void sjfNonpremetive(proinfo* arr)
{
    // Used to sort the processes
    // according to arrival time
    int index = 0;
    for (int i = 0; i < SIZE - 1; i++) {
        index = i;
        for (int j = i + 1; j < SIZE; j++) {
            if (arr[j].atime
                < arr[index].atime) {
                index = j;
            }
        }
        swap(arr[i], arr[index]); // sort by O(N^2)
    }

    // ctime stores the current run time
    int ctime = arr[0].atime;

    // priority queue, wait, is used
    // to store all the processes that
    // arrive <= ctime (current run time)
    // this is a minimum priority queue
    // that arranges values according to
    // the burst time of the processes.
    priority_queue<proinfo, vector<proinfo>,
                   cmpBtime>
        wait;

    int temp = arr[0].atime;

    // The first process is
    // pushed in the wait queue.
    wait.push(arr[0]);
    arr[0].atime = -1;

    cout << "Process id"
         << "\t";
    cout << "Arrival time"
         << "\t";
    cout << "Burst time"
         << "\t";

    cout << endl;

    while (!wait.empty()) {

        cout << "\t";
        cout << wait.top().pname << "\t\t";
        cout << wait.top().atime << "\t\t";
        cout << wait.top().btime << "\t\t";
        cout << endl;

        // ctime is increased with
        // the burst time of the
        // currently executed process.
        ctime += wait.top().btime;

        // The executed process is
        // removed from the wait queue.
        wait.pop();

        for (int i = 0; i < SIZE; i++) {
            if (arr[i].atime <= ctime
                && arr[i].atime != -1) {
                wait.push(arr[i]);

                // When the process once
                // enters the wait queue
                // its arrival time is
                // assigned to -1 so that
                // it doesn't enter again
                // int the wait queue.
                arr[i].atime = -1;
            }
        }
    }
}

// Driver Code
int main()
{
    // an array of process info structures.
    proinfo arr[SIZE];

    arr[0] = { "p1", 4, 3 };
    arr[1] = { "p2", 0, 8 };
    arr[2] = { "p3", 5, 4 };
    arr[3] = { "p4", 9, 2 };

    cout << "Process scheduling ";
    cout << "according to SJF is: \n"
         << endl;

    sjfNonpremetive(arr);
}
