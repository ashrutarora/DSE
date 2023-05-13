#include <iostream>
using namespace std;

// Class representing a node in the hash table
class Node {
public:
    int key;
    Node* next;

    Node(int k) {
        key = k;
        next = NULL;
    }
};

// Class representing the hash table
class HashTable {
private:
    int table_size;
    Node** table;

    // Hash function
    int hash(int key) {
        return key % table_size;
    }

public:
    // Constructor
    HashTable(int size) {
        table_size = size;
        table = new Node*[table_size]();
    }

    // Insert a key into the hash table
    void insert(int key) {
        int index = hash(key);
        Node* new_node = new Node(key);
        new_node->next = table[index];
        table[index] = new_node;
    }

    // Search for a key in the hash table
    bool search(int key, int& num_comparisons) {

        int index = hash(key);

        Node* current = table[index];

        num_comparisons = 1;

        while (current != NULL) {
            
            if (current->key == key) {
                return true;
            }
            current = current->next;
            num_comparisons++;
        }

        return false;
    }

};

int main() {
    int n, key;
    cout << "Enter the size of the hash table: ";
    cin >> n;

    HashTable ht(n);

    // Insert keys into the hash table
    cout << "Enter the keys to insert into the hash table (terminate with -1): ";
    cin >> key;
    while (key != -1) {
        ht.insert(key);
        cin >> key;
    }

    // Search for keys in the hash table
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
