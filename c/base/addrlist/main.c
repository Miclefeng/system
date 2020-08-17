#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "addrlist.h"

static char name[MAX_ADDRESSES][NAME_LENGTH];
static char address[MAX_ADDRESSES][ADDR_LENGTH];
static char phone[MAX_ADDRESSES][PHONE_LENGTH];

static int find_entry(char const *name_to_find);

int main()
{
    char const *username = "wxmwife";
    char const *useraddress;
    char const *userphone;

    strcpy(*name, "zsshusband");
    strcpy(*address, "beijing");
    strcpy(*phone, "18310087566");
    //    strcpy(*(&name[0]+1), "wxmwife");
    strcpy(*(name+1), "wxmwife");
    strcpy(*(address+1), "beijing");
    strcpy(*(phone+1), "17610869366");

    printf("name = %d, addr = %d, phone = %d, max = %d\n", NAME_LENGTH, ADDR_LENGTH, PHONE_LENGTH, MAX_ADDRESSES);
    useraddress = lookup_address(username);
    userphone = lookup_phone(username);

    printf("address = %s, phone = %s\n", useraddress, userphone);
    return 0;
}

static int find_entry(char const *name_to_find)
{
    int entry;

    for (entry = 0; entry < MAX_ADDRESSES; entry++) {
        if (strcmp(name_to_find, name[entry]) == 0)
            return entry;
    }

    return -1;
}

char const *lookup_address(char const *name)
{
    int entry;

    entry = find_entry(name);

    if (-1 == entry) {
        return NULL;
    } else {
        return address[entry];
    }
}

char const *lookup_phone(char const *name)
{
    int entry;

    entry = find_entry(name);

    if (-1 == entry) {
        return NULL;
    } else {
        return phone[entry];
    }
}
