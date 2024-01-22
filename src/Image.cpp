#include "Kedarium/Image.hpp"

bool kdr::Image::loadFromPng(const std::string& path, GLubyte** data, int& imgWidth, int& imgHeight, bool& hasAlpha)
{
  FILE* file = fopen(path.c_str(), "rb");
  unsigned int sigRead {0};

  if (file == NULL)
  {
    std::cerr << "Failed to open file (" << path << ")!\n";
    return false;
  }

  png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
  if (png == NULL) {
    std::cerr << "Error creating PNG read structure!\n";
    fclose(file);
    return false;
  }
  png_infop info = png_create_info_struct(png);
  if (info == NULL) {
    std::cerr << "Error creating PNG info structure!\n";
    fclose(file);
    return false;
  }

  if (setjmp(png_jmpbuf(png)))
  {
    png_destroy_read_struct(&png, &info, NULL);
    fclose(file);
    return false;
  }

  png_init_io(png, file);
  png_set_sig_bytes(png, sigRead);
  png_read_png(
    png,
    info,
    PNG_TRANSFORM_STRIP_16 | PNG_TRANSFORM_PACKING | PNG_TRANSFORM_EXPAND,
    NULL
  );

  png_uint_32 width;
  png_uint_32 height;
  int colorType;
  png_get_IHDR(png, info, &width, &height, NULL, &colorType, NULL, NULL, NULL);

  imgWidth = width;
  imgHeight = height;
  hasAlpha = (colorType & PNG_COLOR_MASK_ALPHA);

  unsigned int rowBytes = png_get_rowbytes(png, info);
  *data = reinterpret_cast<unsigned char*>(malloc(rowBytes * imgHeight));
  png_bytepp rowPointers = png_get_rows(png, info);

  for (int i = 0; i < imgHeight; i++)
  {
    memcpy(*data + (rowBytes * (imgHeight - 1 - i)), rowPointers[i], rowBytes);
  }

  png_destroy_read_struct(&png, &info, NULL);
  fclose(file);

  return true;
}
