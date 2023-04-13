// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
    T* arr;
    uint64_t f, l, c;

 public:
    TPQueue(): f(0), l(0), c(0) {
        arr = new T[size];
    }
    bool full() const {
        return c == size;
    }
    bool empt() const {
        return c == 0;
    }
    void push(const T& val) {
        if (full()) {
            throw std::string("full");
        } else {
            c++;
            int id = l;
            for (int i = f; i < l; i++) {
                if (arr[i].prior < val.prior) {
                    id = i;
                    break;
                }
            }
            for (int i = l; i > id; i--) {
                arr[i % size] = arr[(i - 1) % size];
            }
            arr[id % size] = val;
            l++;
        }
    }
    T& pop() {
        if (empt()) 
            throw std::string("empty");
        c--;
        return arr[f++ % size];
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
