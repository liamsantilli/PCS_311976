#pragma once
#include <vector>
#include <algorithm>
#include <limits>

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
            if (A[j] < A[j - 1]) std::swap(A[j], A[j - 1]);
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
            if (A[j] < A[min_idx]) min_idx = j;
        }
        std::swap(A[i], A[min_idx]);
    }
}

template<typename T>
void merge(std::vector<T>& A, size_t p, size_t q, size_t r) {
    size_t n1 = q - p + 1;
    size_t n2 = r - q;
    std::vector<T> L(n1 + 1);
    std::vector<T> R(n2 + 1);

    for (size_t i = 0; i < n1; ++i) L[i] = A[p + i];
    for (size_t j = 0; j < n2; ++j) R[j] = A[q + j + 1];

    if constexpr (std::numeric_limits<T>::has_infinity) {
        L[n1] = std::numeric_limits<T>::infinity();
        R[n2] = std::numeric_limits<T>::infinity();
    } else {
        L[n1] = std::numeric_limits<T>::max();
        R[n2] = std::numeric_limits<T>::max();
    }

    size_t i = 0, j = 0;
    for (size_t k = p; k <= r; ++k) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

template<typename T>
void merge_sort_rec(std::vector<T>& A, size_t p, size_t r) {
    if (p < r) {
        size_t q = p + (r - p) / 2;
        merge_sort_rec(A, p, q);
        merge_sort_rec(A, q + 1, r);
        merge(A, p, q, r);
    }
}

template<typename T>
void ordina_merge(std::vector<T>& A) {
    if (A.size() <= 1) return;
    merge_sort_rec(A, 0, A.size() - 1);
}

template<typename T>
int partition(std::vector<T>& A, int p, int r) {
    T x = A[r];
    int i = p - 1;
    for (int j = p; j <= r - 1; ++j) {
        if (A[j] <= x) {
            i++;
            std::swap(A[i], A[j]);
        }
    }
    std::swap(A[i + 1], A[r]);
    return i + 1;
}

template<typename T>
void quicksort_rec(std::vector<T>& A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quicksort_rec(A, p, q - 1);
        quicksort_rec(A, q + 1, r);
    }
}

template<typename T>
void ordina_quick(std::vector<T>& A) {
    if (A.size() <= 1) return;
    quicksort_rec(A, 0, (int)A.size() - 1);
}

template<typename T>
void quicksort_ibrido_rec(std::vector<T>& A, int p, int r, int soglia) {
    if (p < r) {
        if ((r - p + 1) < soglia) {
            std::vector<T> sub;
            for(int k = p; k <= r; ++k) sub.push_back(A[k]);
            ordina_inserimento(sub);
            for(int k = p; k <= r; ++k) A[k] = sub[k-p];
        } else {
            int q = partition(A, p, r);
            quicksort_ibrido_rec(A, p, q - 1, soglia);
            quicksort_ibrido_rec(A, q + 1, r, soglia);
        }
    }
}

template<typename T>
void ordina_quick_ibrido(std::vector<T>& A, int soglia = 15) {
    if (A.size() <= 1) return;
    quicksort_ibrido_rec(A, 0, (int)A.size() - 1, soglia);
}