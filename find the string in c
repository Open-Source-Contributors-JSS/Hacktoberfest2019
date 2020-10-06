Live Demo
#include <stdio.h>
#include <string.h>

int main() {
   char s1[] = "Beauty is in the eye of the beholder";
   char s2[] = "the";

   int n = 0;
   int m = 0;
   int times = 0;
   int len = strlen(s2);      // contains the length of search string

   while(s1[n] != '\0') {

      if(s1[n] == s2[m]) {     // if first character of search string matches

         // keep on searching

         while(s1[n] == s2[m]  && s1[n] !='\0') {
            n++;
            m++;
         }

         // if we sequence of characters matching with the length of searched string
         if(m == len && (s1[n] == ' ' || s1[n] == '\0')) {

            // BINGO!! we find our search string.
            times++;
         }
      } else {            // if first character of search string DOES NOT match
         while(s1[n] != ' ') {        // Skip to next word
            n++;
            if(s1[n] == '\0')
            break;
         }
      }
		
      n++;
      m=0;  // reset the counter to start from first character of the search string.
   }

   if(times > 0) {
      printf("'%s' appears %d time(s)\n", s2, times);
   } else {
      printf("'%s' does not appear in the sentence.\n", s2);
   }

   return 0;
}
