#include <iostream>
#include <list>
#include <string>
#include <map>
#include <exception>
#include <stack>
#include <sstream>
#include <vector>
#include <cstdio>
#include <queue>
using namespace std;

typedef map<string, string> propertyInfo;
class hrmlPage;

class tagInfo{ 

  friend class hrmlPage;
  string name;
  propertyInfo pInfo;
  list<tagInfo*> childList;
  tagInfo *next;
 
 
  public:
   
    tagInfo(){
      name = "";
      next = nullptr;
    }

    tagInfo(const tagInfo& p) {
      name = p.name;
      pInfo = p.pInfo;
      childList = p.childList;
    } 

    tagInfo& operator=(const tagInfo& p) {
      name = p.name;
      pInfo = p.pInfo;
      childList = p.childList;
      return *this;
    }
    bool isInitialized() const {
       return (name.length() > 0);
    }
    void setTag(string& tname) {
       name = tname;
    }

    void addProperty(string &pname, string& pvalue) {
      pInfo.insert(pair<string, string>(pname, pvalue));
    }

    void addChild(tagInfo* ptag) {
      childList.push_back(ptag); 
    }
   
    bool compareTagName(const string& tname) {
      return(name == tname);
    }
    ~tagInfo() {
      //cout << "destructor got called for tagname" << name << endl;
    }
};


class hrmlPage{

  tagInfo *root;
 
  public:
  
  hrmlPage() {
     root = nullptr;
     //cout << " hrml page instance got created" << endl;
  }   
 
  hrmlPage(const hrmlPage&) = delete; // no copy constructor
  hrmlPage& operator=(const hrmlPage&) = delete; // no assignment operator

  void process(int N, int Q);
  void parse_line(tagInfo *temp, const string& input_line, bool  &pop_current_top, tagInfo *top);
  void processQuery(string&);
  void display();

  ~hrmlPage() {
    tagInfo* temp = root; 
    queue<tagInfo*> tagQ; 
  
    while (temp) {
       /*cout << temp->name ;
       for (auto v : temp->pInfo) {
         cout << (v).first << " = " << (v).second << " ";
       } 
       cout << endl;*/
       for (auto v : temp->childList)  {
         tagQ.push(v);       
       }
       if (temp->next);
         tagQ.push(temp->next);
       delete temp;
       if (!tagQ.empty()){
         temp = tagQ.front();
         tagQ.pop();
       }
       else
         break;
    }
  } 
};

void hrmlPage::display() {

  tagInfo* temp = root; 
  queue<tagInfo*> tagQ; 

  while (temp) {
     cout << temp->name ;
     for (auto v : temp->pInfo) {
       cout << (v).first << " = " << (v).second << " ";
     } 
     cout << endl;
     for (auto v : temp->childList)  {
       tagQ.push(v);       
     }
     if (!tagQ.empty()){
       temp = tagQ.front();
       tagQ.pop();
     }
     else if (temp->next)
         temp = temp->next;
     else
       break;
  }
 
}

void hrmlPage::processQuery(string& input_line) {
  char delim;
  size_t end_pos = input_line.length(), start_pos = 0, tilde_pos = 0, eos;
  string pname , pvalue;
  tagInfo* temp=nullptr;
  char tilde_found = false;
  string entity,ltag;
  start_pos = input_line.rfind("~", end_pos);   
  tilde_pos = start_pos;
  if (start_pos ==  -1) {
   cout << "not valid sytax , ~ must be followed by property name " << endl;
   exit(-1);
  }
  pname = input_line.substr(start_pos + 1, end_pos);
  start_pos = 0;  
  eos = input_line.length(); 
  /*
    if (delim == '~') {
      pvalue = temp->pInfo[pname]; 
      if (!pvalue.empty())
        cout << pvalue << endl; 
      else 
        cout << "NOT FOUND" << endl;
      break;
    }
  */
 
  temp = root;
  bool root_set = false;
  while (start_pos < tilde_pos) {

    end_pos = input_line.find(".", start_pos); 
    end_pos = (end_pos == string::npos) ? tilde_pos : end_pos; 
    ltag = input_line.substr(start_pos, end_pos - start_pos);
    start_pos = end_pos + 1;
    delim = input_line[end_pos];
    // got the tag
    
    if (!root_set) {
      while (temp) {
        if (ltag == temp->name) {
          root_set = true; 
          break;
        }
        temp = temp->next;
     }
     if (root_set)
       continue;
    }

    if (temp) {
       
      list<tagInfo*>::iterator childIter = temp->childList.begin();
      while (childIter != temp->childList.end()) {
        //cout << (*childIter)->name << " -- " << ltag  << endl;
        if ((*childIter)->name == ltag) {
          temp = *childIter;
          break;
        }
        else
          ++childIter;
      }
  
      if (childIter == temp->childList.end()) {
        cout << "Not Found!" << endl;
        return; 
      }
    }
  }

  if (temp){
  pvalue = temp->pInfo[pname]; 
  if (!pvalue.empty())
    cout << pvalue << endl; 
  else 
    cout << "Not Found!" << endl;
  }
  else
    cout << "Not Found!" << endl;
 
}


