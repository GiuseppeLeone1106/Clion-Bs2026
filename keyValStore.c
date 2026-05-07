#include "keyValStore.h"
#include <string.h>
#include <stdio.h>

typedef struct {
    char key[MAX_KEY_LEN];
    char value[MAX_VAL_LEN];
    int used;
} Entry;

static Entry store[MAX_ENTRIES];

static int find_index(char* key) {
    for (int i = 0; i < MAX_ENTRIES; i++) {
        if (store[i].used && strcmp(store[i].key, key) == 0) {
            return i;
        }
    }
    return -1;
}

// PUT: Wert speichern oder überschreiben
int put(char* key, char* value) {
    int idx = find_index(key);

    if (idx >= 0) {
        strncpy(store[idx].value, value, MAX_VAL_LEN - 1);
        store[idx].value[MAX_VAL_LEN - 1] = '\0';
        return 1;
    }

    for (int i = 0; i < MAX_ENTRIES; i++) {
        if (!store[i].used) {
            strncpy(store[i].key, key, MAX_KEY_LEN - 1);
            store[i].key[MAX_KEY_LEN - 1] = '\0';
            strncpy(store[i].value, value, MAX_VAL_LEN - 1);
            store[i].value[MAX_VAL_LEN - 1] = '\0';
            store[i].used = 1;
            return 0;
        }
    }

    return -1;
}

// GET: Wert abrufen
int get(char* key, char* res) {
    int idx = find_index(key);
    if (idx < 0) return -1;

    strncpy(res, store[idx].value, MAX_VAL_LEN - 1);
    res[MAX_VAL_LEN - 1] = '\0';
    return 0;
}

// DEL: Eintrag löschen
int del(char* key) {
    int idx = find_index(key);
    if (idx < 0) return -1;

    store[idx].used = 0;
    memset(store[idx].key, 0, MAX_KEY_LEN);
    memset(store[idx].value, 0, MAX_VAL_LEN);
    return 0;
}