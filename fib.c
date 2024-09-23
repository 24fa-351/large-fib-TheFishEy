#include <stdio.h>
#include <stdlib.h>
//Patrick Hung 860865329

// unsigned long long would be much bigger
long long fib_i(int index);
long long fib_r(int index);

// memoization arrays, 100 should be enough since 92/93 was the cap for signed long long
// could a pair just work?
long long memo_i [100];
long long memo_r [100];

int main(int argc, char *argv[]) {
   //some cleanup
   char which;
   long long answer;
   int argument1;
   int fileInt;
   int index;

   //initialize memoization
   for (int i = 0; i < 100 ; i++)
   {
      memo_i[i] = -1;
      memo_r[i] = -1;
   }

   if (argc != 4)
   {
      printf("Input error");
      return 1; 
   }

   argument1 = atoi(argv[1]);
   argument1 = argument1 - 1;

   which = argv[2][0];//[0] is for accessign character in string, 'i' / 'r'
   char *fileName = argv[3];
  

   FILE *file = fopen(fileName, "r");
   if (file == NULL)
   {
      printf("Unable to open file\n");
      return 1;
   }


   fscanf(file, "%d", &fileInt);
   fclose(file);

   index = argument1 + fileInt;

   if(which == 'i') {
      answer = fib_i(index);
   }
   else {
      answer = fib_r(index);
   }

   printf("%lld", answer);

   return 0;
}

// iternative
long long fib_i(int index) {
   if (index <= 0) return 0; 
   if (index == 1) return 1;

   if (memo_i[index] != -1 && index < 100) return memo_i[index]; // if memo index exists (not -1 default), return memo pair

   long long a = 0;
   long long b = 1;
   long long temp;

   for (int i = 2; i <= index; i++) {
      temp = a + b;
      a = b;
      b = temp;
   }

   if (index < 100) { // somewhat redundant bounds checking
      memo_i[index] = b; // stroign new value in array i
   }
   return b;
}

// recursive
long long fib_r(int index){
   if (index <= 0) return 0;
   if (index == 1) return 1;

   if (memo_r[index] != -1 && index < 100) return memo_r[index];
   memo_r[index] = fib_r( index - 1) + fib_r(index - 2);// storign new value in r array
   return memo_r[index];

}

long long fib_wrapper_i (int index) {
   return fib_i(index);
}

long long fib_wrapper_r (int index) {
   return fib_r(index);
}

