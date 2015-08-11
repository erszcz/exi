-module(encoder).
-author("Piotr Ociepka").
-export([encode_exi/1]).
-on_load(init/0).
-compile(export_all).

init() ->
    Priv = code:priv_dir(exi),
    Nif = filename:join(Priv, "encoder_nif"),
    ok = erlang:load_nif(Nif, 0).

encode_exi([]) -> [];
encode_exi([{sd} | T]) ->
  encode_start_document(),
  encode_exi(T);
encode_exi([{se, Name} | T]) ->
  encode_start_element(Name),
  encode_exi(T);
encode_exi([{se, Name, Uri} | T]) ->
  encode_start_element_with_uri(Name, Uri),
  encode_exi(T);
encode_exi([{at, Name} | T]) ->
  encode_attribute(Name),
  encode_exi(T);
encode_exi([{at, Name, Uri} | T]) ->
  encode_attribute_with_uri(Name, Uri),
  encode_exi(T);
encode_exi([{sc} | T]) ->
  encode_self_contained(),
  encode_exi(T);
encode_exi([{ch, Value} | T]) ->
  encode_value(Value),
  encode_exi(T);
encode_exi([{ee} | T]) ->
  encode_end_element(),
  encode_exi(T);
encode_exi([{ed} | T]) ->
  encode_end_document(),
  encode_exi(T).


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% Initalizers
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

init_buffer() ->
    exit(nif_library_not_loaded).

init_stream() ->
  exit(nif_library_not_loaded).

serialize_header() ->
  exit(nif_library_not_loaded).

close_stream() ->
  exit(nif_library_not_loaded).

init_exi_header() ->
  exit(nif_library_not_loaded).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% Header options
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

set_cookie() ->
  exit(nif_library_not_loaded).

unset_cookie() ->
  exit(nif_library_not_loaded).

set_options() ->
  exit(nif_library_not_loaded).

unset_options() ->
  exit(nif_library_not_loaded).

set_version(_Version) ->
  exit(nif_library_not_loaded).

set_bit_packed_alignment() ->
  exit(nif_library_not_loaded).

set_byte_alignment() ->
  exit(nif_library_not_loaded).

set_precompression_alignment() ->
  exit(nif_library_not_loaded).

set_compression() ->
  exit(nif_library_not_loaded).

set_strict() ->
  exit(nif_library_not_loaded).

set_fragment() ->
  exit(nif_library_not_loaded).

set_preserved_comments() ->
  exit(nif_library_not_loaded).

set_preserved_pis() ->
  exit(nif_library_not_loaded).

set_preserved_dtd() ->
  exit(nif_library_not_loaded).

set_preserved_prefixes() ->
  exit(nif_library_not_loaded).

set_preserved_lexvalues() ->
  exit(nif_library_not_loaded).

set_schema_id() ->
  exit(nif_library_not_loaded).

set_block_size(_Size) ->
  exit(nif_library_not_loaded).

set_value_max_length(_Length) ->
  exit(nif_library_not_loaded).

set_partition_capacity(_Capacity) ->
  exit(nif_library_not_loaded).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% EXI events
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

encode_start_document() ->
  exit(nif_library_not_loaded).

encode_start_element(_Name) ->
  exit(nif_library_not_loaded).

encode_start_element_with_uri(_Name, _Uri) ->
  exit(nif_library_not_loaded).

encode_self_contained() ->
  exit(nif_library_not_loaded).

encode_attribute(_Name) ->
  exit(nif_library_not_loaded).

encode_attribute_with_uri(_Name, _Uri) ->
  exit(nif_library_not_loaded).

encode_value(_Value) ->
  exit(nif_library_not_loaded).

encode_end_element() ->
  exit(nif_library_not_loaded).

encode_end_document() ->
  exit(nif_library_not_loaded).
