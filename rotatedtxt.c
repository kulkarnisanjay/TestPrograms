#include<stdio.h>
void rotatedtxt (char *ostr, char *sstr) {
	char *concat, *constart, *ssstart;
	int i;
	if (strlen(ostr)!=strlen(sstr))
		return;
	concat = (char *)malloc(sizeof(strlen(sstr)*2-1));
	constart = concat;
	ssstart = sstr;
	for(i=0;i<2;i++) {
		while(*ssstart) {
			*constart++ = *ssstart++;
		}
		ssstart = sstr;
	}
	*constart = '\0';
	printf("%s\n",concat);
	while (*concat) {
		if (!*ostr) {
			printf("found\n");
			break;
		}
		if (*concat==*ostr) {
			concat++;
			ostr++;
		}else {
			concat++;
		} 
	}
}
int main() {
	char ostr[8] = "sanjay";
	char sstr[8] = "njaysa";
	rotatedtxt(ostr,sstr);
	return 0;
}
