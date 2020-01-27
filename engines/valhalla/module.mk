MODULE := engines/valhalla

MODULE_OBJS = \
	valhalla.o \
	console.o \
	detection.o

# This module can be built as a plugin
ifeq ($(ENABLE_VALHALLA), DYNAMIC_PLUGIN)
PLUGIN := 1
endif

# Include common rules
include $(srcdir)/rules.mk
