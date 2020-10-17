#ifndef _MY_VECTOR_
#define _MY_VECTOR_

#include <iostream>

using namespace std;

const int MAX_VECTOR_SIZE = 100000;

//Шаблон вектора
template <class T>
class TVector
{
protected:
    T* x;
    int length;

public:
    TVector();
    TVector(int _v);
    TVector(int s, int si);
    TVector(const TVector& v); // конструктор копирования
    virtual ~TVector();

    int GetSize() { return length; } // размер вектора

    T& operator[](int pos);            // доступ
    bool operator==(const TVector& v) const; // сравнение
    TVector& operator=(const TVector& v);    // присваивание

    // скалярные операции
    TVector operator+(const T& val); // прибавить
    TVector operator-(const T& val); // вычесть
    TVector operator*(const T& val); // умножить
    TVector operator/(const T& val); //делить

    // векторные операции
    TVector operator+(const TVector& v); // сложение
    TVector operator-(const TVector& v); // вычитание
    TVector operator*(const TVector& v); // скалярное произведение

    // ввод-вывод
    friend istream& operator>>(istream& in, TVector& v)
    {
        for (int i = 0; i < v.length; i++)
        {
            in >> v.x[i];
        }
        return in;
    }

    friend ostream& operator<<(ostream& out, const TVector& v)
    {
        for (int i = 0; i < v.length; i++)
        {
            out << v.x[i] << '\t';
        }
        return out;
    }
};

template <class T>
inline TVector<T>::TVector()
{
    length = NULL;
}

template <class T>
TVector<T>::TVector(int v)
{
    if (v < 0 || v > MAX_VECTOR_SIZE)
    {
        throw logic_error("ERROR");
    }

    length = v;
    x = new T[length];

    for (int i = 0; i < length; i++)
    {
        x[i] = v;
    }
}

template <class T>
TVector<T>::TVector(int s, int si)
{
    if (si < 0)
    {
        throw logic_error("ERROR");
    }

    length = s;
    x = new T[length];

    for (int i = 0; i < length; i++)
    {
        x[i] = si;
    }
}

template <class T> //конструктор копирования
TVector<T>::TVector(const TVector<T>& v)
{
    length = v.length;
    x = new T[length];

    for (int i = 0; i < length; i++)
    {
        x[i] = v.x[i];
    }
}

template <class T>
TVector<T>::~TVector()
{
    length = NULL;

    if (x != 0)
    {
        delete[] x;
    }

    x = NULL;
}

template <class T> // доступ
T& TVector<T>::operator[](int index)
{
    if (index < 0 || index > length)
    {
        throw logic_error("ERROR");
    }

    if ((index >= 0) && (index < length))
    {
        return x[index];
    }

    return x[0];
}

template <class T> // сравнение
bool TVector<T>::operator==(const TVector& v) const
{
    bool res = true;
    if (length != v.length)
    {
        res = false;
    }

    for (int i = 0; i < length; i++)
    {
        if (x[i] != v.x[i])
        {
            res = false;
        }
    }
    return res;
}

template <class T> //присваивание
TVector<T>& TVector<T>::operator=(const TVector& v)
{
    if (this == &v)
    {
        return *this;
    }

    length = v.length;
    x = new T[length];

    for (int i = 0; i < length; i++)
    {
        x[i] = v.x[i];
    }
    return *this;
}

template <class T> //прибавить
TVector<T> TVector<T>::operator+(const T& val)
{
    TVector<T> res;
    res.length = length;
    res.x = new T[res.length];

    for (int i = 0; i < res.length; i++)
    {
        res.x[i] = x[i] + val;
    }
    return res;
}

template <class T> //вычесть
TVector<T> TVector<T>::operator-(const T& val)
{
    TVector<T> res;
    res.length = length;
    res.x = new T[res.length];

    for (int i = 0; i < res.length; i++)
    {
        res.x[i] = x[i] - val;
    }
    return res;
}

template <class T> //умножить
TVector<T> TVector<T>::operator*(const T& val)
{
    TVector<T> res;
    res.length = length;
    res.x = new T[res.length];

    for (int i = 0; i < res.length; i++)
    {
        res.x[i] = x[i] * val;
    }
    return res;
}

template <class T>
inline TVector<T> TVector<T>::operator/(const T& val)
{
    TVector<T> res;
    res.length = length;
    res.x = new T[res.length];

    for (int i = 0; i < res.length; i++)
    {
        res.x[i] = x[i] / val;
    }
    return res;
}

template <class T> //сложение
TVector<T> TVector<T>::operator+(const TVector<T>& v)
{
    if (v.length != length)
    {
        throw logic_error("ERROR");
    }

    TVector<T> res;
    res.length = length;
    res.x = new T[res.length];

    for (int i = 0; i < res.length; i++)
    {
        res.x[i] = x[i] + v.x[i];
    }
    return res;
}

template <class T> //вычитание
TVector<T> TVector<T>::operator-(const TVector<T>& v)
{
    if (v.length != length)
    {
        throw logic_error("ERROR");
    }

    TVector<T> res;
    res.length = length;
    res.x = new T[res.length];

    for (int i = 0; i < res.length; i++)
    {
        res.x[i] = x[i] - v.x[i];
    }
    return res;
}

template <class T> //скалярное произведение
TVector<T> TVector<T>::operator*(const TVector<T>& v)
{
    if (v.length != length)
    {
        throw logic_error("ERROR");
    }

    TVector<T> res;
    res.length = length;
    res.x = new T[res.length];

    for (int i = 0; i < res.length; i++)
    {
        res.x[i] = x[i] * v.x[i];
    }
    return res;
}
#endif