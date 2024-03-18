#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <windows.h>
#include <unistd.h>
#include <cstdarg>
#include <string.h>

#define BGCOLOR 0
#define FILLCOLOR COLOR(255, 255, 255)
#define MAXLENGTH 800
#define MAXWIDTH 1000

class Bar {
private:
	int x, y, width, height, color; // Declare required variables such as bar dimensions.
	char *num;

public:
	Bar();
	Bar(int x, int y, int width, int height, char *num) : x{x}, y{y}, width{width}, height{height}, num{num} {
		draw(FILLCOLOR);
	}

	// getters
	int get_x() {
		return x;
	}

	int get_y() {
		return y;
	}

	int get_height() {
		return height;
	}

	// setters
	int set_x(int x) {
		this->x = x;
	}

	// Define function to draw a bar object with graphics' functions.
	void draw(int color) {
		outtextxy(x, y + 40, num);
		setcolor(color);
		setfillstyle(1, color);
		int coordArr[8] = {x, y, x + width, y, x + width, y - height, x, y - height};
		fillpoly(4, coordArr);
		rectangle(x, y, x + width, y - height);
	}
};

// Define function to update the Bar chart

void update(Bar arr[], int n) {
	cleardevice();
	int x = 100;
	for (int i = 0; i < n; i++) {
		arr[i].set_x(x);
		arr[i].draw(FILLCOLOR);
		x += 30;
	}
}

// Define sorting algorithm :- Bubble sort.
void bubbleSort(Bar arr[], int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {	
			 // Compare the heights of bar objects.
			if (arr[j].get_height() > arr[j + 1].get_height()) {						  
				Bar temp = arr[j + 1]; // Swap the objects
				arr[j + 1] = arr[j];
				arr[j] = temp;
				update(arr, n); // Update the bars after swapping.
				sleep(1);				// sleep(1);
			}
		}
	}
}

void selection_sort(Bar arr[], int n) {
	int i, j, min;
	for (int i = 0; i < n; i++) {
		min = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j].get_height() < arr[min].get_height()) {
				min = j;
			}
		}
		if (min != i) {
			Bar temp = arr[min]; // Swap the objects
			arr[min] = arr[i];
			arr[i] = temp;
			update(arr, n);
		}
	}
}

int main() {

	initwindow(MAXLENGTH, MAXWIDTH); // Initialize display window

	outtextxy(100, 240, "Press any key to start bubble sort visualization.");

	getch();

	// Clear screen before starting procedure.
	cleardevice();

	// Define bar objects.
	Bar bar1(250, 700, 20, 70, "1");
	Bar bar2(130, 700, 20, 110, "2");
	Bar bar3(550, 700, 20, 190, "3");
	Bar bar4(580, 700, 20, 200, "4");
	Bar bar5(520, 700, 20, 230, "5");
	Bar bar6(460, 700, 20, 250, "6");
	Bar bar7(370, 700, 20, 290, "7");
	Bar bar8(340, 700, 20, 300, "8");
	Bar bar9(220, 700, 20, 315, "9");
	Bar bar10(190, 700, 20, 330, "10");
	Bar bar11(490, 700, 20, 390, "11");
	Bar bar12(310, 700, 20, 400, "12");
	Bar bar13(100, 700, 20, 440, "13");
	Bar bar14(160, 700, 20, 480, "14");
	Bar bar15(400, 700, 20, 510, "15");
	Bar bar16(640, 700, 20, 550, "16");
	Bar bar17(610, 700, 20, 580, "17");
	Bar bar18(280, 700, 20, 600, "18");
	Bar bar19(670, 700, 20, 630, "19");
	Bar bar20(430, 700, 20, 640, "20");

	sleep(1);

	// Store the objects in an array for sorting.
	Bar type[20] = {bar11, bar9, bar7, bar18,
					bar14, bar13, bar8, bar16,
					bar2, bar1, bar19, bar17,
					bar4, bar6, bar10, bar15,
					bar3, bar20, bar5, bar12};

	// Delcare the size of array
	int n = 20;

	// Apply sorting alogorithm.
	bubbleSort(type, n);
	// selection_sort(type, n);
	getch();
	closegraph();
	return 0;
}