/**
* \file aghVector.h
* \author Arkadiusz Blasiak, Piotr Jaromin
* \date 31.05.2014
* \brief Klasa aghVector
*/
#ifndef AGHVECTOR_H
#define AGHVECTOR_H

#include "aghContainer.h"

/**
* \class aghVector
* \author Arkadiusz Blasiak, Piotr Jaromin
* \date 31.05.2014
* \brief Klasa pojemnikowa Vector
*/
template <class T>
class aghVector: public aghContainer<T>
{
private:
   T* vektor; ///< tablica przechowujaca elementy
   int iloscElem; ///< ilosc elementow
   int rozmiarAlloc;  ///< rozmiar zaalokowanej pamieci
   int krokPam; ///< Krok rozmiaru pamieci

   /// \brief Metoda zmienia rozmiar zaalokowanej pamieci
   ///
   /// \param _size - rozmiar
   void zmienAlloc(int _size);

   /// \brief Medota usuwa zaalokowana pamiec
   void usunAlloc();

   /// \brief Metoda zwieksza o 1 zaalokowana pamiec
   void powiekszAlloc();

   /// \brief Metoda zmiejsza o 1 zaalokowana pamiec
   void zmniejszAlloc();


public:
   /// \brief konstruktor bezparametrowy
   aghVector();

   /// \brief konstruktor kopiuj¹cy
   ///
   /// \param other - obiekt do kopiowania
   aghVector(aghVector<T> const & other);

   /// \brief konstruktor parametrowy
   ///
   /// \param other - klasa bazowa
   aghVector(aghContainer<T> const & other);

   /// \brief destruktor
   virtual ~aghVector();

   /// \brief Metoda zwraca ilosc wolnego miejsca
   ///
   /// \return ilosc wolnego miejsca
   int wolnaPamiec() const;

   /// \brief Metoda zwracajaca rozmiar pojemnika
   ///
   /// \return rozmiar pojemnika
   int size() const;

   /// \brief Metoda wirtualna wstawaiana elementu do pojemnika
   ///
   /// \param _index - indeks
   /// \param _object - element
   /// \return True jesli miejsce prawidlowe
   bool insert(int _index, T const & _object);

   /// \brief Metoda zwracajaca element na podanym indeksie
   ///
   /// \param _index - indeks
   /// \return referencja do elementu _index
   T& at(int _index) const;

   /// \brief Metoda usuwajaca element na _index
   ///
   /// \param _index - indeks
   /// \return True jesli miejsce usuniecia prawidlowe
   bool remove(int _index);

   /// \brief Przeciozony operator przypisania
   aghVector<T> const & operator=(aghVector const &);

};


#endif

