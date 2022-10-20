#pragma once

void ssc_cipher(const unsigned char *data, const size_t len, const unsigned char *key, const size_t key_len, const int nonce, unsigned char *out);
