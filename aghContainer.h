/**
* \file aghContainer.h
* \author Arkadiusz Blasiak, Piotr Jaromin
* \date 31.05.2014
* \brief Klasa aghContainer
*/

#ifndef AGHCONTAINER_H
#define AGHCONTAINER_H

/**
* \class aghContainer
* \author Arkadiusz Blasiak, Piotr Jaromin
* \date 31.05.2014
* \brief Klasa abstrakcyjna, z ktorej wywodza sie klasy pojemnikowe
*/
template <class T>
class aghContainer
{
public:
   /// \brief Konstruktor bezparametrowy
   aghContainer();

   /// \brief Destruktor
   virtual ~aghContainer();

   /// \brief Metoda dodajaca element do pojemnika
   ///
   /// \param elem - Element
   void append(T const&);

   /// \brief Metoda wirtualna wstawaiana elementu do pojemnika
   ///
   /// \return True jesli miejsce prawidlowe
   virtual bool insert(int, T const&)=0;

   /// \brief Medota podmiany elementu
   ///
   /// \param index - indeks elementu w pojemniku
   /// \param elem - element wstawiany
   /// \return True jesli miejsce prawidlowe
   bool replace(int, T const&);

   /// \brief Metoda wirtualna zwracaj¹ca wartoœæ elementu
   ///
   /// \return referencja do elementu
   virtual T& at(int) const=0;

   /// \brief Metoda wirtualna zwracajaca ilosc elementow
   ///
   /// \return Ilosc elementow
   virtual int size(void) const=0;

   /// \brief Metoda wirtualna usuwajaca dany element
   ///
   /// \return True jesli miejsce usuniecia jest prawidlowe
   virtual bool remove(int)=0;

   /// \brief Metoda oprozniajaca pojemnik
   ///
   void clear(void);

   /// \brief Metoda sprawdzajaca czy pojemnik jest pusty
   ///
   /// \return True jesli pusty
   bool isEmpty(void);

   /// \brief Metoda wyszukujaca element w pojemniku od danego indeksu
   ///
   /// \param _value - element
   /// \param _from - od indeksu
   /// \return Indeks pierwszego elementu o wartosci _value, jesli nie znaleziono to -1
   int indexOf(T const& _value, int _from = 0) const;

   /// \brief Metoda sprawdzajaca czy dany element jest juz w pojemniku
   ///
   /// \param _value - element
   /// \param _from - od indeksu
   /// \return True jesli znaleziono
   bool contains(T const& _value, int _from = 0) const;

   /// \brief przeciazony operator przypisania
   aghContainer<T> const & operator=(aghContainer<T> const &);

   /// \brief przeciazany operator porownania
   ///
   /// \return True jesli takie same
   bool operator==(aghContainer<T> const& right);

   /// \brief przeciazony operator relacji
   ///
   /// \return True jesli rozne
   bool operator!=(aghContainer<T> const& right);

   /// \brief przeciazaony operator dostepu
   ///
   /// \return element o indeksie n
   T& operator[](int n) const;

   /// \brief Przeciazony operator +=
   ///
   /// dopisuje elementy z right
   /// \return zwraca referencje do this
   aghContainer<T>& operator+=(aghContainer<T> const& right);

   /// \brief Przeciozony operator +=
   ///
   /// dodaje element do pojemnika
   /// \return zwraca referencje do this
   aghContainer<T>& operator+=(T const& element);

   /// \brief Przeciozony operator <<
   ///
   /// dodaje element do pojemnika
   /// \return zwraca referencje do this
   aghContainer<T>& operator<<(T const& element);

   /// \brief Przeciozony operator <<
   ///
   /// dopisuje wszystkie elementu z pojemnika right
   /// \return zwraca referencje do this
   aghContainer<T>& operator<<(aghContainer<T> const& right);

   /// \brief Przeciozony operator >>
   ///
   /// Wypisuje zawartosc pojemnika na strumien
   template<class U> friend ostream& operator<<(ostream&, aghContainer const&);
};

#endif
