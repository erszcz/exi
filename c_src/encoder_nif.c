#include "erl_nif.h"

#include "encodeTestExi.h"

#define MAX_STRING_SIZE 2048

static ERL_NIF_TERM init_buffer_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  if(argc != 0)
    return enif_make_badarg(env);
  init_buffer();
  return enif_make_atom(env, "ok");
}

static ERL_NIF_TERM init_stream_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  if(argc != 0)
    return enif_make_badarg(env);
  if(!init_stream())
    return enif_make_badarg(env);
  else
    return enif_make_atom(env, "ok");
}

static ERL_NIF_TERM serialize_header_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  if(argc != 0)
    return enif_make_badarg(env);
  if(!serialize_header())
    return enif_make_badarg(env);
  else
    return enif_make_atom(env, "ok");
}

static ERL_NIF_TERM close_stream_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  if(argc != 0)
    return enif_make_badarg(env);
  if(!close_stream())
    return enif_make_badarg(env);
  else
    return enif_make_atom(env, "ok");
}

/// HEADER ///

static ERL_NIF_TERM init_exi_header_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  if(argc != 0)
    return enif_make_badarg(env);
  init_exi_header();
  return enif_make_atom(env, "ok");
}

static ERL_NIF_TERM set_cookie_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  if(argc != 0)
    return enif_make_badarg(env);
  set_cookie();
  return enif_make_atom(env, "ok");
}

static ERL_NIF_TERM unset_cookie_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  if(argc != 0)
    return enif_make_badarg(env);
  unset_cookie();
  return enif_make_atom(env, "ok");
}

static ERL_NIF_TERM set_options_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  if(argc != 0)
    return enif_make_badarg(env);
  set_options();
  return enif_make_atom(env, "ok");
}

static ERL_NIF_TERM unset_options_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  if(argc != 0)
    return enif_make_badarg(env);
  unset_options();
  return enif_make_atom(env, "ok");
}

static ERL_NIF_TERM set_version_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  if(argc != 1)
    return enif_make_badarg(env);
  int x;
  if (!enif_get_int(env, argv[0], &x)) {
	   return enif_make_badarg(env);
  }
  set_version(x);
  return enif_make_atom(env, "ok");
}

static ERL_NIF_TERM set_bit_packed_alignment_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  if(argc != 0)
    return enif_make_badarg(env);
  set_bit_packed_alignment();
  return enif_make_atom(env, "ok");
}

static ERL_NIF_TERM set_byte_alignment_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  if(argc != 0)
    return enif_make_badarg(env);
  byte_alignment_cookie();
  return enif_make_atom(env, "ok");
}

static ERL_NIF_TERM set_precompression_alignment_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  if(argc != 0)
    return enif_make_badarg(env);
  set_precompression_alignment();
  return enif_make_atom(env, "ok");
}

static ERL_NIF_TERM set_compression_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  if(argc != 0)
    return enif_make_badarg(env);
  set_compression();
  return enif_make_atom(env, "ok");
}

static ERL_NIF_TERM set_strict_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  if(argc != 0)
    return enif_make_badarg(env);
  set_strict();
  return enif_make_atom(env, "ok");
}

static ERL_NIF_TERM set_fragment_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  if(argc != 0)
    return enif_make_badarg(env);
  set_fragment();
  return enif_make_atom(env, "ok");
}

static ERL_NIF_TERM set_preserved_comments_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  if(argc != 0)
    return enif_make_badarg(env);
  set_preserved_comments();
  return enif_make_atom(env, "ok");
}

static ERL_NIF_TERM set_preserved_pis_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  if(argc != 0)
    return enif_make_badarg(env);
  set_preserved_pis();
  return enif_make_atom(env, "ok");
}

static ERL_NIF_TERM set_preserved_dtd_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  if(argc != 0)
    return enif_make_badarg(env);
  set_preserved_dtd();
  return enif_make_atom(env, "ok");
}

static ERL_NIF_TERM set_preserved_prefixes_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  if(argc != 0)
    return enif_make_badarg(env);
  set_preserved_prefxes();
  return enif_make_atom(env, "ok");
}

static ERL_NIF_TERM set_preserved_lexvalues_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  if(argc != 0)
    return enif_make_badarg(env);
  set_preserved_lexvalues();
  return enif_make_atom(env, "ok");
}

static ERL_NIF_TERM set_schema_id_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  if(argc != 0)
    return enif_make_badarg(env);
  set_schema_id();
  return enif_make_atom(env, "ok");
}

static ERL_NIF_TERM set_block_size_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  if(argc != 1)
    return enif_make_badarg(env);
  int x;
  if (!enif_get_int(env, argv[0], &x)) {
	   return enif_make_badarg(env);
  }
  set_block_size(x);
  return enif_make_atom(env, "ok");
}

static ERL_NIF_TERM set_value_max_length_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  if(argc != 1)
    return enif_make_badarg(env);
  int x;
  if (!enif_get_int(env, argv[0], &x)) {
	   return enif_make_badarg(env);
  }
  set_value_max_length(x);
  return enif_make_atom(env, "ok");
}

static ERL_NIF_TERM set_partition_capacity_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  if(argc != 1)
    return enif_make_badarg(env);
  int x;
  if (!enif_get_int(env, argv[0], &x)) {
	   return enif_make_badarg(env);
  }
  set_partition_capacity(x);
  return enif_make_atom(env, "ok");
}

/// EVENTS ///

static ERL_NIF_TERM encode_start_document_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  if(argc != 0)
    return enif_make_badarg(env);
  if(!encode_start_document())
    return enif_make_badarg(env);
  else
    return enif_make_atom(env, "ok");
}

