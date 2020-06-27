#include<stdio.h>
#include<string.h>

char* backspace_compare(char *S, char* T) {
	int i=strlen(S)-1, j=strlen(T)-1;
	int skipS=0, skipT=0;

	while (i >= 0 || j >= 0) {
		while (i >= 0) {
			if (S[i] == '#') {skipS++; i--;}
			else if (skipS > 0) {skipS--; i--;}
			else break;
		}
		while (j >= 0) {
			if (T[j] == '#') {skipT++; j--;}
			else if (skipT > 0) {skipT--; j--;}
			else break;
		}
		if (i >= 0 && j >= 0 && S[i] != T[j])
			return "false";
		if ((i >= 0) != (j >= 0))
			return "false";
		i--; j--;
	}
	return "true";
}

int main() {
	char S[1000000], T[1000000];
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%s", S);
		scanf("%s", T);
		printf("%s\n", backspace_compare(S, T));
	}
}