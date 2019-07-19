   #include <stdio.h>

   int a[] = {50, 30, 10, 70, 40, 20, 60};

   for (int j = 2; j < sizeof(a)/sizeof(a[0]); j++) {
     key = a[j];
     for (int i=j-1; i >= 0 && a[j] < a[i]; i--) {
          a[i+1] = a[i];
	  a[i] = key;
     }

   }

   for (int i=0; i < sizeof(a)/sizeof(a[0]); i++) printf("%d\n", a[i]);
