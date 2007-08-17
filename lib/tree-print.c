#include <stdint.h>
#include <stdio.h>
#include "tree-i.h"

static void
print_node(const struct AffTreeNode_s *node, void *arg)
{
    printf(" %16p %016llx: [%016llx %08x %16p %16p] ",
	   node, node->id, node->key.pId, node->key.nId,
	   node->children, node->next);
    switch (node->type) {
    case affNodeInvalid:
	printf("unvalid node\n");
	break;
    case affNodeVoid:
	printf("void\n");
	break;
    case affNodeChar:
	printf("char[%d] %016lld\n", node->size, node->offset);
	break;
    case affNodeInt:
	printf("int[%d] %016lld\n", node->size, node->offset);
	break;
    case affNodeDouble:
	printf("double[%d] %016lld\n", node->size, node->offset);
	break;
    case affNodeComplex:
	printf("complex[%d] %016lld\n", node->size, node->offset);
	break;
    default:
	printf("unknown type %d\n", node->type);
	break;
    }
}

void
aff_tt_print(const struct AffTree_s *tt)
{
    if (tt == 0) {
	printf("NULL Tree table\n");
	return;
    }
    printf("Tree table at %p, size=%lld, file-size=%lld:\n",
	   tt, tt->size, tt->file_size);
    aff_tt_foreach(tt, print_node, 0);
    printf("Tree table end\n");
}
