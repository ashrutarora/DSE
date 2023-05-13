#include <iostream>
using namespace std;




int main(){

    int n, key; 
    cout << "Enter size of Hash table: ";
    cin >> n;


    HashTable ht(n);

    cout << "Enter the keys to insert in Hash Table(exit after -1): ";
    cin >> key;
    while(key != -1){
        ht.insert(key);
        cin >> key;
    }

    cout << "Enter the keys to search for in the hash table (terminate with -1): ";
    cin >> key;
    while (key != -1) {
        int num_comparisons;
        if (ht.search(key, num_comparisons)) {
            cout << "Key found in the hash table with " << num_comparisons << " comparisons." << endl;
        }
        else {
            cout << "Key not found in the hash table with " << num_comparisons << " comparisons." << endl;
        }
        cin >> key;
    }

    return 0;
}