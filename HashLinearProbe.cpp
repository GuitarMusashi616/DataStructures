#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <sstream>

using std::list;
using std::system;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;
using std::array;
using std::ifstream;
using std::system;
using std::to_string;
using std::stringstream;

int to_number(string word) {
	int convertedNumber = 0;
	stringstream str(word);
	str >> convertedNumber;
	return convertedNumber;
}

int flipDigits(int num) {
	//return the same number but backwards ie 567 -> 765
	string word = to_string(num);
	string backwardWord = "";

	for (int i = word.length() - 1; i >= 0; i--) {
		backwardWord = backwardWord + word[i];
	}

	return to_number(backwardWord);

}

class Hash
{
public:
	Hash();
	Hash(int size);
	void insert(string word);
	void directInsert(string word, int key, int &collisions);
	void recursiveInsert(string word);
	bool remove(string word);
	int hashFunction(string word);
	void showTable();

	void outputStatistics();

private:
	string *hashTable;
	const int TABLE_SIZE;
};



Hash::Hash() : TABLE_SIZE(7)
{
	hashTable = new string[TABLE_SIZE];
}

Hash::Hash(int size) : TABLE_SIZE(size)
{
	hashTable = new string[TABLE_SIZE];
}

void Hash::insert(string word)
{
	int key = hashFunction(word);
	for (int i = 0; i < TABLE_SIZE; i++) {
		int num = (key + i);
		num = num % TABLE_SIZE;
		if (word == "variable") {
			cout << "found it " << endl;
		}
		if (hashTable[num] == "") {
			hashTable[num] = word;
			return;
		}
	}
	cout << "TABLE FULL" << endl;
	return;
}

void Hash::directInsert(string word, int key, int &collisions) {
	if (hashTable[key] == "") {
		hashTable[key] = word;
		return;
	}
	else {
		directInsert(word, (key + 1)%TABLE_SIZE, collisions);
		collisions += 1;
		//cout << key + 1 << ": " << (key+1)%TABLE_SIZE << endl;
	}
}

void Hash::recursiveInsert(string word)
{
	int collisions = 0;
	int key = hashFunction(word);
	directInsert(word, key, collisions);
	if (collisions > 2000) {
		cout << collisions << endl;
	}
	//cout << "TABLE FULL" << endl;
	return;
}

bool Hash::remove(string word)
{
	return true;
}

int Hash::hashFunction(string word)
{
	int total = 0;
	for (int i = 0; i < word.length(); i++) {
		//cout << (int)c << " ";
		if (i % 2)
		{
			total += (int)word[i] * (3 ^ i);
		}
		else
		{
			total += flipDigits((int)word[i] * (3 ^ i));
		}
	}

	//string strNum = std::to_string(total);

	return total%TABLE_SIZE;
}

void Hash::showTable()
{
	for (int i = 0; i < TABLE_SIZE; i++) {
		if (hashTable[i] != "") {
			cout << hashTable[i] << endl;
		}
	}
}

void Hash::outputStatistics()
{
	int longest = 0;
	int insertionsThatResultedInCollision = 0;
	int numOfEntries = 0;
	int numOfChains = 0;
	int totalChainLength = 0;
	//average length of all chains
	//includes chains of size 1 but not chains of size 0


	for (int i = 0; i < TABLE_SIZE; i++) {

		if (hashTable[i] != "") {
			//finding collisions
			numOfEntries += 1;
			//finding average
		}
	}
	//finding load factor = entries / numPossibleChains
	auto loadFactor = (double)numOfEntries / TABLE_SIZE;
	cout << "Hash Table Size: " << TABLE_SIZE << endl;
	cout << "Load Factor: " << loadFactor * 100 << "%" << endl;
}

//bool Hash::isWordInHashTable(string word)
//{
//	int key = hashFunction(word);
//	for (auto it = hashTable[key].begin(); it != hashTable[key].end(); ++it) {
//		if (*it == word) {
//			hashTable[key].erase(it);
//			return true;
//		}
//	}
//	return false;
//}
//
//void Hash::searchWord() {
//	string input;
//	cout << "type a word to check if its in the hash table, type EXIT to exit" << endl;
//	while (input != "EXIT") {
//		getline(cin, input);
//		if (isWordInHashTable(input)) {
//			cout << "TRUE" << endl;
//		}
//		else if (input != "EXIT") {
//			cout << "FALSE" << endl;
//		}
//	}
//}

