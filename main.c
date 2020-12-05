// PART 1 2 3 4 5 6
enum BlokKodu {A, B , C , D , VarArgs, fSilnia };
enum BlokKodu Wybrany = fSilnia;   // przyk³ad u¿ycia typu wyliczeniowego

// Selektor bloku kodu
#define Struktura     1
#define KilkaStruktur 2
#define FunkcjaWydruk 3
#define VarWydruk     4
#define Rekurencja    5
#define Referencja    6
#define Sortowanie    7
#define MiniBazaKsiazek    8

// ==============
#define PART MiniBazaKsiazek

// ==============
#if PART == Struktura
#include <stdio.h>
#include <stdlib.h>

struct {
   int Id;
   char *Name;
} a, *b;

int main() {
    a.Id   = 1;
    a.Name = "Lamborghini";
    b = &a;

    printf("Nr %d,\tnazwa = %s\n", a.Id,  a.Name);
    printf("Nr %d,\tnazwa = %s\n", b->Id, b->Name);
    printf("Rozmiar zmiennej \'a\'=%d bytes\n", sizeof(a));
    printf("Rozmiar zmiennej \'b\'=%d bytes\n", sizeof(b));
    return 0;
}
#endif // PART== Struktura

#if PART == KilkaStruktur
#include <stdio.h>
#include <stdlib.h>

typedef struct {
   int Id;
   char *Name;
} Record;

int main() {

    Record a, *b, c, d;
    a.Id   = 1;
    a.Name = "Lamborghini";
    b = &a;

    c.Id   = 2;
    c.Name = "Ferrari";

    d.Id   = 3;
    d.Name = "Arrinera";

    printf("Nr %d,\tnazwa = %s\n", a.Id,  a.Name);
    a.Id   = 5;
    a.Name = "Maluch";

    printf("Nr %d,\tnazwa = %s\n", b->Id, b->Name);
    printf("Nr %d,\tnazwa = %s\n", c.Id,  c.Name);
    printf("Nr %d,\tnazwa = %s\n", d.Id,  d.Name);
    return 0;
}
#endif // PART==KilkaStruktur

#if PART == FunkcjaWydruk
#include <stdio.h>
#include <stdlib.h>

typedef struct {
   int Id;
   char *Name;
} Record;

void Wydruczek(Record _a);

int main() {

    Record a, *b, c, d;
    a.Id   = 1;
    a.Name = "Lamborghini";
    b = &a;

    c.Id   = 2;
    c.Name = "Ferrari";

    d.Id   = 3;
    d.Name = "Arrinera";

    Wydruczek(a);
    a.Id = 5, a.Name="Maluch";
    Wydruczek(*b);
    Wydruczek(c);
    Wydruczek(d);

    return 0;
}

void Wydruczek(Record _a){
 printf("Nr %d,\tnazwa = %s\n", _a.Id,  _a.Name);
 return;
};
#endif // PART==FunkcjaWydruk

#if  PART == VarWydruk
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct {
   int Id;
   char *Name;
} Record;

void Wydruczek(Record, ...);

int main() {

    Record a, *b, c, d, Last;
    Last.Id   = 0;
    Last.Name = "";

    a.Id   = 1;
    a.Name = "Lamborghini";
    b = &a;

    c.Id   = 2;
    c.Name = "Ferrari";

    d.Id   = 3;
    d.Name = "Arrinera";

    Wydruczek(a, c,d, a, Last);

    return 0;
}

void Wydruczek(Record argL, ...){
 va_list dane;
 va_start(dane, argL);

 for(Record _a = argL; _a.Id; _a = va_arg(dane, Record))
    printf("Nr %d,\tnazwa = %s\n", _a.Id,  _a.Name);

 va_end(dane);
 return;
};
#endif // PART == VarWydruk

#if  PART == Rekurencja
#include <stdio.h>
#include <stdlib.h>

unsigned long long Silnia(unsigned long long);
unsigned long long SilniaW(unsigned long long);

int main() {
    long a = 23; // ! Przekroczenie zakresu usigned long long przy n==25
    // %lld (lub %I64d) == "long long integer"
    // %llu (lub %I64u) == "unsigned long long integer"
    // %llu oraz %lld wymaga co najmniej C99 dla kompilatora gcc
    // albo w opcjach kompilacji albo porzez prze³¹cznik -std=c99 lub -std=c11
    unsigned long long F = SilniaW(a);  // dodalem zmienn¹ pomocnicz¹ 'F'
    printf("Dla N=%ld, \nN! = %llu (%%llu), \nN! = %I64u (%%I64u)", a, F, F);
    return 0;
}
unsigned long long  Silnia(unsigned long long _n){
  static long Cnt = 0;   // <==!
  printf("Cnt=%ld\n", ++Cnt);

    if (_n)
       return _n*Silnia(_n-1);
    else
       return 1;
};

