#include <stdio.h>
#include <stdlib.h>

int *data, comp;

struct mix{
	int min, max;
};

struct mix min_max(int l, int r)
{
	struct mix ret, left, right;
	
	comp += 1; // if() checksum

	if (l == r)
	{
		ret.min = ret.max = data[l];
		return ret;
	}

	left = min_max(l, (l + r) / 2);
	right = min_max((l + r) / 2 + 1, r);

	comp += 2; // 2 ternary conditional checksum

	ret.min = left.min < right.min ? left.min : right.min;
	ret.max = left.max > right.max ? left.max : right.max;

	return ret;
}

int main()
{
	FILE *in = fopen("input.txt", "r");

	int n = 0, x;
	while (fscanf(in, "%d", &x) != EOF) n += 1;

	data = (int *)malloc(sizeof(int) * n);
	fseek(in, 0, SEEK_SET);

	for (int i = 0; i < n; i++) fscanf(in, "%d", &data[i]);

	struct mix rlt = min_max(0, n - 1);

	printf("Min = %d, Max = %d\n\n", rlt.min, rlt.max);
	printf("Number of comparisons : %d\n", comp);

	free(data);
	fclose(in);
	return 0;
}
