#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Yuval Grimberg 315823328 //
int everythingcheckker(char*input3, char*  Matname, char*  rowchar, char*  colchar, char* trash, int row, int col) { //checks everything while command is zeros and gives back valus to user
	int casenum = 1;
		switch (casenum) {
		case 1: {
			if ((charcleaner(Matname)) == 0) {//matname has invalid charcater
				return 2;
				break;
			}
			if ((lengthchecker(Matname)) == 0) {//Matname name too long
				return 3;
				break;
			}
			if (((isnum(Matname)) == 1) || ((isalpha(Matname) == 0 ))) { //matname has a number
				return 4;
				break;
			}
			if (((charcleaner(rowchar)) == 0)) { //row\col has unvalid char
				return 5;
				break;
			}
			if (((charcleaner(colchar)) == 0)) {//row\col has unvalid char
				return 6;
				break;
			}
			if ((isalpha(rowchar)) == 1) {//row has letter
				return 7;
				break;
			}
			if (((isalpha(colchar))) == 1) { //row\col has letter inside of them
				return 8;
				break;
			}
			if ((row < 0) || (col<0)) { //row or col are negatives
				return 9;
				break;
			}
			else {
				return 1;
			}
		}
		}
	}
int lengthchecker(char*matname) {//check length of matname
	size_t length = strlen(matname);
	if (length < 11) {
		return  1;
	}
	else {
		return 0;
	}}
void pointeretiver(int** Matdoogo1, int** Matdooggo2, int row1, int col1, int row2, int col2,  char* doggo8, char* doggo9, char* doggo10) { // frees memory of everything.
	int i, j;
	free(doggo8);
	free(doggo9);
	free(doggo10);
	for (i = 0; i < row1; i++) {
		for (j = 0; j < col1; j++) {

		}
		free(Matdoogo1);
		for (i = 0; i < row2; i++) {
			for (j = 0; j < col2; j++) {
			}
		}
			free(Matdooggo2);
		

	}
}
int charcleaner(char* input) {//checks if char has signs, non alphanumeric chars
	size_t length = strlen(input);
	for (size_t i = 0; i < length; i++) {
		if ((input[i] >= 97 && input[i] <= 122) || (input[i] >= 65 && input[i] <= 90) || (input[i] >= 48 && input[i] <= 57) || (input[i]=='-') || (input[i] == 10) )
			continue;
		else {
			return 0;
		}
		return 1;
	}
}
int isnum(char* input) {//check if string is num, goes for both ways
		size_t length = strlen(input);	
	for (size_t i = 0; i <= length; i++) {
		for (size_t j = length; j >=0 && j>i ; j--)
		if ( (input[i] >= 48 && input[i] <= 57) || (input[j] >= 48 && input[j] <= 57))
			continue;
		else {
			return 0;
		}
		return 1;
	}
}
int isalpha(char* input) {//check if string has only latters, capital or small
	size_t length = strlen(input);
	for (size_t i = 0; i < length; i++) {
		if (((input[i] >= 97 && input[i] <= 122) || (input[i] >= 65 && input[i] <= 90)))
			continue;
		else {
			return 0;
		}
		return 1;
	}
}
int** matrixzero(int** arr, int row, int col) {//gets dynamic array and st it to zero
	int i, j;
	i = row;
	j = col;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			arr[i][j] = 0;
		}
	}
	return arr;
}
int char2int(char*numchar) {//takes char and make it int.
	//printf_s(numchar,"%c");
		int num;
		sscanf_s(numchar, "%d", &num);
		return num;
}
void setmatrix(int** arr, int row, int col) {//sets matrix from user input
	int i, j;
	char s[3];
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			scanf_s("%d", &arr[i][j]);
		}
	}
	gets_s(s, sizeof(s)); //ignoring space in the end
	}
