#include <cstdio>
#include <cmath>

int main() {
	int x, y, w, h;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	int xMargin = w - x > x ? x : w - x;
	int yMargin = h - y > y ? y : h - y;
	printf("%d\n", xMargin > yMargin ? yMargin : xMargin);
}