#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

// to display last string from lexicographical order

string upmostString(string& s) {
  string temp(s);
  sort(temp.begin(), temp.end());
  char upmost_char = temp[temp.size()-1];
  size_t pos = s.find(upmost_char);
  string upmost_str = s.substr(pos);
  return upmost_str; 
}

int main() { 

  string myStr;
  cin >> myStr;
  cout << upmostString(myStr) << endl;
  return(0);
}