unsigned long long SilniaW(unsigned long long _n){
  static long Cnt = 0;   // <==!
  printf("Cnt=%4ld\n", ++Cnt); // dlaczego Cnt i N! s¹ drukowane OSOBNO?

  long long _w = (_n>1)?_n*SilniaW(_n-1) : 1;   // ternary operator
  printf("N! = %llu\n", _w);
  return _w;
};
#endif // PART==Rekurencja

#if  PART == Referencja
#include <stdio.h>
#include <stdlib.h>

void Swap(int*, int*);

int main() {
    long a = 4, b = 1;
    printf("a=%d, \tb = %d\n", a, b);
    Swap(&a, &b);
    printf("a=%d, \tb = %d  ", a, b);
    return 0;
}
void Swap(int *_a, int *_b){
   register int _c = *_a;  // wskazówka dla kompilatora - trzymaj _c "pod rek¹"
   *_a = *_b;
   *_b =  _c;
   return;
};
#endif // PART==Referencja; funkcja Swap


#if PART == Sortowanie
//=====  Sortowanie =====
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char * marka;
    int przebieg;
} autko, *p_autko;

int comp(const void *i, const void *j);
int comp_search(const void *a, const void *b);

int main(int argc, char *argv[]){
    int count = 5;//atoi(argv[1]);
    p_autko tab = (p_autko)malloc(sizeof( autko)*count);

    for(int i = 0; i < count; i++){
        tab[i].marka = (char*)malloc(100);
        printf("podaj %d marke: ", i+1);
        scanf("%s", tab[i].marka);

        printf("podaj przebieg: ");
        scanf("%d", &(tab[i].przebieg));
        printf("sztuka: %d, marka: %s, przebieg: %d\n", i+1, tab[i].marka, tab[i].przebieg);
    }

    for(int i = 0; i < count; i++){
        printf("marka nr %d to: %s, przebieg: %d\n", i+1, tab[i].marka, tab[i].przebieg);
    }

    printf("\nStarting qsort \n");
    qsort(tab, count, sizeof(autko), comp);
    printf("\nqsort done: \n");

    for(int i = 0; i < count; i++){
        printf("marka nr %d to: %s, przebieg: %d\n", i+1, tab[i].marka, tab[i].przebieg);
    }

    char wzor[20];
    strcpy(wzor, "Fiat");
    printf("Searching for: %s\n", wzor);

    autko *wsk;
    printf("\nStarting bsearch\n");
    wsk = (p_autko)bsearch(wzor, tab, count, sizeof(autko), comp_search);
    printf("\nbsearch done!\n");

    if(wsk == NULL)
       printf("Nie ma samochodu marki: %s\n", wzor);
    else
       printf("Znaleziono samochod marki: %s,\t przebieg: %d\n", wsk->marka, wsk->przebieg);

    return 0;
}

int comp(const void *i, const void *j){
//    static int cnt=0;
//    static int cnt=0;
    char* m1 = ((p_autko)i)->marka;
    char* m2 = ((p_autko)j)->marka;
    int p1 = ((p_autko)i)->przebieg;
    int p2 = ((p_autko)j)->przebieg;
//    printf("[%d]: %s, %s, %d, %d\n", cnt++, m1,m2,p1,p2);
    int temp_cmp = strcmp(m1, m2);
    if(temp_cmp!=0)
        return temp_cmp;
    else if(p1 < p2)
           return -1;
         else if(p1 > p2)
           return 1;
  return 0;
}

int comp_search(const void *a, const void *b){
   char *aa = (char *)a;
   char *mm = ((p_autko)b)->marka;
   return (strcmp(aa, mm));
}
#endif // PART == Sortowanie

#if PART == MiniBazaKsiazek
//=====  MiniBazaKsiazek =====
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char * tytul;
    int rok;
    int liczba_stron;
} ksiazka, *p_ksiazka;

ksiazka ksiazki[30];

int licznikKsiazek = 0;

