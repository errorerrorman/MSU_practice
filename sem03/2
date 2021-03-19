#include <iostream>
#include <sstream>
#include <cmath>
#include <iomanip>

namespace numbers{
    class complex{
        double re_{};
        double im_{};
    public:
        complex(double re = 0, double im = 0) : re_{re}, im_{im} {}

        explicit complex(const std::string& str) noexcept {
            char c1, c2, c3;
            std::istringstream s(str);
            s >> c1 >> re_ >> c2 >> im_ >> c3;
        }

        double re() const noexcept {return re_;}
        double im() const noexcept {return im_;}

        double abs2() const {
            return re_ * re_ + im_ * im_;
        }
        double abs() const {
            return std::sqrt(abs2());
        }

        std::string to_string() const{
            std::ostringstream s;
            s.precision(10);
            s << '(' << re_ << ',' << im_ << ')';
            return s.str();
        }

        complex operator ~() const{
            return {re_, -im_};
        }

        complex operator -() const{
            return {-re_, -im_};
        }

        complex operator +=(const complex& z){
            re_ += z.re();
            im_ += z.im();
            return *this;
        }

        complex operator -=(const complex& z){
            return *this += -z;
        }

        complex operator *=(const complex& z){
            double t_re = re_ * z.re() - im_ * z.im();
            double t_im = re_ * z.im() + im_ * z.re();
            re_ = t_re;
            im_ = t_im;
            return *this;
        }

        complex operator /=(const complex& z){
            double c = z.abs2();
            double t_re = (re_ * z.re() + im_ * z.im()) / c;
            double t_im = (im_ * z.re() - re_ * z.im()) / c;
            re_ = t_re;
            im_ = t_im;
            return {re_, im_};
        }
    };

    complex operator +(const complex& a, const complex& b){
        complex t = a;
        return t += b;
    }

    complex operator -(const complex& a, const complex& b){
        complex t = a;
        return t -= b;
    }

    complex operator *(const complex& a, const complex& b){
        complex t = a;
        return t *= b;
    }
    
    complex operator /(const complex& a, const complex& b){
        complex t = a;
        return t /= b;
    }
}
