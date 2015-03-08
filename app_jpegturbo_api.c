#include <turbojpeg.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_SIZE 24*1014*1024

int main(int argc, char **argv)
{
    long unsigned int jpegSize; //!< _jpegSize from above
    int jpegSubsamp, width, height;

    unsigned char *bufferCom = (unsigned char *)malloc(MAX_FILE_SIZE);

	FILE *f = fopen(argv[1], "rb");
	if (f) {
		 jpegSize = fread(bufferCom, MAX_FILE_SIZE, 1, f);
	} else {
		perror("Error reading jpeg file");
		return EXIT_FAILURE;
	}

    tjhandle handler = tjInitDecompress();
    tjDecompressHeader2(handler, bufferCom, jpegSize, &width, &height, &jpegSubsamp);

    unsigned char *buffer = (unsigned char *)malloc(width*height*3);

    tjDecompress2(handler, bufferCom, jpegSize, buffer, width, 0/*pitch*/, height, TJPF_RGB, TJFLAG_FASTDCT);

    tjDestroy(handler);

	free(buffer);
	free(bufferCom);
	return EXIT_SUCCESS;
}
