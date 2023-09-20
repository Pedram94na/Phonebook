/*
Create a phone book application. A phone book can store a list of (name, phone number) pairs.

Represent an entry with a struct of a name and a phone number. The name and the phone number should both be 30 character arrays.

Represent a phone book with a structure that contains a pointer to an array of entries, the number of inserted elements and the actual size of the array.

Create an init() function which initializes the phone book. This function has an integer parameter which determines the size of the entries' array. An array with this size should be allocated on the heap memory. Don't forget to implement a corresponding destroy() in order to avoid memory leak.

Create an insert() function which is given a name and a phone number. These should be inserted to the phone book. If the name is already in the phone book then the person's phone number should be updated. The insert() function should return a boolean value depending on whether the insertion was successful. The insertion is not successful if the array is full.

Create a get() function which is given a name and returns the phone number of this person. If the person is not found in the phone book then NULL pointer should return.

Create a print() function which prints all entries of the phone book.

Create a dump() function which prints all entries to a text file. The text file's name should be given as a parameter to this function.

In the main() function demonstrate the usage of all functions. Create a phone book, insert a few entries and print its content to the screen and a text file.

Make sure to avoid any undefined behavior in the program. In case of compilation error, the assignment automatically scores 0 points.
*/

#include <stdio.h>
#include "phonebook.h"

int main()
{
    PhoneBook phonebook;
    int size = 6;
    Init(&phonebook, &size); // Initializes phonebook
    printf("\nSize of your phonebook is: %d\n\n", Size(&phonebook));

    Insert(&phonebook, "Pedram", "+3611122"); // Adds to phonebook
    Insert(&phonebook, "Jill", "+3622233"); // Adds to phonebook
    Insert(&phonebook, "Carlos", "+3633344"); // Adds to phonebook
    Insert(&phonebook, "Mark", "+3644455"); // Adds to phonebook
    Insert(&phonebook, "Kate", "+3655566"); // Adds to phonebook
    Insert(&phonebook, "Pedram", "+36121212"); // Updates Pedram's number
    Insert(&phonebook, "Julia", "+3666677"); // Adds to phonebook
    Insert(&phonebook, "Peter", "+3677788"); // phonebook is full! Not added
    Insert(&phonebook, "Kate", "+36565656"); // Even though phonebook is full, we can update Kate's number

    printf("Here's your phonebook:\n");
    Print(&phonebook); // Shows the content of phonebook in terminal
    printf("\n");

    char search[30];
    printf("Enter a name to search for: ");
    scanf("%s", &search); // Enter a name to search for their number
    printf("%s's number is: %s\n", search, Get(&phonebook, search)); // If name doesn't exist, returns "NULL"

    char fileName[30];
    printf("\nEnter a file name to save the phonebook in: ");
    scanf("%s", &fileName); // Enter a file name
    Dump(&phonebook, fileName); // Saves the phonebook in the given file

    printf("\n");

    Destroy(&phonebook); // Frees memories
    return 0;
}

/*Output example:

Size of your phonebook is: 6

Pedram was successfully added!
Jill was successfully added!
Carlos was successfully added!
Mark was successfully added!
Kate was successfully added!

Pedram's number has been updated!

Julia was successfully added!

ERROR: Phonebook is full! Impossible to add new entry: Peter

Kate's number has been updated!

Here's your phonebook:
Number #1: Pedram +36121212
Number #2: Jill +3622233
Number #3: Carlos +3633344
Number #4: Mark +3644455
Number #5: Kate +36565656
Number #6: Julia +3666677

Enter a name to search for: Jill
Jill's number is: +3622233

Enter a file name to save the phonebook in: Phonebook.txt
Phonebook successfully saved!

*/