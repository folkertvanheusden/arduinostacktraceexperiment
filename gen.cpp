#include <Arduino.h>

extern "C" {
#define F_FLUSH() \
	asm volatile("": : :"memory"); \
	asm("dsb"); \
	SCB_CACHE_DCCMVAC = uint32_t(0x2027FFC0 & 0xFFFFFFE0); \
	asm("dsb"); \
	asm("isb");
    void __cyg_profile_func_enter (void *func,  void *caller)
    {
	volatile struct crashreport_breadcrumbs_struct *bc = (struct crashreport_breadcrumbs_struct *)0x2027FFC0;
	for(int i=0; i<5; i++)
		bc->value[i] = bc->value[i+1];
	bc->value[5] = caller;
	F_FLUSH();
    }

    void __cyg_profile_func_exit (void *func, void *caller)
    {
	volatile struct crashreport_breadcrumbs_struct *bc = (struct crashreport_breadcrumbs_struct *)0x2027FFC0;
	for(int i=0; i<5; i++)
		bc->value[i] = bc->value[i+1];
	bc->value[5] = caller;
	F_FLUSH();
    }
}
