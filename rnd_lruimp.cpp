#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
#include <fstream>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){
   };
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){
   };
};

class Cache{
   
   protected: 
   int cp;  //capacity
   Node* head; // double linked list head pointer
   Node* tail; // double linked list tail pointer
   map<int, Node*> mp; //map the key to the node in the linked list
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

   public:
   ~Cache() {
     Node *ref;
     while (head) {
       ref = head->next; 
       delete head;
       head = ref;
     }
     head = tail = nullptr;
   }

};

class LRUCache : public Cache {

   public:

   LRUCache(int capacity) { 
      cp = capacity;
      head = nullptr; 
      tail = nullptr;
     //mp = new map_int_nptr(); 
   };

   void set(int key, int value){ //set function 

     Node *fPtr = mp[key];
    
     if(!fPtr) { // if key not found
       if (!head) {
           head = new Node(key, value);
           tail = head;
           if (tail)
             mp[key] = tail;
       } else { // if list is existing
           //cout << "map size is " << mp.size() << "  " << cp << " tail key is " << tail->key << endl;
           if (mp.size() == cp + 1) {
            /* if (tail == head) {
                delete tail;
                tail = head = nullptr;
             }
             else { 
               dPtr= tail->prev; 
               mp.erase(key);
               delete tail;          
               tail = dPtr;
             }*/
             mp.erase(tail->key);
             tail->key = key; 
             tail->value = value;
             mp[key] = tail;
           }
           else { // if capacity is there , then add at head
             head = new Node(nullptr, head, key, value); // tail always points to new Node 
             mp[key] = head;
           }
       }
     }
     else { // if key exists
       /*if(head != fPtr) {
         if(fPtr == tail)
           tail = fPtr->prev;
         fPtr->prev->next = fPtr->next; // linking fptr prev and fptr next
         fPtr->prev = nullptr;           
         fPtr->next = head;
         head = fPtr;
       }
       if (head->value != value) // to set new value to existing key
         head->value = value;*/
       if (fPtr->value != value)
         fPtr->value = value;
     }
     fPtr = nullptr;

    if (!mp.empty()) {
       for (auto p : mp) {
          cout << mp.size() << "  " << p.first  << endl;
       }
     }
   }
   int get(int key) { //get function
     if(mp.find(key) != mp.end())
       return mp[key]->value; 
     else 
       return -1;
   }
};

int main() {
   int n, capacity,i;
   ifstream ifs("input01.txt");
   //cin >> n >> capacity;
   ifs >> n >> capacity;
   assert(1<=n && n<=500000);
   assert(1<=capacity && capacity<=1000);
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      //cin.ignore();
      ifs >> command;
      if(command == "get") {
         int key;
         ifs >> key;
         assert(1<=key && key<=20);
         cout << " get " << key << endl;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         //cin >> key >> value;
         ifs >> key >> value;
         assert(1<=key && key<=20);
         assert(1<=value && value<=2000);
         cout << " set " << key <<  " " << value << endl;
         l.set(key,value);
      }
   }
   return 0;
}
