/* No-op stand-ins for the rest of libsuperdrastic that this line's src/resume.c calls, for host tests that link
 * resume.c alone (tools/resume-keep-test.c, tools/ut/t_hold_diff.c). Weak, so a test's own definition wins. */
#define W __attribute__((weak))
W volatile int dsflip_stalled;
W int menu_is_open(void) { return 0; }
W int menu_hint(const char *name, int times) { (void)name; (void)times; return 0; }
W const char *menu_game_title(void) { return "test"; }
W void audio_hand_off(void) {}
