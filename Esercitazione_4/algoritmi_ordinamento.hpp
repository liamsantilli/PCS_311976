#pragma once
#include <vector>
#include <algorithm>

template<typename T>
bool e_ordinato(const std::vector<T>& v) {
    if (v.size() <= 1) return true;
    for (size_t i = 0; i < v.size() - 1; ++i) {
        if (v[i] > v[i + 1]) return false;
    }
    return true;
}

template<typename T>
void ordina_bolle(std::vector<T>& A) {
    if (A.empty()) return;
    for (size_t i = 0; i < A.size() - 1; ++i) {
        for (size_t j = A.size() - 1; j > i; --j) {
            if (A[j] < A[j - 1]) {
                std::swap(A[j], A[j - 1]);
            }
        }
    }
}

template<typename T>
void ordina_inserimento(std::vector<T>& A) {
    for (size_t j = 1; j < A.size(); ++j) {
        T chiave = A[j];
        int i = (int)j - 1;
        while (i >= 0 && A[i] > chiave) {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = chiave;
    }
}

template<typename T>
void ordina_selezione(std::vector<T>& A) {
    if (A.empty()) return;
    for (size_t i = 0; i < A.size() - 1; ++i) {
        size_t min_idx = i; 
        for (size_t j = i + 1; j < A.size(); ++j) {
            if (A[j] < A[min_idx]) {
                min_idx = j;
            }
        }
        std::swap(A[i], A[min_idx]);
    }
}