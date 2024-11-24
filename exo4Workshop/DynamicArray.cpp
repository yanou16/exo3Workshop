#include "DynamicArray.h"

using namespace std;

// Convertit un �l�ment de tableau en une cha�ne
string array_element_to_string(ArrayElement* el) {
    return to_string(*el);
}

// Constructeur
DynamicArray::DynamicArray(int size) {
    count = 0;
    this->size = size;
    els = new ArrayElement * [size];
}

// Redimensionne le tableau
void DynamicArray::resize(int size) {
    try {
        ArrayElement** temp;

        this->size = size;
        temp = new ArrayElement * [size];
        for (int i = 0; i < count; i++) {
            temp[i] = els[i];
        }

        delete[] els;
        els = temp;
    }
    catch (std::bad_alloc& e) {
        this->size /= 2;
    }
}

// Ajuste le tableau � la taille actuelle
void DynamicArray::fit() {
    resize(count);
}

// Ajoute un �l�ment
int DynamicArray::add(ArrayElement* el) {
    if (count >= RESIZE_THRESHOLD * size) {
        resize(size * 2);
    }

    els[count] = el;

    return count++;
}

// Supprime un �l�ment
ArrayElement* DynamicArray::remove(int i) {
    ArrayElement* ptr = nullptr;

    if (0 <= i && i < count) {
        ptr = els[i];
        els[i] = els[--count];

        if (count < REFIT_THRESHOLD * size) {
            fit();
        }
    }

    return ptr;
}

// R�cup�re un �l�ment
ArrayElement* DynamicArray::get(int i) {
    return els[i];
}

// Affiche le contenu du tableau
void DynamicArray::print() {
    cout << "[";
    if (count > 0) {
        for (int i = 0; i < count - 1; i++) {
            cout << array_element_to_string(els[i]) << ", ";
        }
        cout << array_element_to_string(els[count - 1]);
    }
    cout << "]";
}

// Destructeur
DynamicArray::~DynamicArray() {
    delete[] els;
}
