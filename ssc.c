#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include "ssc.h"

#define SHUFFLES 4

static void xor(const unsigned char *a, const unsigned char *b, const size_t len, unsigned char *out) {
	for (size_t i = 0; i < len; i++)
		out[i] = a[i] ^ b[i];
}

static void shuffle(unsigned char *a, const size_t len, int nonce, size_t key_len) {
	for (size_t i = 0; i < len; i++) {
		unsigned char tmp = a[((i*87)+key_len)%len];
		a[i] += 1 + ((tmp >> 5) + a[tmp%len]) + ((nonce + tmp) >> 3) * i;
	}
}

void ssc_cipher(const unsigned char *data, const size_t len, const unsigned char *key, const size_t key_len, const int nonce, unsigned char *out) {

	unsigned char k[len];

	for (int i = 0; i < len; i++)
		k[i] = key[i % key_len];

	for (int i = 0; i < SHUFFLES; i++)
		shuffle(k, len, nonce, key_len);

	xor(data, k, len, out);
}
