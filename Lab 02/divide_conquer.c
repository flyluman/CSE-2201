#include <stdio.h>
#include <stdlib.h>

int *data, comp;

struct mix{
	int min, max;
};

struct mix min_max(int l, int r)
{
	struct mix ret, left, right;

	if (l == r)
	{
		ret.min = ret.max = data[l];
		return ret;
	}

	else if(l == r - 1)
	{
		comp += 1; // if() chcksum
		if(data[l] > data[r]) ret.max = data[l], ret.min = data[r];
		else ret.max = data[r], ret.min = data[l];
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

	if (!in)
    {
        printf("Error finding input.txt\n");
        return 0;
    }

	int n = 0, x;
	while (fscanf(in, "%d", &x) != EOF) n += 1;

	if(!n)
	{
		printf("No value found in input.txt\n");
		return 0;
	}

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
