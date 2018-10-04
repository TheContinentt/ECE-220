#include <stdio.h> 
int sum(int);
 int main()  
  {
      int number;
      int return_value;
    scanf("%d", &number);
    return_value = sum(number);
    printf("%d\n", return_value);
    return 0;
  }
  int sum(int number)
  {
      int remain;
      if (number == 0)
      {
          return 0;
      }
      else
      {
          remain = number % 10;
          number = (number-remain)/10;
          return sum(number) + remain;
      }
  }
