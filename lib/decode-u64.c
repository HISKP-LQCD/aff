#include <stdint.h>
#include <stdarg.h>
#include "node.h"
#include "coding.h"

uint8_t *
aff_decode_u64(uint64_t *data, uint8_t *buf, uint32_t size)
{
    int i;
    uint64_t v;

    if (buf == 0 || size < 8)
	return 0;

    for (i = 0, v = 0; i < 8; i++) {
	v = (v << 8) | buf[i];
    }
    *data = v;
    return buf + 8;
}
