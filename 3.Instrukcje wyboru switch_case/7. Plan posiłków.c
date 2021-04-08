#include <stdio.h>
#include <ctype.h>

int main()
{
  char mp;
  printf("Meal plan type please:\n");
  scanf("%c",&mp);

  switch(mp!='A' && mp!='B' &&mp!='C')
  {
    case 1:
    printf("Incorrect input");
    return 1;
  }

  printf("You chose ");
  switch(mp)
  {
    case 'A':
    printf("Breakfast, ");

    case 'B':
    printf("Lunch and ");

    case 'C':
    printf("Dinner as your meal plan.");  
    return 0; 
  }
  
}