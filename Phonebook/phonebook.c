#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "phonebook.h"

int Size(PhoneBook* phonebook)
{
    return phonebook->size;
}

void Init(PhoneBook* phonebook, int* size)
{
    phonebook->size = *size;
    phonebook->index = 0;
    phonebook->entry = (Entries*)malloc(phonebook->size * sizeof(Entries));
}

bool Insert(PhoneBook* phonebook, char name[], char number[])
{
    if(phonebook->index == phonebook->size)
    {
        if (!Contains(phonebook, name, number))
        {
            printf("\nERROR: Phonebook is full! Impossible to add new entry: %s\n", name);
            return false;
        }
    }
    else
    {
        if(!Contains(phonebook, name, number))
        {
            char* tempName = (char*)malloc(strlen(name) + 1);
            char* tempNumber = (char*)malloc(strlen(number) + 1);
            
            strcpy(tempName, name);
            strcpy(tempNumber, number);
            
            strcpy(phonebook->entry[phonebook->index].name, tempName);
            strcpy(phonebook->entry[phonebook->index++].number, tempNumber);
            

            printf("%s was successfully added!\n", name);
        }
        return true;
    }
}

void Destroy(PhoneBook* phonebook)
{
    free(phonebook->entry);
}

bool Contains(PhoneBook* phonebook, char name[], char number[])
{
    for(int i = 0; i < phonebook->index; i++)
        if(strcmp((*(phonebook->entry + i)).name, name) == 0)
        {
            strcpy((*(phonebook->entry + i)).number, number);
            printf("\n%s's number has been updated!\n\n", name);
            return true;
        }
    
    return false;
}

void Print(PhoneBook* phonebook)
{
    for (int i = 0; i < phonebook->size; i++)
        printf("Number #%d: %s %s\n", i+1, phonebook->entry[i].name, phonebook->entry[i].number);
}

char* Get(PhoneBook* phonebook, char search[])
{
    for (int i = 0; i < phonebook->size; i++)
        if (strcmp(search, phonebook->entry[i].name) == 0)
            return phonebook->entry[i].number;

    return "NULL";
}

void Dump(PhoneBook* phonebook, char fileName[])
{
    FILE* file = fopen(fileName, "w+");

    if (!file)
        printf("ERROR!\n");
    
    for (int i = 0; i < phonebook->size; i++)
        fprintf(file, "%s:   %s\n", phonebook->entry[i].name, phonebook->entry[i].number);

    fclose(file);
    printf("Phonebook successfully saved!");
}