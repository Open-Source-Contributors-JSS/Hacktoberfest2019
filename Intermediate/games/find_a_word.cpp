#include<stdio.h>

#include<conio.h>

char arr[] = {
  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
};
int pos1[20];
int pos2[20];

void main() {
  int i, no, j, z;
  textattr(1 << 4 | 14);
  clrscr();
  cprintf("Asume A Word!\n\n\rStep 1:\n\r=======\n\rTabel 1:\n\n\r");
  textattr(1 << 4 | 12);
  for (i = 0; i < 5; i++)
    cprintf("%d ", i + 1);
  textattr(7 << 4);
  for (i = 0; i < 30; i++) {
    if (i % 5 == 0)
      printf("\n");
    cprintf("%c ", arr[i]);
  }
  textattr(1 << 4 | 14);
  gotoxy(1, 15);
  cprintf("\n\n\rEnter Total Number of letters in word:");
  cscanf("%d", & no);
  cprintf("                                            ");
  for (i = 0; i < no; i++) {
    gotoxy(1, 15);
    cprintf("\n\n\rEnter Letter %d Coloumn number:", i + 1);
    scanf("%d", & pos1[i]);
    pos1[i] -= 1;
  }
  clrscr();
  cprintf("Step 2:\n\rTabel 2:\n\r");
  textattr(1 << 4 | 12);
  for (i = 0; i < 6; i++)
    cprintf("%d ", i + 1);
  textattr(7 << 4);
  for (i = 0; i < no; i++) {
    printf("\n");
    for (j = pos1[i]; j < 30; j += 5)
      cprintf("%c ", arr[j]);
  }
  textattr(1 << 4 | 14);
  for (i = 0; i < no; i++) {
    gotoxy(1, 15);
    cprintf("\n\n\rEnter the  %d Letter's Coloumn number:", i + 1);
    scanf("%d", & pos2[i]);
    pos2[i] -= 1;
  }
  clrscr();
  gotoxy(30, 13);
  cprintf("We Got U! ");
  gotoxy(30, 15);
  cprintf("SURPRISED!");
  textcolor(WHITE + BLINK);
  gotoxy(30, 14);
  for (i = 0; i < no; i++) {
    cprintf("%c", arr[pos2[i] * 5 + pos1[i]]);
  }
  textcolor(YELLOW + BLINK);
  cprintf("\n\n\n\n\n\n\n\n\rPress Esc To Exit...");
  while (getch() != 27);
}