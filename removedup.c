#include<stdio.h>
void removedup(char *str) {
	int mark = 0, i, j, len = strlen(str);
	for (i = 0;i < len; i++) {
		if (str[i] == 'M')
			continue;
		for (j=i+1;j<len;j++) {
			if (str[j] == 'M')
				continue;
			if (str[i] == str[j])
				str[j] = 'M';
		}
	}
	printf("After Marking :%s\n",str);
	for (i=0; i<len; i++) {
		if (str[i]!='M') {
			if (mark) {
				str[mark] = str[i];
				mark++;
			} else {
				continue;
			}
		} else if(!mark) {
			mark = i;
		}
	}
	printf("After Marking :%s\n",str);
}
int main()
{
  char str[9] = "santash";
  removedup(str);
}
