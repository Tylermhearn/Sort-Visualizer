

#include <iostream>
#include <Windows.h>
#include "functions.h"
#include <gdiplus.h>
#include <thread>
#include <chrono>
#include <vector>
#include <stdlib.h>
#include <time.h>

int main()
{

	char menu_selection = NULL;
	int num_lines = 0;



	std::cout << "Hello! In this program you will be able to see various different sorting algorithms visualized.\nCreated by Tyler Hearn\n";
	while (toupper(menu_selection) != 'X') {
		menu();
		std::cin >> menu_selection;
		if (toupper(menu_selection) == 'A') {
			std::cout << "Input how many items you would like to sort: ";
			std::cin >> num_lines;
			system("CLS");
			line_creation(num_lines);
			line_display();
			std::cout << "\nSorting in:\n";
			for (int i = 3; i >= 0; i--) {
				printf("\t%d\r", i);
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			}
			for (int i = 0; i < num_lines; i++) {
				for (int j = 0; j < num_lines - i - 1; j++) {
					if (lines[j] > lines[j + 1]) {
						int temp;
						temp = lines[j];
						lines[j] = lines[j + 1];
						lines[j + 1] = temp;
						system("CLS");
						line_display();
						std::this_thread::sleep_for(std::chrono::milliseconds(25));
					}
				}
			}
			lines.clear();
		}

		else if (toupper(menu_selection) == 'B') {
			int key, j;
			std::cout << "Input how many items you would like to sort: ";
			std::cin >> num_lines;
			line_creation(num_lines);
			line_display();
			std::cout << "\nSorting in:\n";
			for (int i = 3; i >= 0; i--) {
				printf("\t%d\r", i);
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			}
			for (int i = 1; i < num_lines; i++) {
				key = lines[i];
				j = i - 1;

				while (j >= 0 && lines[j] > key) {
					lines[j + 1] = lines[j];
					j = j - 1;
				}
				lines[j + 1] = key;
				system("CLS");
				line_display();
				std::this_thread::sleep_for(std::chrono::milliseconds(25));
			}
			lines.clear();
		}
		else if (toupper(menu_selection) == 'C') {
			std::cout << "Input how many items you would like to sort: ";
			std::cin >> num_lines;
			line_creation(num_lines);
			line_display();
			std::cout << "\nSorting in:\n";
			for (int i = 3; i >= 0; i--) {
				printf("\t%d\r", i);
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			}
			merge_sort(lines, 0, num_lines - 1);
			lines.clear();
		}
		else if (toupper(menu_selection) == 'D') {
			std::cout << "Input how many items you would like to sort: ";
			std::cin >> num_lines;
			line_creation(num_lines);
			line_display();
			std::cout << "\nSorting in:\n";
			for (int i = 3; i >= 0; i--) {
				printf("\t%d\r", i);
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			}
			quickSort(lines, 0, num_lines - 1);
			lines.clear();
		}
		else if (toupper(menu_selection) == 'E') {
			std::cout << "Input how many items you would like to sort: ";
			std::cin >> num_lines;
			line_creation(num_lines);
			line_display();
			std::cout << "\nSorting in:\n";
			for (int i = 3; i >= 0; i--) {
				printf("\t%d\r", i);
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			}
			radixsort(lines, num_lines);
			lines.clear();
		}
		else if (toupper(menu_selection) == 'F') {
			std::cout << "Input how many items you would like to sort: ";
			std::cin >> num_lines;
			line_creation(num_lines);
			line_display();
			std::cout << "\nSorting in:\n";
			for (int i = 3; i >= 0; i--) {
				printf("\t%d\r", i);
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			}
			shellSort(lines, num_lines);
			lines.clear();
		}
		else if (toupper(menu_selection) == 'G') {
			std::cout << "Input how many items you would like to sort: ";
			std::cin >> num_lines;
			line_creation(num_lines);
			line_display();
			std::cout << "\nSorting in:\n";
			for (int i = 3; i >= 0; i--) {
				printf("\t%d\r", i);
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			}
			CocktailSort(lines , num_lines);
			lines.clear();
		}
		else if (toupper(menu_selection) == 'Y') {
			system("CLS");
		}

	}
	return 0;
}


