#include <stdio.h>//Yuval Grimberg 315823328
//dear inspector, i had some erors with the text compare, ive tried to solve it with stack overflow and the guides in the course, hopefully nothing is not totally inaccurate.
#include <math.h>
int main() {
	char Num1; //user need to choose his number to start program given calculator
	do {//starts the big loop of everything before the user choose the oparation after that is goes back to menu
		printf_s("Please choose from the menu below the section you want:\n1. Standard Calculator\n2. Bitwise Shift Calculator\n3. Pascal's triangle\n0. To exit\nEnter a number between 1-3:");//all the options, its under 1 op to save resources.
		scanf_s(" %c", &Num1, 1);
		if (Num1 == '1') {//the user selected the basic calculator
			char calc; double num1, num2;
			printf_s("what would you like to do: '+' , '-' , '*' , '/' :");//the user needs to choose oparator
			scanf_s(" %c", &calc, 1);
			printf_s("Enter 2 numbers:");
			scanf_s("%lf", &num1);
			scanf_s("%lf", &num2);
			if (calc == '+') {
				printf_s("\nthe result of adding %.2lf to %.2lf is: %.2lf.\n", num1, num2, num1 + num2);//what happens with + sign
			}
			if (calc == '-') {
				printf_s("\nthe result of subtracking %.2lf from %.2lf is: %.2lf.\n", num1, num2, num1 - num2);//minus sign
			}
			if (calc == '*') {
				printf_s("\nthe result of multiplying %.2lf by %.2lf is: %.2lf.\n", num1, num2, num1 * num2);//multiply sign
			}
			if (calc == '/') {
				if (!num2) printf_s("You are trying to divide by zero!\n");//divide by zero, you cant do that
				else(printf_s("\nthe result of dividing %.2lf by %.2lf is: %.2lf.\n", num1, num2, num1 / num2));//dividing
			}
		}
		else if (Num1 == '2') {//the user seleceted the bitwise shifter
			int int1, int2, result_int;
			printf_s("Please enter a positive integer number to shift:");
			scanf_s("%d", &int1);
			printf_s("Please enter the integer number for bits to shift:");
			scanf_s("%d", &int2);
			if (int2 > 0) {
				result_int = int1 << int2;
				printf_s("the result is: %d\n", result_int);
			}
			else if (int2 < 0) {
				result_int = int1 >> abs(int2);//its in abs value because the computer cant see stuff in minus sign. so the program tells to move "x" steps in oppisete direction
				printf_s("the result is %d\n", result_int);
			}
			else {
				printf_s("Second number was 0, the number stays the same!\n");
			}
		}
		else if (Num1 == '3') {//the user seleced pascal calculator
			int int3, coefficent = 1, spaces, i, j;
			printf_s("In this section you will create Pascal's triangle.\nPlease enter the depth of the triangle(integer):");
			scanf_s("%d", &int3);
			if (int3 > 13) {
				printf_s("The number entered is larger than 13.\n")
					;
			};
			if (int3 == 0) {
				printf_s("You entered 0.\n")
					;
			}
			if (int3 <= 13) {//if num is 13 or less the command start, it moves the numbers by rows and the coeffieient runs from 1 to the selected power
				for (i = 0; i < int3; i++) {
					for (spaces = 1; spaces <= int3 - i; spaces++)
						printf_s("  ");
					for (j = 0; j <= i; j++) {
						if (j == 0 || i == 0)
							coefficent = 1;
						else
							coefficent = coefficent * (i - j + 1) / j;
						printf_s("%4d", coefficent);
					}
					printf_s("\n");
				}
			}
		}
		else if (Num1 != '0') //if its not '0' the program goes back to the start
			printf_s("Wrong input, try again\n");
	} while (Num1 != '0');
	if (Num1 == '0') printf_s("Goodbye");//end of program
}
