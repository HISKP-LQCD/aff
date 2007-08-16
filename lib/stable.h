#ifndef MARK_0c0bd3af_a15b_47a9_b1be_747bb78298b6
#define MARK_0c0bd3af_a15b_47a9_b1be_747bb78298b6
/*
 * String tables.
 *  insert() makes a copy of the name.
 *  lookup() returns zero index if the name is not found.
 *  index() returns NULL if index is out of range.
 *  size() returns the largest valid index in the table.
 *  file_size() returns the number of bytes it takes to store the table.
 *  for_each() goes through indices in order and is exposed for uniformity.
 */
struct AffSTable_s;

struct AffSTable_s *aff_st_init(void);
void *aff_st_fini(struct AffSTable_s *st);
uint32_t aff_st_lookup(const struct AffSTable_s *st, const char *name);
const char *aff_st_index(const struct AffSTable_s *st, uint32_t index);
uint32_t aff_st_insert(struct AffSTable_s *st, const char *name);
uint32_t aff_st_size(const struct AffSTable_s *st);
uint64_t aff_st_file_size(const struct AffSTable_s *st);
void aff_st_foreach(const struct AffSTable_s *st,
                    void (*proc)(const char *name, uint32_t index, void *arg),
                    void *arg);
void aff_st_print(struct AffSTable_s *st);

#endif /* !defined(MARK_0c0bd3af_a15b_47a9_b1be_747bb78298b6) */