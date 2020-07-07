
// Ex AbCdE A-B B-C C-D D-E , directed edge information
// take a char from first string
// convert both characters to capitals
// for each char in first str
// convert it , search for its position and put it to pos array and go to next pos
// if next pos - prev pos is with in range
// 

#include <bits/stdc++.h>
#include <cctype>
using namespace std;

string abbreviation(string a, string b) {
    int n,m;

    n=a.length();
    m=b.length();
    vector<vector<bool>> d(n+1, vector<bool>(m+1));

    d[0][0] = true;

    int count=0;

    for(int k=1;k<=n;k++){  // iterating over a
        int i=k-1;
        if(a[i]>=65&&a[i]<=90||count==1){  // if upper case character or count == 1
            count=1;
            d[k][0]=false;
        }else d[k][0]=true;
    }

    for(int k=1;k<=n;k++){  // for each char from a 
        int i=k-1;
        for(int l=1;l<=m;l++){ // for all char from b
            int j=l-1;
            if(a[i]==b[j]){ // if exact match
                d[k][l]=d[k-1][l-1]; // taking flag value from previous location and proceed with next i
                continue;
            }
            else {
                if(toupper(a[i])==b[j]){ // if matched after conversion
                    d[k][l]=d[k-1][l-1]|d[k-1][l];
                    continue;
                }
            }
            if(a[i]>=65&&a[i]<=90){ // if upper case character
                d[k][l]=false;
                continue;
            }
            else{
             d[k][l]=d[k-1][l]; // if lower case character // taking from prev row
             continue;
            }
        }
    }

    cout << "d[n][m] is " << boolalpha << d[n][m] << endl;
    if(d[n][m]) return "YES";
    else return "NO";
}

int main()
{

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviation(a, b);

        cout << result << "\n";
        getchar();
    }


    return 0;
}
