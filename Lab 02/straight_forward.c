#include <stdio.h>

int main()
{
	FILE *in = fopen("input.txt", "r");

	int x, comp = 0, min, max;

	fscanf(in, "%d", &x);
	min = max = x;

	while(fscanf(in, "%d", &x) != EOF)
	{
		comp += 2;
		if (x > max) max = x, comp -= 1;
		else if (x < min) min = x;
	}

	printf("Min = %d, Max = %d\n\n", min, max);
	printf("Number of comparisons : %d\n", comp);

	fclose(in);
	return 0;
}
