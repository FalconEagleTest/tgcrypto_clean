// tgcrypto.h
#ifndef TGCRYPTO_H
#define TGCRYPTO_H

#include <stdint.h>

#ifdef _WIN32
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __attribute__((visibility("default")))
#endif

#ifdef __cplusplus
extern "C" {
#endif

EXPORT uint8_t* ige256_encrypt(const uint8_t* data, uint32_t length, const uint8_t* key, const uint8_t* iv);
EXPORT uint8_t* ige256_decrypt(const uint8_t* data, uint32_t length, const uint8_t* key, const uint8_t* iv);
EXPORT uint8_t* ctr256_encrypt(const uint8_t* data, uint32_t length, const uint8_t* key, const uint8_t* iv, const uint8_t* state);
EXPORT uint8_t* ctr256_decrypt(const uint8_t* data, uint32_t length, const uint8_t* key, const uint8_t* iv, const uint8_t* state);
EXPORT uint8_t* cbc256_encrypt(const uint8_t* data, uint32_t length, const uint8_t* key, const uint8_t* iv);
EXPORT uint8_t* cbc256_decrypt(const uint8_t* data, uint32_t length, const uint8_t* key, const uint8_t* iv);

#ifdef __cplusplus
}
#endif

#endif // TGCRYPTO_H