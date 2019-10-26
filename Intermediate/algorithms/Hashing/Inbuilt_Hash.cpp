//Hashmap_Inbuild
#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;


int main()
{
	// unordered_map<string,int> h;
	map<string,int> h;
	h.insert(make_pair("Mango",100));
	h.insert(make_pair("Apple",150));

	pair<string,int> p("Banana",60);
	h.insert(p);

	h["Kiwi"] = 300;
	h["Papaya"] = 40;

	// for each loop :
	for(auto node : h){
		cout<<node.first<<"-->"<<node.second<<endl;
	}

	return 0;
}