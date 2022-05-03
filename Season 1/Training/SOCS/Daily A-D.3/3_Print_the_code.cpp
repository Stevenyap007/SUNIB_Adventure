#include <stdio.h>
#include <stdlib.h>

int main () {

char S[100];

scanf("%[^\n]", S);

printf("#include <stdio.h>\n");
printf("int main()\n");
printf("{\n");
printf("    printf(\"%s\\n\",\"%s\");\n", "%s", S);
printf("    return 0;\n");
printf("}\n");







    return 0;
}