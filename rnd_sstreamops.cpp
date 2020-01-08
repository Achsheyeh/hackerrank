#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
 stringstream ss(str);
 vector<int> int_vec;
 int intvar; 
 char delim;
 do {
   ss >> intvar; 
   int_vec.push_back(intvar);
   if (ss.eof())
     break;
   ss >> delim;
 }while(true);
 return int_vec;  
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}
