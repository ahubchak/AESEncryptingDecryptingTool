cmake_minimum_required(VERSION 3.6)
project(AES_Tool)

set(CMAKE_C_STANDARD 99)

include_directories(LibTomCrypt/src/headers)


set(LIBTOMCRYPT_SOURCE
        ./LibTomCrypt/src/misc/crypt/crypt_register_cipher.c
        ./LibTomCrypt/src/misc/crypt/crypt_cipher_descriptor.c
        ./LibTomCrypt/src/misc/crypt/crypt_argchk.c
        ./LibTomCrypt/src/misc/zeromem.c
        ./LibTomCrypt/src/ciphers/aes/aes.c
        ./LibTomCrypt/src/ciphers/aes/aes_tab.c
        ./LibTomCrypt/src/misc/crypt/crypt_find_cipher.c
        ./LibTomCrypt/src/encauth/ccm/ccm_memory.c
        ./LibTomCrypt/src/misc/crypt/crypt_cipher_is_valid.c
        ./LibTomCrypt/src/misc/mem_neq.c
        )

set(LIBTOMCRYPT_INCLUDE
        ./LibTomCrypt/src/headers/
        )

set(SOURCE_FILES ${LIBTOMCRYPT_SOURCE} main.c )

add_executable(AES_Tool ${SOURCE_FILES} ${LIBTOMCRYPT_INCLUDE} )


