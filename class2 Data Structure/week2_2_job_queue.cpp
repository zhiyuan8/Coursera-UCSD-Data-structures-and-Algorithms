// refer from
// https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/

// C++ program to demonstrate min heap for user-defined struct
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Job{
    public:
        int proc_ID; // the ID of processor which takes the job
        long long end_time; // the absolute time when the job is finished
};
struct Comp{
    bool operator()(const Job& a, const Job& b){ // min heap. By default, it is max heap.
        if (a.end_time == b.end_time){
          return a.proc_ID > b.proc_ID;   // when end_time is same, choose the min ID
        }
        else{
          return a.end_time > b.end_time;  // when there is not a tie, choose the shorter end_time
        }
    }
};

void DisplayQueue(priority_queue<Job,vector<Job>,Comp> pqueue){ // priority queue does not have iterator!!!
    while (!pqueue.empty()) { // use emplty()
        cout << "ID: " << pqueue.top().proc_ID << " end_time: " << pqueue.top().end_time << std::endl;
        pqueue.pop();
  }
}

int main(){
    // read number of processors and jobs_
    int num_proc, num_job, time;
    cin >> num_proc >> num_job;
    priority_queue< Job, vector<Job>, Comp> pqueue;

    // read in proc_time and initialize queue
    Job job; // instantiation
    vector<int> proc_time_vector; // save processing time
    long long current_time = 0;

    for (size_t i = 0; i < num_job; i++) {
      cin >> time;
      proc_time_vector.push_back(time);

      if (i < num_proc) { // take the jobs at time 0
        job.proc_ID = i;
        job.end_time = proc_time_vector[i] + current_time;
        pqueue.push(job); // priority_queue uses "push", not "push_back"
        cout << i << ' ' << current_time << endl; // print out processor ID and time 0
      }
    }

    //DisplayQueue(pqueue); // print JobQueue

    // pop the root of heap, then add a new job
    // [important!!!] assign priority of node to be current_time + proc_time
    for (size_t i = num_proc; i < num_job; i++) {
      Job finished_job = pqueue.top(); // get the fristly finished job
      current_time = finished_job.end_time; // get the current time
      cout << finished_job.proc_ID << ' ' << current_time << endl; // print out processor ID and time 0

      pqueue.pop(); // delete the top of heap
      job.proc_ID = finished_job.proc_ID; // proceed ith job
      job.end_time = proc_time_vector[i] + current_time; // get time when ith job be done
      pqueue.push(job); // push to heap

    //DisplayQueue(pqueue); // print JobQueue to debug
    }

    return 0;
}
