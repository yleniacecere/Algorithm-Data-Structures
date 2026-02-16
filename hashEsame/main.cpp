#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <fstream>

using namespace std;

struct HashElement {
    int key;
    string value;

    HashElement(int k, const string& v) : key(k), value(v) {}
};

class HashTable {
private:
    vector<list<HashElement>> table;
    int size;

    int hashFunction(int key) const {
        int h = key % size;
        if (h < 0) h += size; // gestisce chiavi negative
        return h;
    }

public:
    explicit HashTable(int s) : table(s), size(s) {}

    void insert(int key, const string& value) {
        int index = hashFunction(key);
        table[index].emplace_back(key, value);
    }

    bool search(int key, string& outValue) const {
        int index = hashFunction(key);
        for (const auto& element : table[index]) {
            if (element.key == key) {
                outValue = element.value;
                return true;
            }
        }
        return false;
    }

    bool remove(int key) {
        int index = hashFunction(key);
        auto& bucket = table[index];

        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->key == key) {
                bucket.erase(it);
                return true;
            }
        }
        return false;
    }

    bool loadFromFile(const string& filename) {
        ifstream inputFile(filename);
        if (!inputFile.is_open()) {
            return false;
        }

        int k;
        string v;

        while (inputFile >> k >> v) {
            insert(k, v);
        }

        inputFile.close();
        return true;
    }

    void printBuckets(ostream& out, const string& prefix) const {
        for (int i = 0; i < size; i++) {
            out << prefix << "[" << i << "]: ";

            if (table[i].empty()) {
                out << "-";
            } else {
                bool first = true;
                for (const auto& element : table[i]) {
                    if (!first) out << " -> ";
                    out << "<" << element.key << ", " << element.value << ">";
                    first = false;
                }
            }

            out << endl;
        }
    }
};

void printMenu() {
    cout << "\n===== MENU =====\n";
    cout << "1) Insert in H1\n";
    cout << "2) Insert in H2\n";
    cout << "3) Search in H1\n";
    cout << "4) Search in H2\n";
    cout << "5) Remove from H1\n";
    cout << "6) Remove from H2\n";
    cout << "7) Stampa entrambe su OUT.txt\n";
    cout << "0) Esci\n";
    cout << "Scelta: ";
}

int main() {

    const int TABLE_SIZE = 101; // numero primo consigliato

    HashTable h1(TABLE_SIZE);
    HashTable h2(TABLE_SIZE);

    if (!h1.loadFromFile("IN1.txt")) {
        cout << "Errore apertura IN1.txt\n";
        return 1;
    }

    if (!h2.loadFromFile("IN2.txt")) {
        cout << "Errore apertura IN2.txt\n";
        return 1;
    }

    // Prima stampa iniziale su OUT.txt
    ofstream outFile("OUT.txt");
    if (!outFile.is_open()) {
        cout << "Errore creazione OUT.txt\n";
        return 1;
    }

    h1.printBuckets(outFile, "H1");
    h2.printBuckets(outFile, "H2");
    outFile.close();

    cout << "Hash tables caricate e stampate su OUT.txt\n";

    int scelta;

    do {
        printMenu();
        cin >> scelta;

        if (scelta == 1 || scelta == 2) {
            int key;
            string value;

            cout << "Inserisci key (int): ";
            cin >> key;
            cout << "Inserisci value (string): ";
            cin >> value;

            if (scelta == 1)
                h1.insert(key, value);
            else
                h2.insert(key, value);

            cout << "Inserimento completato.\n";
        }

        else if (scelta == 3 || scelta == 4) {
            int key;
            cout << "Inserisci key da cercare: ";
            cin >> key;

            string result;
            bool trovato;

            if (scelta == 3)
                trovato = h1.search(key, result);
            else
                trovato = h2.search(key, result);

            if (trovato)
                cout << "Trovato: <" << key << ", " << result << ">\n";
            else
                cout << "Chiave non trovata.\n";
        }

        else if (scelta == 5 || scelta == 6) {
            int key;
            cout << "Inserisci key da rimuovere: ";
            cin >> key;

            bool removed;

            if (scelta == 5)
                removed = h1.remove(key);
            else
                removed = h2.remove(key);

            if (removed)
                cout << "Elemento rimosso.\n";
            else
                cout << "Chiave non presente.\n";
        }

        else if (scelta == 7) {
            ofstream outFile("OUT.txt");
            h1.printBuckets(outFile, "H1");
            h2.printBuckets(outFile, "H2");
            outFile.close();
            cout << "OUT.txt aggiornato.\n";
        }

    } while (scelta != 0);

    return 0;
}
