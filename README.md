# Text-Formatting
	Functii:

1. ordonare_crescatoare:
- folosind bubble sort sorteaza crescator prin intermediul functiei strcmp() sirul de caractere.

2. ordonare_descrescatoare:
- folosind bubble sort sorteaza descrescator prin intermediul functiei strcmp() sirul de caractere.

3. lung_max:
- returneaza cea mai lunga linie;

4. elim_spini
- elimina spatiile initiale ale liniei;
- pentru a nu modifica sirul initial prin functia strcpy(), foloseste un sir auxiliar, pentru care aloca dinamic memorie;

5. elim_spfin
- elimina spatiile finale ale linei;

6. parsare
- extrage parametrii strart_Line si end_line din comanda;
- in cazul in care acestia nu exista iau valoarea "-1", iar in cazul in care exista, convertim parametrii din siruri de caractere in numere intregi si ii retinem in variabile de tip pointer.

Functia main:
- citeste din fisier conform scheletului dat;
- declara un sir destinatie in care se efectueaza toate comenzile, cu exceptia comenzii 'L', respectiv 'l', atunci cand se considera sirul destinatie egal cu sirul sursa;
- retine intr-o variabila (literac) litera comenzii, aceasta fiind obtinuta prin impartirea sirului de caractare asociat comenzii dupa virgula;

Cazul 'W', cazul 'w':
- adauga si elimina spatii astel incat textul sa se incadreze in max_Line_lenght, textul obtinut aflandu-se in destinatie;
- in cazul in care un cuvant este mai lung decat max_Line_lenght, parcurge textul de la coada pana gaseste un spatiu, apoi de la acesta trece cuvantul pe linia urmatoare, eliminand spatiul, asttel neimpartind cuvantul. 

Cazul 'L', cazul 'l':
-verifica daca exista parametrii start_line si end_line;
-aliniaza la stanga liniile, apeland functia elim_spini() si elimina spatiile finale ale liniilor prin apelarea functiei elim_spfin().

Cazul 'R', cazul 'r':
-verifica daca exista parametrii start_line si end_line;
-elimina atat spatiile initiale, cat si finale ale liniei;
-calculeaza cate spatii sa adauge la inceputul liniei, facand diferenta dintre linia cea mai lunga si linia din text, atatea spatii fiind retinute intr-un alt sir de caractere, pe care il concateneaza la text, astfel realizand alinierea la dreapta a liniei;

Cazul 'C', cazul 'c':
-verifica daca exista parametrii start_line si end_line;
-calculeaza cate spatii are in plus linia de centrat fata de linia cea mai lunga atat la stanga cat si la dreapta, apoi imparte numarul obtinut, adaugand atatea spatii la inceputul liniei.

Cazul P:
-extrage parametrul indent_length din comanda, retine adresa la care se gaseste primul spatiu care ne ajuta sa verificam daca indent lenght este singurul parametru, apoi acesta este retinut intr-un sir de caractere, care este in final convertit la numar intreg;
-concateneaza la inceput de paragraf indent lenght spatii.

Cazul I:
- extrage parametrii list_type si special_character de tip char din comanda;
- in functie de parametrul list_type este creat un sir de caractere care contine formatul cerut, apoi acesta este concatenat fiecarui element al listei.
- sprintf converteste un numar intreg in sir de caractere.

Cazul O:
- extrage in plus fata de cazul I si parametrul ordering;
- pe langa atribuirea de indici a elementelor listei, acesta si ordoneaza crescator sau descrescator lista prin intermediul functiilor ordonare_crescatoare si ordonare_descrescatoare.


 


