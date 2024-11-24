#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>
#include <string>

typedef int ArrayElement;

// Convertit un élément de tableau en une chaîne
std::string array_element_to_string(ArrayElement* el);

class DynamicArray {
private:
    int count;
    int size;

    ArrayElement** els;

    const float REFIT_THRESHOLD = 0.8;
    const float RESIZE_THRESHOLD = 0.8;

    // Redimensionne le tableau
    void resize(int size);
    // Ajuste le tableau à la taille actuelle
    void fit();

public:
    // Constructeur
    DynamicArray(int size = 1);
    // Ajoute un élément
    int add(ArrayElement* el);
    // Supprime un élément
    ArrayElement* remove(int i);
    // Récupère un élément
    ArrayElement* get(int i);
    // Affiche le contenu du tableau
    void print();

    // Destructeur
    ~DynamicArray();
};

#endif // DYNAMICARRAY_H
#pragma once
