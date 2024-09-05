//Vectors Introduction :
#include<iostream>
#include<vector>
using namespace std;
int main(){
  vector <int> vec1 = {1,2,3,4,5};
  cout << vec1.size() << "\n";
  vector <int> vec2(10,-1);
  cout << vec2.size() << " "; 

  for(int i=0; i<vec2.size(); i++){
    cout << vec2[i] << endl;
  }
  cout << endl;
  return 0;
}
//Vector Implementation in Memory:
#include<iostream>
#include <vector>
using namespace std;
int main(){
  vector<int> vec = {1,2,3,4};
  cout << "size : "<< vec.size() << endl;
  cout << "capacity : " << vec.capacity() << endl;

  vec.push_back(5);
  cout << "size : "<< vec.size() << endl;
  cout << "capacity : " << vec.capacity() << endl;

  vec.pop_back();
  cout << "size : "<< vec.size() << endl;
  cout << "capacity : " << vec.capacity() << endl;
  return 0;
}