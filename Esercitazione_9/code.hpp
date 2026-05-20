#pragma once
#include <queue>
#include <stack>

class fifo {
    std::queue<int> coda;
public:
    fifo() {}
    void put(int v) { coda.push(v); }
    int get() {
        int v = coda.front();
        coda.pop();
        return v;
    }
    bool empty() const { return coda.empty(); }
};

class lifo {
    std::stack<int> pila;
public:
    lifo() {}
    void put(int v) { pila.push(v); }
    int get() {
        int v = pila.top();
        pila.pop();
        return v;
    }
    bool empty() const { return pila.empty(); }
};