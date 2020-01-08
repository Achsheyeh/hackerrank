#include <iostream>
#include <exception>
#include <string>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;

class Server {
private:
	static int load;
public:
	static int compute(long long A, long long B) {
		load += 1;
		if(A < 0) {
			throw std::invalid_argument("A is negative");
		}
		vector<int> v(A, 0);
		int real = -1, cmplx = sqrt(-1);
		if(B == 0) throw 0;
		real = (A/B)*real;
		int ans = v.at(B);
		return real + A - B*ans;
	}
	static int getLoad() {
		return load;
	}
};
int Server::load = 0;

int main() {
        ifstream inp= ifstream("server_exception.inp");
	int T; inp >> T;
	while(T--) {
		long long A, B;
		inp >> A >> B;

	  try {
            cout << Server::compute(A, B) << endl;
          }
          /*catch (int arg) {
            cout << "Other Exception" <<endl;
          }*/
	  catch (invalid_argument e) {
	    cout << "Exception: " << e.what() << endl;  
	  }
	  catch (logic_error e) {
	    cout << e.what() << endl;
	  }
	  catch (runtime_error e) {
	    cout << e.what() << endl;
	  }
	  catch (bad_alloc e) {
	    cout << "Not enough memory" << endl;
	  }
	  catch (...) {
    	    cout << "Other Exception" << endl;
	  }    
	}
	cout << Server::getLoad() << endl;
	return 0;
}  

 /* try {
          Server::compute(A, B);
        }
        catch (invalid_argument e) {
          cout << "Exception: " << e.what() << endl;
        }
        catch (bad_alloc e) {
          cout << "not enough memory" << endl;
        }
        catch (range_error e) {
          cout << e.what() << endl;
        }
        catch (overflow_error e) {
          cout << e.what() << endl;
        }
        catch (underflow_error e) {
          cout << e.what() << endl;
        }
        catch (logic_error e) {
          cout << e.what() << endl;
        }
        catch (domain_error e) {
          cout << e.what() << endl;
        }
        catch (length_error e) {
          cout << e.what() << endl;
        }
        catch (out_of_range e) {
          cout << e.what() << endl;
        }
        catch (exception e) {
          cout << "Not enough memory" << endl;
        }    
    */    
		/* Enter your code here. */

