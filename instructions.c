#include "instructions.h"

struct {
    char *instruction;
    void (*func)(void);
} instructions[] = {
        {"mov", mov},
        {"cmp", cmp},
        {"add", add},
        {"sub", sub},
        {"not", negative},
        {"clr", clr},
        {"lea", lea},
        {"inc", dec},
        {"jmp", jmp},
        {"bne", bne},
        {"red", red},
        {"prn", prn},
        {"jsr", jsr},
        {"rts", rts},
        {"stop", stop},
        {"not_valid", NULL}
    };

void mov(void)
{
	
}
void cmp(void)
{
	
}
void add(void)
{
	
}
void sub(void)
{
	
}
void negative(void)
{
	
}
void clr(void)
{
	
}
void lea(void)
{
	
}
void dec(void)
{
	
}
void jmp(void)
{
	
}
void bne(void)
{
	
}
void red(void)
{
	
}
void prn(void)
{
	
}
void jsr(void)
{
	
}
void rts(void)
{
	
}
void stop(void)
{
	
}