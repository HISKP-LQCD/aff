#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdarg.h>
#include "node.h"
#include "md5.h"
#include "coding.h"
#include "aff-i.h"

int
aff_node_put_int(struct AffWriter_s *aff,
		 struct AffNode_s *n,
		 const uint32_t *d,
		 uint32_t s)
{
    uint32_t i;
    uint8_t buf[4];

    if (aff == 0 || n == 0 || d == 0 || aff->error != 0)
	return 1;
    if (aff_node_type(n) != affNodeVoid) {
	aff->error = "Changing the type of the node";
	return 1;
    }
    aff_node_assign(n, affNodeInt, s, aff->position);
    for (i = 0; i < s; i++) {
	if (aff_encode_u32(buf, sizeof(buf), d[i]) == 0) {
	    aff->error = "uint32_t encoder failed";
	    return 1;
	}
	if (fwrite(buf, sizeof (buf), 1, aff->file) != 1) {
	    aff->error = strerror(errno);
	    return 1;
	}
	aff_md5_update(&aff->data_hdr.md5, (const uint8_t *)buf, 4);
	aff->data_hdr.size += sizeof (uint32_t);
	aff->position += sizeof (uint32_t);
    }
    return 0;
}