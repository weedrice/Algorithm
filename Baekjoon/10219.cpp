#include <cstdio>

char** matrix;
int h, w;

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		scanf("%d %d", &h, &w);
		matrix = new char*[h];
		for (int i = 0; i < h; i++) {
			getchar();
			matrix[i] = new char[w];
			for (int j = 0; j < w; j++) {
				scanf("%c", &matrix[i][j]);
			}
			for (int j = w - 1; j >= 0; j--) {
				printf("%c", matrix[i][j]);
			}
			printf("\n");
		}
	}
}