void wybierzOpcje();
void dodajKsiazke();
void wyszukajKsiazke();
void wszystkieKsiazki();
int stringComp(const void *i, const void *j);
int yearComp(const void *i, const void *j);
int pageComp(const void *i, const void *j);

int main(int argc, char *argv[]){
    //ksiazki = (ksiazka*)malloc(sizeof(ksiazka)*30);
    free(ksiazki);

    wybierzOpcje();

    return 0;
}

void wybierzOpcje(){
    int opcja;

    printf("\nMini Baza Ksiazek\nWybierz opcje:\n1.Dodaj ksiazke do bazy\n2.Wyszukaj ksiazke\n3Posortowane ksiazki\n4.Zamknij program\n");
    scanf("%d",&opcja);

    switch(opcja){
        case 1:{
            dodajKsiazke();

        }break;
        case 2:{
            wyszukajKsiazke();

        }break;
        case 3:{
            wszystkieKsiazki();

        }break;
        case 4:{
            return ;

        }break;
        default:{
            return ;

        }break;
    }
    return ;
}

void dodajKsiazke(){
    char tekst[200];

    printf("Podaj tytul:\n");
    getchar();
    fgets(tekst, 200, stdin);//tab[i].marka = (char*)malloc(100);
    ksiazki[licznikKsiazek].tytul = (char *)malloc(strlen(tekst)-1);
    for(int i=0;i<strlen(tekst)-1;i++)
        ksiazki[licznikKsiazek].tytul[i]=tekst[i];

    printf("Podaj rok wydania:\n");
    scanf("%d", &ksiazki[licznikKsiazek].rok);
    printf("Podaj liczbe stron:\n");
    scanf("%d", &ksiazki[licznikKsiazek].liczba_stron);
    /*if(licznikKsiazek%5==4)
    {
        pomoc=licznikKsiazek/5+1;
        ksiazki = (ksiazka*) realloc (ksiazki,pomoc*sizeof(ksiazka));
    }*/

    licznikKsiazek++;
    wybierzOpcje();

    return ;
}

void wyszukajKsiazke(){
    char tekst[200];

    printf("Podaj tytul:\n");
    getchar();
    fgets(tekst, 200, stdin);
    tekst[strlen(tekst)-1]='\0';
    for(int i=0; i<licznikKsiazek;i++){
        if(strcmp(ksiazki[i].tytul, tekst)==0){
            printf("Tytul: %s Rok wydania: %d Liczba stron: %d", ksiazki[i].tytul, ksiazki[i].rok, ksiazki[i].liczba_stron);
            i = licznikKsiazek;
        }
    }
    wybierzOpcje();
    return ;
}

void wszystkieKsiazki(){
    int opcja;
    printf("\nWszystkie Ksiazki\nPodaj opcje sortowania:\n1.Po tytule\n2.Po liczbie stron\n3.Po Po roku wydania\n");
    scanf("%d",&opcja);

    switch(opcja){
        case 1:{
            qsort(ksiazki, licznikKsiazek, sizeof(ksiazka), stringComp);
        }break;
        case 2:{
            qsort(ksiazki, licznikKsiazek, sizeof(ksiazka), pageComp);
        }break;
        case 3:{
            qsort(ksiazki, licznikKsiazek, sizeof(ksiazka), yearComp);
        }break;
        default:{
            return ;
        }break;
    }

    for(int i =0; i<licznikKsiazek; i++)
        printf("Tytul: %s Rok wydania: %d Liczba stron: %d\n", ksiazki[i].tytul, ksiazki[i].rok, ksiazki[i].liczba_stron);

    wybierzOpcje();
    return ;
}
int stringComp(const void *i, const void *j){
    char* k1 = ((p_ksiazka)i)->tytul;
    char* k2 = ((p_ksiazka)j)->tytul;
    int temp = strcmp(k1,k2);
    if(temp!=0)
        return temp;
    else return 0;
}
int yearComp(const void *i, const void *j){
    int r1 = ((p_ksiazka)i)->rok;
    int r2 = ((p_ksiazka)j)->rok;
    if(r1<r2) return -1;
    else if(r1 > r2) return 1;
    else return 0;
}

int pageComp(const void *i, const void *j){
    int r1 = ((p_ksiazka)i)->liczba_stron;
    int r2 = ((p_ksiazka)j)->liczba_stron;
    if(r1<r2) return -1;
    else if(r1 > r2) return 1;
    else return 0;
}

#endif // PART == MiniBazaKsiazek
