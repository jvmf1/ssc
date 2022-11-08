# Example
```c
#include "ssc.h"

char key[] = "abc";
char data[] = "1234567890";

char enc[sizeof(data)];
char dec[sizeof(data)];

size_t nonce = 123;

ssc_cipher(data, sizeof(data)-1, key, sizeof(key)-1, nonce, enc);

printf("encrypted: %s\n", enc);

ssc_cipher(enc, sizeof(data)-1, key, sizeof(key)-1, nonce, dec);

printf("decrypted: %s\n", dec);
```

# Visualize randomness
```sh
$ make
$ ./a.out -o | ./visualize.py
```
