#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>

using namespace std;

int main() {
	int cases;
	scanf("%d", &cases);

	char *a, *b;
	while (cases-- > 0) {
		int n, m, k;
		scanf("%d %d %d", &n, &m, &k);

		scanf("%s", a);
		scanf("%s", b);
	
		// sort a and b first
		sort(a, a+n);
		sort(b, b+m);

		char *c = (char *) malloc(sizeof(char)*(n+m));
		
	    int i=0, j=0; // pointers to pos in arrays	
		int k1=0, k2=0; // have to ensure these < k
		while (i < n && j < m) {
			if ((a[i] < b[j] && k1 < k) || k2 >= k) {
				c[i+j] = a[i];
				i++;
				k1++;
				k2 = 0;
			} else if ((b[j] < a[i] && k2 < k) || k1 >= k) {
				c[i+j] = b[j];
				j++;
				k2++;
				k1 = 0;
			}
		}
		c[i+j] = '\0';

		printf("c: %s", c);
		free(c);
	}
	return 0;
}
