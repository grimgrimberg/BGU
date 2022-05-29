#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
char removeSpecialCharacter(char* input)//function to remove any non alpha numerical char but to keep spaces.
{
	int j = 0;
	size_t length = strlen(input);
	for (int i = 0; i < length; i++) {
		if ((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z') || (input[i] = 32))
			input[j] = input[i];
		j++;
	}

	return input;
}
int fsize(FILE* fp) {
	int prev = ftell(fp);
	fseek(fp, 0L, SEEK_END);
	int sz = ftell(fp);
	fseek(fp, prev, SEEK_SET); //go back to where we were
	return sz;
}
void set_me_free(char** array, int linenum) {//function to free 2d array
	int i = 0;
	for (i = 0; i < linenum; i++)
		free(array[i]);
	free(array);
}
char* stringRemoveNonAlphaNum(char* str) {//function to remove and shring every string to remove any non alpha numeric char inside
	unsigned long i = 0;
	unsigned long j = 0;
	char c;
	while ((c = str[i++]) != '\0')
	{
		if (isalnum(c))
		{
			str[j++] = c;
		}
	}
	str[j] = '\0';
	return str;
}
char** George_Shrinks(char** lines, int numrows, int numtotal) {//remove any nonalpha numeric char from given string and makes array of it.
	int a = numrows;
	int b = numtotal;
	int c = 0;
	int j = 4;
	int k = 1;
	char** linecut = malloc(a * (sizeof(char*) + 1));
	while (c < a) {
		char** linetest = _strdup(lines[j]);
		linecut[c] = _strdup(stringRemoveNonAlphaNum(linetest));
		j++;
		c++;
	}
	return linecut;
}
char** dude_where_is_my_pawn(char** input, int numrows, int numtotal) {//make array from every cuted string to find the start location.
	int a = numrows;
	int b = numtotal;
	int i = 0;
	char** location = malloc(a * (sizeof(char*) + 1));
	while (i < a) {
		location[i] = malloc(3 * sizeof(char*) + 1);
		char* linetest = _strdup(input[i]);
		size_t length = strlen(linetest);
		if (length == 5) {
			location[i][0] = linetest[1];
			location[i][1] = linetest[2];
			location[i][2] = '\0';
		}
		if (length == 6) {
			location[i][0] = linetest[2];
			location[i][1] = linetest[3];
			location[i][2] = '\0';
		}
		i++;
		free(linetest);
	}
	return location;
}
char** you_have_arrived(char** input, int numrows, int numtotal) {
	int a = numrows;
	int b = numtotal;
	int i = 0;
	char** location = malloc(a * (sizeof(char*) + 1));//make array from every cuted string to find the end location.
	char* linetest = { 0 };
	while (i < a) {
		location[i] = malloc(3 * (sizeof(char*) + 1));
		linetest = _strdup(input[i]);
		size_t length = strlen(linetest);
		if (length == 5) {
			location[i][0] = linetest[3];
			location[i][1] = linetest[4];
			location[i][2] = '\0';
		}
		if (length == 6) {
			location[i][0] = linetest[4];
			location[i][1] = linetest[5];
			location[i][2] = '\0';
		}
		i++;
		free(linetest);
	}
	return location;
}
int rook(char* startpos, char* endpos) {//function for rook
	char* start = startpos;
	char* end = endpos;
	extern locationchecker(end);
	extern locationchecker(start);
	int i = locationchecker(start);
	int j = locationchecker(end);
	char x = start[0];
	char x_1 = end[0];
	char y = start[1];
	char y_1 = end[1];
	int z = abs(x - x_1);
	int w = abs(y - y_1);
	if ((i != 1) || (j != 1))
		return 0;
	if (z == 0 && w == 0)
		return 0;
	if ((x == x_1) && (w > 0 && w <= 7))
		return 1;
	else if ((y == y_1) && (z > 0 && z <= 7))
		return 1;
	else return 0;
}
int bishop(char* startpos, char* endpos) {//function for bishop
	char* start = startpos;
	char* end = endpos;
	int i = locationchecker(start);
	int j = locationchecker(end);
	char x = start[0];
	char x_1 = end[0];
	char y = start[1];
	char y_1 = end[1];
	int z = abs(x - x_1);
	int w = abs(y - y_1);
	int k = 0;
	if ((i != 1) || (j != 1))
		return 0;
	if (z == 0 || w == 0)
		return 0;
	if (z == 0 && w == 0)
		return 0;
	if (w != 0 && z != 0)
		k = z / w;
	if (k == 1)
		return 1;
	else return 0;
}
int knight(char* startpos, char* endpos) {//function for knight
	char* start = startpos;
	char* end = endpos;
	int i = locationchecker(start);
	int j = locationchecker(end);
	char x = start[0];
	char x_1 = end[0];
	char y = start[1];
	char y_1 = end[1];
	int z = abs(x - x_1);
	int w = abs(y - y_1);
	if ((i != 1) || (j != 1))
		return 0;
	if (z == 0 && w == 0)
		return 0;
	if ((z == 1) && (w == 2))
		return 1;
	else if ((z == 2) && (w == 1))
		return 1;
	else return 0;
}
int king(char* startpos, char* endpos) {//function for king
	char* start = startpos;
	char* end = endpos;
	int i = locationchecker(start);
	int j = locationchecker(end);
	char x = start[0];
	char x_1 = end[0];
	char y = start[1];
	char y_1 = end[1];
	int z = abs(x - x_1);
	int w = abs(y - y_1);
	int k = 0;
	if ((i != 1) || (j != 1))
		return 0;
	if (z == 0 && w == 0)
		return 0;
	if (w != 0)
		k = z / w;
	if ((z == 1) && (w == 0))
		return 1;
	else if ((z == 0) && (w == 1))
		return 1;
	else if (abs(k) == 1)
		return 1;
	else return 0;
}
int queen(char* startpos, char* endpos) {//function for queen
	char* start = startpos;
	char* end = endpos;
	int i = locationchecker(start);
	int j = locationchecker(end);
	char x = start[0];
	char x_1 = end[0];
	char y = start[1];
	char y_1 = end[1];
	int z = abs(x - x_1);
	int w = abs(y - y_1);
	int k = 0;
	int t = 0;
	if ((i != 1) || (j != 1))
		return 0;
	if (z == 0 && w == 0)
		return 0;
	if (w != 0) {
		k = z % w;
		t = z / w;
	}
	if ((z == 1) && (w == 0))
		return 1;
	if ((z == 0) && (w == 1))
		return 1;
	if ((abs(k) == 0) && (abs(t) == 1))
		return 1;
	if ((x == x_1) && (w > 0 && w <= 7))
		return 1;
	else if ((y == y_1) && (z > 0 && z <= 7))
		return 1;
	else return 0;
}
int pawn(char* startpos, char* endpos) {//function for pawn
	char* start = startpos;
	char* end = endpos;
	int i = locationchecker(start);
	int j = locationchecker(end);
	char x = start[0];
	char x_1 = end[0];
	char y = start[1];
	char y_1 = end[1];
	int z = (x - x_1);
	int w = (y - y_1);
	int k = NULL;
	if ((i != 1) || (j != 1))
		return 0;
	if (z == 0 && w == 0)
		return 0;
	if (w != 0 && z != 0) {
		k = z % w;
	}
	if ((y == '2') && (z == 0) && (abs(w) == 2)) { // starting move 
		if (w == -2)
			return 1;
		else
			return 0;
	}
	if ((y == '7') && (z == 0) && (abs(w) == 2)) { // starting move 
		if (w == 2)
			return 2;
		else
			return 0;
	}
	if ((abs(z) == 1) && (w == -1))//white eats
		return 1;
	if ((z == 0) && (w == -1))//white moves 
		return 1;
	/* if (k == 0)//see's if eating is ok
		return 1;*/
	if ((abs(z) == 1) && (w == 1))//black eats
		return 2;
	if ((z == 0) && (w == 1))//black moves
		return 2;
	else return 0;
}
int blackorwhite(char** lines, int numrows, int numtotal) {//checks if first char in given line is B or W or somehing else
	int a = numrows;
	int b = numtotal;
	int c = 0;
	int j = 4;
	int k = 1;
	char* linetest = _strdup(lines);
	size_t length = strlen(linetest);
	for (int i = 0; i < length;) {
		if (linetest[i] == 66) {
			i++;
			k++;
			free(linetest);
			return 2;
		}
		else if (linetest[i] == 87) {
			i++;
			k++;
			free(linetest);
			return 1;
		}
		else
		{
			free(linetest);
			return; 0;
		}
	}
	j++;
}
int locationchecker(char** location) {
	char* input = _strdup(location);
	int i = 0;
	if ((input[i] >= 97 && input[i] <= 104) && (input[i + 1] >= 49 && input[i + 1] <= 56)) {

		return 1;
	}
	free(input);
	return 0;
	//free(input);

}//check the location
int linecounter(FILE* f) {
	int i = 0;
	char str[1000];
	char* line = malloc(sizeof(str) * strlen(str + 1));
	fseek(f, 0, SEEK_SET);
	while (fgets(str, 1000, f)) {
		i++;
	}
	return i;
}//counts the number of lines
char** colornamepicker(char** userinput) {//takes from specific line the player name and color.
	char* ptr;	ptr = 0;
	userinput == removeSpecialCharacter(userinput);
	char* Color = strtok_s(userinput, " \t", &ptr);
	Color = stringRemoveNonAlphaNum(Color);
	char* first_name = strtok_s(NULL, " \t", &ptr);
	first_name = stringRemoveNonAlphaNum(first_name);
	char* last_name = strtok_s(NULL, " \t", &ptr);
	last_name = stringRemoveNonAlphaNum(last_name);
	char** player = malloc(3 * sizeof(*player));
	player[0] = _strdup(Color);
	player[1] = _strdup(first_name);
	player[2] = _strdup(last_name);
	return player;
}
int whowon(FILE* f) {//goes on every char on first line to see first number and declae who by first char occarnce.
	char* str[1000];
	char* endptr;
	char* p = str;
	fseek(f, 0, SEEK_SET);
	(fgets(str, 1000, f));
	while (*p != '0') {
		int val = strtol(p, &p, 10); // Read number
		if (val != 0) return 1;

		else if (p++);
		else
			// Otherwise, move on to the next character.
			return 0;
	}
}
int main() {
	FILE* ptr = NULL;
	errno_t err = 0;
	FILE* ptr_2 = NULL;
	errno_t err_2 = 0;
	err = fopen_s(&ptr, "Game.txt", "r");//open 1st file for read
	if (err != 0)
		printf_s("Error: Missing 'Game.txt' file.");
	err_2 = fopen_s(&ptr_2, "output_315823328.txt", "w");//creates 2nd file to print output.
	if (err_2 != 0)
		printf_s("Error: The file 'output_315823328' cannot be created.");
	int sz = fsize(ptr);
	char str[1000];
	int linenum = linecounter(ptr);
	int j = linenum;
	int k = j - 4;
	int i = 0;
	char** cut_lines;
	char** start;
	char** end;
	char** line = malloc(j * (sizeof(str) + 1));//making an array of every line in file
	while (ptr != 0 && ptr_2 != 0) {
		fseek(ptr, 0, SEEK_SET);
		while (fgets(str, sz + 1, ptr)) {
			str[strcspn(str, "\n")] = 0;
			line[i] = _strdup(str);
			i++;
		}
		char** player_1 = colornamepicker(line[1]);//taking the stuff that we need about the players.
		char** player_2 = colornamepicker(line[2]);
		if ((whowon(ptr) == 1))//white wins
			fprintf_s(ptr_2, "The player %s %s played %s and won\nThe player %s %s lost the match", player_1[1], player_1[2], player_1[0], player_2[1], player_2[2]);
		else (fprintf_s(ptr_2, "The player %s %s played %s and won\nThe player %s %s lost the match", player_2[1], player_2[2], player_2[0], player_1[1], player_1[2]));
		cut_lines = George_Shrinks(line, k, j);//taking the char array and removing everying but alphanumerical chars
		start = dude_where_is_my_pawn(cut_lines, k, j);//staring location
		end = you_have_arrived(cut_lines, k, j);//end location
		int t = 0;
		i = 0;
		int a = 1;
		fprintf_s(ptr_2, "\n\nIllegal moves:");
		while (i < k) {
			size_t length = strlen(cut_lines[i]);//checking the size of the lines
			int c = blackorwhite(cut_lines[i], k, j);
			if ((c == 1) || (c == 2)) {
				if ((length == 5) && ((locationchecker(start[i]) != 1) || (locationchecker(end[i]) != 1))) { // checking if the location is good and the size of cuted sting is ok for pawn
					if (c == 1) {
						fprintf_s(ptr_2, "\nStep %d of W pawn is illegal", a);
					}
					if (c == 2) {
						fprintf_s(ptr_2, "\nStep %d of B pawn is illegal", a);
					}
				}
				if ((length == 5)) { //pawn is moving
					t = pawn(start[i], end[i]);
					if ((t == 1) && (c == 1)) {
					}
					if ((t == 2) && (c == 2)) {
					}
					if ((t == 1) && (c == 2)) {
						fprintf_s(ptr_2, "\nStep %d of B pawn is illegal", a);
					}
					if ((t == 2) && (c == 1)) {
						fprintf_s(ptr_2, "\nStep %d of W pawn is illegal", a);
					}
					if ((t == 0) && (c == 1)) {
						fprintf_s(ptr_2, "\nStep %d of W pawn is illegal", a);
					}
					if ((t == 0) && (c == 2)) {
						fprintf_s(ptr_2, "\nStep %d of B pawn is illegal", a);
					}
				}
				if ((length == 6)) {//length = 6 so im checking every 2nd char to see the type of the soldier that is moving
					if (cut_lines[i][1] == 'B') {
						t = bishop(start[i], end[i]);
						if (t == 1 && c == 2) {}
						if (t == 1 && c == 1) {}
						if (t == 0 && c == 2)
							fprintf_s(ptr_2, "\nStep %d of B bishop is illegal", a);
						if (t == 0 && c == 1)
							fprintf_s(ptr_2, "\nStep %d of W bishop is illegal", a);
					}
					if (cut_lines[i][1] == 'R') {
						t = rook(start[i], end[i]);
						if (t == 1 && c == 2) {}
						if (t == 1 && c == 1) {}
						if (t == 0 && c == 2)
							fprintf_s(ptr_2, "\nStep %d of B rook is illegal", a);
						if (t == 0 && c == 1)
							fprintf_s(ptr_2, "\nStep %d of W rook is illegal", a);
					}
					if (cut_lines[i][1] == 'N') {
						t = knight(start[i], end[i]);
						if (t == 1 && c == 2) {}
						if (t == 1 && c == 1) {}
						if (t == 0 && c == 2)
							fprintf_s(ptr_2, "\nStep %d of B knight is illegal", a);
						if (t == 0 && c == 1)
							fprintf_s(ptr_2, "\nStep %d of W knight is illegal", a);
					}
					if (cut_lines[i][1] == 'K') {
						t = king(start[i], end[i]);
						if (t == 1 && c == 2) {}
						if (t == 1 && c == 1) {}
						if (t == 0 && c == 2)
							fprintf_s(ptr_2, "\nStep %d of B king is illegal", a);
						if (t == 0 && c == 1)
							fprintf_s(ptr_2, "\nStep %d of W king is illegal", a);
					}
					if (cut_lines[i][1] == 'Q') {
						t = queen(start[i], end[i]);
						if (t == 1 && c == 2) {}
						if (t == 1 && c == 1) {}
						if (t == 0 && c == 2)
							fprintf_s(ptr_2, "\nStep %d of B queen is illegal", a);
						if (t == 0 && c == 1)
							fprintf_s(ptr_2, "\nStep %d of W queen is illegal", a);
					}
				}
				/*i++;
				a++;*/
			}
			i++;
			a++;
		}
		free(player_1);
		free(player_2);
		free(line);
		set_me_free(cut_lines, k);
		set_me_free(start, k);
		set_me_free(end, k);
		free(err);
		free(err_2);
		fclose(ptr);
		fclose(ptr_2);
		return 0;
	}
}