static ERL_NIF_TERM encode_start_element_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  if(argc != 1)
    return enif_make_badarg(env);
  char name[MAX_STRING_SIZE];
  if (!enif_get_string(env, argv[0], name, MAX_STRING_SIZE, ERL_NIF_LATIN1)) {
    return enif_make_badarg(env);
  }
  if(!encode_start_element(name))
    return enif_make_badarg(env);
  else
    return enif_make_atom(env, "ok");
}

static ERL_NIF_TERM encode_start_element_with_uri_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  if(argc != 1)
    return enif_make_badarg(env);
  char name[MAX_STRING_SIZE];
  char uri[MAX_STRING_SIZE];
  if (!enif_get_string(env, argv[0], name, MAX_STRING_SIZE, ERL_NIF_LATIN1)) {
    return enif_make_badarg(env);
  }
  if (!enif_get_string(env, argv[0], uri, MAX_STRING_SIZE, ERL_NIF_LATIN1)) {
    return enif_make_badarg(env);
  }
  if(!encode_start_element_with_uri(name, uri))
    return enif_make_badarg(env);
  else
    return enif_make_atom(env, "ok");
}

static ERL_NIF_TERM encode_self_contained_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  if(argc != 0)
    return enif_make_badarg(env);
  if(!encode_self_contained())
    return enif_make_badarg(env);
  else
    return enif_make_atom(env, "ok");
}

static ERL_NIF_TERM encode_attribute_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  if(argc != 1)
    return enif_make_badarg(env);
  char name[MAX_STRING_SIZE];
  if (!enif_get_string(env, argv[0], name, MAX_STRING_SIZE, ERL_NIF_LATIN1)) {
    return enif_make_badarg(env);
  }
  if(!encode_attribute(name))
    return enif_make_badarg(env);
  else
    return enif_make_atom(env, "ok");
}

static ERL_NIF_TERM encode_attribute_with_uri_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  if(argc != 1)
    return enif_make_badarg(env);
  char name[MAX_STRING_SIZE];
  char uri[MAX_STRING_SIZE];
  if (!enif_get_string(env, argv[0], name, MAX_STRING_SIZE, ERL_NIF_LATIN1)) {
    return enif_make_badarg(env);
  }
  if (!enif_get_string(env, argv[0], uri, MAX_STRING_SIZE, ERL_NIF_LATIN1)) {
    return enif_make_badarg(env);
  }
  if(!encode_attribute_with_uri(name, uri))
    return enif_make_badarg(env);
  else
    return enif_make_atom(env, "ok");
}

static ERL_NIF_TERM encode_value_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  if(argc != 1)
    return enif_make_badarg(env);
  char value[MAX_STRING_SIZE];
  if (!enif_get_string(env, argv[0], value, MAX_STRING_SIZE, ERL_NIF_LATIN1)) {
    return enif_make_badarg(env);
  }
  if(!encode_value(value))
    return enif_make_badarg(env);
  else
    return enif_make_atom(env, "ok");
}

static ERL_NIF_TERM encode_end_element_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  if(argc != 0)
    return enif_make_badarg(env);
  if(!encode_end_element())
    return enif_make_badarg(env);
  else
    return enif_make_atom(env, "ok");
}

static ERL_NIF_TERM encode_end_document_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) {
  if(argc != 0)
    return enif_make_badarg(env);
  if(!encode_end_document())
    return enif_make_badarg(env);
  else
    return enif_make_atom(env, "ok");
}

static ErlNifFunc nif_funcs[] = {
    {"init_buffer",                   0, init_buffer_nif_nif},
    {"init_stream",                   0, init_stream_nif},
    {"serialize_header",              0, serialuze_header_nif},
    {"close_stream",                  0, close_stream_nif},
    {"init_exi_header",               0, init_exi_header_nif},
    {"set_cookie",                    0, set_cookie_nif},
    {"unset_cookie",                  0, unset_cookie_nif},
    {"set_options",                   0, set_options_nif},
    {"unset_options",                 0, unset_options_nif},
    {"set_version",                   1, set_version_nif},
    {"set_bit_packed_alignment",      0, set_bit_packed_alignment_nif},
    {"set_byte_alignment",            0, set_byte_alignment_nif},
    {"set_precompression_alignment",  0, set_precompression_alignment_nif},
    {"set_compression",               0, set_compression_nif},
    {"set_strict",                    0, set_strict_nif},
    {"set_fragment",                  0, set_fragment_nif},
    {"set_preserved_comments",        0, set_preserved_comments_nif},
    {"set_preserved_pis",             0, set_preserved_pis_nif},
    {"set_preserved_dtd",             0, set_preserved_dtd_nif},
    {"set_preserved_prefixes",        0, set_preserved_prefixes_nif},
    {"set_preserved_lexvalues",       0, set_preserved_lexvalues_nif},
    {"set_schema_id",                 0, set_schema_id_nif},
    {"set_block_size",                1, set_block_size_nif},
    {"set_value_max_length",          1, set_value_max_length_nif},
    {"set_partition_capacity",        1, set_partition_capacity_nif},
    {"encode_start_document",         0, encode_start_document_nif},
    {"encode_start_element",          1, encode_start_element_nif},
    {"encode_start_element_with_uri", 2, encode_start_element_with_uri_nif},
    {"encode_self_contained",         0, encode_self_contained_nif},
    {"encode_attribute",              1, encode_attribute_nif},
    {"encode_attribute_with_uri",     2, encode_attribute_with_uri_nif},
    {"encode_value",                  1, encode_value_nif},
    {"encode_end_element",            0, encode_end_element_nif},
    {"encode_end_document",           0, encode_end_document_nif}
};

ERL_NIF_INIT(encoder, nif_funcs, NULL, NULL, NULL, NULL)
