#ifndef KEYVALSTORE_H
#define KEYVALSTORE_H

#define MAX_ENTRIES 100
#define MAX_KEY_LEN 64
#define MAX_VAL_LEN 256

int put(char* key, char* value);
int get(char* key, char* res);
int del(char* key);

#endif