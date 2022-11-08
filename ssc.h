#pragma once
#include <stddef.h>

void ssc_cipher(const unsigned char *data, const size_t len, const unsigned char *key, const size_t key_len, size_t nonce, unsigned char *out);
