#ifndef __TMATRIX_H__
#define __TMATRIX_H__

#include <iostream>

using namespace std;

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

// Шаблон вектора
template <class ValType>
class TVector
{
protected:
	ValType* pVector;
	int Size;       // размер вектора
	int StartIndex; // индекс первого элемента вектора
public:
	TVector(int s = 10, int si = 0);
	TVector(const TVector& v);                // конструктор копирования
	~TVector();
	int GetSize() { return Size; } // размер вектора
	int GetStartIndex() { return StartIndex; } // индекс первого элемента
	ValType& operator[](int pos);             // доступ
	bool operator==(const TVector& v) const;  // сравнение
	bool operator!=(const TVector& v) const;  // сравнение
	TVector& operator=(const TVector& v);     // присваивание

	// скалярные операции
	TVector  operator+(const ValType& val);   // прибавить скаляр
	TVector  operator-(const ValType& val);   // вычесть скаляр
	TVector  operator*(const ValType& val);   // умножить на скаляр

	// векторные операции
	TVector  operator+(const TVector& v);     // сложение
	TVector  operator-(const TVector& v);     // вычитание
	ValType  operator*(const TVector& v);     // скалярное произведение

	// ввод-вывод
	friend istream& operator>>(istream& in, TVector& v)
	{
		for (int i = 0; i < v.Size; i++)
			in >> v.pVector[i];

		return in;
	}
	friend ostream& operator<<(ostream& out, const TVector& v)
	{
		for (int i = 0; i < v.Size; i++)
			out << v.pVector[i] << ' ';

		return out;
	}
};

template <class ValType>
TVector<ValType>::TVector(int s, int si)
{
	if ((s < 0) || (s > MAX_VECTOR_SIZE) || (si < 0))
		throw "Wrong value";
	Size = s;
	pVector = new ValType[Size];
	StartIndex = si;
}

template <class ValType> //конструктор копирования
TVector<ValType>::TVector(const TVector<ValType>& v)
{
	if (this != &v)
	{
		if (Size != v.Size)
		{
			Size = v.Size;
			pVector = new ValType[Size];
		}
		StartIndex = v.StartIndex;
		for (int i = 0; i < Size; i++)
			pVector[i] = v.pVector[i];
	}
}

template <class ValType>
TVector<ValType>::~TVector()
{
	delete[] pVector;
}

template <class ValType> // доступ
ValType& TVector<ValType>::operator[](int pos)
{
	if ((pos - StartIndex >= 0) && (pos - StartIndex < Size))
		return pVector[pos - StartIndex];
	else
		throw(pos);
}

template <class ValType> // сравнение
bool TVector<ValType>::operator==(const TVector& v) const
{
	if ((Size == v.Size) && (StartIndex == v.StartIndex))
	{
		for (int i = 0; i < Size; i++)
			if (pVector[i] != v.pVector[i])
				return false;
		return true;
	}
	else
		return false;
}

template <class ValType> // сравнение
bool TVector<ValType>::operator!=(const TVector& v) const
{
	return !(*this == v);
}

template <class ValType> // присваивание
TVector<ValType>& TVector<ValType>::operator=(const TVector& v)
{
	if (&v != this)
	{
		if (Size != v.Size)
		{
			Size = v.Size;
			delete[] pVector;
			pVector = new ValType[Size];
		}
		StartIndex = v.StartIndex;
		for (int i = 0; i < Size; i++)
			pVector[i] = v.pVector[i];
	}
	return *this;
}

template <class ValType> // прибавить скаляр
TVector<ValType> TVector<ValType>::operator+(const ValType& val)
{
	TVector<ValType> temp(*this);
	for (int i = 0; i < Size; i++)
		temp.pVector[i] += val;

	return temp;
}

template <class ValType> // вычесть скаляр
TVector<ValType> TVector<ValType>::operator-(const ValType& val)
{
	TVector<ValType> temp(*this);
	for (int i = 0; i < Size; i++)
		temp.pVector[i] -= val;

	return temp;
}

template <class ValType> // умножить на скаляр
TVector<ValType> TVector<ValType>::operator*(const ValType& val)
{
	TVector<ValType> res(*this);
	for (int i = 0; i < Size; i++)
		res.pVector[i] *= val;

	return res;
}

template <class ValType> // сложение
TVector<ValType> TVector<ValType>::operator+(const TVector<ValType>& v)
{
	if ((Size != v.Size) || (StartIndex != v.StartIndex))
		throw "Wrong value";
	TVector<ValType> temp(Size, StartIndex);
	for (int i = 0; i < Size; i++)
		temp.pVector[i] = pVector[i] + v.pVector[i];

	return temp;
}

template <class ValType> // вычитание
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType>& v)
{
	if ((Size != v.Size) || (StartIndex != v.StartIndex))
		throw "Wrong value";
	TVector<ValType> temp(Size, StartIndex);
	for (int i = 0; i < Size; i++)
		temp.pVector[i] = pVector[i] - v.pVector[i];

	return temp;
}

template <class ValType> // скалярное произведение
ValType TVector<ValType>::operator*(const TVector<ValType>& v)
{
	if ((Size != v.Size) || (StartIndex != v.StartIndex))
		throw "Wrong value";
	ValType temp = 0;
	for (int i = 0; i < Size; i++)
		temp += pVector[i] * v.pVector[i];

	return temp;
}
#endif