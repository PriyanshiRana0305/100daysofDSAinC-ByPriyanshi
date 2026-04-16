#include <stdio.h>
#include <string.h>

#define SIZE 100

int table[SIZE];
int m;

void init() {
    for(int i = 0; i < m; i++)
        table[i] = -1;
}

int hash(int key) {
    return key % m;
}

void insert(int key) {
    int h = hash(key);
    int i = 0;
    int newIndex;

    while(i < m) {
        newIndex = (h + i * i) % m;
        if(table[newIndex] == -1) {
            table[newIndex] = key;
            return;
        }
        i++;
    }
}

void search(int key) {
    int h = hash(key);
    int i = 0;
    int newIndex;

    while(i < m) {
        newIndex = (h + i * i) % m;
        if(table[newIndex] == key) {
            printf("FOUND\n");
            return;
        }
        if(table[newIndex] == -1) {
            printf("NOT FOUND\n");
            return;
        }
        i++;
    }
    printf("NOT FOUND\n");
}

int main() {
    int n;
    char op[10];
    int key;

    scanf("%d", &m);
    init();

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%s %d", op, &key);

        if(strcmp(op, "INSERT") == 0)
            insert(key);
        else if(strcmp(op, "SEARCH") == 0)
            search(key);
    }

    return 0;
}