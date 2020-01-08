#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// to display last string from lexicographical order

int getParentProcessNum(int pid) {

  /*
    starting 1
    generate cpid from last pid from stack till last pid + current top value 
    if generated cpid matches pid , break from loop

  */
  int cpid, start_pid; 
  queue<int> pids;
  pids.push(1);
  bool pid_found = false; 
  while (1) {
    cpid = pids.front(); 
    start_pid = pids.back();
    pids.pop();
    for (int npid = start_pid + 1; npid <= (start_pid + cpid) ; ++npid) {
      if (npid == pid) {
        pid_found = true;
        break;
      }
      pids.push(npid);
    }
   if (pid_found)
    break;
  }
  for (auto it= pids.front();  !pids.empty(); pids.pop(),it=pids.front())
    cout << it << " ";
  /*for (auto it= pids.front();  !pids.empty(); pids.pop(),it=pids.front())
    cout << it;*/
  cout << endl;
  return cpid; 
}

int main() { 

  int pid;
  cin >> pid;
  cout << getParentProcessNum(pid) << endl;
  return(0);
}
