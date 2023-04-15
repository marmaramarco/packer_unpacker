/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int getDigitCount(int number) {
    int digit_count = 0;
    while(number) {
        digit_count++;
        number /= 10;
    }
    return digit_count;
}

int powerOfTenPositive(int num) {
    int res = 1;
    for(int i = 0; i < num; i++)
        res *= 10;
    return res;
}

int getDigit(int num, int digit) {
    int digit_count = getDigitCount(num);
    num /= powerOfTenPositive(digit_count - digit);
    num %= 10;
    return num;
}



char* dataPacker(int* numData, int dataLength) {
    static char stringData[150];
    int temp, stringIndex = 0;
    for(int i = 0; i < dataLength; i++) {
        temp = getDigitCount(numData[i]);
        for(int j = 1; j <= temp; j++) {
            stringData[stringIndex] = getDigit(numData[i], j) + '0';
            stringIndex++;
        }
        stringData[stringIndex] = '/';
        stringIndex++;
    }

    stringData[stringIndex] = '\0';
    return stringData;
}

int* dataUnPacker(char* stringData) {
    int stringIndex = 0, temp = 0, intIndex = 0;
    while(stringData[stringIndex] != '\0') {
        while(stringData[stringIndex] != '/') {
            
            stringIndex++;
        }
            
        stringIndex++;
        intIndex++;
    }
    stringIndex = 0;
    int *numData = (int *)malloc(intIndex * sizeof(int));
    for(int i = 0; i < intIndex; i++)
        numData[i] = 0;
    intIndex = 0;
    while(stringData[stringIndex] != '\0') {
        while(stringData[stringIndex] != '/') {
            stringIndex++;
            temp++;
        }
        for(int i = temp-1; i >= 0; i--) {
            numData[intIndex] += powerOfTenPositive(i)*(stringData[stringIndex - i - 1] - '0');
        }
        intIndex++;
        stringIndex++;
        temp = 0;
    }
    
    
    return numData;
        
}

int main()
{
    int numData[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 3223};
    int data_length = 13;
    char* stringData = dataPacker(numData, data_length);
    printf("%s", stringData);
    int* num_data_res = dataUnPacker(stringData);
    printf("\n");
    for(int i = 0; i < data_length; i++)
        printf("%d ", num_data_res[i]);
    free(num_data_res);
    return 0;
}