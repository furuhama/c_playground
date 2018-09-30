#include "stdio.h"

typedef struct person {
    int age;
} Person;

int main() {
    Person person_instance = {
        .age = 10
    };

    printf("%d\n", person_instance.age); //=> 10
}
