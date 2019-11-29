#include <iostream>

using namespace std;
void addFinder(int **matrix, int cornerx, int cornery);
void setInfoAreas(int **matrix, int dimval);
int main()
{
    int version = 2;
    int dim = (((version-1)*4)+21);
	int **matrix;
	matrix = new int*[dim];
	for(int i = 0; i < dim; i++)
		matrix[i] = new int[dim];
	//Set finder patterns
	addFinder(matrix, 0, 0);
	addFinder(matrix, (((version-1)*4)+21) - 7, 0);
	addFinder(matrix, 0, (((version-1)*4)+21) - 7);
	if (version = 2)
	{
		for(int i= 0; i < 5; i++)
		{
			matrix[16 + i][16] = 1;
			matrix[16][16 + i] = 1;
			matrix[20][16 + i] = 1;
			matrix[16 + i][20] = 1;
		}
	}
	//Add timing patterns
	int timePat = dim - 7;
	for(int i = 8; i < dim - 7; i = i+2)
	{
	    matrix[i][6] = 1;
	    matrix[6][i] = 1;
	}
	//Add dark module
	int darkx = (4 * version) + 9;
	matrix[darkx][8] = 1;
	//Reserve format info with value 2 (format)
	setInfoAreas(matrix, dim - 1);



	
	for(int i= 0; i < dim; i++)
	{
	    for(int j= 0; j < dim; j++)
	    {
	        cout << matrix[i][j];
	    }
	    cout << "\n";
	}
	return 0;
}
void addFinder(int **matrix, int cornerx, int cornery)
{
	//map[cornerx][cornery] = 1;
	for(int i=0; i < 7; i++)
	{
		matrix[cornerx + i][cornery] = 1;
		matrix[cornerx][cornery + i] = 1;
		matrix[cornerx + 6][cornery + i] = 1;
		matrix[cornerx + i][cornery + 6] = 1;
	}
	for(int j=2; j < 5; j++)
	{
		for(int k=2; k < 5; k++)
		{
			matrix[cornerx + j][cornery + k] = 1;
		}
	}
}
void setInfoAreas(int **matrix, int dimval)
{
    for(int i = 0; i < 7; i++)
	{
	   matrix[dimval - i][8] = 2;
	}
	for(int k = 0; k < 8; k++)
	{
	   matrix[8][dimval - k] = 2;
	}
	for(int i = 0; i < 6; i++)
	    {
	        matrix[i][8] = 2;
	        matrix[8][i] = 2;
	    }
	for(int j = 7; j < 9; j++)
	{
	    matrix[j][8] = 2;
	    matrix[8][j] = 2;
	}
}
