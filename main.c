/******************************************************************
* Projekt: Algorithmen und Datenstrukturen
* Dateiname: main.c
* Beschreibung: ???
* Autor: Sören Zacharias
* Matr.-Nr.: 823436
* Erstellt: 27.05.2022
******************************************************************/

#include <stdio.h>
#include <stdlib.h>

// Hier Konstanten und Statuscodes definieren
#define NOT_IMPLEMENTED_ERROR -1000

// Hier Struktur und globale Variablen definieren
typedef struct listnode {
    int daten;
    struct listnode *pNext;
} Listnode;

// Vorgegebene Enumeration als Hilfestellung
enum DIRECTION { FORWARD, REVERSE } direction;


/* Vorgegebene Unterprogramme zur Verwaltung der verketteten Liste */
/* Die folgenden 6 Funktionen werden von CodeFreak erwartet.       */
/* Fehler sollten durch die Rückgabe eines negativen Statuscodes   */
/* kenntlich gemacht werden. */
void put_entry(Listnode *pStart, int position, int aktdata);  /* Eintrag einfuegen */
int del_entry(Listnode *pStart, int position);                  /* Eintrag Loeschen  */
int find_entry(int value);                 /* Eintrag suchen    */
void del_list(Listnode *pStart);                                /* Liste loeschen    */
int get_anzentries(Listnode *pStart);                           /* Anzahl ermitteln  */
int printall(Listnode *pStart, enum DIRECTION direction);       /* Liste ausgeben    */


int main(void) {
    // Erstellen einer verketteten Liste
    Listnode bsp1, bsp2, bsp3, bsp4;
    Listnode *pStart = NULL;

    printf("Erstellen:\n");
    printall(pStart, FORWARD);

    pStart = &bsp1;
    bsp1.daten = 10;
    bsp1.pNext = &bsp2;
    bsp2.daten = 20;
    bsp2.pNext = &bsp3;
    bsp3.daten = 30;
    bsp3.pNext = &bsp4;
    bsp4.daten = 40;
    bsp4.pNext = NULL;

    printf("Zuweisen:\n");
    printall(pStart, FORWARD);

    printf("Loeschen:\n");
    del_entry(pStart, 1);
    printall(pStart, FORWARD);


    return 0;
}


/* Unterprogramm zum Einfuegen eines Nutzdatenelements
*  Parameter: position = Einfuegeposition; 0 = vor pstart
*             aktdata  = einzufuegende Zahl
*/
void put_entry(Listnode *pStart, int position, int aktdata) {

    if (position < 0) { // falls eine negative Zahl übergeben wird, hier abbrechen
        printf("Not a valid position!\n");
    } else if(position > get_anzentries(pStart)) {
        position = get_anzentries(pStart);
    }

    // neues Objekt erstellen
    Listnode *p;
    p = (Listnode *) malloc(sizeof(Listnode));
    p->daten = aktdata;
    p->pNext = NULL;
    pStart = p;
    printf("Pointer in der Funktion: %p und %p\n", pStart, p);

    // neue Liste erstellen, falls pStart NULL ist
    /*
    if (pStart == NULL) {
        printf("Liste leer!\n");
        pStart = temp;
        return;
    }
     */
}


/* Unterprogramm zu Ausgabe aller Listenelemente
*  Parameter: direction  = FORWARD	vorwaerts
*                        = REVERSE	rueckwaerts
*  Return:    0          = alles OK
*         negative Werte = Fehler
*/
int printall(Listnode *pStart, enum DIRECTION direction) {
    if (pStart == NULL) {
        printf("Liste ist leer.\n");
        return -1;
    }
    int count = 1;
    Listnode *p = pStart;
    if (direction == FORWARD) {
        while (p != NULL) {
            printf("Inhalt vom %d. Element: %d\n", count++, p->daten);
            p = p->pNext;
        }
    } else {
        printf("Optional.\n");
    }
    return 0;
}


/* Unterprogramm zum Loeschen der gesamten Liste
*  Parameter: keine
*  Return:    0         = Loeschen OK
*         negative Werte = Fehler
*/
void del_list(Listnode *pStart) {
    Listnode *temp = pStart;
    while (temp != NULL) {

    }
}


/* Unterprogramm zum Loeschen eines Nutzdatenelements
*  Parameter: position   = Loeschpos.;
*  Return:    0          = Loeschen OK
*         negative Werte = Fehler
*/
int del_entry(Listnode *pStart, int position) {
    // Fehlerabfrage, falls falsche Position übergeben wird
    if (position <= 0 || position > get_anzentries(pStart)) {
        printf("Position existiert nicht!\n");
        return -1;
    }

    Listnode *p = pStart, *pTemp = pStart;
    if (position == 1) {
        pStart = pStart->pNext;
        pTemp->pNext = NULL;
    }

    /*
    printf("%p\n", p);
    // zum Element vor dem zu löschenden gehen
    for (int i = 0; i < position - 2; i++) {
        p = p->pNext;
        printf("%p\n", p);
    }
    pTemp = p->pNext;
    p->pNext = pTemp->pNext;
     */

    free(pTemp);


    return 0;
}


/* Unterprogramm zur Ermittlung der Elementanzahl
*  Parameter: keine
*  Return: aktuelle Anzahl der Elemente
*/
int get_anzentries(Listnode *pStart) {
    int amount = 0;
    while (pStart != NULL) {
        pStart = pStart->pNext;
        amount++;
    }
    return amount;
}


/* Unterprogramm zum Suchen eines Elementes
*  Parameter: value      = Zahl, nach der gesucht wird
*  Return:    0          = nicht gefunden
*         negative Werte = Fehler
*/
int find_entry(int value)
{
    return NOT_IMPLEMENTED_ERROR;
}