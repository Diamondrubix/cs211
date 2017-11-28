#include <stdio.h>
#include <string.h>
#include <stdlib.h> //with maloc


//Writes a function that will make a copy the values from one array to another array.
void arrayCopy (int *fromArray, int *toArray, int size){
    int i =0;
    for(i; i<size;i++){
        toArray[i] = fromArray[i];
    }
    //printf(fromArray[0]);
}
//Write your own function that will sort an array in ascending order.
void myFavorateSort (int arr[], int size){
    //int temp[size];
    int i=1;
    for(i;i<size;i++){
        int j = i;
        while(j>0){
            if(arr[j]<arr[j-1]){
                int x = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = x;
                j--;
            }else{
                break;
            }
        }
    }
}

//Write your own function that will perform a linear search on the unsorted array.
int linSearch (int arr[], int size, int target, int* numComparisons){
    int i =0;
    for(i; i<size;i++){
        if(arr[i]==target){
            *numComparisons = i+1;
            //printf("%d",numComparisons);
            return i;
        }
    }
    *numComparisons=size;
    return -1;
}

//Write your own function that will perform a binary search on the sorted array.
int binSearch (int arr[], int size, int target, int* numComparisons){
    int low=0;
    int high=size;
    int count = 0;
    while(high-low>0){
        count++;
        int index = ((high-low)/2)+low;
        if(arr[index]==target){
            *numComparisons = count+1;
            return (index);
        }else{
            int test = arr[index]; //delete later
            if(arr[index]<target){
                low=index+1;
            }else{
                high=index;
            }
        }
    }
    return -1;
}


void oneByOne(){ //not used rn
    int *array1;
    int value = 0;
    int size = 3;
    array1 = (int *) malloc (size * sizeof(int) );
    //array1[3]; //how is this different than the above line of code?
    int count =0;
    while(value!=-999) {
        if(count >=size){
            int *temp;
            temp = (int *) malloc ( size * 2 * sizeof(int) );
            int i;
            for ( i = 0 ; i < size ; i++)
                temp[i] = array1[i];
            free (array1);
            array1 = temp;
            size = size * 2;
        }
        count++;
        printf("\nso what input do you want?(-999 to stop) ");
        scanf("%d", &value);
        array1[count] = value;

    }
}

int main() {

    int value =0;
    int *array1;
    int size = 3;
    array1 = (int *) malloc (size * sizeof(int) );
    int count =0;
    while(value!=-999) {
        if(count+1 >=size){
            int *temp;
            size = size * 2;
            temp = (int *) malloc ( size * sizeof(int) );
            //temp[size];
            int i;
            for ( i = 0 ; i < size ; i++)
                temp[i] = array1[i];
            free (array1);
            array1 = temp;
        }
        printf("\nso what input do you want?(-999 to stop) ");
        scanf("%d", &value);
        if(value!=-999) { //more effecient solution available. fix later
            array1[count] = value;
            count++;
        }
    }

    //printArray(array1,count);

    printf("\nArray program\n");
    //part 1
    //printf("%d",array1[5]);
    int array2[count];
    arrayCopy(array1,array2,count);

    //part 2
    myFavorateSort(array2,count);

    //part 3

    int  comparisons = 0;
    printf("what value are you looking for? ");//why can't i add this string into the scanf below?
    scanf("%d", &value);
    while(value!=-999) {
        printf("the value of %d is at index %d", value,
               linSearch(array1, count, value, &comparisons)); //not sure this is allowed
        printf(" it needed %d comparisons with the linear search.\n", comparisons);
        //printf("\n%d",x); //checks to see if it works

        //part 4
        //printArray(array1,5);
        printf("The value of %d is at index %d", value, binSearch(array2, count, value, &comparisons));
        printf(" it needed %d comparisons with the binary serach.\n", comparisons);
        /*
        int j =0;
        for(j;j<20;j++) {
            printf("The value of %d is at index %d", j, binSearch(array1, count, j, &comparisons));
            printf(" it needed %d comparisons with the binary serach.\n", comparisons);
        }
         */
        scanf("%d", &value);
    }
    return 0;
}

void printArray(int *array,int size){
    //int n = sizeof(array) / sizeof(array[1]);
    //printf("%d",sizeof(array);
    int i =0;
    for(i; i<size;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}

void test(int *array1){
    printf("test \n");
    int n = sizeof(array1) / sizeof(array1[1]);
    printf("%d",sizeof(*array1));
    printf("\nend tets\n");

}
/*old
int binSearch (int arr[], int size, int target, int* numComparisons){
    int start = 0;
    int end = size;
    int location = size/2;
    int lastLocation;
    while(start<=end) {
        if (arr[location] == target) {
            return location;
        } else {
            if (arr[location] < target) {
                start = location;
            } else {
                end = location;
            }
            lastLocation = location;
            location = (end - start)/2 + start;
            if(lastLocation==location){
                break;
            }
        }
    }
    return -1;
}
//*/