#include <stdio.h>
#include "vector.h"

void main() {

	Vector list = init();
	vprint(&list);

	vappend(&list, 67);
	vappend(&list, 45);
	vinsert(&list, 1, 100);

	vprint(&list);

	for (int i = 0; i < 10; i++)
		vappend(&list, i * i * i);

	vprint(&list);

	vpop(&list);
	vremove(&list, 3);
	vremove(&list, 4);

	vprint(&list);
}
