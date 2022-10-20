#include <stdio.h>
#include <string.h>
#include "ssc.h"
#include <time.h>
#include <assert.h>

void print_data(const unsigned char *a, size_t len) {
	printf("0x");
	for (size_t i = 0; i < len; i++) {
		printf("%02x", a[i]);
	}
	printf("\n");
}

size_t arrcmp(const unsigned char *a, const unsigned char *b, size_t len) {
	for (size_t i = 0; i < len; i++) {
		if (a[i] - b[i] != 0)
			return a[i] - b[i];
	}
	return 0;
}

int main(int argc, char **argv) {

	unsigned char key[] = {'a'};

	unsigned char text[5*5];

	memset(text, 0xAA, sizeof(text));

	unsigned char encrypted[sizeof(text)];
	unsigned char decrypted[sizeof(text)];

	int nonce = time(NULL);

	ssc_cipher(text, sizeof(text), key, sizeof(key), nonce, encrypted);

	ssc_cipher(encrypted, sizeof(text), key, sizeof(key), nonce, decrypted);

	assert(arrcmp(text, decrypted, sizeof(text)) == 0);

	if (argc > 1 && strcmp(argv[1], "-o") == 0)
		fwrite(encrypted, sizeof(text), 1, stdout);
	else {
		printf("text:\t\t");
		print_data(text, sizeof(text));
		printf("encrypted:\t");
		print_data(encrypted, sizeof(text));
		printf("decrypted:\t");
		print_data(decrypted, sizeof(text));
	}


}
