#include <string>
#include <vector>
#include "hash_functions.h"

class Ceil {
public:
    Ceil (std::string key, std::string data) : key(key), data(data) {}
    std::string key;
    std::string data;
    Ceil* next{NULL};
    Ceil* prev{NULL};
};

class LinkedList {
private:
    Ceil* head{nullptr};
    Ceil* tail{nullptr};
public:
// сделать шаблонный класс и методы <T>
    bool insert(std::string key, std::string value) {
        if (head == nullptr) {
            Ceil *obj = new Ceil(key, value); // попробовать через auto obj = std::make_unique<Ceil>(key, value)
            head = tail = obj;
            return false;
        }
        else {
            Ceil *tmp = head;
            while (tmp) {
                if (key == tmp->key) {
                    tmp->data = value;
                    return false;
                }
                tmp = tmp->next;
            }
            Ceil *obj = new Ceil(key, value);
            obj->prev = tail;
            tail->next = obj;
            tail = obj;
            return true;
        }
    }

    bool erase(std::string key) {
        Ceil *tmp = head;
        while (tmp) {
            if (tmp->key == key) {
                if (head == tail) {
                    head == nullptr;
                    tail == nullptr;
                    delete tmp;
                }
                else if (tmp == head) {
                    head = head->next;
                    delete head->prev;
                    head->prev = nullptr;
                    return true;
                }
                else if (tmp == tail) {
                    tail = tail->prev;
                    delete tail->next;
                    tail->next = nullptr;
                    return true;
                }
                else {
                    tmp->prev->next = tmp->next;
                    tmp->next->prev = tmp->prev;
                    delete tmp;
                    return true;
                }
            }
            tmp = tmp->next;
        }
        throw "KeyError";
    }

    std::string get(std::string key) {
        Ceil *tmp = head;
        while (tmp) {
            if (key == tmp->key) return tmp->data;
            tmp = tmp->next;
        }
        throw "KeyError";
    }

    bool is_head_null() { return  head ? true : false; }
};

class My_Hash_Map {
private:
    size_t size{0};
    int collisions{0};
    int (*hash_function)(std::string, size_t);
public:
    std::vector<LinkedList> pole;

    My_Hash_Map (int (*func)(std::string, size_t), size_t size) : pole(size), hash_function(func), size(size) {}

    void add_item(std::string key, std::string value) {
        int idx = hash_function(key, size);
        collisions += pole[idx].insert(key, value);
    }

    bool del_item(std::string key) {
        int idx = hash_function(key, size);
        return pole[idx].erase(key);
    }

    std::string get_item(std::string key) {
        int idx = hash_function(key, size);
        return pole[idx].get(key);
    }

    int get_collisions() {
        return this->collisions;
    }
};