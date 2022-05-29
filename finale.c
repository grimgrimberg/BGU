///*This is a skeleton code for Group home assignment written by Shai&Avihai*/
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <math.h>
//
//#define BMP "flake.bmp"
//#define BMPCPY "flake-copy.bmp"
//#define TXT "defects.txt"
//#define BESTFILE "best-route.txt"
//#define DBG 'd'
//#define DX 0.001
//
//typedef struct line_size {
//	int size;
//	char** lines;
//	struct line_size* next;
//}lineswithcontant;
//
//typedef struct RGB // pixel's color
//{
//	unsigned char blue;
//	unsigned char green;
//	unsigned char red;
//} RGB;
//
//typedef struct { //pixel's coordinates
//	int x;
//	int y;
//}co_t;
//
//typedef struct pixel { //list of pixels
//	co_t p;
//	struct pixel* next;
//}pix_t;
//
//typedef struct flake { //flake's detailed list extructed of bmp
//	int size; //the number of pixels that combine the flake
//	co_t p1;
//	co_t p2;
//	pix_t* pArr; //list of flake pixels
//	struct flake* next;
//}flakeList_t;
//
//typedef struct tflist {//flake's list read from txt file
//	co_t p1, p2;
//	int size;
//	struct tflist* next;
//}textfile_t;
//
//typedef struct map_s { // flake in a map context
//	textfile_t* flake;
//	struct map_s* n1;
//	double n1Dist;
//	struct map_s* n2;
//	double n2Dist;
//	int visit;
//	struct map_s* route;
//	int oil;
//	struct map_s* next;
//}map_t;
//
//typedef struct route_s { //route
//	textfile_t* flake;
//	int oil;
//	int count;
//	struct route_s* next;
//}route_t;
//
//typedef struct path { //this is list of list, that contain all revesed possible routes.
//	route_t* path;
//	struct path* next;
//}pathsList_t;
//
///*prototype*/
//void option1(char);
//unsigned char** readBMP(unsigned int* width, unsigned int* hight);			//read bmp file
//flakeList_t* buildFlakesList(unsigned char**, unsigned int, unsigned int);//scan picture for flake pixels to constract flake list from them
//int pixelInFlake(int y, int x, flakeList_t*);								//check if a pixels is in the flake list
//pix_t* buildPixelsArr(unsigned char**, unsigned int, unsigned int, unsigned int, unsigned int, pix_t*); //scan bmp matrix for a group of black pixel e.g. flake
//flakeList_t* addToList(pix_t*, flakeList_t*);								//add a list of pixels that qualify for a flake
//int getPixelCount(pix_t*);													//return the number of pixels in a pixel list
//int getFlakesCount(flakeList_t*);											//return the number of flake structures in the flake list
//void writeFileFlakeProp(flakeList_t* flakes, char* filename);				//write flakes prop to file
//void freeMat(unsigned char** blue, unsigned int width, unsigned hight);
//void freeFlakeList(flakeList_t* flakeList);									//free flakelist
//
////function 1 NOAM
//void printProperties(flakeList_t* flakeList);
//pix_t* chainListOfPixels(pix_t* last, pix_t* returned_list);
//int findBiggestpixelX(pix_t* pArr, int y);
//int findHighestPixelY(pix_t* pArr);
//
////function 2 YUVAL
//int char2int(char* numchar);
//int fsize(FILE* fp);
//int linecounter(FILE* f);
//lineswithcontant* sortList_size(lineswithcontant* list);
//void set_me_free(char** array, int linenum);
//lineswithcontant* listinsert_3(textfile_t* head, char** lines, int size, int j);
//void printlines_size(lineswithcontant* head);
//FILE* fileopener();
//char** line2array(FILE* deffile, int j);
//void freeList_2(lineswithcontant* list);
//void option2();
//
////function 3 ALON
//int str2int(char* str);   //convert numbers from strings to int //********* arithmetic overflow****
//int get_width(FILE* bmp_file); //get bmp file width with known offset
//int get_height(FILE* bmp_file);  //get bmp file height with known offset
//textfile_t* set_COOR(FILE* bmp_file);
//int set_oil(); // set amount of oil to the drone to use
//
////------- data extracting and lists building-------
//int offset_counter(FILE* fptr); //counting the number of char to get to the falkes data + forwarding file pointer
//int defect_counter(FILE* fptr); //counting the number of defects acoording to defects.txt
//int get_data(FILE* fptr); //reading forn txt file char by char and return the first number they get
//void save_data(FILE* fptr, textfile_t* strc_ptr); //initialize falkes according to defect.txt file struct, while get data do the forwarding
//textfile_t* build_flk_list(int flake_num, FILE* fptr); //allocating space and saving the data of the flake
//void innit_node(map_t* strc_ptr); //initialize map_t nodes data
//map_t* build_map_list(textfile_t* flk_lst_ptr);  // building flakes list in map_t format, according to textfile_t flakes list
//
////------------------ map building---------------------
//double calc_dist(textfile_t* flake1, textfile_t* flake2); //calculate the distance between 2 flakes (pithagoras)
//void build_graph(map_t* head); // create new connections from map_t nodes according to distance
//map_t* userCoor2graph(map_t* list_head, textfile_t* starting_point, int user_oil);
//void free_mapNflake(map_t* head); //free map_t and textfile_t lists
//
////--------------- finding all the possible routes -----------
//void print_route(route_t* route_node); //printing route to cmd from a reversed list
//route_t* scan_route(map_t* map_node); //saving a potential route from user coor to last node, and save it in route_t list format
//pathsList_t* make_path_list(route_t* route_tail, pathsList_t* path_head); // making a list of lists, from all route_t lists, while every node contain pointer to every route ending.
//route_t* the_road_yes_taken(pathsList_t* path_ptr);//comparing a specific route to all other possible routes
//pathsList_t* find_all_paths(map_t* map_head, map_t* node, pathsList_t* path_head); // scaning all possible routes from the map graph, and saving it in route_t and pathlist_t formats
//void free_route(route_t* route_head); //free route_t list from the end
//void free_pathNroute(pathsList_t* path_head); //free the pathlist_t + all the route_t lists in it
//void free_for_all(map_t* map_ptr, pathsList_t* path_ptr);
//
////------------- creating best route file ---------
//route_t* pickDAbest(pathsList_t* path_ptr); //picks the most optimal route from all possible routes
//void print2best_file(route_t* route_node, FILE* file_ptr); //print route steps to best-toute.txt from the end of the list, which is the first coorinate
//route_t* create_best_file(pathsList_t* path_ptr); //creating the text file and adding the table format + printing data to the file with func
//
////-------- create flake-copy bmp------
//route_t* reverse_route(route_t* route_head); //reverse route list
//void draw_pix_way(route_t* start, unsigned char** mat, int height);//changing the mat that represent pixels to a different num to build actual route
//void fix_mat(route_t* best_route, unsigned char** mat, int height);
//unsigned char** readBMP1(unsigned int* width, unsigned int* hight); // Noam Eldar
//void copy_bmp(FILE* flakecopy, unsigned int* width, unsigned int* hight, unsigned int* dataOffset);//Gal Patz
//void dye_bmp(unsigned char arr, FILE* flakecopy, unsigned int dataOffset, int j, int k, unsigned int hight);//Gal Patz
//void create_flake_copy(unsigned char** mat, int count); //Gal Patz ft. Alon Gershon
//void draw_route(FILE* bmp_ptr, route_t* best_route);
//
//void option3();
//
////function 4 GAL
//void GetCoordinates(char* p1, char* px, char* py);
//int checkint(char* str, int size);
//double max_distance(pix_t* head);
//void print_fun_4(int JUMP, float distance, pix_t* head);
//int f_x(double D, int temp, int* ptr);
//double caloffset(float distance, double c);
//void free_list(pix_t* head);
//
////function 5 
//void option5();
//int get_fuel(textfile_t* head);
//int get_route_fuel(textfile_t* head, int count);
//void spread_the_word(unsigned char** mat, int height, textfile_t* flake_list_head);
//textfile_t* listinsert(textfile_t* head, int x1, int y1, int x2, int y2, int size);
//void free_txtfile_list(textfile_t* head);
//void create_flake_copy_5(unsigned char** mat);
//int Toyotaprius(textfile_t* head);
//void set_me_free(char** array, int linenum);
//void printstats(textfile_t* head, int signedwidth, int signedheight);
//
//int main(int argc, char* argv[]) {
//	char d = argc > 1 ? argv[1][0] : 'f';
//	int choice = 0;
//	char garbage[10];
//
//	//function 4
//	FILE* best_file;
//	int X1 = 0, Y1 = 0, JUMP = 0, flag = 0, i, count = 1;
//	float distance = 0;
//	char s1[20], x1[4], y1[4], jump[81];
//	char* ptr;
//	do {
//		printf("--------------------------\nME LAB services\n--------------------------\nMenu:\n");
//		printf("1. Scan flakes\n2. Print sorted flake list\n3. Select route\n4. Numeric report.\n5. Students addition\n9. Exit.\nEnter choice: ");
//		choice = fgetc(stdin) - '0';
//		if (choice + '0' != '\n' && fgetc(stdin) != '\n')
//			while ((choice = fgetc(stdin)) != '\n');
//		printf("\n");
//		switch (choice) {
//		case 1:
//			option1(d); break;
//		case 2:
//			option2(); break;
//		case 3:
//			option3();
//			gets_s(garbage, sizeof(garbage));
//			break;
//		case 4: {
//			pix_t* head = NULL, * p = NULL, * temp = NULL;
//
//			fopen_s(&best_file, BESTFILE, "rt"); //Open a file to read
//			if (!best_file)
//				printf_s("Can't find file best-route.txt, or it might be empty.\n"); //Error printing that file could not be opened
//
//			printf_s("Please enter an intger as distance display interval:\n");//print
//
//			while (flag == 0) {//get input from user for the jumps
//				gets_s(jump, sizeof(jump));
//				ptr = jump;
//				if (checkint(ptr, 81) == 1) {//send to function to chech if input legal
//					flag = 1;
//					JUMP = atoi(jump);//convert from string to number
//				}
//				else
//					printf_s("Bad input, try again\n");
//			}
//
//			fgets(s1, 20, best_file); flag = 0; //Read the first line
//			while (fgets(s1, 20, best_file)) {//get lines from the file
//
//				if (count == 2 && s1[0] == '\n') { //just initial position and no flake's
//					printf_s("Best route doesn't leave origin.\n");
//					flag = 1;
//				}
//				else {
//					GetCoordinates(s1, x1, y1);//send to a function line from the flie and two string 
//					X1 = atoi(x1);//change from string to intager
//					Y1 = atoi(y1);
//
//					temp = (pix_t*)malloc(sizeof(pix_t));//bild a linked list with the cordinate of road
//					temp->p.x = X1;
//					temp->p.y = Y1;
//					temp->next = NULL;
//
//					if (head == NULL)
//						head = temp;
//					else {
//						p = head;
//						while (p->next != NULL)
//							p = p->next;
//						p->next = temp;
//					}
//					for (i = 0; i < 4; i++)//reset the strings
//						x1[i] = 0;
//					for (i = 0; i < 4; i++)
//						y1[i] = 0;
//					count++;
//				}
//			}
//			if (flag != 1) {//check that the first condition in the while loop was not met
//				distance = max_distance(head);//get the maximum distance
//				print_fun_4(JUMP, distance, head);
//				free_list(head);
//				fclose(best_file);
//			}
//			break;
//		}
//		case 5:
//			option5();
//			gets_s(garbage, sizeof(garbage));
//			break;
//		case 9:
//			printf("Good bye!\n"); break;
//		default:
//			printf("Bad input, try again\n\n");
//		}
//	} while (choice != 9);
//	//return 0;
//	exit(1);
//}
//
//void option1(char d) {
//	unsigned char** mat = NULL;
//	unsigned int width = 0, hight = 0;
//	flakeList_t* flakeList = NULL;
//	mat = readBMP(&width, &hight);
//	if (!mat) return;
//	flakeList = buildFlakesList(mat, width, hight);
//
//	freeMat(mat, width, hight);	//free matrix memory
//	//flakeList = revList(flakeList);
//	printProperties(flakeList);
//	writeFileFlakeProp(flakeList, TXT);
//	freeFlakeList(flakeList);	//free flake list and pixel array in it								
//}
//
//unsigned char** readBMP(unsigned int* width, unsigned int* hight) { //wrote Noam
//	unsigned char** blue = NULL; // blue matrix of bmp image
//	FILE* flakeFile;
//	fopen_s(&flakeFile, BMP, "r");
//	if (flakeFile == NULL) {
//		printf_s("Error: file is not open\n");
//		return 0;
//	}
//	// set data offset from header.
//	fseek(flakeFile, 10, SEEK_SET);
//	int dataOffset;
//	fread_s(&dataOffset, 4, 1, 4, flakeFile);
//	// set widht from header.
//	fseek(flakeFile, 4, SEEK_CUR);
//	fread_s(width, 4, 1, 4, flakeFile);
//	// set heifht from header.
//	fread_s(hight, 4, 1, 4, flakeFile);
//	blue = (unsigned char**)malloc(*hight * sizeof(unsigned char*));
//	if (blue == NULL) {
//		return 0;
//	}
//	for (int i = 0; i < (int)(*hight); i++) {
//		blue[i] = (unsigned char*)malloc(*width * sizeof(unsigned char));
//	}
//
//	// point file to image data (pixels)
//	fseek(flakeFile, dataOffset, SEEK_SET);
//	for (int i = (int)(*hight - 1); i >= 0; i--) {
//		for (unsigned int j = 0; j < *width; j++) {
//			RGB pixel;
//			fread_s(&pixel, sizeof(RGB), 1, sizeof(RGB), flakeFile);
//			blue[i][j] = (pixel.red + pixel.green + pixel.blue) / 3;
//		}
//		int jump = (*width * 3) % 4 == 0 ? 0 : (4 - ((*width * 3) % 4));
//		fseek(flakeFile, jump, SEEK_CUR);
//	}
//	return blue;
//}
//
//// return 1 if the pixel was found in the flake list
//// 0- otherwise
//int pixelInFlake(int y, int x, flakeList_t* flakeList) { //wrote Noam
//	// the list is empty- no need to search
//	if (flakeList == NULL)
//		return 0;
//	flakeList_t* flakeRunner = flakeList;
//	// step 1: iterate on all flakes
//	while (flakeRunner) {
//		pix_t* pixelRunner = flakeRunner->pArr;
//		// step 2: iterate on all pixels
//		while (pixelRunner) {
//
//			// step 3: compare
//			if (pixelRunner->p.x == x && pixelRunner->p.y == y) {
//				return 1;
//			}
//
//			pixelRunner = pixelRunner->next;
//		}
//
//		flakeRunner = flakeRunner->next;
//	}
//
//	return 0;
//}
//
//flakeList_t* buildFlakesList(unsigned char** mat, unsigned int width, unsigned int hight) { //wrote Noam
//	// point to left most pixel
//	flakeList_t* flakeList = NULL;
//	for (int row = (int)(hight - 1); row >= 0; row--) {
//		for (unsigned int col = 0; col < width; col++) {
//			if (mat[row][col] == 0) {
//				//step 1: check if the current pixel belogn to a flake already
//				int res = pixelInFlake(hight - row, col + 1, flakeList);	//check if a pixels is in the flake list
//				if (res == 0) {
//					flakeList_t* currFlake = (flakeList_t*)malloc(sizeof(flakeList_t));
//					currFlake->p1.x = col + 1;
//					currFlake->p1.y = hight - row;
//					currFlake->pArr = buildPixelsArr(mat, col, row, width, hight, NULL);
//					currFlake->size = getPixelCount(currFlake->pArr);
//					currFlake->p2.y = findHighestPixelY(currFlake->pArr);
//					currFlake->p2.x = findBiggestpixelX(currFlake->pArr, currFlake->p2.y);
//					currFlake->next = NULL;
//					// corner case the list is empty and this is the first flake
//					if (flakeList == NULL)
//						flakeList = currFlake;
//					else {
//						// search for the last flake in the list
//						flakeList_t* tempFlake = flakeList;
//						// move temp to the last element
//						while (tempFlake->next) {
//							tempFlake = tempFlake->next;
//						}
//						tempFlake->next = currFlake;
//					}
//				}
//			}
//		}
//	}
//	return flakeList;
//}
//
//int findBiggestpixelX(pix_t* pArr, int y) { //wrote Noam
//	int maxX = -1;
//	while (pArr) {
//		if (pArr->p.y == y && pArr->p.x > maxX)
//			maxX = pArr->p.x;
//		pArr = pArr->next;
//	}
//
//	return maxX;
//}
//
//int findHighestPixelY(pix_t* pArr) { //wrote Noam
//	int maxY = -1;
//	while (pArr) {
//		if (pArr->p.y > maxY)
//			maxY = pArr->p.y;
//		pArr = pArr->next;
//	}
//
//	return maxY;
//}
//
//pix_t* buildPixelsArr(unsigned char** mat, unsigned int x, unsigned int y, unsigned int width, unsigned int hight, pix_t* pArr) { //wrote Noam
//	// keep this pointing to the last element in the pixel list
//	pix_t* last = NULL;
//	pix_t* returned_list = NULL;
//	// stop conditions
//	if (x == (int)width || x < 0 || x>1000) {
//		return NULL;
//	}
//	else if (y == (int)hight || y < 0 || y>1000) {
//		return NULL;
//	}
//	else if (mat[y][x] != 0) {
//		return NULL;
//	}
//	// IF WE got to this line it means that this coordiante is inside of the matrix and is a black pixel
//	pix_t* currPixel = (pix_t*)malloc(sizeof(pix_t));
//	currPixel->p.x = x + 1;
//	currPixel->p.y = hight - y;
//	currPixel->next = NULL;
//	last = currPixel;
//	mat[y][x] = 255;
//	// move in all direction, chain the reslt to the current list
//	returned_list = buildPixelsArr(mat, x - 1, y - 1, width, hight, pArr);
//	last = chainListOfPixels(last, returned_list);
//	returned_list = buildPixelsArr(mat, x - 1, y, width, hight, pArr);
//	last = chainListOfPixels(last, returned_list);
//	returned_list = buildPixelsArr(mat, x - 1, y + 1, width, hight, pArr);
//	last = chainListOfPixels(last, returned_list);
//	returned_list = buildPixelsArr(mat, x, y + 1, width, hight, pArr);
//	last = chainListOfPixels(last, returned_list);
//	returned_list = buildPixelsArr(mat, x + 1, y + 1, width, hight, pArr);
//	last = chainListOfPixels(last, returned_list);
//	returned_list = buildPixelsArr(mat, x + 1, y, width, hight, pArr);
//	last = chainListOfPixels(last, returned_list);
//	returned_list = buildPixelsArr(mat, x + 1, y - 1, width, hight, pArr);
//	last = chainListOfPixels(last, returned_list);
//	returned_list = buildPixelsArr(mat, x, y - 1, width, hight, pArr);
//	last = chainListOfPixels(last, returned_list);
//	return currPixel;
//}
//
//pix_t* chainListOfPixels(pix_t* last, pix_t* returned_list) { //wrote Noam
//		// insert the new list to the end of the current list
//	last->next = returned_list;
//
//	// move last to the end of the updated list
//	while (last->next != NULL)
//		last = last->next;
//	return last;
//}
//
//int getPixelCount(pix_t* pArr) { //wrote Noam
//	if (pArr == NULL) {
//		return 0;
//	}
//	return 1 + getPixelCount(pArr->next);
//}
//
//void writeFileFlakeProp(flakeList_t* flakeList, char* output_file) {  //wrote Noam
//	flakeList_t* head = flakeList;
//	FILE* p_output_file = NULL;   //open defects file or print error
//	fopen_s(&p_output_file, output_file, "w");
//	if (p_output_file == NULL) {
//		printf_s("Error: The file 'defects' cannot be created.\n");
//		return;
//	}
//	fprintf_s(p_output_file, "Coordinate1	Coordinate2	Size\n===========	===========	====\n");
//	while (head != NULL)
//	{
//		fprintf(p_output_file, "(%d,%d)   	(%d,%d)   	%d\n", head->p1.x, head->p1.y, head->p2.x, head->p2.y, head->size);
//		head = head->next;
//	}
//	fclose(p_output_file);
//}
//
//int getFlakesCount(flakeList_t* list) {  //wrote Noam
//	int counter = 0;
//	while (list) {
//		counter++;
//		list = list->next;
//
//	}
//	return counter;
//}
//
//void printProperties(flakeList_t* flakeList) { //wrote Noam
//	printf_s("Coordinate x1,y1 of the first discoverd flake (%d,%d)\n", flakeList->p1.x, flakeList->p1.y);
//	printf_s("Size %d\n", flakeList->size);
//	printf("Total of %d flakes.\n", getFlakesCount(flakeList));
//}
//
//void freeFlakeList(flakeList_t* flakeList) { //wrote Noam
//	flakeList_t* tempFlake;
//	pix_t* tempPixel;
//	while (flakeList) {
//		// step 1: disconnect the first flake in the list
//		tempFlake = flakeList;
//		flakeList = flakeList->next;
//
//		while (tempFlake->pArr) {
//			// step 2: disconnect the first pixel in the list
//			tempPixel = tempFlake->pArr;
//			tempFlake->pArr = tempFlake->pArr->next;
//
//			free(tempPixel);
//		}
//		free(tempFlake);
//	}
//}
//
//void freeMat(unsigned char** blue, unsigned int width, unsigned hight) { //wrote Noam
//	for (int i = 0; i < (int)hight; i++)
//		free(blue[i]);
//
//	free(blue);
//}
//
////function 2
//int char2int(char* numchar) {//takes char and make it int.
//	//printf_s(numchar,"%c");
//	int num;
//	sscanf_s(numchar, "%d", &num);
//	return num;
//}
//
//int fsize(FILE* fp) {
//	int prev = ftell(fp);
//	fseek(fp, 0L, SEEK_END);
//	int sz = ftell(fp);
//	fseek(fp, prev, SEEK_SET); //go back to where we were
//	return sz;
//}
//
//int linecounter(FILE* f) {
//	int i = 0;
//	char str[1000];
//	char* line = malloc(sizeof(str) * strlen(str + 1));
//	fseek(f, 0, SEEK_SET);
//	while (fgets(str, 1000, f)) {
//		i++;
//	}
//	return i;
//}//counts the number of lines
//
//lineswithcontant* sortList_size(lineswithcontant* list)//sorts list by size of defects
//{
//
//	// 
//	if (list == NULL || list->next == NULL)
//		return list; // the list is sorted.
//
//	//replace largest node with the first : 
//
//	//first step - find largerst node
//	lineswithcontant* curr, * largest, * largestPrev, * prev;
//	curr = list;
//	largest = list;
//	prev = list;
//	largestPrev = list;
//	while (curr != NULL) {
//		if (curr->size > largest->size) {
//			largestPrev = prev;
//			largest = curr;
//		}
//		prev = curr;
//		curr = curr->next;
//
//	}
//	//largest node is in largest. 
//
//	//2nd step- switching first node and largest node : 
//	lineswithcontant* tmp;
//	if (largest != list)
//	{
//		largestPrev->next = list;
//		tmp = list->next;
//		list->next = largest->next;
//		largest->next = tmp;
//	}
//
//	// now largest is the first node of the list.
//
//	// calling the function again with the sub list :
//	//            list minus its first node :
//	largest->next = sortList_size(largest->next);
//
//
//	return largest;
//}
//
//void set_me_free(char** array, int linenum) {//function to free 2d array
//	int i = 0;
//	for (i = 0; i < linenum; i++)
//		free(array[i]);
//	free(array);
//}
//
//lineswithcontant* listinsert_3(lineswithcontant* head, char** lines, int size, int j) {//makes list from line of defects and size
//	lineswithcontant* newnode;
//	newnode = (lineswithcontant*)malloc(sizeof(lineswithcontant));
//	newnode->lines = lines;
//	newnode->size = size;
//	newnode->next = head;
//	head = newnode;
//	return head;
//}
//
//void printlines_size(lineswithcontant* head)
//{
//	lineswithcontant* temp_1 = head;
//	while (temp_1 != NULL)
//	{
//		printf_s("\n%s ", temp_1->lines);
//		temp_1 = temp_1->next;
//	}
//	printf("\n");
//}
//
//FILE* fileopener() {
//	FILE* deffile;
//	errno_t err;
//	err = fopen_s(&deffile, TXT, "r");
//	if (err == 0)
//		return(deffile);
//	else printf_s("Problem reading defects.txt file\nList is empty");
//	return-1;
//}
//
//char** line2array(FILE* deffile, int j) {
//	char** output = malloc(j * (sizeof(char**) + 1));
//	char str[1000];
//	int i = 0;
//	fseek(deffile, 0, SEEK_SET);
//	while (fgets(str, sizeof(str) + 1, deffile)) {
//		str[strcspn(str, "\n")] = 0;
//		output[i] = _strdup(str);
//		i++;
//	}
//	return output;
//}
//void freeList_2(lineswithcontant* head)
//{
//	lineswithcontant* tmp;
//
//	while (head != NULL)
//	{
//		tmp = head;
//		head = head->next;
//		free(tmp);
//	}
//
//}
//
//void option2() {
//	FILE* deffile = fileopener();//open file
//	if (deffile != -1) {
//		int j = linecounter(deffile);//counts number of lines
//		int sz = fsize(deffile);//searches for longest line
//		char** line = malloc(j * (sizeof(sz) + 1));//allocating memroy for an array of every line in file
//		char** lines = malloc(j * (sizeof(sz) + 1));
//		line = line2array(deffile, j);//makes array of every line in fille
//		lines = line2array(deffile, j);
//		fclose(deffile);
//		lineswithcontant* head_1 = NULL;
//		int i = 0;
//		for (int k = 0; k + 2 < j; k++) {
//			char* sizechar;
//			sizechar = strrchr(line[i + 2], ') ');//finds size of defects in every line from file
//			i++;
//			int size = char2int(sizechar);
//			head_1 = listinsert_3(head_1, lines[k + 2], size, j);//bulilds a linked list made of lines of the file and the size of defects
//		}
//		head_1 = sortList_size(head_1);//sorts lines
//		printf_s("Sorted flakes by size:\n");
//		printf_s("%s\n%s", lines[0], lines[1]);
//		printlines_size(head_1);//prints contant of list
//		printf_s("\n");
//		freeList_2(head_1);//free list
//		set_me_free(lines, j);//free array
//	}
//	return 0;
//}
//
////functin 3
//
////-----pick coordinate and oil functions------
//int str2int(char* str) {     //convert numbers from strings to int 
//	int converted_num = 0, temp, i, flag = 0, length;
//	length = (int)strlen(str);
//	if (str[0] != ' ' && str[0] != '\t')
//		flag = 1;
//	for (i = 0; i < length; i++) {
//		if (str[i] >= '0' && str[i] <= '9') {
//			temp = (int)(str[i] - '0');
//			temp = temp * (int)pow((double)10, (double)length - 1 - i);
//			converted_num += temp;
//			flag = 1;
//		}
//		else if (flag == 1) return 0;
//	}
//	return (converted_num);
//}
//
//int get_width(FILE* bmp_file) { //get bmp file width with known offset
//	int width;
//	fseek(bmp_file, 18, SEEK_SET);
//	fread_s(&width, 4, 1, 4, bmp_file); //save data according to size
//	return width;
//}
//
//int get_height(FILE* bmp_file) {  //get bmp file height with known offset
//	int height;
//	fseek(bmp_file, 22, SEEK_SET);
//	fread_s(&height, 4, 1, 4, bmp_file); //save data according to size
//	return height;
//}
//
//textfile_t* set_COOR(FILE* bmp_file) {
//	int userX = 0, userY = 0, key = 0;
//	int width, height;
//	char comma = 0, garbage = 0;
//	textfile_t* user_coor;
//
//	width = get_width(bmp_file);
//	height = get_height(bmp_file);
//
//	while (key != 1) {
//		printf_s("Please Enter valid x,y start coordinate, bmp width is %d and height is %d\n", width, height);
//		scanf_s("%d %c %d", &userX, &comma, 1, &userY);
//		garbage = getchar();
//		if ((userX > 0 && userX <= width) && (userY > 0 && userY <= height)) {
//			key = 1;
//		}
//		while (garbage != '\n') {
//			garbage = getchar();
//			key = 0;
//		}
//	}
//	user_coor = malloc(sizeof(textfile_t));
//	if (user_coor == NULL)
//		exit(1);
//	user_coor->p1.x = userX;
//	user_coor->p1.y = userY;
//	user_coor->p2.x = 0;
//	user_coor->p2.y = 0;
//	user_coor->size = 0;
//	user_coor->next = NULL;
//	return user_coor;
//}
//
//int set_oil() {  // set amount of oil to the drone to use
//	int oil = 0;
//	do {
//		printf_s("Please enter valid oil supply in range 1-1000\n");
//		scanf_s("%d", &oil);
//	} while (oil < 1 || oil > 1000);
//	return oil;
//}
//
////------- data extracting and lists building-------
//int offset_counter(FILE* fptr) { //counting the number of char to get to the falkes data + forwarding file pointer
//	int char_offset = 0, next_line = 0;
//
//	while (next_line < 2) {
//		if (fgetc(fptr) == '\n')
//			next_line++;  //stoping condition after 2 garbage line
//		char_offset++; //counting every chat till the flakes data
//	}
//	return(char_offset + 2);
//}
//
//int defect_counter(FILE* fptr) { //counting the number of defects acoording to defects.txt
//	int counter = 0;
//	char c = 0;
//
//	while (c != EOF) {
//		c = fgetc(fptr);
//		if (c == '\n')
//			counter++;   // counting falkes by number of rows
//	}
//	return (counter);
//}
//
//int get_data(FILE* fptr) { //reading forn txt file char by char and return the first number they get
//	char data_str[4] = { 0 };
//	char cur_char = 0;
//	int  i = 0, flag = 0;
//
//	while ((cur_char >= '0' && cur_char <= '9') || flag == 0) { //keep going while the char is not a digit or the flag is dwon
//		cur_char = fgetc(fptr);
//		if (cur_char >= '0' && cur_char <= '9') {
//			flag = 1;  //flag is up when fgetc reads the first digits so the loop can end after reading all the number digits
//			data_str[i] = cur_char;
//			i++;
//		}
//	}
//	data_str[i] = '\0';
//	return (atoi(data_str)); //convert the string that contain the digits in order, to int.
//}
//
//void save_data(FILE* fptr, textfile_t* strc_ptr) { //initialize falkes according to defect.txt file struct, while get data do the forwarding
//	strc_ptr->p1.x = get_data(fptr);
//	strc_ptr->p1.y = get_data(fptr);
//	strc_ptr->p2.x = get_data(fptr);
//	strc_ptr->p2.y = get_data(fptr);
//	strc_ptr->size = get_data(fptr);
//}
//
//textfile_t* build_flk_list(int flake_num, FILE* fptr) { //allocating space and saving the data of the flake
//	textfile_t* head = NULL;
//	textfile_t* lst_ptr = NULL;
//	int i;
//
//	for (i = 0; i < flake_num; i++) {
//		lst_ptr = malloc(sizeof(textfile_t)); //allocate node per itteration
//		if (lst_ptr == NULL)
//			exit(1); 
//		save_data(fptr, lst_ptr);
//		lst_ptr->next = head; //connect the nodes to each other
//		head = lst_ptr;
//	}
//	return head;
//}
//
//void innit_node(map_t* strc_ptr) { //initialize map_t nodes data
//	strc_ptr->n1 = NULL;
//	strc_ptr->n2 = NULL;
//	strc_ptr->n1Dist = INT_MAX; //setting high num so that it will replaced with the first distance
//	strc_ptr->n2Dist = INT_MAX; //setting high num so that it will replaced with the first distance
//	strc_ptr->visit = 0;
//	strc_ptr->oil = 0;
//	strc_ptr->route = NULL;
//
//}
//
//map_t* build_map_list(textfile_t* flk_lst_ptr) {  // building flakes list in map_t format, according to textfile_t flakes list
//	map_t* map_head = NULL;
//	map_t* cur_ptr = NULL;
//
//	while (flk_lst_ptr != NULL) {
//		cur_ptr = malloc(sizeof(map_t)); //allocate node per itteration
//		if (cur_ptr == NULL)
//			exit(1); 
//		innit_node(cur_ptr);
//		cur_ptr->flake = flk_lst_ptr;
//		cur_ptr->next = map_head;  //connect the nodes to each other
//		map_head = cur_ptr;
//		flk_lst_ptr = flk_lst_ptr->next;
//	}
//	return map_head;
//}
//
////------------------ map building---------------------
//double calc_dist(textfile_t* flake1, textfile_t* flake2) { //calculate the distance between 2 flakes (pithagoras)
//	double dist = 0;
//	double deltaX = 0;
//	double deltaY = 0;
//
//	deltaX = ((double)(flake1->p1.x) - (double)(flake2->p1.x));
//	deltaY = ((double)(flake1->p1.y) - (double)(flake2->p1.y));
//	deltaX *= deltaX;
//	deltaY *= deltaY;
//	dist = deltaX + deltaY;
//	dist = sqrt(dist);
//	return dist;
//}
//
//void build_graph(map_t* head) { // create new connections from map_t nodes according to distance
//	map_t* cur = head;
//	map_t* temp = NULL;
//	double dist;
//
//	while (cur != NULL) { // outer loop-pick one node at a time to compate to all other for ditance calc while picking his 2 closest neighboors
//		temp = head;
//		while (temp != NULL) { //inner loop- go thru all nodes and compare them to outer loop chosen node and filling outer loop n1, n2
//			if (cur != temp) {
//				dist = calc_dist(cur->flake, temp->flake);
//				if (dist < (cur->n1Dist)) {     // we manage n1dist < n2dist
//					cur->n2Dist = cur->n1Dist;  //we moved n1 to n2 before overriding n1.
//					cur->n2 = cur->n1;
//					cur->n1Dist = dist;
//					cur->n1 = temp;
//				}
//				else if (dist < (cur->n2Dist)) {
//					cur->n2Dist = dist;   //swapping
//					cur->n2 = temp;
//				}
//			}
//			temp = temp->next;
//		}
//		cur = cur->next;
//	}
//}
//
//map_t* userCoor2graph(map_t* list_head, textfile_t* starting_point, int user_oil) {
//	double dist;
//	map_t* temp = list_head;
//	map_t* user_coor = malloc(sizeof(map_t)); //aloocating new node
//	if (user_coor == NULL)
//		exit(1);  
//
//	user_coor->flake = starting_point;
//	user_coor->next = list_head; //conect node to map_t list, and making this pointer as the new head
//	innit_node(user_coor);
//	user_coor->oil = user_oil;
//
//	while (temp != NULL) { //finding the 2 closest nodes same way as in build graph(only one node so one loop needed)
//		dist = calc_dist(user_coor->flake, temp->flake);
//		if (dist < user_coor->n1Dist) {
//			user_coor->n2Dist = user_coor->n1Dist;
//			user_coor->n2 = user_coor->n1;
//			user_coor->n1Dist = dist;
//			user_coor->n1 = temp;
//		}
//		else if (dist < user_coor->n2Dist) {
//			user_coor->n2Dist = dist;
//			user_coor->n2 = temp;
//		}
//		temp = temp->next;
//	}
//	return user_coor;
//}
//
//void free_mapNflake(map_t* head) { //free map_t and textfile_t lists
//	if (head == NULL)
//		return;
//	free_mapNflake(head->next);
//	free(head->flake);
//	free(head);
//}
//
////--------------- finding all the possible routes -----------
//void print_route(route_t* route_node) { //printing route to cmd from a reversed list
//	if (route_node == NULL)
//		return;
//	print_route(route_node->next);
//	if (route_node->next == NULL)
//		printf_s("|%d| (%d,%d) oil=%d", route_node->flake->size, route_node->flake->p1.x, route_node->flake->p1.y, route_node->oil); //first move does not require '->'
//	else printf_s(" -> |%d| (%d,%d) oil=%d", route_node->flake->size, route_node->flake->p1.x, route_node->flake->p1.y, route_node->oil);
//	return;
//}
//
//route_t* scan_route(map_t* map_node) { //saving a potential route from user coor to last node, and save it in route_t list format
//	route_t* cur_route = NULL;
//	route_t* head = NULL;
//	int counter = 0;
//
//	while (map_node != NULL) {
//		cur_route = malloc(sizeof(route_t)); //aloocating memory fo route_t node
//		if (cur_route == NULL)
//			exit(1); 
//
//		//initializing node data:
//		cur_route->flake = map_node->flake;
//		cur_route->oil = map_node->oil;
//		counter++; //counting the number of coordinates passed in a specific route
//		cur_route->count = counter;
//
//		cur_route->next = head; //connect the nodes to a list
//		head = cur_route;
//
//		map_node = map_node->route;
//	}
//	return head; //returning the head of the rout+t list, which is the end of the specific route
//}
//
//pathsList_t* make_path_list(route_t* route_tail, pathsList_t* path_head) { // making a list of lists, from all route_t lists, while every node contain pointer to every route ending.
//	pathsList_t* path_node = NULL;
//	path_node = malloc(sizeof(pathsList_t));
//	if (path_node == NULL)
//		exit(1); 
//	path_node->path = route_tail; //saving the end of the road (head of rout_t)
//	path_node->next = path_head; //connecting the pathlist_t nodes
//	path_head = path_node;
//	return path_head;
//}
//
//route_t* the_road_yes_taken(pathsList_t* path_ptr) { //comparing a specific route to all other possible routes
//	route_t* best_route = path_ptr->path;
//
//	if (path_ptr->next == NULL)
//		return best_route; //in case that the route contain 1 coordinate
//
//	while (path_ptr != NULL) {
//		if ((best_route->count) < (path_ptr->path->count))
//			return NULL; // returns null if the specific route isnt optimal
//
//		else if ((best_route->count) == (path_ptr->path->count))
//			if ((best_route->oil) > (path_ptr->path->oil))
//				return NULL; // returns null if the specific route isnt optimal
//
//		path_ptr = path_ptr->next;
//	}
//	return best_route; //returns the specific route pointer if indeed optimal
//}
//
//pathsList_t* find_all_paths(map_t* map_head, map_t* node, pathsList_t* path_head) { // scaning all possible routes from the map graph, and saving it in route_t and pathlist_t formats
//	map_t* temp = node;
//	route_t* cur_route = NULL;
//	route_t* temp_best_route = NULL;
//	int trash_oil = 0;
//
//	temp->visit = 1;
//	cur_route = scan_route(map_head);  //scaning the route from the user coor to a specific map_t node
//	path_head = make_path_list(cur_route, path_head); // save the route in pathlist_t list format
//	temp_best_route = the_road_yes_taken(path_head); // check if this specific route is optimal
//	if (temp_best_route != NULL) {
//		print_route(temp_best_route);
//		printf_s("\n");
//	}
//	if (temp->n1->visit == 0) {  //checking the n1 node--going for the closest neighboor
//		temp->route = temp->n1;
//		trash_oil = abs((temp->flake->p1.x) - (temp->n1->flake->p1.x));
//		trash_oil += abs((temp->flake->p1.y) - (temp->n1->flake->p1.y)); //calc the oil used for the movment
//		temp->n1->oil = (temp->oil) - trash_oil - (temp->n1->flake->size); //calc the amount of oil that the drwon remain at the specific node
//
//		if (temp->n1->oil >= 0)
//			path_head = find_all_paths(map_head, temp->n1, path_head);
//	}
//	if (temp->n2->visit == 0) {  //checking the n2-going for the second closest neighboor
//		temp->route = temp->n2;
//		trash_oil = abs((temp->flake->p1.x) - (temp->n2->flake->p1.x));
//		trash_oil += abs((temp->flake->p1.y) - (temp->n2->flake->p1.y)); //calc the oil used for the movment
//		temp->n2->oil = temp->oil - trash_oil - (temp->n2->flake->size); //calc the amount of oil that the drwon remain at the specific node
//
//		if (temp->n2->oil >= 0)
//			path_head = find_all_paths(map_head, temp->n2, path_head);
//	}
//	temp->visit = 0;
//	temp->route = NULL; //closing the route_t list
//	return path_head;
//}
//
//void free_route(route_t* route_head) { //free route_t list from the end
//	if (route_head == NULL)
//		return;
//	free_route(route_head->next);
//	free(route_head);
//	return;
//}
//
//void free_pathNroute(pathsList_t* path_head) { //free the pathlist_t + all the route_t lists in it
//	if (path_head == NULL)
//		return;
//	free_pathNroute(path_head->next);
//	free_route(path_head->path);
//	free(path_head);
//}
//
//void free_for_all(map_t* map_ptr, pathsList_t* path_ptr) {
//	free_pathNroute(path_ptr);
//	free_mapNflake(map_ptr);
//}
//
////------------- creating best route file ---------
//route_t* pickDAbest(pathsList_t* path_ptr) { //picks the most optimal route from all possible routes
//	route_t* best_route = path_ptr->path;
//
//	while (path_ptr != NULL) {
//		if ((best_route->count) < (path_ptr->path->count))
//			best_route = path_ptr->path;  //swapping to a new best route according to demand
//
//		else if ((best_route->count) == (path_ptr->path->count))
//			if ((best_route->oil) > (path_ptr->path->oil))// maybe add =
//				best_route = path_ptr->path;  //swapping to a new best route according to demand
//
//		path_ptr = path_ptr->next;
//	}
//	return best_route;
//}
//
//void print2best_file(route_t* route_node, FILE* file_ptr) { //print route steps to best-toute.txt from the end of the list, which is the first coorinate
//	if (route_node == NULL)
//		return;
//	print2best_file(route_node->next, file_ptr);
//	fprintf_s(file_ptr, "(%3d,%3d)\t%d\n", route_node->flake->p1.x, route_node->flake->p1.y, route_node->flake->size); //file format
//}
//
//route_t* create_best_file(pathsList_t* path_ptr) { //creating the text file and adding the table format + printing data to the file with func
//	FILE* best_file_ptr;
//	errno_t error;
//	route_t* best_route = NULL;
//
//
//	error = fopen_s(&best_file_ptr, BESTFILE, "wt");
//	if (error != 0) {
//		printf_s("Error open the best-route.txt\n");
//		return NULL;
//	}
//	else {
//		best_route = pickDAbest(path_ptr);
//		fprintf_s(best_file_ptr, "Best Route\tSize\n");
//		print2best_file(best_route, best_file_ptr);
//		fclose(best_file_ptr);
//		printf_s("New best-route.txt file was created\n");
//		return best_route;
//	}
//}
//
////-------- create flake-copy bmp------
//route_t* reverse_route(route_t* route_head) { //reverse route list
//	route_t* cur = route_head;
//	route_t* new_next = NULL;
//	route_t* temp = NULL;
//
//	while (cur != NULL) {
//
//		temp = cur->next;
//		cur->next = new_next; //swap direction
//		new_next = cur;
//		cur = temp;   //forwarding
//	}
//	route_head = new_next;
//	return route_head;
//}
//
//void draw_pix_way(route_t* start, unsigned char** mat, int height) { //changing the mat that represent pixels to a different num to build actual route
//	int deltaX = 0, deltaY = 0;
//	int cur_x = (start->flake->p1.x) - 1;
//	int cur_y = (start->flake->p1.y) - 1;
//
//	while ((cur_x != (start->next->flake->p1.x) - 1) || (cur_y != (start->next->flake->p1.y) - 1)) {
//		deltaX = (start->next->flake->p1.x - 1) - cur_x;
//		deltaY = (start->next->flake->p1.y - 1) - cur_y;
//
//		if (abs(deltaX) > abs(deltaY)) {    //going right or left in case horizinal distance is longer
//			(deltaX > 0) ? ++cur_x : --cur_x;  //picking right or left according to delta sign
//			mat[height - 1 - cur_y][cur_x] = 175;
//		}
//		else if (abs(deltaX) < abs(deltaY)) {  //going up or down in case vertical distance is longer
//			(deltaY > 0) ? ++cur_y : --cur_y;  //picking up or down according to delta sign
//			mat[height - 1 - cur_y][cur_x] = 175;
//		}
//		else {         // going to one of the diagonal neighboors acording to delta x and delta y signs
//			if (deltaX > 0)
//				++cur_x;
//
//			if (deltaX < 0)
//				--cur_x;
//
//			if (deltaY > 0)
//				++cur_y;
//
//			if (deltaY < 0)
//				--cur_y;
//
//			mat[height - 1 - cur_y][cur_x] = 175;
//		}
//	}
//}
//
//void fix_mat(route_t* best_route, unsigned char** mat, int height) {
//	int i = 0, j = 0;
//
//	i = best_route->flake->p1.x - 1;
//	j = best_route->flake->p1.y - 1;
//	mat[height - 1 - j][i] = 100;  //puts 100 char as the starting point
//	draw_pix_way(best_route, mat, height);
//	best_route = best_route->next;
//
//	while (best_route != NULL) {
//		i = best_route->flake->p1.x - 1;
//		j = best_route->flake->p1.y - 1;
//		mat[height - 1 - j][i] = 150;  //puts 150 char at the p1 coor of every flake
//		if (best_route->next != NULL)
//			draw_pix_way(best_route, mat, height);
//		best_route = best_route->next;
//	}
//}
//
//unsigned char** readBMP1(unsigned int* width, unsigned int* hight) { // Noam Eldar
//	unsigned char** blue = NULL; // blue matrix of bmp image
//	FILE* flakeFile;
//	fopen_s(&flakeFile, BMP, "r");
//	if (flakeFile == NULL) {
//		printf_s("Error: file open\n");
//		return 0;
//	}
//	// set data offset from header.
//	fseek(flakeFile, 10, SEEK_SET);
//	int dataOffset;
//	fread_s(&dataOffset, 4, 1, 4, flakeFile);
//
//	// set widht from header.
//	fseek(flakeFile, 4, SEEK_CUR);
//	fread_s(width, 4, 1, 4, flakeFile);
//
//	// set heifht from header.
//	fread_s(hight, 4, 1, 4, flakeFile);
//
//	blue = (unsigned char**)malloc(*hight * sizeof(unsigned char*));
//	if (blue == NULL) {
//		return 0;
//	}
//	for (int i = 0; i < (int)(*hight); i++) {
//		blue[i] = (unsigned char*)malloc(*width * sizeof(unsigned char));
//	}
//	// point file to image data (pixels)
//	fseek(flakeFile, dataOffset, SEEK_SET);
//	for (int i = (int)(*hight - 1); i >= 0; i--) {
//		for (unsigned int j = 0; j < *width; j++) {
//			RGB pixel;
//			fread_s(&pixel, sizeof(RGB), 1, sizeof(RGB), flakeFile);
//			blue[i][j] = (pixel.red + pixel.green + pixel.blue) / 3;
//		}
//		int jump = (*width * 3) % 4 == 0 ? 0 : (4 - ((*width * 3) % 4));
//		fseek(flakeFile, jump, SEEK_CUR);
//	}
//	return blue;
//}
//
//void copy_bmp(FILE* flakecopy, unsigned int* width, unsigned int* hight, unsigned int* dataOffset) {//Gal Patz
//	FILE* flakeFile;
//	unsigned int charget;
//	fopen_s(&flakeFile, BMP, "r");
//	if (flakeFile == NULL) {
//		printf_s("Error: file open\n");
//		return;
//	}
//	fseek(flakeFile, 0, SEEK_SET);
//	while ((charget = fgetc(flakeFile)) != EOF)
//		fputc(charget, flakecopy);
//
//	fseek(flakeFile, 10, SEEK_SET);
//	fread_s(dataOffset, 4, 1, 4, flakeFile);
//
//	// set widht from header.
//	fseek(flakeFile, 4, SEEK_CUR);
//	fread_s(width, 4, 1, 4, flakeFile);
//
//	// set heifht from header.
//	fread_s(hight, 4, 1, 4, flakeFile);
//
//	fclose(flakeFile);
//}
//
//void dye_bmp(unsigned char arr, FILE* flakecopy, unsigned int dataOffset, int j, int k, unsigned int hight) {//Gal Patz
//	int jump = 0, temp = 0;
//
//	temp = (hight * 3) % 4 == 0 ? 0 : (4 - ((hight * 3) % 4));
//	jump = dataOffset + j * 3 + k * hight * 3 + (k * temp);
//
//	fseek(flakecopy, jump, SEEK_SET);
//
//	switch (arr) {
//	case 100: {//red
//		fputc(0, flakecopy);
//		fputc(0, flakecopy);
//		fputc(255, flakecopy);
//		break;
//	}
//	case 150: { //blue
//		fputc(255, flakecopy);
//		fputc(255, flakecopy);
//		fputc(0, flakecopy);
//		break;
//	}
//	case 175: {
//		fputc(255, flakecopy);
//		fputc(0, flakecopy);
//		fputc(0, flakecopy);
//		break;
//	}
//	}
//}
//
//void create_flake_copy(unsigned char** mat, int count) { //Gal Patz & Alon Gershon
//	FILE* flakecopy;
//	unsigned int dataOffset = 0, width = 0, hight = 0;
//	int i, j, k = 0;
//
//	fopen_s(&flakecopy, BMPCPY, "wb");
//	if (flakecopy == NULL) {
//		printf_s("Error: could not open 'flake-copy'\n\n");
//		return;
//	}
//
//	else {
//		copy_bmp(flakecopy, &width, &hight, &dataOffset);
//		if (count > 1) {
//			for (i = hight; i > 0; i--) {
//				for (j = 0; j < width; j++) {
//					if (mat[i - 1][j] != 255 && mat[i - 1][j] != 0) // only care about pixels that were painted and not original flakes
//						dye_bmp(mat[i - 1][j], flakecopy, dataOffset, j, k, width);
//				}
//				k++;
//			}
//		}
//	}
//	fclose(flakecopy);
//	printf_s("A BMP file flake-copy.bmp was created\n\n");
//}
//
//void draw_route(FILE* bmp_ptr, route_t* best_route) {
//	unsigned int width = 0, hight = 0;
//	unsigned char** mat = NULL;
//	int count = 0;
//
//	count = best_route->count;
//	best_route = reverse_route(best_route); //make the last coor, last on the list
//	mat = readBMP1(&width, &hight);
//	if (count > 1) // wont bother going thru those functions if he didnt made his way not even to a single flake
//		fix_mat(best_route, mat, hight); //insert new chars to the matrix that will be invert to colored route
//
//	create_flake_copy(mat, count); //creates the bmp file with the new route printed
//}
//
//
//void option3() {
//	int  dfct_num, offset, oil, userX = 0, userY = 0;
//	FILE* defect_ptr, * flake_ptr;
//	textfile_t* flake_list_head, * user_cord;
//	map_t* map_list_head = NULL;
//	route_t* best_route = NULL;
//	pathsList_t* path_ptr = NULL;
//	errno_t error = fopen_s(&flake_ptr, BMP, "r");
//	if (error != 0) {
//		printf_s("Error open the flake.bmp\n");
//	}
//	else {
//		user_cord = set_COOR(flake_ptr);
//		oil = set_oil();
//		error = fopen_s(&defect_ptr, TXT, "r");
//		if (error != 0) {
//			printf_s("Problem reading defects.txt file\n");
//			printf_s("No flakes found!\n");
//		}
//		else {
//			offset = offset_counter(defect_ptr);
//			dfct_num = defect_counter(defect_ptr);
//			if (dfct_num == 0) {
//				printf_s("No flakes found!\n");
//				return;
//			}
//			fseek(defect_ptr, offset, SEEK_SET);
//			flake_list_head = build_flk_list(dfct_num, defect_ptr);
//			map_list_head = build_map_list(flake_list_head);
//			build_graph(map_list_head);
//			map_list_head = userCoor2graph(map_list_head, user_cord, oil);
//			path_ptr = find_all_paths(map_list_head, map_list_head, path_ptr);
//			best_route = create_best_file(path_ptr);
//			fclose(defect_ptr);
//		}
//		fclose(flake_ptr);
//		draw_route(flake_ptr, best_route);
//	}
//	free_for_all(map_list_head, path_ptr);
//}
//
////function 4
//void GetCoordinates(char* p1, char* px, char* py) {//Gal Patz, get the cordinat to string
//	while (*p1 == '(' || *p1 == ' ')//move until a number
//		p1++;
//	while (*p1 != ',')//put the number in px string
//		*px++ = *p1++;
//	while (*p1 == ',' || *p1 == ' ')//move until the next number
//		p1++;
//	while (*p1 != ')')//put the number in py string
//		*py++ = *p1++;
//}
//
//int checkint(char* str, int size) {//Gal Patz, check if the value is valid
//	int i, flag = 0;
//	char temp;
//	temp = *str;
//
//	for (i = 0; i < size; i++) {//check each character in the string
//
//		if (!(temp >= '0' && temp <= '9' || temp == '\0' || temp == -2))//If one of the characters is invalid return 0
//			return 0;
//		temp = *str++;
//	}
//	str = str - 81;//Return the position of the pointer to the beginning of the string
//	temp = *str;
//	while (temp == '0' && temp != -2 || temp == '\0') {//A loop that handles the case and the user entered a value i.e. 00001
//		if (temp >= '1' && temp <= '9')
//			return 1;
//		else
//			temp = *str++;
//	}
//	if (temp == -2)
//		return 0;
//	else
//		return 1;
//}
//
//double max_distance(pix_t* head) {//Gal Patz, calculate the max distance
//	double sum = 0;
//	pix_t* p1 = NULL;
//	p1 = head->next;//pointer to the next cordinate
//
//	while (p1 != NULL) {
//		sum = sqrt(pow(head->p.x - p1->p.x, 2) + pow(head->p.y - p1->p.y, 2)) + sum;//distance between to cordinate
//		head = p1;//move the next cordunate
//		p1 = p1->next;
//	}
//	return sum;//return the sum of the distnace
//}
//
//void print_fun_4(int JUMP, float distance, pix_t* head) {//Gal Patz
//	double c = 0.100, D = 0;
//	int i = 0, dx = 0, temp = 0, intdistance = distance;
//	int* ptr = NULL;
//	double* arr;
//	pix_t* p1 = NULL;
//	arr = malloc(sizeof(double) * 2 * intdistance);//A one-dimensional array that will contain the calculations
//
//	for (i = 0; i < distance; i++) {//A loop that ran up to an entire value from a distance
//		if (i == 0) {//In the first iteration
//			printf_s("Distance   Consumption\n========== ===========\n");
//			arr[i] = 0.100;
//			p1 = head->next;
//			D = sqrt(pow(head->p.x - p1->p.x, 2) + pow(head->p.y - p1->p.y, 2));
//			//Calculate the distance between the starting pointand the first defect
//		}
//		else {
//			while (dx != 1000) {//Calculation of 1000 iterations
//				if (ptr == 1) {//In a situation where the distance is equal to zero
//					head = p1;
//					p1 = p1->next;
//					if (p1 != NULL) {
//						D = 0, temp = 0; ptr = NULL;
//						D = sqrt(pow(head->p.x - p1->p.x, 2) + pow(head->p.y - p1->p.y, 2));
//						//Calculate the distance to the next defect
//					}
//					else ptr = NULL;
//				}
//				c = DX * (1 / (c * 2.5) + 5 * f_x(D, temp, &ptr)) + c;//calculation
//				dx++; temp++;
//			}
//			arr[i] = c; dx = 0;//Saving all the thousand iterations in the array
//		}
//	}
//	for (i = 0; i < distance; i += JUMP) {//Print to the screen according to the jumps entered by the user
//		if (arr[i] < 10)
//			printf_s("%10d\t%.3f\n", i, arr[i]);
//		else
//			printf_s("%10d     %.3f\n", i, arr[i]);
//	}
//	printf_s("%10.3f     %.3f\n", distance, caloffset(distance, c));
//	free(arr);
//}
//
//int f_x(double D, int temp, int* ptr) {//Gal Patz, A function that calculates the value of fx
//	int intD = 0;
//	D = D * 1000;//Get the distance in an integer and consider three digits after the dot
//	intD = D;
//	intD -= temp;
//	if (intD == 0)
//		*ptr = 1;//In a situation where the distance to the defect is 0, the pointer indicates 1
//	if (intD <= 5000)//If the distance is greater than 5000 you will return 0 and if it is small you will return 1
//		return 1;
//	else
//		return 0;
//}
//
//double caloffset(float distance, double c) {//Gal Patz, Calculate the difference between an integer and the maximum distance
//	int dx = 0;
//	distance *= 1000;
//	distance = (int)distance % 1000;
//
//	while (dx != ((int)distance)) {
//		c = DX * (1 / (c * 2.5) + 5 * 1) + c;//calculation
//		dx++;
//	}
//	return c;//Returns the final value
//}
//
//void free_list(pix_t* head) {//Gal Patz, Release a linked list
//	pix_t* temp = head;
//	while (head != NULL) {
//		temp = head->next;
//		free(head);
//		head = temp;
//	}
//}
//
////function 5
//
//void option5() {// Everyone on the team
//	FILE* Routefile = fileopener();
//	int x1, y1, x2, y2, i = 0, sz, key = 0;
//	char* sizechar;
//	char x_2[4], y_2[4], c;
//	unsigned int* width = 0, height = 0;
//	unsigned char** mat5 = NULL;
//	if (Routefile != -1) {
//		int j = linecounter(Routefile);
//		mat5 = readBMP(&width, &height);
//		int signedwidth = (int)width;
//		int signedheight = (int)height;
//		while (key == 0) {
//			printf_s("Please Enter valid x, y start coordinate, bmp width is % d and height is % d\n", signedwidth, signedheight);
//			scanf_s(" %d %c %d", &x1, &c, 1, &y1);
//			if ((x1 > 0 && x1 <= width) && (y1 > 0 && y1 <= height) && (c == ','))
//				key = 1;
//		}
//		textfile_t* head = NULL;
//		sz = fsize(Routefile);
//		char** line = malloc(j * (sizeof(sz) + 1));//making an array of every line in file
//		line = line2array(Routefile, j);
//		fclose(Routefile);
//		for (int k = 0; k + 2 < j; k++) {
//			sizechar = strrchr(line[i + 2], ') ');
//			GetCoordinates(line[i + 2], x_2, y_2);
//			x2 = char2int(x_2);
//			y2 = char2int(y_2);
//			int size = char2int(sizechar);
//			head = listinsert(head, x1, y1, x2, y2, size);
//			i++;
//		}
//		spread_the_word(mat5, height, head);
//		printstats(head, signedwidth, signedheight);
//		create_flake_copy_5(mat5);
//		free_txtfile_list(head);
//		set_me_free(line, j);
//	}
//}
//
//int get_fuel(textfile_t* head) { //Gal Patz	
//	textfile_t* head_next = head;
//	int sum_fuel = 0;
//
//	if (head == NULL) //if list is ampty
//		return 0;
//
//	while (head != NULL)
//	{
//		sum_fuel += head->size; //take from each struct the integer size and sum
//		head = head->next;
//	}
//	sum_fuel = get_route_fuel(head_next, sum_fuel); //sand the list and the sum_fuel until now
//	return sum_fuel;
//}
//
//int get_route_fuel(textfile_t* head, int sum_fuel) { //Gal Patz	
//
//	while (head != NULL) { //move until the end of the list
//		sum_fuel += abs(head->p1.x - head->p2.x) + abs(head->p1.y - head->p2.y); //calculat the fuel that the quadcopter need
//		head = head->next;
//	}
//	return sum_fuel;
//}
//
//void spread_the_word(unsigned char** mat, int height, textfile_t* flake_list_head) {
//	int x_start, y_start, deltaX = 0, deltaY = 0;
//	textfile_t* temp = NULL;
//
//	x_start = flake_list_head->p1.x - 1;
//	y_start = flake_list_head->p1.y - 1;
//	mat[height - 1 - y_start][x_start] = 100; //paint starting point 
//	temp = flake_list_head;
//
//	while (temp != NULL) {
//		x_start = flake_list_head->p1.x - 1;
//		y_start = flake_list_head->p1.y - 1;
//		while ((x_start != temp->p2.x - 1) || (y_start != temp->p2.y - 1)) {
//			deltaX = (temp->p2.x - 1) - x_start;
//			deltaY = (temp->p2.y - 1) - y_start;
//			if (abs(deltaX) > abs(deltaY)) {
//				(deltaX > 0) ? ++x_start : --x_start;
//			}
//			else if (abs(deltaX) < abs(deltaY)) {
//				(deltaY > 0) ? ++y_start : --y_start;
//			}
//			else {
//				(deltaX > 0) ? ++x_start : --x_start;
//				(deltaY > 0) ? ++y_start : --y_start;
//			}
//			mat[height - 1 - y_start][x_start] = 175;
//		}
//		temp = temp->next;
//	}
//}
//
//textfile_t* listinsert(textfile_t* head, int x1, int y1, int x2, int y2, int size) {
//	textfile_t* newnode;
//	newnode = (textfile_t*)malloc(sizeof(textfile_t));
//	newnode->p1.x = x1;
//	newnode->p1.y = y1;
//	newnode->p2.x = x2;
//	newnode->p2.y = y2;
//	newnode->size = size;
//	newnode->next = head;
//	head = newnode;
//	return head;
//}
//
//void free_txtfile_list(textfile_t* head) {
//	if (head == NULL)
//		return;
//	free_txtfile_list(head->next);
//	free(head);
//}
//
//void create_flake_copy_5(unsigned char** mat) { //Gal Patz & Alon Gershon
//	FILE* flakecopy_5;
//	unsigned int dataOffset = 0, width = 0, hight = 0;
//	int i, j, k = 0;
//
//	fopen_s(&flakecopy_5, "bmp_fun_5.bmp", "wb");
//	if (flakecopy_5 == NULL) {
//		printf_s("Error: could not open 'bmp_fun_5'\n\n");
//		return;
//	}
//	else {
//		copy_bmp(flakecopy_5, &width, &hight, &dataOffset);
//		for (i = hight; i > 0; i--) {
//			for (j = 0; j < width; j++) {
//				if (mat[i - 1][j] != 255 && mat[i - 1][j] != 0) // only care about pixels that were painted and not original flakes
//					dye_bmp(mat[i - 1][j], flakecopy_5, dataOffset, j, k, width);
//			}
//			k++;
//		}
//	}
//	fclose(flakecopy_5);
//	printf_s("A BMP file bmp_fun_5.bmp was created\n--------------------------\n\n");
//}
//
//int Toyotaprius(textfile_t* head) {
//	textfile_t* head_next = head;
//	int sum_size = 0;
//
//	if (head == NULL)
//		return 0;
//
//	while (head != NULL)
//	{
//		sum_size += head->size;
//		head = head->next;
//	}
//	return sum_size;
//}
//void printstats(textfile_t* head,int signedwidth, int signedheight) {
//	int sum_fuel,  efficency,  sum_size;
//	int surface = signedwidth * signedheight;
//	float black_pix_matter = 0;
//
//	sum_fuel = get_fuel(head);
//	printf_s("--------------------------\n");
//	printf_s("The cost of fuel for all $$$ShmulikQUADcopter$$$ is: %d\n", sum_fuel);
//	sum_size = Toyotaprius(head);
//	efficency = sum_size * 100 / sum_fuel;
//	black_pix_matter = ((float)(sum_fuel * 100) / (float)(surface));
//	printf_s("The efficency is at roughly %d%c\n", efficency,37);
//	printf_s("%.2f%c of the image Isn't white\n",black_pix_matter,37);
//	return;
//}