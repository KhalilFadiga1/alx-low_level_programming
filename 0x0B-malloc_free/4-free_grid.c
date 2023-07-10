#include <stdlib.h>
#include "main.h"

/**
 * free_grid - function that frees a 2-dimensional grid previously
 * created by alloc_grid function
 * @grid: The grid created
 * @height: height
 */
void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}
