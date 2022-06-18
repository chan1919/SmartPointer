//一个极简的shared_pointer实现
#include <iostream>
using namespace std;

template <typename T>
class SmartPointer {
private:
    T* p_;
    size_t* count_;
public:
    SmartPointer(T* ptr = nullptr) : p_(ptr) {
        if (p_) {
            count_ = new size_t(1);
        }else {
            count_ = size_t(0);
        }
    }

    SmartPointer(const SmartPointer& ptr) {
        p_ = ptr.p_;
        count_ = ptr.count_;
        (*count_)++;
    }

    SmartPointer& operator = (const SmartPointer& ptr) {
        if (p_ == ptr.p_) {
            return *this;
        }

        if (p_) {
            if (--(*count_) == 0) {
                delete p_;
                delete count_;
            }
        }

        p_ = ptr.p_;
        count_ = ptr.count_;
        (*count_)++;
        return *this;
    }

    ~SmartPointer() {
        if (--(*count_) == 0) {
            delete p_;
            delete count_;
        }
    }

    size_t use_count() {
        return *count_;
    }
};