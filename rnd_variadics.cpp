#include <iostream>
using namespace std;

//template<bool bit>
/*template<>
int reversed_binary_value(bool bit){
  return bit;
}
*/ 
template<bool bit>
int reversed_binary_value() {
  return bit;
}

template<bool bit, bool... Args>
int reversed_binary_value() {
 
    int bitv = (bit == true) ? 1 : 0;
    int ans = 0;
   // if((sizeof...(Args)) > 1)
     //bool bit;
     ans = reversed_binary_value<Args...>() << 1 + bitv;
  //  else
     // return bitv;
 
//    cout << sizeof...(Args) << endl;
    return ans;
};

template <int n, bool...digits>
struct CheckValues {
  	static void check(int x, int y)
  	{
    	CheckValues<n-1, 0, digits...>::check(x, y);
    	CheckValues<n-1, 1, digits...>::check(x, y);
  	}
};

template <bool...digits>
struct CheckValues<0, digits...> {
  	static void check(int x, int y)
  	{
    	int z = reversed_binary_value<digits...>();
        cout << (z+64*y==x);
  	}
};

int main()
{
  	int t; std::cin >> t;

  	for (int i=0; i!=t; ++i) {
		int x, y;
    	cin >> x >> y;
    	CheckValues<6>::check(x, y);
    	cout << "\n";
  	}
}
