#include <iostream>
#include <map>

using namespace std;

int main()
{
  struct node{
    int *dp;
  };
  map<int , node*> mp;

  int i =3;
  struct node a;
  a.dp = &i; 
 
  mp.insert(pair<int, node*>(i, &a));
  cout << *((mp[i])->dp) << endl;
  return(0);
}
