#include <stdio.h>
#include <stdlib.h>
#include "lib/qrcode.h"

int main() {

    // The structure to manage the QR code
    QRCode qrcode;

// Allocate a chunk of memory to store the QR code
    uint8_t qrcodeBytes[qrcode_getBufferSize((uint8_t)5000)];

    qrcode_initText(&qrcode, qrcodeBytes, 3, ECC_LOW, "BONJOUR LE PEUPLE");

    for (uint8_t y = 0; y < qrcode.size; y++) {
        for (uint8_t x = 0; x < qrcode.size; x++) {
            if (qrcode_getModule(&qrcode, x, y)) {
                printf("##");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    printf("BONJOUR LE PEUPLE\n");
    return 0;
}