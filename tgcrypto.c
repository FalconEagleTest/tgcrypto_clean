// tgcrypto.c
#include <stdio.h>
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
    fprintf(stderr, "C: ige256_encrypt called with length=%u\n", length);
    
    if (!data || !key || !iv) {
        fprintf(stderr, "C: ige256_encrypt null pointer check failed\n");
        return NULL;
    }

    if (length == 0 || length % 16 != 0) {
        fprintf(stderr, "C: ige256_encrypt invalid length\n");
        return NULL;
    }

    uint8_t* result = ige256(data, length, key, iv, 1);
    fprintf(stderr, "C: ige256_encrypt completed\n");
    return result;
}

EXPORT uint8_t* ige256_decrypt(const uint8_t* data, uint32_t length, const uint8_t* key, const uint8_t* iv) {
    fprintf(stderr, "C: ige256_decrypt called with length=%u\n", length);
    
    if (!data || !key || !iv) {
        fprintf(stderr, "C: ige256_decrypt null pointer check failed\n");
        return NULL;
    }

    if (length == 0 || length % 16 != 0) {
        fprintf(stderr, "C: ige256_decrypt invalid length\n");
        return NULL;
    }

    uint8_t* result = ige256(data, length, key, iv, 0);
    fprintf(stderr, "C: ige256_decrypt completed\n");
    return result;
}

EXPORT uint8_t* ctr256_encrypt(const uint8_t* data, uint32_t length, const uint8_t* key, uint8_t* iv, uint8_t* state) {
    fprintf(stderr, "C: ctr256_encrypt called with length=%u\n", length);
    
    if (!data || !key || !iv || !state) {
        fprintf(stderr, "C: ctr256_encrypt null pointer check failed\n");
        return NULL;
    }

    if (length == 0) {
        fprintf(stderr, "C: ctr256_encrypt invalid length\n");
        return NULL;
    }

    uint8_t* result = ctr256(data, length, key, iv, state);
    fprintf(stderr, "C: ctr256_encrypt completed\n");
    return result;
}

EXPORT uint8_t* ctr256_decrypt(const uint8_t* data, uint32_t length, const uint8_t* key, uint8_t* iv, uint8_t* state) {
    fprintf(stderr, "C: ctr256_decrypt called with length=%u\n", length);
    return ctr256_encrypt(data, length, key, iv, state);
}

EXPORT uint8_t* cbc256_encrypt(const uint8_t* data, uint32_t length, const uint8_t* key, uint8_t* iv) {
    fprintf(stderr, "C: cbc256_encrypt called with length=%u\n", length);
    
    if (!data || !key || !iv) {
        fprintf(stderr, "C: cbc256_encrypt null pointer check failed\n");
        return NULL;
    }

    if (length == 0 || length % 16 != 0) {
        fprintf(stderr, "C: cbc256_encrypt invalid length\n");
        return NULL;
    }

    uint8_t* result = cbc256(data, length, key, iv, 1);
    fprintf(stderr, "C: cbc256_encrypt completed\n");
    return result;
}

EXPORT uint8_t* cbc256_decrypt(const uint8_t* data, uint32_t length, const uint8_t* key, uint8_t* iv) {
    fprintf(stderr, "C: cbc256_decrypt called with length=%u\n", length);
    
    if (!data || !key || !iv) {
        fprintf(stderr, "C: cbc256_decrypt null pointer check failed\n");
        return NULL;
    }

    if (length == 0 || length % 16 != 0) {
        fprintf(stderr, "C: cbc256_decrypt invalid length\n");
        return NULL;
    }

    uint8_t* result = cbc256(data, length, key, iv, 0);
    fprintf(stderr, "C: cbc256_decrypt completed\n");
    return result;
}
