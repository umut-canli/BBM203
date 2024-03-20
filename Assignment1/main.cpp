#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
//I initialized  global variables for functions.

int keySize;
string output = "";
string outName;
//  I created dynamic 2d arrays in this function .File is mapmatrix.txt or keymatrix.txt

int **CreateMap(int row, int col, string fileName)
{
    ifstream ifile;
    ifile.open(fileName);

    int **arr;
    arr = new int *[row];
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[col];
    }

    if (ifile.is_open())
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                ifile >> arr[i][j];
            }
        }
    }
    ifile.close();

    return arr;
}
// I deleted dynamic arrays in here.

void deleteArray(int **arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}
//I sent keymatrix and submatrix as parameters and also did a dot product between this two arrays.
//After that I calculated the point and returned it for calculations.
int Point(int **key, int **subMatrix, int size)
{
    int point = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {

            point += key[i][j] * subMatrix[i][j];
        }
    }
    return point;
}
//With this function,I created submatrix from mapmatrix.
void findSubM(int **subMatrix, int **map, int size, int row, int col)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            subMatrix[i][j] = map[row + i][col + j];
        }
    }
}
//I printed the output in this function . I also saved the output to the string before and sent it as a parameter.

void print(string output, string name)
{
    ofstream ofile;
    ofile.open(name);
    ofile << output;
    ofile.close();
}
/*This is my important function .I called the all functions  in here and also it is recursive function.
Firstly I called the findSubM function to find submatrix.After that I sent the subMatrix as a parameter of Point function
As I said before Point function returns the dot product between subMatrix and mapmatrix.
The important point is I did the calculations here starting from (0,0) not mid point of submatrix so I need to find
 midpoints of current position  to write  outputs .
*/

void findtreasure(int **map, int **key, int size, int **subMatrix, int row, int col, int maxRow, int maxCol)
{
    findSubM(subMatrix, map, size, row, col);
    int point = Point(key, subMatrix, keySize);
    int C = point % 5;
    int midRow = (size - 1) / 2 + row;
    int midCol = (size - 1) / 2 + col;
    // I wrote the midRow ,midCol and point to output .After finding the treasure i sent output to Print function.
    output += to_string(midRow) + "," + to_string(midCol) + ":" + to_string(point) + "\n";
    // if C<0 I added 5 until C is a positive number
    while (C < 0)
    {
        C += 5;
    }
    // If C=0 game is over else I called findtreasure function recursively.
    if (C == 0)
    {
        print(output, outName);
    }
    else if (C == 1)
    {
        if (row - size < 0)
        {
            findtreasure(map, key, size, subMatrix, row + size, col, maxRow, maxCol);
        }
        else
        {
            findtreasure(map, key, size, subMatrix, row - size, col, maxRow, maxCol);
        }
    }
    else if (C == 2)
    {
        if (row + size > maxRow-1)
        {
            findtreasure(map, key, size, subMatrix, row - size, col, maxRow, maxCol);
        }
        else
        {
            findtreasure(map, key, size, subMatrix, row + size, col, maxRow, maxCol);
        }
    }
    else if (C == 3)
    {
        if (col + size > maxCol-1)
        {
            findtreasure(map, key, size, subMatrix, row, col - size, maxRow, maxCol);
        }
        else
        {
            findtreasure(map, key, size, subMatrix, row, col + size, maxRow, maxCol);
        }
    }
    else if (C == 4)
    {
        if (col - size < 0)
        {
            findtreasure(map, key, size, subMatrix, row, col + size, maxRow, maxCol);
        }
        else
        {
            findtreasure(map, key, size, subMatrix, row, col - size, maxRow, maxCol);
        }
    }
}

int main(int argc, char *argv[])
{
    keySize = stoi(argv[2]);
    outName = argv[5];

    int *mapSizes = new int[2];
    stringstream sStream(argv[1]);
    /*I had to split the first argument (18x18  to 18  18) so I created mapSizes array.mapSizes[0]=row size mapSizes[1]=col size
    And also i splitted the first argument below.
     */
    int j = 0;
    while (j < 2)
    {
        string str;
        getline(sStream, str, 'x');
        mapSizes[j] = stoi(str);
        j++;
    }
//I created subMatrix in here.

    int **subMatrix = new int *[keySize];
    for (int i = 0; i < keySize; i++)
    {
        subMatrix[i] = new int[keySize];
    }
// I created map and key 2d dynamic matrix .

    int **map = CreateMap(mapSizes[0], mapSizes[1], argv[3]);
    int **key = CreateMap(keySize, keySize, argv[4]);
    findtreasure(map, key, keySize, subMatrix, 0, 0, mapSizes[0], mapSizes[1]);
    // I deleted the arrays to clear memory.

    deleteArray(map, mapSizes[0]);
    deleteArray(key, keySize);
    deleteArray(subMatrix, keySize);
    delete[] mapSizes;

    return 0;
}
