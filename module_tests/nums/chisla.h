#ifndef CHISLA_H
#define CHISLA_H
#include <QTextStream>
class number {
    int a;
public:
    number(): a(0) {}
    number(int x): a(x) {}
    number(const number& X):a(X.a){}
    number& operator=(const number& X) {
        if (this != &X) {
            a = X.a;
        } return *this;
    }
    int nod(const number& X) {
        int x = a;
        int b = X.a;

        while (b != 0) {
            int temp = b;
            b = x % b;
            x = temp;
        }
        return x;
    }
    int nok(const number& X) {
        return (a * X.a) / nod(X);
    }
    bool IsSimple() {
        if (a == 1 || a == 2) return false;
        for (int i = 2; i <= sqrt(a) + 1; i++) {
            if (a % i == 0) {
                return false;

            }
        }
        return true;
    }
    int count_numb() {
        int x = a;
        unsigned int res = 0;
        if (x == 0)
        {
            res = 1;
            return res;
        }
        while (x != 0)
        {
            x /= 10;
            res++;
        }
        return res;
    }
    bool is_Armstrong() {
        int y = a;
        unsigned int sum = 0, z = y, k = 1;
        k = count_numb();
        unsigned int ost;
        bool res = false;
        while (y != 0)
        {

            ost = y % 10;
            ost = pow(ost, k);
            sum += ost;
            y /= 10;
        }

        if (sum == z)
            res = true;
        return res;

    }
    friend QTextStream& operator>>(QTextStream& in, number& X) {
        in >> X.a;
        return in;
    }
    friend QTextStream& operator<<(QTextStream& out,const number& X) {
        out << X.a;
        return out;
    }
};

#endif // CHISLA_H
