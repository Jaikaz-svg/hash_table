#pragma once
#include <openssl/sha.h>

int hash_func1(std::string key, size_t size) {
    uint32_t hash = 2166136261u;
    for (char c : key) {
        hash ^= c;
        hash *= 16777619u;
    }
    return hash % size;
}

int hash_func2(std::string key, size_t size) {
    unsigned long hash = 5381;
    for (char c : key) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % size;
}

int hash_func3(std::string key, size_t size) {
    int hash = 0;
    for (char c : key) {
        hash += c;
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash % size;
}

// int SHA_hash(const std::string& key, size_t size) {
//     unsigned char output[20];
//     SHA1(reinterpret_cast<const unsigned char*>(key.c_str()), key.length(), output);
//     return *reinterpret_cast<int*>(output) % size;
// }