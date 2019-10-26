#include <iostream>
using namespace std;

template<typename T>
class node{
public:
	string key;
	T value;
	node* next;
	node(string k,T v){
		key = k;
		value = v;
		next = NULL;
	}
};

template<typename T>
class Hashmap
{
	node<T>** Bucket;
	int ts;
	int cs;
	int hashFn(string key){
		int ans = 0;
		int mul_factor = 1;
		for (int i = 0; key[i]!='\0' ; ++i)
		{
			ans += key[i]*mul_factor;
			mul_factor *= 37;
			ans %= ts;
			mul_factor %= ts;
		}
		return ans%ts;
	}

public:
	Hashmap(int s=7){
		ts = s;
		Bucket = new node<T>*[ts];
		cs = 0;

		for (int i = 0; i < ts; ++i)
		{
			Bucket[i] = NULL;
		}
	}

	void rehash(){
		node<T>** oldBucket = Bucket;
		int oldts = ts;
		Bucket = new node<T>*[2*ts];
		ts = 2*ts;
		cs = 0;
		for (int i = 0; i < ts; ++i)
		{
			Bucket[i] = NULL;
		}
		for (int i = 0; i < oldts; ++i)
		{
			node<T>* temp = oldBucket[i];
			while(temp){
				insert(temp->key,temp->value);
				temp = temp->next;
			}
			delete oldBucket[i];
		}
		delete []oldBucket;

	}

	void insert(string key, T value){
		int i = hashFn(key);
		node<T>* n = new node<T>(key,value);
		n->next = Bucket[i];
		Bucket[i] = n;
		cs++;

		float load_factor = cs/(ts*1.0);
		if(load_factor>0.7){
			rehash();
		}
	}
	
	T* search(string key){
		int i = hashFn(key);
		node<T>* temp = Bucket[i];
		while(temp){
			if(temp->key == key){
				return &(temp->value);
			}
			temp = temp->next;
		}
		return NULL;

	}

	T& operator[](string key){
		T* temp = search(key);
		if(temp==NULL){
			T garbage;
			insert(key,garbage);
			temp = search(key);
			return *temp;
		}
		else{
			return *temp;
		}
	}

	void remove(string key){
		T* temp = search(key);
		if(temp==NULL){
			return;
		}
		else{
			int i = hashFn(key);
			node<T>* temp1 = Bucket[i];
			if(temp1->key==key){
				Bucket[i] = temp1->next;
				delete temp1;
				return;
			}
			while(temp1->next->key!=key){
				temp1 = temp1->next;
			}
			node<T>* n = temp1->next;
			temp1->next = n->next;
			delete n;
			return;
		}
	}

	void print(){
		for (int i = 0; i < ts; ++i)
		{
			node<T>* temp = Bucket[i];
			cout<<i<<" -> ";
			while(temp){
				cout<<temp->key<<" : "<<temp->value<<" ";
				temp = temp->next;
			}
			cout<<endl;
		}
	}
};

int main()
{
	Hashmap<int> h;
	h.insert("mango",100);
	h.insert("apple",150);
	h.insert("banana",80);
	h.insert("orange",60);
	h.insert("pineapple",60);
	cout<<"Initial Table : "<<endl;
	h.print();
	cout<<endl<<"After adding kiwi : "<<endl;
	h["kiwi"] = 50; // insert
	h.print();
	cout<<endl<<"After updating mango : "<<endl;
	h["mango"] = 120; // update
	h.print();
	cout<<endl<<"Now price of mango is : "<<h["mango"]<<endl; // search
	cout<<endl<<"After removing apple : "<<endl;
	h.remove("apple"); // remove
	h.print();

	return 0;
}