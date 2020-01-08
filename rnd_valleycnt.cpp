#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
   /*
    stack U
    if current depth == 0 and next is D , dont increment
    else
       increment valley count
    
    current depth += (current char)

  */
    int current_depth = 0;
    int valley_count=0;
    bool valley_flag = false;
    for (size_t idx = 0; idx < s.length(); ++idx ) {
      if (s[idx] == 'U')
        current_depth += 1;
      else
        current_depth -= 1;
      
      if (current_depth  < 0)
         valley_flag = true;

      if (valley_flag && current_depth == 0) {
          valley_count++;
          valley_flag = false;
      }
    }
  return valley_count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}

