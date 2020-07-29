#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ARRAY_SIZE  11

// The following code (combinationUtil and printCombination) is taken from
// https://www.geeksforgeeks.org/print-all-possible-combinations-of-r-elements-in-a-given-array-of-size-n/

void combinationUtil(const char *arr[], int n, int r, int index, const char *data[], int i, char *root);

// The main function that prints all combinations of size r
// in arr[] of size n. This function mainly uses combinationUtil()
void printCombination(const char *arr[], int n, int r, char *root)
{
    // A temporary array to store all combination one by one
    const char *data[r];

    // Print all combination using temporary array 'data[]'
    combinationUtil(arr, n, r, 0, data, 0, root);
}

/* arr[]  ---> Input Array
   n      ---> Size of input array
   r      ---> Size of a combination to be printed
   index  ---> Current index in data[]
   data[] ---> Temporary array to store current combination
   i      ---> index of current element in arr[]     */
void combinationUtil(const char *arr[], int n, int r, int index, const char *data[], int i, char *root)
{
    // Current combination is ready, print it
    if (index == r)
    {
        printf("%c%c\t",root[0],root[1]);
        for (int j=0; j<r; j++)
            printf("%s\t",data[j]);
        printf("\n");
        return;
    }

    // When no more elements are there to put in data[]
    if (i >= n)
        return;

    // current is included, put next at next location
    data[index] = arr[i];
    // strncpy(data[index], arr[i], 2);
    combinationUtil(arr, n, r, index+1, data, i+1, root);

    // current is excluded, replace it with next (Note that
    // i+1 is passed, but index is not changed)
    combinationUtil(arr, n, r, index, data, i+1, root);
}

const char *chromaticScaleSharps[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
const char *chromaticScaleFlats[]  = {"C", "Db", "D", "Eb", "E", "F", "Gb", "G", "Ab", "A", "Bb", "B"};
const char *formulas[] = {"b2","2","b3","3","4","b5","5","b6","6","b7","7"};
const char noteNames[] = {'C', ' ', 'D', ' ', 'E', 'F', ' ', 'G', ' ', 'A', ' ', 'B'};

int main(int argc, char *argv[]){
    char root[2];
    if ( argc < 2 ) {
        // generate 12-note formulas
        root[0] = '1';
        int i = 0;
        for (i; i < 11; i++) {
            // i = number of notes in formula
            // generate i-note formulas
            printf("%d-note formulas\n",i+1);
            printCombination(formulas, MAX_ARRAY_SIZE, i, root);
            printf("Press Enter to continue");
            getchar();
        }
        printf("12-note formula\n"
               "1\t");
        for (i = 0; i < 11; i++) {
            printf("%s\t",formulas[i]);
        }
    }
    else {
        strncpy(root, argv[1], 2);
        printf("%c\n",root[1]);
        root[0] = toupper(root[0]);
        if ( root[0] != 'A' && root[0] != 'B' && root[0] != 'C' && root[0] != 'D' &&
             root[0] != 'E' && root[0] != 'F' && root[0] != 'G' || argc > 2 ) {
            printf("Usage: formulas [note]\n"
                   "where [note] is a note name e.g. C, C#, Db, etc. (Double flats or sharps are not supported.)\n"
                   "If [note] is omitted, formulas are generated using notation a la Krantz\n"
                   "(i.e. 1, b2, 2, b3, 3, 4, b5, 5, b6, 6, b7, 7).");
            return 0;
        }
        int i = 0;
        int rootNumber;
        for (i; root[0] != noteNames[i]; i++) {
            rootNumber = i + 1;
        }
        if ( root[1] == 'b' )
            rootNumber -= 1;
        else if ( root[1] == '#' )
            rootNumber += 1;
        rootNumber %= 12;
        const char * noteValues[MAX_ARRAY_SIZE];
        for (i = 0; i < 11; i++) {
            noteValues[i] = (root[0] == 'C' || root[0] == 'F' || root[1] == 'b') ? chromaticScaleFlats[(rootNumber + i + 1) % 12] : chromaticScaleSharps[(rootNumber + i + 1) % 12];
        }
        for (i = 0; i < MAX_ARRAY_SIZE; i++) {
            printf("%d-note sets\n",i+1);
            printCombination(noteValues, MAX_ARRAY_SIZE, i, root);
            printf("Press Enter to continue");
            getchar();
        }
        printf("12-note set\n"
               "%s\t", root);
        for (i = 0; i < MAX_ARRAY_SIZE; i++) {
            printf("%s\t",noteValues[i]);
        }
    }
    return 0;
}
