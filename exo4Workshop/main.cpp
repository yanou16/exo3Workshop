#include "DynamicArray.h"

using namespace std;

int main() {
    DynamicArray arr;

    int a = 2, b = 3, c = 5;

    arr.add(&a);
    arr.add(&b);
    arr.add(&c);

    arr.remove(0);

    arr.print();

    return 0;
}
