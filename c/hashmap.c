/*
  Hashmap implementation in C

  Goal: To crate a hash table using which an element can be stored and retrieved using a key/value pair.
  e.g. x["key1"] ---> "value1"
  x["key2"] ---> "value2"
  x["key3"] ---> "value3" and so on...

  Requirements
  - insert a key value pair in O(1)
  - retrieve a key value pair in O(1)
  - delete a key value pair in O(1)

  Constraints/Assumptions
  - To begin with, only consider string (char *) types for keys and values
  - Fixed memory address range

  Method
  - Function takes key and value
  - The key gets converted to an address
  - The value gets stored in that address
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TABLE_SIZE 64

typedef struct {
  char *key[TABLE_SIZE];
  char *value[TABLE_SIZE];
  char occupied[TABLE_SIZE];
  int shift[TABLE_SIZE];
} hashTable; 

int hash(char *s){
  unsigned int len, hash_val = 0;
  len = strlen(s);
  for(int i=0; i<len; i++){
    hash_val += ((int)s[i]) ^ i;
  }
  return hash_val % TABLE_SIZE;
}

int hash_insert(hashTable *h, char *key, char *val){
  int hash_val, hash_index;
  hash_index = hash(key);

  /* check if index hash_index is occupied */
  if( h->occupied[hash_index] == 1){
    /* if hash_index is occupied, search next free location */
  } else {
    h->occupied[hash_index] = 1;
    h->key[hash_index] = key;
    h->value[hash_index] = val;
  }
  return 0;
}

char* hash_read(hashTable *h, char *key){
  int hash_index = hash(key);
  return h->value[hash_index];
}

int main(){
  hashTable ht;
  int res;
  res = hash_insert(&ht, "hello", "world");
  if(res != 0){
    printf("hashing failed\n");
    return -1;
  }
  printf("Key is hello and value is %s", hash_read(&ht, "hello"));
  return 0;
}