void hrmlPage::process(int N, int Q) {
  string input_line;
  char s[200]; 
  stack<tagInfo *> st;
  tagInfo *temp;
  bool pop_current_top = false;
  vector<string> tags;
  vector<string> queries;
   
  for (int i = 0 ; i < N; i++){
    getline(cin, input_line); 
    if (input_line.length() > 200) {
      cout << "Given input string length is exceeding 200 , terminating " << endl;
      exit(-1);
    }

    tags.push_back(input_line); 
  }

  for (int i = 0 ; i < Q; i++){
    getline(cin, input_line); 
    queries.push_back(input_line);
  }
 
  /*for (auto a : tags)
    cout << a << endl;
  for (auto a : queries)
    cout << a << endl;
  */ 
  if (tags.size() < 2){
    cout << "End tag not present" << endl;
    exit(-1);
  }
  tagInfo* parent= nullptr; 
   
  bool root_visited = false; 
  for (auto v : tags) {
    input_line = v; 
    //cout << "input line is " << input_line << endl;

    temp = new tagInfo();
    parse_line(temp, input_line, pop_current_top, parent);

    if (!root_visited) {
      if (!root)
        parent = root = temp; // setting root for first time
      else {
        parent->next = temp; // handling adjacent roots
        parent = temp;
      }
      root_visited = true;
      continue;
    }

    if (pop_current_top) {
      if (!st.empty()) {
        parent = st.top();
        st.pop();
      }
      else {
       root_visited = false; // new root started
      }
      pop_current_top = false;
    } 
    else {
      parent->addChild(temp);
      st.push(parent);
      parent = temp;
    }
  
  }
  if (!st.empty()) {
    parent = st.top();
    st.pop(); 
    cout << "End tag not present for " << parent->name << endl;
    exit(-1);
  }

  //display();

  for (auto v : queries) {
    input_line = v; 
    processQuery(v);
  }
}

void hrmlPage::parse_line(tagInfo *temp, const string& input_line, bool  &pop_current_top, tagInfo *top){
  stringstream s{input_line};
  string ptag;
  s >> ptag;
  string tagname;
  if (ptag[0] == '<' && ptag[1] != '/') { //start of tag
     // new tag
     tagname = ptag.substr(1, ptag.length());
     if(tagname[tagname.size() - 1] == '>')
       tagname.pop_back();
     //cout << "ptag is " << ptag << " new tag is " << tagname << endl;
     temp->setTag(tagname);
  }
  else if (ptag[0] == '<' && ptag[1] == '/') { // end tag
    tagname = ptag.substr(1, ptag.length()); 
    tagname.pop_back();
    if (top->name == tagname) {
      cout << "check tag ordering " << endl;
      exit(1);
    }
    pop_current_top = true;
    return;  
  } else {
    cout << "Not proper format" << endl;
    exit(1);
  }
 
  while(!s.eof()) {
    string pname;
    string delim;
    string pvalue;
    s >> pname >> delim >> pvalue;
    if (delim != "="){ 
      cout << pname << " syntax is not proper " << endl;
      exit(1);
    }
    if (pvalue[pvalue.size() - 1] == '>')
      pvalue.pop_back();
    pvalue.erase(0,1);
    pvalue.pop_back();
    temp->addProperty(pname, pvalue);
  }
}

int main(){

  int N, Q;
  char junk;
  hrmlPage page;
  
  //cout << "Enter number of lines and queries " << endl;
  cin >> N >> Q;
 // cout << " N is " << N << " Q is " << Q << endl;
  cin.ignore();

  //cin >> junk;
  if ( N  < 1  && N > 20) {
    cout << " No of queries must be between 1 and 20 ... \n" << endl;
    exit(-1);
  }
  if ( Q  < 1  && Q > 20) {
    cout << " No of queries must be between 1 and 20 ... \n" << endl;
    exit(-1);
  }
 // char input[200];
  page.process(N,Q);
  return(0);
}
