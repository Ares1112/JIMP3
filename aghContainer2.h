/**
* \file aghContainer2.h
* \author Arkadiusz Blasiak, Piotr Jaromin
* \date 31.05.2014
* \brief Definicje metod klasy aghContainer
*/
#ifndef AGHCONTAINER2_H_
#define AGHCONTAINER2_H_

template <class T>
aghContainer<T> :: aghContainer()
{}

template <class T>
aghContainer<T> :: ~aghContainer()
{}

template <class T>
void aghContainer<T> :: append(T const & elem)
{
   if(insert(size(), elem)==false)
   {
      throw aghException(1, "Nie powiodlo sie", __FILE__, __LINE__);
   }
}

template <class T>
bool aghContainer<T> :: replace(int index, T const& elem)
{
   if(index<0 || index>=size() )
   {
      return false;
   }
   else
   {
      remove(index);
      insert(index, elem);
      return true;
   }
}


template <class T>
void aghContainer<T> :: clear(void)
{
   if(isEmpty()==true)
      throw aghException(1, "juz jest puste", __FILE__, __LINE__);
   else
   {
      for(int i=size(); i>0; i--)
         remove(i);

      int length = size();
      for(int i = length; i > 0; i--)
         remove(i);
   }
}


template <class T>
bool aghContainer<T> :: isEmpty(void)
{
   if(size()==0)
      return true;
   else
      return false;
}


template <class T>
int aghContainer<T> :: indexOf(T const& _value, int _from) const
{
   if(_from>=size() )
      throw aghException(1, "zly index", __FILE__, __LINE__);
   else
   {
      for(int i=_from; i<size(); i++)
      {
         if(at(i)==_value)
            return i;
      }
      return -1;
   }
}


template <class T>
bool aghContainer<T> :: contains(T const& _value, int _from) const
{
   if(_from>=size() )
      throw aghException(1, "zly index", __FILE__, __LINE__);
   else
   {
      for(int i=0; i<size(); i++)
      {
         if(at(i)==_value)
            return true;
      }
      return false;
   }
}


template <class T>
aghContainer<T> const & aghContainer<T> :: operator = (aghContainer<T> const& right)
{
   if(this != &right)
   {
      if(!this->isEmpty())
         this->clear();
      *this += right;
   }
   return *this;
}


template<class T>
bool aghContainer<T>::operator==(aghContainer<T> const& right)
{

   if(size() == right.size() )
   {

      for(int i = 0; i < size(); i++)
         if(at(i) != right.at(i))
            return false;

      return true;
   }
   else
      return false;
}

template<class T> bool aghContainer<T>::operator!=(aghContainer<T> const& right)
{
   return !(*this == right);
}

template<class T> T& aghContainer<T>::operator[](int n) const
{
   if(n >= size())
      throw aghException(1, "zly index", __FILE__, __LINE__);
   else
      return at(n);

}

template<class T> aghContainer<T>& aghContainer<T>::operator+=(aghContainer<T> const& right)
{

   for(int i = 0; i < right.size(); i++)
      append(right.at(i));

   return *this;
}

template<class T> aghContainer<T>& aghContainer<T>::operator+=(T const& element)
{
   append(element);
   return *this;
}

template<class T> aghContainer<T>& aghContainer<T>::operator<<(T const& element)
{
   return *this += element;
}

template<class T> aghContainer<T>& aghContainer<T>::operator<<(aghContainer<T> const& right)
{
   return *this += right;
}

template<class U> ostream& operator<<(ostream& stream, aghContainer<U> const& right)
{
   for(int i = 0; i < right.size(); i++) {
      stream << right[i];
      stream << endl;
   }
   return stream;
}
#endif
