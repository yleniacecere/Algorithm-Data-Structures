#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class hashElement {
public:
    char key;   // carattere da contare
    int value;  // numero di occorrenze
    bool occupied; // indica se questo slot è occupato
    bool deleted;  // indica se è stato cancellato (utile per probing)
    hashElement() : key(0), value(0), occupied(false), deleted(false) {}
};

class hashTable {
private:
    vector<hashElement> table;
    int size;

    int hash(char key) const {
        return static_cast<int>(key) % size;
    }

    int findSlot(char key) const {
        // restituisce l'indice dove si trova il carattere, o -1 se non presente
        int index = hash(key);
        int startIndex = index;
        while (table[index].occupied) {
            if (!table[index].deleted && table[index].key == key) {
                return index;
            }
            index = (index + 1) % size;
            if (index == startIndex) {
                break; // abbiamo controllato tutta la tabella
            }
        }
        return -1;
    }

public:
    explicit hashTable(int s) : size(s) {
        table.resize(size);
    }

    void increment(char key) {
        int index = hash(key);
        int startIndex = index;
        while (table[index].occupied) {
            if (!table[index].deleted && table[index].key == key) {
                table[index].value++;
                return;
            }
            index = (index + 1) % size;
            if (index == startIndex) {
                cout << "HashTable piena! Impossibile inserire.\n";
                return;
            }
        }
        // slot vuoto trovato
        table[index].key = key;
        table[index].value = 1;
        table[index].occupied = true;
        table[index].deleted = false;
    }

    void printToFile(const string& filename) {
        ofstream outputFile(filename);
        for (const auto& element : table) {
            if (element.occupied && !element.deleted) {
                outputFile << "Carattere: " << element.key << " Occorrenza: " << element.value << endl;
            }
        }
        outputFile.close();
    }

    int searchCharacter(char keyToFind) {
        int slot = findSlot(keyToFind);
        if (slot != -1) {
            return table[slot].value;
        }
        return 0;
    }

    void removeCharacter(char keyToRemove) {
        int slot = findSlot(keyToRemove);
        if (slot != -1) {
            table[slot].deleted = true;
        }
    }

    vector<hashElement> getTable() {
        return table;
    }
};

int main() {
    hashTable myHash(256);
    ifstream inputFile("IN.txt");

    char ch;
    while (inputFile.get(ch)) {
        myHash.increment(ch);
    }
    inputFile.close();

    myHash.printToFile("OUT.txt");

    cout << "Tabella hash:" << endl;
    for (const auto& element : myHash.getTable()) {
        if (element.occupied && !element.deleted) {
            cout << "Carattere: " << element.key << " Occorrenza: " << element.value << endl;
        }
    }

    char searchChar;
    cout << "Inserisci il carattere da cercare: ";
    cin >> searchChar;

    int occurrence = myHash.searchCharacter(searchChar);
    cout << "Occorrenza del carattere '" << searchChar << "': " << occurrence << endl;

    char charToRemove;
    cout << "Inserisci il carattere da rimuovere: ";
    cin >> charToRemove;

    myHash.removeCharacter(charToRemove);

    int occurrence1 = myHash.searchCharacter(charToRemove);
    if (occurrence1 == 0) {
        cout << "Il carattere '" << charToRemove << "' è stato rimosso dalla tabella hash." << endl;
    } else {
        cout << "Il carattere '" << charToRemove << "' è ancora presente nella tabella hash con " << occurrence1 << " occorrenza(e)." << endl;
    }

    cout << "Tabella hash finale:" << endl;
    for (const auto& element : myHash.getTable()) {
        if (element.occupied && !element.deleted) {
            cout << "Carattere: " << element.key << " Occorrenza: " << element.value << endl;
        }
    }

    return 0;
}

