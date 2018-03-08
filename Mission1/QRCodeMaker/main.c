//
// Created by zero on 26/02/18.
//

#include "lib/qrcode.h"

#include <stdio.h>

void main(int argc, char** argv){

    // The structure to manage the QR code
    QRCode qrcode;

    // Allocate a chunk of memory to store the QR code
    uint8_t qrcodeBytes[qrcode_getBufferSize()];

    qrcode_initText(&qrcode, qrcodeBytes, 3, ECC_LOW, "HELLO WORLD");

    for (uint8_t y = 0; y < qrcode.size; y++) {
        for (uint8_t x = 0; x < qrcode.size; x++) {
            if (qrcode_getModule(&qrcode, x, y){
                printf("**");
            } else {
                printf("  ");

            }
        }
        printf("\n");
    }
}