//int main() {
//	Hash h1;
//	h1.insert("stuff");
//	h1.insert("things");
//	h1.insert("more");
//	h1.insert("suits");
//	h1.insert("thugs");
//	h1.insert("bandits");
//	h1.insert("knights");
//	h1.insert("romans");
//
//	h1.showTable();
//	system("pause");
//	return 0;
//}

//class Hash
//{
//	//Hash using chaining
//public:
//	Hash(int size);
//	void insert(string word);
//	bool remove(string word);
//	int hashFunction(string word);
//	void showTable();
//	void outputStatistics();
//	bool isWordInHashTable(string word);
//	void searchWord();
//
//protected:
//	list<string> *hashTable;
//	int TABLE_SIZE;
//};
//
//Hash::Hash(int size) : TABLE_SIZE(size)
//{
//	hashTable = new list<string>[TABLE_SIZE];
//}
//
//void Hash::insert(string word)
//{
//	int key = hashFunction(word);
//	hashTable[key].push_back(word);
//}
//
//bool Hash::remove(string word)
//{
//	//returns false if word does not exist in table
//	int key = hashFunction(word);
//	for (auto it = hashTable[key].begin(); it != hashTable[key].end(); ++it) {
//		if (*it == word) {
//			hashTable[key].erase(it);
//			return true;
//		}
//	}
//	return false;
//}
//
//int Hash::hashFunction(string word)
//{
//	int total = 0;
//	for (int i = 0; i < word.length(); i++) {
//		//cout << (int)c << " ";
//		total += (int)word[i] * (11 ^ i);
//	}
//
//	//string strNum = std::to_string(total);
//
//	return total%TABLE_SIZE;
//}
//
//void Hash::showTable()
//{
//	for (int i = 0; i < TABLE_SIZE; i++) {
//		for (string w : hashTable[i]) {
//			cout << i << ": " << w << endl;
//		}
//	}
//}
//
//void Hash::outputStatistics()
//{
//	int longest = 0;
//	int insertionsThatResultedInCollision = 0;
//	int numOfEntries = 0;
//	int numOfChains = 0;
//	int totalChainLength = 0;
//	//average length of all chains
//	//includes chains of size 1 but not chains of size 0
//
//
//	for (int i = 0; i < TABLE_SIZE; i++) {
//
//		if (hashTable[i].size() > 0) {
//			//finding collisions
//			numOfEntries += hashTable[i].size();
//			//finding average
//			numOfChains += 1;
//			totalChainLength += hashTable[i].size();
//			if (hashTable[i].size() > longest) {
//				//finding longest
//				longest = hashTable[i].size();
//			}
//		}
//	}
//	auto averageChainLength = (double)totalChainLength / numOfChains;
//	int collisions = numOfEntries - numOfChains;
//	//finding load factor = entries / numPossibleChains
//	auto loadFactor = (double)numOfEntries / TABLE_SIZE;
//	cout << "Hash Table Size: " << TABLE_SIZE << endl;
//	cout << "Load Factor: " << loadFactor * 100 << "%" << endl;
//	cout << "Collisions: " << collisions << endl;
//	cout << "Longest Chain: " << longest << endl;
//	cout << "Average Chain: " << averageChainLength << endl;
//}
//
//bool Hash::isWordInHashTable(string word)
//{
//	int key = hashFunction(word);
//	for (auto it = hashTable[key].begin(); it != hashTable[key].end(); ++it) {
//		if (*it == word) {
//			hashTable[key].erase(it);
//			return true;
//		}
//	}
//	return false;
//}
//
//void Hash::searchWord() {
//	string input;
//	cout << "type a word to check if its in the hash table, type EXIT to exit" << endl;
//	while (input != "EXIT") {
//		getline(cin, input);
//		if (isWordInHashTable(input)) {
//			cout << "TRUE" << endl;
//		}
//		else if (input != "EXIT") {
//			cout << "FALSE" << endl;
//		}
//	}
//}
//
//
//
int main()
{
	list<string> words = { "things","stuff","other","unnamed" };
	Hash h1(60331);
	//120721
	//60331

	string str;
	ifstream infile;
	infile.open("text.txt");
	while (!infile.eof()) {
		getline(infile, str);

		//cout << str << endl;
		h1.recursiveInsert(str);
	}
	//h1.showTable();

	//for (string str: words) {
	//	cout << str << endl;
	//	h1.insert(str);
	//}

	//h1.showTable();
	//cout << h1.findLongestCollision() << endl;
	//h1.showTable();
	//h1.outputStatistics();

	cout << "done" << endl;
	system("pause");
}
