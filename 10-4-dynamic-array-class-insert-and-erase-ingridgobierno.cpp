#include <iostream>
#include <string>
using namespace std;

class DynamicArray {
private:
    int size;
    int capacity;
    string* array;

public:
    // constructor
    DynamicArray(int initialCapacity) {
        size = 0;
        capacity = initialCapacity;
        array = new string[capacity];
    }

    // destructor
    ~DynamicArray() {
        delete[] array;
    }

    // inserta un element
    bool insert(string newElement, int position) {
        if (position < 0 || position > size) {
            return false; // posició no vàlida
        }

        if (size == capacity) {
            // ampliem la capacitat
            capacity *= 2;
            string* newArray = new string[capacity];
            for (int i = 0; i < size; i++) {
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
        }

        for (int i = size; i > position; i--) {
            array[i] = array[i - 1];
        }

        array[position] = newElement;
        size++;
        return true;
    }

    // elimina un element
    bool remove(int position) {
        if (position < 0 || position >= size) {
            return false; // posició no vàlida
        }

        for (int i = position; i < size - 1; i++) {
            array[i] = array[i + 1];
        }

        size--;
        return true;
    }

    // imprimeix l'array
    void print() {
        cout << "{";
        for (int i = 0; i < size; i++) {
            cout << array[i];
            if (i < size - 1) cout << ", ";
        }
        cout << "}" << endl;
    }
};

int main() {
    DynamicArray arr(5);

    arr.insert("zero", 0);
    arr.insert("one", 1);
    arr.insert("two", 2);
    arr.insert("three", 3);
    arr.insert("four", 4);

    cout << "array inicial: ";
    arr.print();

    cout << "Inserim 'five' a la posicio 5:" << endl;
    arr.insert("five", 5);
    arr.print();

    cout << "Eliminem l'element a la posicio 2:" << endl;
    arr.remove(2);
    arr.print();

    return 0;
}
