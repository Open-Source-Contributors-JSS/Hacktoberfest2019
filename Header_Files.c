
// <assert.h>	Program assertion functions
// <ctype.h>	Character type functions
// <locale.h>	Localization functions
// <math.h>	Mathematics functions
// <setjmp.h>	Jump functions
// <signal.h>	Signal handling functions
// <stdarg.h>	Variable arguments handling functions
// <stdio.h>	Standard Input/Output functions
// <stdlib.h>	Standard Utility functions
// <string.h>	String handling functions
// <time.h>	Date time functions <assert.h>	Program assertion functions
// <ctype.h>	Character type functions
// <locale.h>	Localization functions
// <math.h>	Mathematics functions
// <setjmp.h>	Jump functions
// <signal.h>	Signal handling functions
// <stdarg.h>	Variable arguments handling functions
// <stdio.h>	Standard Input/Output functions
// <stdlib.h>	Standard Utility functions
// <string.h>	String handling functions
// <time.h>	Date time functions



#include <stdio.h>
#include <math.h>
int main()
{
// finding square root of a number
   float num, root;
   printf("Enter a number: ");
   scanf("%f", &num);

   // Computes the square root of num 
   root = sqrt(num);

   printf("Square root of %.2f = %.2f", num, root);
   return 0;
}
