#ifndef _MATRIX_
#define _MATRIX_
#include "MyVector.h"

const int MAX_MATRIX_SIZE = 100000;


template <class T> //Верхнетреугольная матрица
class TMatrix : public TVector<TVector<T> >
{
private:
    int mSize;
public:
    TMatrix(int s);
    TMatrix(const TMatrix& mt);                        //копирование
    TMatrix(const TVector<TVector<T> >& mt);    //преобразование типа
    ~TMatrix();

    int GetSize() { return mSize; };               //Получение размера Матрицы
    bool operator==(const TMatrix& mt) const;     //сравнение Матриц
    TMatrix operator= (const TMatrix& mt);       //присваивание Матриц
    TMatrix  operator+ (const TMatrix& mt);     //сложение Матриц
    TMatrix  operator- (const TMatrix& mt);    //вычитание Матриц
    TMatrix  operator* (const TMatrix& mt);   //умножение Матриц

    // ввод / вывод
    friend istream& operator>>(istream& in, TMatrix& mt)
    {
        for (int i = 0; i < mt.length; i++)
        {
            in >> mt.x[i];
        }
        return in;
    }
    friend ostream& operator<<(ostream& out, const TMatrix& mt)
    {
        for (int i = 0; i < mt.length; i++)
        {
            out << mt.x[i] << endl;
        }
        return out;
    }
};

template<class T>
inline TMatrix<T>::TMatrix(int s) : TVector<TVector <T> >(s)
{
    if (s < 0 || s > MAX_MATRIX_SIZE)
    {
        throw  logic_error("ERROR");
    }
    mSize = s;
}

template <class T> //конструктор копирования
inline TMatrix<T>::TMatrix(const TMatrix<T>& mt) : TVector<TVector<T> >(mt)
{
    mSize = mt.length;
}

template <class T> //конструктор преобразования типа
inline TMatrix<T>::TMatrix(const TVector<TVector<T> >& mt) : TVector<TVector<T> >(mt)
{

}

template<class T>
inline TMatrix<T>::~TMatrix()
{
    if (mSize != 0)
    {
        mSize = NULL;
    }
}

template <class T> //сравнение
bool TMatrix<T>::operator==(const TMatrix<T>& mt) const
{
    bool res = true;
    int S = this->length;

    if (S != mt.length)
    {
        res = false;
    }

    for (int i = 0; i < S; i++)
    {
        if (this->x[i] == mt.x[i])
        {
            res = true;
        }
        else res = false;
    }

    return res;
}

template <class T> //присваивание
inline TMatrix<T> TMatrix<T>::operator=(const TMatrix<T>& mt)
{
    if (this != &mt)
    {
        if (this->length != mt.length)
        {
            if (this->x != NULL)
            {
                delete[] this->x;
            }
            this->x = new TVector<T>[mt.length];
        }

        this->length = mt.length;

        for (int i = 0; i < this->length; i++)
        {
            this->x[i] = mt.x[i];
        }
    }

    return *this;
}

template <class T> // сложение
inline TMatrix<T> TMatrix<T>::operator+(const TMatrix<T>& mt)
{
    if (this->GetSize() != mt.length)
    {
        throw  logic_error("ERROR");
    }

    TMatrix<T> temp(*this);

    for (int i = 0; i < this->length; i++)
    {
        temp.x[i] = temp.x[i] + mt.x[i];
    }
    return temp;
}

template <class T> //вычитание
inline TMatrix<T> TMatrix<T>::operator-(const TMatrix<T>& mt)
{
    if (this->GetSize() != mt.length)
    {
        throw  logic_error("ERROR");
    }

    TMatrix<T> temp(*this);

    for (int i = 0; i < this->length; i++)
    {
        temp.x[i] = temp.x[i] - mt.x[i];
    }
    return temp;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator*(const TMatrix& mt)
{
    TMatrix<T> temp(*this);

    for (int i = 0; i < this->length; i++)
    {
        temp.x[i] = temp.x[i] * mt.x[i];
    }
    return temp;
}

#endif
