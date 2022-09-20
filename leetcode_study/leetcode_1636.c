#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "uthash.h"

typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} HashItem;

HashItem* hashFindItem(HashItem** obj, int key) {
    HashItem* pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    return pEntry;
}

bool hashAddItem(HashItem** obj, int key, int val) {
    if(hashFindItem(obj, key)) {
        return false;
    }
    HashItem* pEntry = (HashItem*)malloc(sizeof(HashItem));
    pEntry->key = key;
    pEntry->val = val;
    HASH_ADD_INT(*obj, key, pEntry);
    return true;
}

bool hashSetItem(HashItem** obj, int key, int val) {
    HashItem* pEntry = hashFindItem(obj, key);
    if(!pEntry) {
        hashAddItem(obj, key, val);
    }
    else {
        pEntry->val = val;
    }
    return true;
}

int hashGetItem(HashItem** obj, int key, int defaultVal) {
    HashItem* pEntry = hashFindItem(obj, key);
    if(!pEntry) {
        return defaultVal;
    }
    return pEntry->val;
}

void hashFree(HashItem** obj) {
    HashItem* curr = NULL, * tmp = NULL;
    HASH_ITER(hh, *obj, curr, tmp) {
        HASH_DEL(*obj, curr);
        free(curr);
    }
}

HashItem* cnt = NULL;

static inline int cmp(const void* pa, const void* pb) {
    int a = *(int*)pa;
    int b = *(int*)pb;
    int cnta = hashGetItem(&cnt, a, 0);
    int cntb = hashGetItem(&cnt, b, 0);
    if(cnta != cntb) {
        return cnta - cntb;
    }
    return b - a;
}

int* frequencySort(int* nums, int numsSize, int* returnSize) {
    cnt = NULL;
    for(int i = 0; i < numsSize; i++) {
        hashSetItem(&cnt, nums[i], hashGetItem(&cnt, nums[i], 0) + 1);
    }
    qsort(nums, numsSize, sizeof(int), cmp);
    hashFree(&cnt);
    *returnSize = numsSize;
    return nums;
}
