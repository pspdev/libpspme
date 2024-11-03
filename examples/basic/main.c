#include <stdio.h>

#include <pspkernel.h>
#include <pspdebug.h>
#include <pspdisplay.h>
#include <pspkernel.h>

#include <me.h>

#define VERS 1
#define REVS 0
PSP_MODULE_INFO("BasicME", 0, VERS, REVS);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER | THREAD_ATTR_VFPU);

static int exitRequest = 0;

static int isRunning()
{
    return !exitRequest;
}

static int exitCallback(int arg1, int arg2, void *common)
{
    exitRequest = 1;
    return 0;
}

static int callbackThread(SceSize args, void *argp)
{
    int callbackID;

    callbackID = sceKernelCreateCallback("Exit Callback", exitCallback, NULL);
    sceKernelRegisterExitCallback(callbackID);

    sceKernelSleepThreadCB();

    return 0;
}

static int setupExitCallback()
{
    int threadID = 0;

    threadID = sceKernelCreateThread("Callback Update Thread", callbackThread, 0x11, 0xFA0, THREAD_ATTR_USER, 0);

    if (threadID >= 0)
    {
        sceKernelStartThread(threadID, 0, 0);
    }

    return threadID;
}

int main(int argc, char **argv)
{
    // basic init
    setupExitCallback();

    foo_me();

    return 0;
}