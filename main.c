#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void stringToHex (char *message, long pow, long mod);
long encrypt (long encryptNum, long pow, long mod);

long encrypt (long encryptNum, long pow, long mod)
{
  long result;

   result = 1;

   if (pow < 1)
      return result;

   if (pow == 1)
      return encryptNum % mod;

   result = encrypt(encryptNum, pow / 2, mod) % mod;
   result = (result * result) % mod;

   if (pow & 1)
      result = (result * encryptNum) % mod;

   return result;
}


void stringToHex(char *message, long pow, long mod)
{
  int i, j, block, rest;
  long threeChar = 0, encryptNum;
  block = strlen(message)/3;
  rest = strlen(message)%3;
  i =0;
  printf("\n");
  while(block !=0)
  {

    threeChar = message[i * 3] * 256 * 256 +
                message[i * 3+1] * 256 +
                message[i * 3+2];

    encryptNum = encrypt(threeChar, pow, mod);
    printf("%08lX ", encryptNum);
    if(((i + 1) % 8) == 0)
    {
      printf("\n");
    }

    block = block -1;
    i++;
    j = i;

  }


  if (rest == 1)
  {
    threeChar = message[j * 3] *256*256 + ' ' *256 + ' ';
    encryptNum = encrypt(threeChar, pow, mod);
    printf("%08lX ", encryptNum);

  }
 else if (rest ==2)
  {
    threeChar = message[j * 3] *256*256+ message[j *3+1] * 256 + ' ';
    encryptNum = encrypt(threeChar, pow, mod);
    printf("%08lX ", encryptNum);
  }

  printf("\n");

}

int main (int argc, char **argv)
{
   long pow, mod;
   char text;
   char message[4097];
   int i = 0;

   scanf("%ld", &pow);
   scanf("%lX", &mod);
   scanf("%c", &text);
   while(((scanf("%c", &text)) != EOF))
   {
      message[i++] = text;
   }

   message[i] = 0;
   stringToHex(message,pow,mod);
   return 0;
}


