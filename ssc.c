#include <stddef.h>
#include <string.h>
#include "ssc.h"

#define SHUFFLES 4

static void xor(const unsigned char *a, const unsigned char *b, const size_t len, unsigned char *out) {
	for (size_t i = 0; i < len; i++)
		out[i] = a[i] ^ b[i];
}

static void shuffle(unsigned char *a, const size_t len, int nonce) {
	for (size_t i = 0; i < len; i++) {
		a[i] = (a[i] << 3) + (i*137/len) + (a[(i*87+3)%len]*27 ^ nonce);
	}
}

void ssc_cipher(const unsigned char *data, const size_t len, const unsigned char *key, const size_t key_len, const int nonce, unsigned char *out) {

	unsigned char k[len];

	for (int i = 0; i < len; i++)
		k[i] = key[i % key_len];

	for (int i = 0; i < SHUFFLES; i++)
		shuffle(k, len, nonce);

	xor(data, k, len, out);
}
