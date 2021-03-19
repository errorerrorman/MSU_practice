#include <iostream>
#include <sstream>
#include <cmath>
#include <iomanip>

namespace numbers{
    void copy_stack(complex *head1, complex const *head2, size_t len) {
        for (size_t i = 0; i < len; ++i) {
            *head1 = *head2;
            ++head1;
            ++head2;
        }
    }

    class complex_stack{
        size_t size_{0};
        complex *stack_{nullptr};
    public:
        explicit complex_stack(size_t size = 0)
            : size_{size} {
            if (size_) {
                stack_ = new complex[size_];
            }
        }
        
        complex_stack(const complex_stack& s) : size_{s.size_} {
            if (s.stack_) {
                stack_ = new complex[size_];
                copy_stack(stack_, s.stack_, size_);
            }
        }

        const complex_stack& operator =(const complex_stack& s) {
            if (&s != this) {
                size_ = s.size_;
                if (stack_) {
                    delete [] stack_;
                }
                if (s.stack_) {
                    stack_ = new complex[size_];
                    copy_stack(stack_, s.stack_, size_);
                } else {
                    stack_ = nullptr;
                }
            }
            return *this;
        }

        complex_stack(complex_stack&& s) : size_{s.size_}, stack_{s.stack_} {
            s.size_ = 0;
            s.stack_ = nullptr;
        }

        complex_stack& operator =(complex_stack&& s) {
            if (&s != this) {
                size_ = s.size_;
                if (stack_) {
                    delete [] stack_;
                }
                stack_ = s.stack_;
                s.size_ = 0;
                s.stack_ = nullptr;
            }
            return *this;
        }

        ~complex_stack(){
            if (stack_) {
                delete [] stack_;
            }
        }

        [[nodiscard]] size_t size() const {return size_;}

        [[nodiscard]] complex *stack() const {return stack_;}

        const complex& operator [](size_t n) const noexcept{
            return stack_[size_ - n - 1];
        }

        complex_stack operator <<(const complex& z) const{
            complex_stack tmp(size_ + 1);
            *tmp.stack() = z;
            copy_stack(tmp.stack() + 1, stack_, size_);
            return tmp;
        }

        complex operator +() const {return *stack_;}

        complex_stack operator ~() const {
            if (size_) {
                complex_stack tmp(size_ - 1);
                copy_stack(tmp.stack(), stack_ + 1, size_ - 1);
                return tmp;
            }
            return *this;
        }
    };
}
