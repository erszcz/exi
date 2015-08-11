#ifndef eXI
#define eXI

void init_buffer();
errorCode init_stream();
errorCode serialize_header();
errorCode close_stream();

/// HEADER ///
void init_exi_header();

void set_cookie();
void unset_cookie();
void set_options();
void unset_options();
void set_version(int version);
void set_bit_packed_alignment();
void set_byte_alignment();
void set_precompression_alignment();
void set_compression();
void set_strict();
void set_fragment();
void set_preserved_comments();
void set_preserved_pis();
void set_preserved_dtd();
void set_preserved_prefixes();
void set_preserved_lexvalues();
void set_schema_id();
// void init_encoder();
void set_block_size(int block_size);
void set_value_max_length(int value_max_length);
void set_partition_capacity(int partition_capacity);

/// EVENTS ///
errorCode encode_start_document();
errorCode encode_start_element(char* name);
errorCode encode_start_element_with_uri(char* name, char* uri);
errorCode encode_self_contained();
errorCode encode_attribute(char* name);
errorCode encode_attribute_with_uri(char* name, char* uri);
errorCode encode_value(char* value);
errorCode encode_end_element();
errorCode encode_end_document();

#endif
