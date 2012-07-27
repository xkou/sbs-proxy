#include <stdio.h>
#include <spawn.h>
#include <CoreFoundation/CoreFoundation.h>
#include <Foundation/Foundation.h>
#include <Python.h>

BOOL isCapable(){
	return YES;
}

BOOL isEnabled() {
	static struct stat buf;
	if(stat("/tmp/xuke.autossh", &buf) == -1) return NO;
	else return YES;
}

BOOL getStateFast(){
	return isEnabled();
}

void setState( BOOL enable ){
	if(YES == enable ){
		system("/var/xuke/startssh");
//		execl("/bin/sh", "/bin/sh", "/var/xuke/startssh", NULL);
//		notify_post("com.sbsettings.proxy.enable");
	}else{
		system("kill `cat /tmp/xuke.autossh`");
			system("rm /tmp/xuke.autossh");
//		notify_post("com.sbsettings.proxy.disable");
	}
}

float getDelayTime(){ return 2.0f; }



