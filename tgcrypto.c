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

// Helper function to allocate and copy memory
static uint8_t* copy_and_return(const uint8_t* data, uint32_t length) {
    uint8_t* result = (uint8_t*)malloc(length);
    if (!result) return NULL;
    memcpy(result, data, length);
    return result;
}

EXPORT uint8_t* ige256_encrypt(const uint8_t* data, int length, const uint8_t* key, const uint8_t* iv) {
    fprintf(stderr, "C: ige256_encrypt called with length=%d\n", length);
    
    if (!data || !key || !iv || length <= 0 || length % 16 != 0) {
        fprintf(stderr, "C: ige256_encrypt validation failed\n");
        return NULL;
    }

    uint8_t* result = ige256(data, length, key, iv, 1);
    if (!result) {
        fprintf(stderr, "C: ige256_encrypt internal call failed\n");
        return NULL;
    }

    uint8_t* output = copy_and_return(result, length);
    free(result);
    
    fprintf(stderr, "C: ige256_encrypt completed\n");
    return output;
}

EXPORT uint8_t* ige256_decrypt(const uint8_t* data, int length, const uint8_t* key, const uint8_t* iv) {
    fprintf(stderr, "C: ige256_decrypt called with length=%d\n", length);
    
    if (!data || !key || !iv || length <= 0 || length % 16 != 0) {
        fprintf(stderr, "C: ige256_decrypt validation failed\n");
        return NULL;
    }

    uint8_t* result = ige256(data, length, key, iv, 0);
    if (!result) {
        fprintf(stderr, "C: ige256_decrypt internal call failed\n");
        return NULL;
    }

    uint8_t* output = copy_and_return(result, length);
    free(result);
    
    fprintf(stderr, "C: ige256_decrypt completed\n");
    return output;
}

EXPORT uint8_t* ctr256_encrypt(const uint8_t* data, int length, const uint8_t* key, uint8_t* iv, uint8_t* state) {
    fprintf(stderr, "C: ctr256_encrypt called with length=%d\n", length);
    
    if (!data || !key || !iv || !state || length <= 0) {
        fprintf(stderr, "C: ctr256_encrypt validation failed\n");
        return NULL;
    }

    uint8_t* result = ctr256(data, length, key, iv, state);
    if (!result) {
        fprintf(stderr, "C: ctr256_encrypt internal call failed\n");
        return NULL;
    }

    uint8_t* output = copy_and_return(result, length);
    free(result);
    
    fprintf(stderr, "C: ctr256_encrypt completed\n");
    return output;
}

EXPORT uint8_t* ctr256_decrypt(const uint8_t* data, int length, const uint8_t* key, uint8_t* iv, uint8_t* state) {
    fprintf(stderr, "C: ctr256_decrypt called with length=%d\n", length);
    return ctr256_encrypt(data, length, key, iv, state);
}
