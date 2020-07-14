#include <bits/stdc++.h>
 
using namespace std;

// Complete the candies function below.

// if decreasing , increming D
// if increasing , proceed with incrementing
// if equal, put 1 for the right side rating 
//54276 - 2 12221 - 1 12221 - 1 2 67417 - 2 3 12279 - 1 1 12279 - 2 2 5811 - 1  1 88620 - 1 2 88620 - 2 1

long candies(int n, vector<int> arr) {
   
   vector<long> c(n, 1);
  
  
   for (int i = 0; i < n-1; i++)
      if (arr[i + 1] > arr[i]) 
        c[i+1] = c[i] + 1;
   for (int i = n - 1; i > 0 ; i--) 
      if (arr[i-1]  > arr[i] && c[i-1] <= c[i]) 
        c[i-1] = c[i] + 1;
 
      
   long res = accumulate(c.begin(), c.end(), 0L);
   cout << res << endl;
   return res;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    long result = candies(n, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
