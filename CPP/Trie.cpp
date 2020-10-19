#include<bits/stdc++.h>
using namespace std;

#define CHAR_SIZE 128

class Trie {
	bool isEndOfWord;
	Trie* children[CHAR_SIZE];

public:
	Trie(){
		isEndOfWord = false;
		for(int i = 0; i < CHAR_SIZE; i++){
			children[i] = nullptr;
		}
	}
	
	void insert(string);
	bool check(string);
	bool haveChildren(Trie const*);
	bool deletion (Trie*&, string);

};

void Trie :: insert(string str) {
	Trie* curr = this;
	for (int i = 0; i < str.length(); i++){
		if(curr->children[str[i]] == nullptr){
			curr->children[str[i]] = new Trie();
		}
		curr = curr->children[str[i]];
	}
	curr->isEndOfWord = true;
}

bool Trie :: check(string str) {
	if (this == nullptr) return false;
	
	Trie* curr = this;
	for (int i = 0; i < str.length(); i++){
		curr = curr->children[str[i]];
		if(curr == nullptr){
			return false;
		}
	}
	return curr->isEndOfWord;
}

bool Trie :: haveChildren(Trie const* curr) {
	for(int i = 0; i < CHAR_SIZE; i++){
		if(curr->children[i]){
			return true;
		}
	}
	return false;
}

bool Trie :: deletion(Trie*& curr, string str) {
	if(curr == nullptr) return false;
	
	if(str.length()) {
		if(curr != nullptr &&
		curr->children[str[0]] != nullptr &&
		deletion(curr->children[str[0]], str.substr(1)) &&
		curr->isEndOfWord == false) {
			if (!haveChildren(curr)){
				delete curr;
				curr = nullptr;
				return true;
			} else {
				return false;
			}
		}
	}
	
	if(str.length() == 0 && curr->isEndOfWord){
		if (!haveChildren(curr)){
			delete curr;
			curr = nullptr;
			return true;
		} else {
			curr->isEndOfWord = false;
			return false;
		}
	}
	return false;
}
int main() {
	Trie* head = new Trie();

	head->insert("hello");
	cout << head->check("hello") << " ";

	head->insert("helloworld");
	cout << head->check("helloworld") << " ";

	cout << head->check("helll") << " ";

	head->insert("hell");
	cout << head->check("hell") << " ";

	head->insert("h");
	cout << head->check("h") << endl;

	head->deletion(head, "hello");
	cout << head->check("hello") << " ";

	cout << head->check("helloworld") << " ";
	cout << head->check("hell") << endl;

	head->deletion(head, "h");
	cout << head->check("h") << " ";
	cout << head->check("hell") << " ";
	cout << head->check("helloworld") << endl;

	head->deletion(head, "helloworld");
	cout << head->check("helloworld") << " ";
	cout << head->check("hell") << " ";

	head->deletion(head, "hell");
	cout << head->check("hell") << endl;

	if (head == nullptr) {
		cout << "Trie empty!!\n";
	}

	cout << head->check("hell") << endl;

	return 0;
}
