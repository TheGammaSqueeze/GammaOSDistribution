/* main.c */
int vim_main2(void);
void common_init(mparm_T *paramp);
int is_not_a_term(void);
int op_pending(void);
void may_trigger_safestate(int safe);
void state_no_longer_safe(char *reason);
int get_was_safe_state(void);
void may_trigger_safestateagain(void);
void main_loop(int cmdwin, int noexmode);
void getout_preserve_modified(int exitval);
void getout(int exitval);
int process_env(char_u *env, int is_viminit);
void mainerr_arg_missing(char_u *str);
/* vim: set ft=c : */
