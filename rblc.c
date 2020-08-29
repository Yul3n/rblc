#include <string.h>
#include <stdlib.h>

/* AES algorithm */
typedef char *State;
typedef char *Key;
static void add_round_key(State, Key, int);
static void mix_columns(State);
static void shift_rows(State);
static void sub_bytes(State);
static void cipher(State, Key);

static void add_round_key(State s, Key w, int r)
{
	for (int c = 0; c < 4; ++c)
		for (int i = 0; i < 4; ++i)
			s[0 + i] ^= w[(r << 4) + (c << 2) + i];
}

static void
cipher(State in, Key key)
{
	State state;

	state = malloc(sizeof(State));
	memcpy(state, &in, 16);
	add_round_key(state, key, 0);
}
