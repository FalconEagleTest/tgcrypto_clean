// tgcrypto.c
#include <stdint.h>
#include <stdlib.h>
#include "aes256.h"
#include "ige256.h"
#include "ctr256.h"
#include "cbc256.h"

#ifdef _WIN32
    #define EXPORT __declspec(dllexport)
#else
    #define EXPORT __attribute__((visibility("default")))
#endif

EXPORT uint8_t* ige256_encrypt(const uint8_t* data, uint32_t length, const uint8_t* key, const uint8_t* iv) {
    if (length == 0 || length % 16 != 0) {
        return NULL;
    }
    return ige256(data, length, key, iv, 1);
}

EXPORT uint8_t* ige256_decrypt(const uint8_t* data, uint32_t length, const uint8_t* key, const uint8_t* iv) {
    if (length == 0 || length % 16 != 0) {
        return NULL;
    }
    return ige256(data, length, key, iv, 0);
}

EXPORT uint8_t* ctr256_encrypt(const uint8_t* data, uint32_t length, const uint8_t* key, uint8_t* iv, uint8_t* state) {
    if (length == 0) {
        return NULL;
    }
    return ctr256(data, length, key, iv, state);
}

EXPORT uint8_t* ctr256_decrypt(const uint8_t* data, uint32_t length, const uint8_t* key, uint8_t* iv, uint8_t* state) {
    return ctr256_encrypt(data, length, key, iv, state);
}

EXPORT uint8_t* cbc256_encrypt(const uint8_t* data, uint32_t length, const uint8_t* key, uint8_t* iv) {
    if (length == 0 || length % 16 != 0) {
        return NULL;
    }
    return cbc256(data, length, key, iv, 1);
}

EXPORT uint8_t* cbc256_decrypt(const uint8_t* data, uint32_t length, const uint8_t* key, uint8_t* iv) {
    if (length == 0 || length % 16 != 0) {
        return NULL;
    }
    return cbc256(data, length, key, iv, 0);
}
