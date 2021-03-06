#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

/*
$1 = std::vector of length 100000000, capacity 134217728 = {1232077670, 156240823063214118, -6864707917150921562, 
  -3955525475247216730, 6169549535071242662, 8479579632999273894, 1082114831359008166, -2874329871176331866, 
  273594413031468454, -5768148121874698842, -8752777617250783834, 8780569153840999846, -9193617893788226138, 
  -4080761428793889370, -8909549955540587098, -298419439591232090, 7399662940887444902, 3121892587183009190, 
  -7580303010346570330, 5300620776049208742, 7065291205314604454, 409428391754198438, -2051993482209792602, 
  1791094410540740006, 8361498340700450214, 8492158516150660518, -5303377505624265306, -6050010312508707418, 
  -7776916323204338266, -3733639831646376538, -5586992265106559578, -3453893871330136666, -4303926173324808794, 
  1186336431026990502, -861213154880262746, 5630385958881324454, 1935290216763354534, 8374324978135854502, 
  5233847090323910054, 6332637438472088998, -2523656044379902554, -4618744664781492826, 6060556689109151142, 
  -4591863804505625178, -1375730720609669722, 4212110517050273190, -7044636751562281562, -7787730690078413402, 
  3462261179093085606, -5418837286081532506, 8740479942371306918, 309741439933738406, -1851986381204099674, 
  -987295252748964442, -5022520518872928858, 7659616031802387878, -8481285032693469786, 5353773022588693926, 
  -3869599014266081882, -3869599014266081882, -3869599014266081882, -3869599014266081882, -3869599014266081882, 
  -3869599014266081882, -3869599014266081882, -3869599014266081882, -3869599014266081882, -3869599014266081882, 
  -3869599014266081882, -3869599014266081882, -3869599014266081882, -3869599014266081882, -3869599014266081882, 
  -3869599014266081882, -3869599014266081882, -3869599014266081882, -3869

*/

inline void check_limit(int val, long max_lim) {
   if (!(0 < val < max_lim)) 
     exit(1);
}
int main() {

    long  N, S, P, Q;
    cin >> N >> S >> P >> Q;
    
    if ( N < 1 || N > 100000000)
      exit(1);
  
    unsigned long max_lim  = pow (2, 31);
    unsigned long qmod = Q % max_lim;
    check_limit(S, max_lim);
    check_limit(P, max_lim);
    check_limit(Q, max_lim);

    //set<unsigned long long, less<unsigned long long>> a;
 
    //a.push_back(S % max_lim);
    //unsigned long long next = a[0];
    unsigned long long temp = S % max_lim;
    unsigned long long new_temp = temp;
    unsigned long long count = 0;
    //a.insert(temp); 
    for (int i = 1; i< N; i++) {
       temp = ((temp * P) + Q) % max_lim;
       if (new_temp == temp)
          break; 
       cout << max_lim << "  " << new_temp << " " << temp << endl;
       ++count;
       if (i == 31)
          break;
       /*if (temp < 0) {
          --i;
       } */
      // a.insert(temp);
       //cout << P << "  " << Q  << "  " << (a[i-1] * P) << "  " << (Q % max_lim) << " " << a[i] << endl;
    }
    
   
//2 , 1, 5 , 1000000000

// 11 , 23, 47, 95 , 191, 383, 767, 1535 
// 1 ,  3, 2 , 0, 1, 3, 2, 0
// 0   1  2 3 4 
  
/*    for (auto x : a) 
      cout << x << " ";
    cout << endl;
*/

    cout << count << endl;
    /*sort (a.begin(), a.end());
    auto dup_pos = unique(a.begin(), a.end());
    a.resize(distance(a.begin(), dup_pos));
    unsigned cntr = 0;
    for (auto item : a)
      cout << cntr++ << item << endl;

    */
  
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

