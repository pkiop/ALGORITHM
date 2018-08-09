#include <stdio.h>
#include <string.h>

int main(void) {
	int n, m;
	int i, j;
	int arr[101];
	int a, b;
	int cnt = 0;
	int ansarr[101];

	memset(arr, -1, sizeof(arr));
	memset(ansarr, -1, sizeof(ansarr));
	scanf("%d%d", &n, &m);

	for (i = 0; i < n; ++i) {
		scanf("%d%d", &a, &b);
		for (j = a; j <= b; ++j) {
			arr[j] = 1;
		}
	}

	for (i = 1; i <= m; ++i) {
		if (arr[i] == -1) {
			ansarr[cnt++] = i;
		}
	}

	printf("%d\n", cnt);
	for (i = 0; i < cnt; ++i) {
		printf("%d ", ansarr[i]);
	}
	return 0;
}