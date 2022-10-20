#include <stddef.h>
#include <string.h>
#include "ssc.h"

#define SHUFFLES 4

static int sum(unsigned char *data, size_t len) {
	int r = 0;
	for (size_t i = 0; i < len; i++)
		r+=data[i];
	return r;
}

static void xor(const unsigned char *a, const unsigned char *b, const size_t len, unsigned char *out) {
	for (size_t i = 0; i < len; i++)
		out[i] = a[i] ^ b[i];
}

static void shuffle(const unsigned char *a, const size_t len, int random, unsigned char *out) {
	for (size_t i = 0; i < len; i++) {
		out[i] = (a[i] << 3) + (i*137/len) + (a[(i*87+3)%len]*27 ^ random);
	}
}

void ssc_cipher(const unsigned char *data, const size_t len, const unsigned char *key, const size_t key_len, const int nonce, unsigned char *out) {

	unsigned char keys[2][len];

	unsigned char *k1 = &keys[0][0];
	unsigned char *k2 = &keys[1][0];

	unsigned char tmp[len];

	memcpy(tmp, data, len);

	for (int i = 0; i < len; i++) {
		keys[0][i] = key[i % key_len];
		keys[1][i] = key[i % key_len];
	}

	for (int i = 0; i < SHUFFLES; i++) {
		shuffle(k1, len, sum(k1, len)^nonce, k2);
		k1 = k2;
	}

	xor(data, k2, len, out);
}
