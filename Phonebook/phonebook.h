#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <stdbool.h>

typedef struct Entries
{
    char name[30];
    char number[30];
} Entries;

typedef struct PhoneBook
{
    int size;
    int index;
    Entries* entry;
} PhoneBook;

int Size(PhoneBook* phonbook);
void Init(PhoneBook* phonebook, int* size);
bool Insert(PhoneBook* phonebook, char name[], char number[]);
void Destroy(PhoneBook* PhoneBook);
bool Contains(PhoneBook* phonebook, char name[], char number[]);
void Print(PhoneBook* phonbook);
char* Get(PhoneBook* phonebook, char search[]);
void Dump(PhoneBook* phonebook, char fileName[]);

#endif