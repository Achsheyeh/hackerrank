#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <exception>
using namespace std;


int main() {
    int n, q;
    cin >> n >> q;
    const int max_inp_lmt = pow(10,5); 
    if (!(1 < n < max_inp_lmt)) 
      exit(-1);
    if (!(1 < q < max_inp_lmt)) 
      exit(-1);
  
    vector<vector<int> *> parent;
    vector<int>* vec_int_ptr;
    int chldArry_elmnt_cnt;
    int vec_element, tot_element_cnt = 0;
    for (int arr_counter = 0; arr_counter < n; ++arr_counter){
      cin >> chldArry_elmnt_cnt;
      if(!(1 < chldArry_elmnt_cnt < (3*max_inp_lmt)))
        exit(-1);
      vec_int_ptr = new vector<int>;
      
      for (int chldArray_cntr =0 ; chldArray_cntr < chldArry_elmnt_cnt; ++chldArray_cntr) {
        cin >> vec_element; 
        vec_int_ptr->push_back(vec_element);
      }
      parent.push_back(vec_int_ptr);
      tot_element_cnt += chldArry_elmnt_cnt;
    }

    if (!(n < tot_element_cnt < (3*max_inp_lmt)))
      exit(-1);

    int array_pos, array_element_pos;
    vector<int> output;
    for (int qry_cntr = 0; qry_cntr < q; ++qry_cntr) {
      cin >> array_pos >> array_element_pos;
      try {
       output.push_back(parent[array_pos]->at(array_element_pos));
     } catch (exception& e) {
       cout << "Exception while fetching element at " << array_pos << array_element_pos << endl;
     } 
    } 
    for (auto element : output)
      cout << element << endl;
    
    for (auto element : parent)  
      delete (element);
   
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
