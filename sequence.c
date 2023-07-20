
#include <assert.h>
#include <stdio.h>
#include "sequence.h"
#include "cs136-trace.h"

// The maximum number of values that can be stored in a sequence.
static const int SEQUENCE_MAX_LENGTH = 100;

struct sequence seq_init(void) {
   struct sequence new;
   new.length = 0;
   for(int i = 0; i < SEQUENCE_MAX_LENGTH; ++i) {
       new.data[i] = '\0';
   }
   return new;
}

// See sequence.h for documentation.
int sequence_length(const struct sequence *seq){
	assert(seq);
	return seq->length; 
}

// See sequence.h for documentation.
char sequence_item_at(const struct sequence *seq, int pos){
	assert(0 <= pos);
	assert(pos < SEQUENCE_MAX_LENGTH);
	return seq->data[pos];
}

// See sequence.h for documentation.
bool sequence_insert_at(struct sequence *seq, int pos, char value){
	if (seq->length == SEQUENCE_MAX_LENGTH) {
		return false;
	}else{
		for (int i = seq->length; i > pos; --i) {
		seq->data[i] = seq->data[i - 1];
		}
		seq->data[pos] = value;
		seq->length ++;
		return 1;
	}
}

// See sequence.h for documentation.
char sequence_remove_at(struct sequence *seq, int pos){
	assert(seq);
	assert(0 <= pos);
	assert(pos < SEQUENCE_MAX_LENGTH);

	char removed = seq->data[pos];

	for (int i = pos; i < seq->length - 1; ++i) {
		seq->data[i] = seq->data[i + 1];
	}
	seq->length -= 1;
	return removed;
}

// See sequence.h for documentation.
void sequence_print(const struct sequence *seq){
	assert(seq);
	if (seq->length == 0) {
		printf("[empty]\n");
	} else {
		printf("[%d]:", seq->length);
		for (const char *p = seq->data; p < seq->data + seq->length; ++p) {
			printf("%c", *p);
		}
		printf("\n");
	}
}
