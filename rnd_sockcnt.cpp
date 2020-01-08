#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);

// Complete the sockMerchant function below.
int sockMerchant(int n, vector<int> ar) {
   sort (ar.begin(), ar.end());
   int sock_cnt =0, item_cnt =1;
   for (auto item : ar )
     cout << item << " ";
   cout << endl;
   //cout << "vector size is " << ar.size() << endl;
   int vec_size = ar.size();
   if (vec_size > 1)
   for (size_t idx = 0; idx <= (vec_size - 2) ; ++idx)  {
   //do {
       if (ar[idx] == ar[idx+1]) {
         ++item_cnt; 
       } else {
         sock_cnt += (item_cnt/2);
         item_cnt = 1;
       }
   }
   
   sock_cnt += (item_cnt/2); // for last iteration

   cout << sock_cnt << endl;
   return sock_cnt;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string ar_temp_temp;
    getline(cin, ar_temp_temp);

    vector<string> ar_temp = split_string(ar_temp_temp);

    vector<int> ar(n);

    for (int i = 0; i < n; i++) {
        int ar_item = stoi(ar_temp[i]);

        ar[i] = ar_item;
    }

    int result = sockMerchant(n, ar);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
