/**
* \file aghVector2.h
* \author Arkadiusz Blasiak, Piotr Jaromin
* \date 31.05.2014
* \brief Definicje klasy aghVector
*/
#ifndef AGHVECTOR2_H_
#define AGHVECTOR2_H_

template <class T>
aghVector<T> :: aghVector()
{
   krokPam=1;
   iloscElem=0;
   vektor=NULL;
   rozmiarAlloc=0;
   zmienAlloc(krokPam);
}

template <class T>
aghVector<T> :: aghVector(aghVector<T> const & right)
{
   krokPam=1;
   iloscElem=0;
   vektor=NULL;
   rozmiarAlloc=0;
   this->aghContainer<T>::operator=(right);
}


template <class T>
aghVector<T> :: aghVector(aghContainer<T> const & right)
{
   krokPam=1;
   iloscElem=0;
   vektor=NULL;
   rozmiarAlloc=0;
   this->aghContainer<T>::operator=(right);
}

template <class T>
aghVector<T> :: ~aghVector()
{
   usunAlloc();
}

template <class T>
int aghVector<T> :: wolnaPamiec() const
{
    return rozmiarAlloc - size();
}

template <class T>
int aghVector<T> :: size() const
{
   return iloscElem;
}

template <class T>
bool aghVector<T> :: insert(int _index, T const & _object)
{
   if(_index>iloscElem || _index<0)
      return false;
   else
   {
      if(wolnaPamiec() == 0)
         powiekszAlloc();

      for(int i = iloscElem; i > _index; i--)
         vektor[i] = vektor[i - 1];

      vektor[_index] = _object;
      iloscElem++;

      return true;
   }
}

template <class T>
T& aghVector<T> :: at(int _index) const
{
   if(_index>=size() || _index<0)
      throw aghException(1, "zly index", __FILE__, __LINE__);
   else
      return vektor[_index];
}

template <class T>
bool aghVector<T> :: remove(int _index)
{
   if(_index>iloscElem || _index<0)
      return false;
   else
   {
      if(size() > 0)
      {
         for(int i = _index; i < size() - 1; i++)
            vektor[i] = vektor[i + 1];

         
         iloscElem--;

         if(wolnaPamiec() > krokPam)
            zmniejszAlloc();

         return true;
      }
      else
         return false;
   }
}


template<class T>
void aghVector<T>::zmienAlloc(int _rozm) {
   if(_rozm < 0)
      throw aghException(1, "zla alokacja pamieci", __FILE__, __LINE__);
    else
    {
      T* temp = new T[_rozm];

      for(int i = 0; i < _rozm && i < size(); i++)
         temp[i] = vektor[i];

      usunAlloc();

      if(size() < _rozm)
         iloscElem=size();
      else
         iloscElem=_rozm;

      rozmiarAlloc = _rozm;
      vektor = temp;
   }
}

template<class T>
void aghVector<T>::powiekszAlloc()
{
   zmienAlloc(rozmiarAlloc + 1);
}

template<class T>
void aghVector<T>::zmniejszAlloc()
{
   zmienAlloc(rozmiarAlloc - 1);
}

template<class T>
void aghVector<T>::usunAlloc()
{
   if(vektor != NULL)
   {
      delete[] vektor;
      vektor = NULL;
   }
}

template<class T>
aghVector<T> const & aghVector<T>::operator=(aghVector<T> const & right)
{
   this->aghContainer<T>::operator =(right);
   return *this;
}
#endif
