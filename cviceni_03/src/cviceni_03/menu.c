#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
/* #define ALTER */

void vyprazdni_buffer(void)
{
  while (getchar() != '\n')
    ;
}

void nasobit(void)
{
  printf("Nasobeni\n");
}

void delit(void)
{
  printf("Deleni\n");
}

void konec(void)
{
  printf("Konec.\n");
}

void unknown(void)
{
  printf("Neznama operace typu nasobeni.\n");
}

void menu1(void)
{ /*Pole pointeru na funkce */
  typedef enum { NASOBENI, DELENI, KONEC, POCET_MOZNYCH_NASOBICICH_OPERACI } OPERACE;
  const char MOZNE_OPERACE[POCET_MOZNYCH_NASOBICICH_OPERACI] = { "NDK" };
  typedef void (* P_FCE)();
  P_FCE funkce[POCET_MOZNYCH_NASOBICICH_OPERACI + 1] = { nasobit, delit, konec, unknown };
  int i;
  char c;

  do {
    printf("Mozne operace: ");
    for (i = 0; i < POCET_MOZNYCH_NASOBICICH_OPERACI; i++) {
      printf("%c ", MOZNE_OPERACE[i]);
    }

    printf("\nZadejte typ operace: ");
    scanf("%c", &c);
    vyprazdni_buffer();
    c = toupper(c);
#ifndef ALTER
    for (i = 0; i < POCET_MOZNYCH_NASOBICICH_OPERACI; i++) {
      if (c == MOZNE_OPERACE[i]) {
        break;
      }
    }
    funkce[i]();
#else
    char *p_c;
    p_c = strchr(MOZNE_OPERACE, c);
    if (p_c != NULL) {
      funkce[p_c - MOZNE_OPERACE](); /* index pole funkce_povel je rozdil pointeru */
    } else {
	    funkce[strlen(MOZNE_OPERACE)]();
    }
#endif
  } while (c != MOZNE_OPERACE[KONEC]);
}

void menu2(void)
{
  typedef enum { SCITANI, ODCITANI, KONEC, POCET_MOZNYCH_SCITACICH_OPERACI } OPERACE;
  const char MOZNE_OPERACE[POCET_MOZNYCH_SCITACICH_OPERACI] = { 'S', 'O', 'K' };
  OPERACE vybrana_operace;
  int i;
  char c;

  do {
    printf("Mozne operace: ");
    for (i = 0; i < POCET_MOZNYCH_SCITACICH_OPERACI; i++) {
      printf("%c ", MOZNE_OPERACE[i]);
    }

    printf("\nZadejte typ operace: ");
    scanf("%c", &c);
    vyprazdni_buffer();

    for (vybrana_operace = 0; vybrana_operace < POCET_MOZNYCH_SCITACICH_OPERACI; vybrana_operace++) {
      if (c == MOZNE_OPERACE[vybrana_operace]) {
        break;
      }
    }

    switch (vybrana_operace) {

        case SCITANI:
          printf("Scitani\n");
          break;

        case ODCITANI:
          printf("Odcitani\n");
          break;

        case KONEC:
          printf("Konec\n");
          break;

        default:
          printf("Neznama operace typu scitani.\n");
          break;
    }
  } while (vybrana_operace != KONEC);
}

void menu3(void)
{
  int i;
  do {
    printf("Zadejte cislo (0 znamena Konec.): ");
    if (scanf("%d", &i) != 1) {
      i = -1;
    }
    vyprazdni_buffer();
    switch (i) {

      case 0:
        break;

      case 1:
        printf("jedna\n");
        break;

      case 2:
        printf("dva\n");
        break;

      case 3:
        printf("tri\n");
        break;

      case 4:
        printf("ctyri\n");
        break;

      default:
        printf("nezname cislo\n");
        break;
    }
  } while (i != 0);
}

int main()
{
  char c;

  do {
    printf("Zadejte a, b, c nebo k (Konec): ");
    scanf("%c", &c);
    vyprazdni_buffer();
    switch (c) {

      case 'a':
      case 'A':
        menu1();
        break;

      case 'b':
      case 'B':
        menu2();
        break;

      case 'c':
      case 'C':
        menu3();
        break;

      case 'k':
      case 'K':
        break;

      default:
        printf("Neznama volba.\n");
        break;
    }
  } while (c != 'k' && c != 'K');

  return 0;
}