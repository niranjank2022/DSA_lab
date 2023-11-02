#include <stdio.h>
#include "vector.h"

void main() {

	Vector vec = init();
	vprint(&vec);

	for (int i = 0; i < 10; i++)
		vappend(&vec, i * 2);

	vprint(&vec);

	vinsert(&vec, 5, 100);
	vinsert(&vec, 9, 1000);
	vprint(&vec);

	vpop(&vec);
	vremove(&vec, 2);
	vprint(&vec);
}
