#include <stdio.h>
#include <string.h>
#include "jparser.h"


int main(void) {
	char *text = "    My text}        ";
	jparse(text, strlen(text));
  return 0;
}
