#include <stdio.h>

#include <pspkernel.h>

#define VERS 1
#define REVS 0
PSP_MODULE_INFO("PSPME", PSP_MODULE_KERNEL, VERS, REVS);

int main_thread(SceSize args, void *argp)
{
	printf("PSPME Module\n");

	return 0;
}

/* Entry point */
int module_start(SceSize args, void *argp)
{
	int thid;

	thid = sceKernelCreateThread("template", main_thread, 7, 0x800, 0, NULL);
	if(thid >= 0)
	{
		sceKernelStartThread(thid, args, argp);
	}
	return 0;
}

/* Module stop entry */
int module_stop(SceSize args, void *argp)
{
	return 0;
}
