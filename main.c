#include <stdio.h>
#include "keyValStore.h"

int main() {
    char result[256];

    // PUT testen
    put("key1", "value1");
    put("key2", "value2");
    printf("PUT key1/key2 gespeichert\n");

    // GET testen
    if (get("key1", result) == 0)
        printf("GET key1 = %s\n", result);  // erwartet: value1
    else
        printf("GET key1 = FEHLER\n");

    // GET nicht vorhandener Key
    if (get("key99", result) < 0)
        printf("GET key99 = key_nonexistent ✓\n");

    // PUT überschreiben
    put("key1", "value3");
    get("key1", result);
    printf("GET key1 nach update = %s\n", result);  // erwartet: value3

    // DEL testen
    if (del("key2") == 0)
        printf("DEL key2 = key_deleted ✓\n");

    // DEL nicht vorhandener Key
    if (del("key99") < 0)
        printf("DEL key99 = key_nonexistent ✓\n");

    return 0;
}