void Matprint(int** arr, int row, int col){//prints matrix
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf_s("%d ", arr[i][j]);
		}
		printf_s("\n");
	}
}
void transpose(int** arr, int row, int col) {//prints arr of [j][i] insted of [i][j]
	int i, j;
	for (i = 0; i < col; i++) {
		for (j = 0; j < row; j++) {
			printf_s("%d ", arr[j][i]);
		}
		printf_s("\n");
	}
}
int** Twodarrayset (int mrow, int mcol) { /*allocating memory to set 2d arry*/
	int i;
	int** arr1 = (int**)malloc(sizeof(int*) * mrow);
	for (i = 0; i < mrow; i++) {
		arr1[i] = (int*)malloc(sizeof(int) * mcol);
	}
	return arr1;
}
void matfrob(int** A, int** B, int row, int col) { //the trace sum of frob matrix
	int i, j;
	int trace = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			trace = trace + (A[i][j] * B[i][j]);
		}
	}
	printf_s("%d\n", trace);
}
int main() {
	int row = 0;
	int col = 0;
	int** A = NULL;
	int** B = NULL;
	int slot1 = 0;
	int slot2 = 0;
	char Matname1[81] = { 0 };
	char Matname2[81] = { 0 };
	int row1 = 0;
	int row2 = 0;
	int col1 = 0;
	int col2 = 0;
	char buffer[81];
	char* ptr;	ptr = 0;
	int num = 0;
	int bluepill = 0;//is an int to make an almost infinte loop
	while (bluepill != 1) {
		printf_s("#");
		fgets(buffer, sizeof buffer, stdin);
		char* command = strtok_s(buffer, " \t", &ptr);
		char* Matname = strtok_s(NULL, " \t", &ptr);
		char* rowchar = strtok_s(NULL, "  \t", &ptr);
		char* colchar = strtok_s(NULL, " \t", &ptr);
		char* trash = strtok_s(NULL, " \t", &ptr);
		buffer[strcspn(buffer, "\n")];
		if ((rowchar != NULL) && (colchar != NULL)) {
			row = char2int(rowchar);
			col = char2int(colchar);
			command[strcspn(command, "\n")] = 0;
		}
		if ((strcmp(command, "zeros") == 0) && ((trash == NULL)) && ((rowchar != NULL) && (colchar != NULL))) {
			num = everythingcheckker(command, Matname, rowchar, colchar, trash, row, col);
			if (num == 2 || num == 3 || num == 4) {
				printf_s("#Error: '%s' - invalid variable name!\n", Matname);
			}
			else if (num == 3 || num == 4 || num == 5 || num == 6 || num == 7 || num == 8 || num == 9) {
				printf_s("#invalid dimension!\n");
			}
			else if (num == 1) { ///no erroes in the first checker now we can set our matrix :)
				if (slot1 == 0 && slot2 == 0) {//storage is empty
					strcpy_s(Matname1, (strlen(Matname) + 1) * sizeof(char), Matname);
					slot1 = 1;
					row1 = row;
					col1 = col;
					A = Twodarrayset(row1, col1);
					A = matrixzero(A, row1, col1);
					Matname = 0;
				}
				else if ((strcmp(Matname, Matname1) == 0)) {
					printf_s("Error: variable name '%s' is already in use!\n", Matname);
				}
				else if (slot1 == 1 && slot2 == 0) {//slot 1 in use, 2 is open, rewrite 2.
					strcpy_s(Matname2, (strlen(Matname) + 1) * sizeof(char), Matname);
					slot2 = 1;
					row2 = row;
					col2 = col;
					B = Twodarrayset(row2, col2);
					B = matrixzero(B, row2, col2);
				}

				else if (slot1 == 1 && slot2 == 1) {//memory is full
					if ((strcmp(Matname, Matname1) == 0) || (strcmp(Matname, Matname2) == 0))
					{
						printf_s("Error: variable name '%s' is already in use!\n", Matname);
					}
					else {
						printf_s("Error: zeroes cannot save more than 2 variables!\n");
					}
				}
			}
		}
		else if (strcmp(command, "set") == 0) { //start to set the matrix and to see add some values
			Matname[strcspn(Matname, "\n")] = 0;//fight \n on 2nd run
			if ((strcmp(Matname, "") == 0)) {
				printf_s("Error: illegal command!\n");
			}
			else if ((rowchar) != NULL) {
				printf_s("Error: illegal command!\n");
			}
			else if ((strcmp(Matname, Matname1) != 0) && (strcmp(Matname, Matname2) != 0)) {
				printf_s("Error: '%s' - unknown variable!\n", Matname);
			}

			else if (strcmp(Matname, Matname1) == 0) {
				setmatrix(A, row1, col1);
			}
			else if (strcmp(Matname, Matname2) == 0) {
				setmatrix(B, row2, col2);
			}
		}
		else if (strcmp(command, "print") == 0) {
			Matname[strcspn(Matname, "\n")] = 0;
			if ((strcmp(Matname, "") == 0)) {
				printf_s("Error: illegal command!\n");
			}
			else if (rowchar != NULL) {
				printf_s("Error: illegal command!\n");
			}
			else if ((strcmp(Matname, Matname1) != 0) && (strcmp(Matname, Matname2) != 0)) {
				printf_s("Error: '%s' - unknown variable!\n", Matname);
			}
			else if (strcmp(Matname, Matname1) == 0) {
				Matprint(A, row1, col1);
			}
			else if (strcmp(Matname, Matname2) == 0) {
				Matprint(B, row2, col2);
			}
		}
		else if (strcmp(command, "transpose") == 0) {//user entered transpose
			Matname[strcspn(Matname, "\n")] = 0;
			if ((strcmp(Matname, "") == 0)) {
				printf_s("Error: illegal command!\n");
			}
			else if (rowchar != NULL) {
				printf_s("Error: illegal command!\n");
			}
			else if (strcmp(Matname, Matname1) != 0 && strcmp(Matname, Matname2) != 0) {
				printf_s("Error: '%s' - unknown variable!\n", Matname);
			}
			else if (strcmp(Matname, Matname1) == 0) {
				transpose(A, row1, col1);
			}
			else if (strcmp(Matname, Matname2) == 0) {
				transpose(B, row2, col2);
			}
		}
		else if ((strcmp(command, "frob") == 0) && (rowchar != NULL)) {//user entered transpose
			Matname[strcspn(Matname, "\n")] = 0;
			rowchar[strcspn(rowchar, "\n")] = 0;
			if ((strcmp(Matname, "") == 0)) {
				printf_s("Error: illegal command!\n");
			}
			else if (colchar != 0) {
				printf_s("Error: illegal command!\n");
			}
			else if (strcmp(Matname, Matname1) != 0 && strcmp(Matname, Matname2) != 0) {
				printf_s("Error: '%s' - unknown variable!\n", Matname);
			}
			else if (strcmp(rowchar, Matname1) != 0 && strcmp(rowchar, Matname2) != 0) {
				printf_s("Error: '%s' - unknown variable!\n", rowchar);
			}
			else if (strcmp(Matname, Matname1) == 0 && strcmp(rowchar, Matname2) == 0) {
				if (((row1 == row2) && (col1 == col2))) {
					matfrob(A, B, row1, col1);
				}
				else {
					printf_s("Error: matrix dimensions mismatch!\n");
				}
			}
			else if (strcmp(rowchar, Matname1) == 0 && strcmp(Matname, Matname2) == 0) {
				if (((row1 == row2) && (col1 == col2))) {
					matfrob(B, A, row1, col1);
				}
				else {
					printf_s("Error: matrix dimensions mismatch!\n");
				}
			}
			else if (strcmp(rowchar, Matname1) == 0 && strcmp(Matname, Matname1) == 0) {
				matfrob(A, A, row1, col1);
			}
			else if (strcmp(rowchar, Matname2) == 0 && strcmp(Matname, Matname2) == 0) {
				matfrob(B, B, row2, col2);
			}
		}
		else if (strcmp(command, "") == 0) {
			continue;
		}
		else if( (strcmp(buffer, "exit") == 0) || (strcmp(command, "exit\n") == 0) ) {//this loop closes and free the memory 
		bluepill = 1;
		pointeretiver(A, B, row1, col1, row2, col2,  Matname, rowchar, colchar);
		printf_s("Goodbye.");
		}
		else {
		printf_s("Error: illegal command!\n");
		}
	}
}