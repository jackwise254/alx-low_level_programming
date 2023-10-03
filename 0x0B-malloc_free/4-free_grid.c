#include "main.h"
#include <stdlib.h>

/**
 * free_grid - frees a 2-dimensional grid previously created.
 * @grid: double pointer to the 2D grid.
 * @height: height of the grid.
 *
 * Return: void.
 */
void free_grid(int **grid, int height)
{
	int i;

	if (grid == NULL || height <= 0)  /* validate input */
		return;

	for (i = 0; i < height; i++)
		free(grid[i]);  /* Free each row */

	free(grid);  /* Free the array of row pointers */
}
