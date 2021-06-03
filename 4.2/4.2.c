#include <stdio.h>
#include <stdlib.h>
void destroy_array_2d(int** ptr, int height) {
    if (ptr != NULL && height > 0) {
        for (int i = 0; height > i; i++) {
            if (*(ptr + i) != NULL) {
                free(*(ptr + i));
            }
        }
        free(ptr);
    }
}
int** create_array_2d(int width, int height) {
    if (width <= 0 || height <= 0) {
        return NULL;
    }
    int** ptr = NULL;
    ptr = (int**)calloc(height, sizeof(int*)); //rzutownaie na wsakżnik na wskaźnik plus alokacaj pamięi dla kolejnych wierszy * ilość pamięci o wielkości wskażnika int
    if (ptr == NULL) {
        //printf("Failed to allocate memory");
        return NULL;
    }
    for (int i = 0; height > i; i++) {
        *(ptr + i) = NULL;
        *(ptr + i) = calloc(width, sizeof(int));
        if (*(ptr + i) == NULL) {
            destroy_array_2d(ptr, height);
            return NULL;
        }
    }
	return ptr;
}
int matrix_read(int** ptr, int width, int height) {
	if (height <= 0 || width <= 0 || ptr == NULL) {
		return 1;
	}
	printf("Podaj wartości: ");
	for (int i = 0; height > i; i++) {
		for (int j = 0; width > j; j++) {
			int temp;
			int check = scanf("%d", &temp);
			if (check != 1) {
				return 2;
			}
			*(*(ptr + i) + j) = temp;
		}
	}
	return 0;
}
void display_array_2d(int** ptr, int width, int height) {
	if (height <= 0 ||width <= 0 || ptr == NULL) {
		return;
	}
	for (int i = 0; height > i; i++) {
		if (*(ptr + i) != NULL) {
			for (int j = 0; width > j; j++) {
				int temp = *(*(ptr + i) + j);
				printf("%d ", temp);
			}
			printf("\n");
		}
	}
}
int main()
{
	int** ptr = NULL;
	int check = 0;
	int height = 0;
	int width = 0;
	printf("Podaj szerokosc i wysokosc: ");
	check = scanf("%d %d", &width, &height);
	if (check != 2) {
		printf("incorrect input");
		return 1;
	}
	if(width<=0 || height<=0){
		printf("incorrect input data");
		return 2;
	}

	ptr = create_array_2d(width, height);
	if (ptr == NULL) {
		printf("Failed to allocate memory");
		return 8;
	}
	


	check = matrix_read(ptr, width, height);
	if (check == 1) {
		printf("incorrect input data");
		destroy_array_2d(ptr, height);
		return 8;
	}
	else if (check == 2) {
		printf("incorrect input");
		destroy_array_2d(ptr, height);
		return 1;
	}

	display_array_2d(ptr, width, height);

	destroy_array_2d(ptr, height);
	return 0;
}