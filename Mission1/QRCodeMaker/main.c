#include <stdio.h>
#include <stdlib.h>
#include "lib/qrcode.h"

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <malloc.h>


#define _height 600
#define _width 600
#define _bitsperpixel 24
#define _planes 1
#define _compression 0
#define _pixelbytesize _height*_width*_bitsperpixel/8
#define _filesize _pixelbytesize+sizeof(bitmap)
#define _xpixelpermeter 0x13B //2835 , 72 DPI
#define _ypixelpermeter 0x130B //2835 , 72 DPI
#define pixel 0xff
#pragma pack(push,1)
typedef struct{
    uint8_t signature[2];
    uint32_t filesize;
    uint32_t reserved;
    uint32_t fileoffset_to_pixelarray;
} fileheader;
typedef struct{
    uint32_t dibheadersize;
    uint32_t width;
    uint32_t height;
    uint16_t planes;
    uint16_t bitsperpixel;
    uint32_t compression;
    uint32_t imagesize;
    uint32_t ypixelpermeter;
    uint32_t xpixelpermeter;
    uint32_t numcolorspallette;
    uint32_t mostimpcolor;
} bitmapinfoheader;
typedef struct {
    fileheader fileheader;
    bitmapinfoheader bitmapinfoheader;
} bitmap;
#pragma pack(pop)

int main() {

    char tmp[8192] = {'\0'};
    int levelQrC = 1;
    char* str;

    //scanf("%s", tmp);

    str = malloc(sizeof(tmp));

    levelQrC += (int)strlen(tmp) / 55;

    printf("%s", str);

    // The structure to manage the QR code
    QRCode qrcode;

// Allocate a chunk of memory to store the QR code
    uint8_t qrcodeBytes[qrcode_getBufferSize((uint8_t) (sizeof(tmp)) )];

    qrcode_initText(&qrcode, qrcodeBytes, (uint8_t )levelQrC, ECC_LOW, tmp);

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

    printf("Taille: %i\n", qrcode.size);
    printf("BONJOUR LE PEUPLE\n");

        FILE *fp = fopen("test.bmp","wb");
        bitmap *pbitmap  = (bitmap*)calloc(1,sizeof(bitmap));
        uint8_t *pixelbuffer = (uint8_t*)malloc(_pixelbytesize);
        strcpy(pbitmap->fileheader.signature,"BM");
        pbitmap->fileheader.filesize = _filesize;
        pbitmap->fileheader.fileoffset_to_pixelarray = sizeof(bitmap);
        pbitmap->bitmapinfoheader.dibheadersize =sizeof(bitmapinfoheader);
        pbitmap->bitmapinfoheader.width = _width;
        pbitmap->bitmapinfoheader.height = _height;
        pbitmap->bitmapinfoheader.planes = _planes;
        pbitmap->bitmapinfoheader.bitsperpixel = _bitsperpixel;
        pbitmap->bitmapinfoheader.compression = _compression;
        pbitmap->bitmapinfoheader.imagesize = _pixelbytesize;
        pbitmap->bitmapinfoheader.ypixelpermeter = _ypixelpermeter ;
        pbitmap->bitmapinfoheader.xpixelpermeter = _xpixelpermeter ;
        pbitmap->bitmapinfoheader.numcolorspallette = 0;
        fwrite (pbitmap, 10, sizeof(bitmap),fp);
        memset(pixelbuffer,pixel,_pixelbytesize);
        fwrite(pixelbuffer,1,_pixelbytesize,fp);
        fclose(fp);
        free(pbitmap);
        free(pixelbuffer);

        int w = 600;
        int h = 600;
        int x, y;
        int r,g,b;
        int red[600][600];
        int green[600][600];
        int blue[600][600];


    FILE *f;
    unsigned char *img = NULL;
    int filesize = 54 + 3*w*h;  //w is your image width, h is image height, both int

    img = (unsigned char *)malloc(3*w*h);
    memset(img,0,3*w*h);

    for(int i=0; i<w; i++)
    {
        for(int j=0; j<h; j++)
        {
            x=i; y=(h-1)-j;
            r = red[i][j]*255;
            g = green[i][j]*255;
            b = blue[i][j]*255;
            if (r > 255) r=255;
            if (g > 255) g=255;
            if (b > 255) b=255;
            img[(x+y*w)*3+2] = (unsigned char)(r);
            //img[(x+y*w)*3+1] = (unsigned char)(g);
            img[(x+y*w)*3+0] = (unsigned char)(b);
        }
    }

    unsigned char bmpfileheader[14] = {'B','M', 0,0,0,0, 0,0, 0,0, 54,0,0,0};
    unsigned char bmpinfoheader[40] = {40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0, 24,0};
    unsigned char bmppad[3] = {0,0,0};

    bmpfileheader[ 2] = (unsigned char)(filesize    );
    bmpfileheader[ 3] = (unsigned char)(filesize>> 8);
    bmpfileheader[ 4] = (unsigned char)(filesize>>16);
    bmpfileheader[ 5] = (unsigned char)(filesize>>24);

    bmpinfoheader[ 4] = (unsigned char)(       w    );
    bmpinfoheader[ 5] = (unsigned char)(       w>> 8);
    bmpinfoheader[ 6] = (unsigned char)(       w>>16);
    bmpinfoheader[ 7] = (unsigned char)(       w>>24);
    bmpinfoheader[ 8] = (unsigned char)(       h    );
    bmpinfoheader[ 9] = (unsigned char)(       h>> 8);
    bmpinfoheader[10] = (unsigned char)(       h>>16);
    bmpinfoheader[11] = (unsigned char)(       h>>24);

    f = fopen("img.bmp","wb");
    fwrite(bmpfileheader,1,14,f);
    fwrite(bmpinfoheader,1,40,f);
    for(int i=0; i<h; i++)
    {
        fwrite(img+(w*(h-i-1)*3),3,w,f);
        fwrite(bmppad,1,(4-(w*3)%4)%4,f);
    }

    free(img);
    fclose(f);



    return 0;
}
