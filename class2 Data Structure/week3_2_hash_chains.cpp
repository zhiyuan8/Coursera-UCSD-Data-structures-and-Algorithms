#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;
// do NOT use vector<string>, use hash chain for this problem

// hash function to map values to key
size_t hash_func(const string& s, const int bucket_count) { // a public function
    static const size_t multiplier = 263;
    static const size_t prime = 1000000007;
    unsigned long long hash = 0;
    for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
        hash = (hash * multiplier + s[i]) % prime;
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
            table[index].push_front(s);
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
      return flag;
    }

    // deletes a key from hash table
    void deleteItem(string s) {
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

    void displayHash(int i) {
        for (auto x : table[i]){
          cout << x << ' ';
        }
    cout << endl;
    }

    void displayHashALL() {
      for (int i = 0; i < BUCKET; i++) { // why there is not a *???
        cout << i;
        for (auto x : table[i])
          cout << " --> " << x;
        cout << endl;
      }
    }
};

struct Query {
    string type, s; // type means "command", s is the string
    size_t ind; // ind is the hashed value
};


class QueryProcessor {
    int bucket_count;
    Hash *hashmap; // Dynamic assign need pointer

public:
    explicit QueryProcessor(int bucket_count): bucket_count(bucket_count) {
      hashmap = new Hash(bucket_count); // must use dynamic assignment
    }

    ~QueryProcessor() { // need deconstructor for dynamic assignment
      delete hashmap;
    }

    Query readQuery() const {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }

    void writeSearchResult(bool was_found) const {
        std::cout << (was_found ? "yes\n" : "no\n");
    }

    void processQuery(const Query& query) {
        if (query.type == "check") {
            hashmap->displayHash(query.ind); // dynamic instantiation need to use -> to access memeber function
        } else {
            if (query.type == "find")
                writeSearchResult(hashmap->findItem(query.s)); // dynamic instantiation need to use -> to access memeber function
            else if (query.type == "add") {
                if (hashmap->findItem(query.s) == false){
                  hashmap->insertItem(query.s); // dynamic instantiation need to use -> to access memeber function
                }
                //hashmap->displayHashALL(); // for debugging
            } else if (query.type == "del") {
                hashmap->deleteItem(query.s); // dynamic instantiation need to use -> to access memeber function
                //hashmap->displayHashALL(); // for debugging
            }
        }
    }

    void processQueries() {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            processQuery(readQuery());
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}
