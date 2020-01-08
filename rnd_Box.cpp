#include<bits/stdc++.h>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)
class Box{
  public:

  Box() : l(0), b(0), h(0){
  }

  Box(int pl, int pb, int ph) : l(pl), b(pb), h(ph)  {
  }

  Box(const Box& src){
    l = src.l;
    b = src.b;
    h = src.h;
  }

  int getLength() {
   return l;
  }
  int getBreadth() {
   return b;
  }
  int getheight() {
   return h;
  }
  long long CalculateVolume() {
   return (long long)l*b*h;
  }
  bool operator<(const Box& rt) const {
    bool flag = false;
    if (l == rt.l) {
       if (b == rt.b) {
          if (h == rt.h)
            flag = false;
          else
            flag = h < rt.h ? true: false;
       }
       else
        flag =  b < rt.b ? true: false;
    } else
        flag = l < rt.l ? true: false;
    return flag;
  }

  friend ostream& operator<<(ostream& out, const Box & b);

  private:
    int l, b, h;
};

ostream& operator<<(ostream& out, const Box& p) {
    out << p.l << " " <<  p.b << " " << p.h;
    return out;
}


void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}
