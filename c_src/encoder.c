#include "EXISerializer.h"
#include "stringManipulate.h"
#include <stdio.h>
#include <string.h>

#include "encoder.h"

#define OUTPUT_BUFFER_SIZE 20000
EXIStream testStrm;
String uri;
String ln;
QName qname = {&uri, &ln, NULL};
char buf[OUTPUT_BUFFER_SIZE];
BinaryBuffer buffer;
EXITypeClass valueType;


void init_buffer() {
	buffer.buf = buf;
	buffer.bufLen = OUTPUT_BUFFER_SIZE;
	buffer.bufContent = 0;
	buffer.ioStrm.readWriteToStream = NULL;
	buffer.ioStrm.stream = NULL;
}

errorCode init_stream() {
	return serialize.initStream(&testStrm, buffer, NULL);
}

errorCode serialize_header() {
	return serialize.exiHeader(&testStrm);
}

errorCode close_stream() {
	return serialize.closeEXIStream(&testStrm);
}

/// HEADER ///

void init_exi_header() {
	serialize.initHeader(&testStrm);
}

void set_cookie() {
	testStrm.header.has_cookie = TRUE;
}

void unset_cookie() {
	testStrm.header.has_cookie = FALSE;
}

void set_options() {
	testStrm.header.has_options = TRUE;
}

void unset_options() {
	testStrm.header.has_options = FALSE;
}

void set_version(int version) {
	testStrm.header.version_number = version;
}

void set_bit_packed_alignment() {
	SET_ALIGNMENT(testStrm.header.opts.enumOpt, BIT_PACKED);
}

void set_byte_alignment() {
	SET_ALIGNMENT(testStrm.header.opts.enumOpt, BYTE_ALIGNMENT);
}

void set_precompression_alignment() {
	SET_ALIGNMENT(testStrm.header.opts.enumOpt, PRE_COMPRESSION);
}

void set_compression() {
	SET_COMPRESSION(testStrm.header.opts.enumOpt);
}

void set_strict() {
	SET_STRICT(testStrm.header.opts.enumOpt);
}

void set_fragment() {
	SET_FRAGMENT(testStrm.header.opts.enumOpt);
}

void set_preserved_comments() {
	SET_PRESERVED(testStrm.header.opts.preserve, PRESERVE_COMMENTS);
}

void set_preserved_pis() {
	SET_PRESERVED(testStrm.header.opts.preserve, PRESERVE_PIS);
}

void set_preserved_dtd() {
	SET_PRESERVED(testStrm.header.opts.preserve, PRESERVE_DTD);
}

void set_preserved_prefixes() {
	SET_PRESERVED(testStrm.header.opts.preserve, PRESERVE_PREFIXES);
}

void set_preserved_lexvalues() {
	SET_PRESERVED(testStrm.header.opts.preserve, PRESERVE_LEXVALUES);
}

void set_self_contained() {
	SET_SELF_CONTAINED(testStrm.header.opts.enumOpt);
}

void set_schema_id() {
	const String SCHEMA_ID_STR = {"http://www.ltu.se/exip", 22};
	testStrm.header.opts.schemaID = SCHEMA_ID_STR;
}

void set_block_size(int block_size) {
	testStrm.header.opts.blockSize = block_size;
}

void set_value_max_length(int value_max_length) {
	testStrm.header.opts.valueMaxLength = value_max_length;
}

void set_partition_capacity(int partition_capacity) {
	testStrm.header.opts.valuePartitionCapacity = partition_capacity;
}

/// EVENTS ///
errorCode encode_start_document() {
	return serialize.startDocument(&testStrm);
}

errorCode encode_start_element(char* name) {
	String local_name;
	asciiToString(name, &local_name, &testStrm.memList, FALSE);
	String elem_uri;
	getEmptyString(&elem_uri);
	qname.uri = &elem_uri;
	qname.localName = &local_name;
	return serialize.startElement(&testStrm, qname, &valueType);
}

errorCode encode_start_element_with_uri(char* name, char* uri) {
	String local_name;
	asciiToString(name, &local_name, &testStrm.memList, FALSE);
	String elem_uri;
	asciiToString(uri, &elem_uri, &testStrm.memList, FALSE);
	qname.uri = &elem_uri;
	qname.localName = &local_name;
	return serialize.startElement(&testStrm, qname, &valueType);
}

errorCode encode_self_contained() {
	return serialize.selfContained(&testStrm);
}

errorCode encode_attribute(char* name) {
	String local_name;
	asciiToString(name, &local_name, &testStrm.memList, FALSE);
	String elem_uri;
	getEmptyString(&elem_uri);
	qname.uri = &elem_uri;
	qname.localName = &local_name;
	return serialize.attribute(&testStrm, qname, TRUE, &valueType);
}

errorCode encode_attribute_with_uri(char* name, char* uri) {
	String local_name;
	asciiToString(name, &local_name, &testStrm.memList, FALSE);
	String elem_uri;
	asciiToString(uri, &elem_uri, &testStrm.memList, FALSE);
	qname.uri = &elem_uri;
	qname.localName = &local_name;
	return serialize.attribute(&testStrm, qname, TRUE, &valueType);
}

errorCode encode_value(char* value) {
	String val;
	asciiToString(value, &val, &testStrm.memList, FALSE);
	return serialize.stringData(&testStrm, val);
}

errorCode encode_end_element() {
	return serialize.endElement(&testStrm);
}

errorCode encode_end_document() {
	return serialize.endDocument(&testStrm);
}
