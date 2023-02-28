//conversion constructors

/*Keta konstruktore marrin nje argument, qe mund te jete nje fundamental type ose other user-defined types dhe i konverton keto objekte ne objekte te klases ku eshte
deklaruar. Kompileri keta konstruktor mund ti ngaterroj me konstruktoret qe kane nje argument dhe perdoren per qellime te tjera. Per ta parandaluar kete, kontruktoret
qe mund te marrin vetem nje argument dhe nuk jane conversion constructor duhet te deklarohen me keyword "explicit" perpara.*/
/*Kompilatori eshte inteligjent mjaftueshem per ta therritur conversion constructor kur ndonje funksion i klases me argument objekt te asaj klase, aksidentalisht
ka ndonje type tjeter.*/

//conversion operators

/*Keta operator perdoren per te konvertuar nje objekt te nje klase ne fundamental types te tjere. Keta funksione duhet te jene non-static member functions.
Shembull prototipi:
MyClass::operator string() const;
(keto operatori ben konvertimin e objektit te klases "MyClass" ne string)
thirrja: s.operator string()*/