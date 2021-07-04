#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
int main(){
cout<<cin.tie()<<endl;
cout<<&cout<<endl;
cout<<&cin<<endl;
cout<<cout.tie()<<endl;
cout<<"tie the cerr to cout "<<endl;
cout.tie(&cerr);
cout<<cout.tie()<<endl;
cout<<&cerr<<endl;
cout.tie(nullptr);
cout<<"free the tie:"<<cout.tie()<<endl;
cout.tie(nullptr);
cout<<cout.tie()<<endl;
cout<<"tie the new:"<<endl;
ostream* old_tie=cin.tie(nullptr);
cout<<"old value: "<<old_tie<<endl;
cout<<"now cin 's tie is:"<<cin.tie()<<endl;
return 0;
}