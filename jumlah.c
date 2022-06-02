#include <stdio.h>
#include "jumlah.h"
#define SIZE 10

float summary(float arr[SIZE][6], int i, int j) {	//function untuk menjumlahkan nilai semester 1 sampai 6
	if(j == 0)
		return arr[i][0];
	return arr[i][j] + summary(arr, i, j - 1);
}


