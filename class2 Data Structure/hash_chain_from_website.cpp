// refer from
// https://www.geeksforgeeks.org/c-program-hashing-chaining/
// CPP program to implement hashing with chaining
#include<iostream>
#include <string>
#include <list>
using namespace std;

// hash function to map values to key
size_t hash_func(const string& s, const int bucket_count) { // a public function
    static const size_t multiplier = 263;
    static const size_t prime = 1000000007;
    unsigned long long hash = 0;
    for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
        hash = (hash * multiplier + s[i]) % prime;
    cout << "hash value: " << hash % bucket_count << endl;
    return hash % bucket_count;
}

class Hash
{
    int BUCKET;    // No. of buckets
    list<string> *table; // Pointer to an array containing buckets

public:
    Hash(int V)  // Constructor
    {
        this->BUCKET = V;
        table = new list<string>[BUCKET];
    }

    void insertItem(string s) { // inserts a key into hash table
        int index = hash_func(s,BUCKET);
        if (!findItem(s)) {
            table[index].push_back(s);
        }
    }

    bool findItem(string s){
      int index = hash_func(s,BUCKET); // get the hash index of key

      // find the key in (inex)th list
      bool flag =false;
      list<string>::const_iterator itr;
      for (auto itr = table[index].begin();
               itr != table[index].end(); itr++) {
        if (s.compare(*itr) == 0){ // itr is a iterator, use * to get the value
          //  "compare" functions like this: if(x.compare(y) == 0)
          // NOTE, str.compare return >0, <0, =0
          flag=true;
          break;
        }
      }
    }

    // deletes a key from hash table
    void deleteItem(string s) {
      cout << "I am using deleteItem. string is:  " << s << endl;
      int index = hash_func(s,BUCKET); // get the hash index of key

      // find the key in (inex)th list
      bool flag =false;
      list<string>::iterator itr;
      for (itr = table[index].begin(); // I have defined itr, no "auto" here
               itr != table[index].end(); itr++) {
        if (s.compare(*itr) == 0){ // itr is a iterator, use * to get the value
          table[index].erase(itr);
          break;
        }
      }
    }

    void displayHash() {
      for (int i = 0; i < BUCKET; i++) { // why there is not a *???
        cout << i;
        for (auto x : table[i])
          cout << " --> " << x;
        cout << endl;
      }
    }

};


// Driver program
int main()
{
  int n , bucket_count;
  string x;
  cin >> bucket_count >> n ;
  Hash h(bucket_count);

  for (int i = 0; i < n; i++){
    cin >> x;
    h.insertItem(x); // insert the keys into the hash table
    h.displayHash();
  }

  // delete 12 from hash table
  h.deleteItem(x);

  // display the Hash table
  h.displayHash();

  return 0;
}
