#include <iostream>
#include <deque> 
#include <vector>
#include <cmath>
#include <queue>
using namespace std;


void printKMax(int arr[], int n, int k) {

  //cout << n << " " << k << endl;
  deque<int> maxQ(k); // leaving 0 index for faster processing
  //maxQ.push_front(0); 
  int idx = 0, heap_pos;
  int qidx=0, j = 0;
  // Populating maxpq initially just to avoid extra checks 
  if (k == 1) {
    for (idx = 0; idx < n ;++idx)
      cout << arr[idx] << " ";
    cout << endl;
    return;
  }
 
  int parent_pos = -1;
  vector<int> pos_in_Q(n);

  while (j < k ) { // iterating for parent array
    maxQ[qidx] = j; 
    heap_pos = qidx;
    pos_in_Q[j] = qidx; 
  /*  for (int pidx =1 ; pidx <= qidx; pidx++) 
      cout << arr[maxQ[pidx]] << " " ;
    cout << endl;*/
    parent_pos = ceil(heap_pos/2.0) - 1;
    while (parent_pos >= 0) { //heapify
      if (arr[maxQ[heap_pos]] > arr[maxQ[parent_pos]]) {
        auto t = maxQ[heap_pos];
        maxQ[heap_pos] = maxQ[parent_pos];
        maxQ[parent_pos] = t;
        pos_in_Q[maxQ[heap_pos]] = heap_pos;  
        pos_in_Q[maxQ[parent_pos]] = parent_pos;
        heap_pos = parent_pos;
      }
      else
        break;
      parent_pos = ceil(heap_pos/2.0) - 1;
    }
    ++qidx;
    ++j;
  }

  //cout  << arr[maxQ.front()] << " ";
  fprintf(stdout, "%d ", arr[maxQ.front()]);
   
//  maxQ.pop_front();  // recent max has been popped
  for(idx = k ; idx < n; ++idx) {

    int pos_to_del = pos_in_Q[idx - k];

    //identify idx- k and remove the element from maxQ
   
    maxQ[pos_to_del] = maxQ[k-1]; //placing 
    pos_in_Q[maxQ[pos_to_del]] = pos_to_del;
    heap_pos = pos_to_del;
  
    parent_pos = ceil(heap_pos/2.0) -1;
    bool adjusted_at_parent_loc = false; 
    while(parent_pos >=0 && arr[maxQ[heap_pos]] > arr[maxQ[parent_pos]]) {
        adjusted_at_parent_loc = true;
        auto t = maxQ[heap_pos];
        maxQ[heap_pos] = maxQ[parent_pos];
        maxQ[parent_pos] = t;
        pos_in_Q[maxQ[heap_pos]] = heap_pos;  
        pos_in_Q[maxQ[parent_pos]] = parent_pos;
        heap_pos = parent_pos;
        parent_pos = ceil(heap_pos/2.0) -1;
    }
    if (!adjusted_at_parent_loc) {
      int child_pos = 2*heap_pos + 1;
     
      while(child_pos < k-1) {
        if (((child_pos + 1) < k-1)  && (arr[maxQ[child_pos]] < arr[maxQ[child_pos + 1]]))
          child_pos += 1;
        if(arr[maxQ[child_pos]] > arr[maxQ[heap_pos]]) {
          auto t = maxQ[heap_pos];
          maxQ[heap_pos] = maxQ[child_pos];
          maxQ[child_pos] = t;
          pos_in_Q[maxQ[heap_pos]] = heap_pos;  
	  pos_in_Q[maxQ[child_pos]] = child_pos;
          heap_pos = child_pos;
          child_pos = 2*heap_pos + 1;
        } else
        break;
      }
    }

    maxQ[k-1] = idx;
    pos_in_Q[idx%k] = k-1; 
    heap_pos = k-1;
  
    parent_pos = ceil(heap_pos/2.0) -1;
    while(parent_pos >=0 && arr[maxQ[heap_pos]] > arr[maxQ[parent_pos]]) {
        auto t = maxQ[heap_pos];
        maxQ[heap_pos] = maxQ[parent_pos];
        maxQ[parent_pos] = t;
        pos_in_Q[maxQ[heap_pos]] = heap_pos;  
        pos_in_Q[maxQ[parent_pos]] = parent_pos;
        heap_pos = parent_pos;
        parent_pos = ceil(heap_pos/2.0) -1;
    }
    // put idx into maxQ 
    
   
    //cout << " hello " << nmaxQ.size() << endl; 
     fprintf(stdout, "%d ", arr[maxQ.front()]);
  }
  fprintf(stdout, "\n");
}

int main(){
  
	int t;
	//cin >> t;
        scanf("%d", &t);
      
        int idx = 0;

	while(t>0) {
		int n,k;
        scanf("%d %d", &n, &k);
        //cin >> n >> k; 
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
          scanf("%d", &arr[i]);
      //		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
        ++idx;
  	}
       
  	return 0;
}
