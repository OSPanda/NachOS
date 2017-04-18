# NOTE: this is a GNU Makefile.  You must use "gmake" rather than "make".
#
# Makefile for the file system assignment
#    Defines set up assuming multiprogramming and virtual memory done first.
#    If not, use the "bare bones"  defines below. 
#
# Copyright (c) 1992 The Regents of the University of California.
# All rights reserved.  See copyright.h for copyright notice and limitation 
# of liability and disclaimer of warranty provisions.

DEFINES =-DTHREADS -DUSER_PROGRAM -DVM -DFILESYS_NEEDED -DFILESYS
INCPATH = -I../filesys -I../bin -I../vm -I../userprog -I../threads -I../machine
HFILES = $(THREAD_H) $(USERPROG_H) $(VM_H) $(FILESYS_H)
CFILES = $(THREAD_C) $(USERPROG_C) $(VM_C) $(FILESYS_C)
C_OFILES = $(THREAD_O) $(USERPROG_O) $(VM_O) $(FILESYS_O)

# bare bones version
# DEFINES =-DTHREADS -DFILESYS_NEEDED -DFILESYS
# INCPATH = -I../filesys -I../threads -I../machine
# HFILES = $(THREAD_H) $(FILESYS_H)
# CFILES = $(THREAD_C) $(FILESYS_C)
# C_OFILES = $(THREAD_O) $(FILESYS_O)

include ../Makefile.common
include ../Makefile.dep
#-----------------------------------------------------------------
# DO NOT DELETE THIS LINE -- make depend uses it
# DEPENDENCIES MUST END AT END OF FILE
main.o: ../threads/main.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/utility.h ../threads/bool.h \
 ../machine/sysdep.h ../threads/copyright.h /usr/include/stdio.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/4.9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/system.h ../threads/thread.h \
 ../machine/machine.h ../threads/utility.h ../machine/translate.h \
 ../machine/disk.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../threads/scheduler.h ../threads/list.h \
 ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
 ../machine/timer.h ../filesys/synchdisk.h ../machine/disk.h \
 ../threads/synch.h
list.o: ../threads/list.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/list.h ../threads/utility.h \
 ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/4.9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h
scheduler.o: ../threads/scheduler.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/scheduler.h ../threads/list.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 ../threads/copyright.h /usr/include/stdio.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/4.9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/system.h ../machine/interrupt.h ../threads/list.h \
 ../machine/stats.h ../machine/timer.h ../filesys/synchdisk.h \
 ../machine/disk.h ../threads/synch.h
synch.o: ../threads/synch.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/synch.h ../threads/thread.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 ../threads/copyright.h /usr/include/stdio.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/4.9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/list.h \
 ../threads/system.h ../threads/scheduler.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h ../machine/timer.h \
 ../filesys/synchdisk.h ../machine/disk.h ../threads/synch.h \
 /usr/include/assert.h
synchlist.o: ../threads/synchlist.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/synchlist.h ../threads/list.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 ../threads/copyright.h /usr/include/stdio.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/4.9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/synch.h ../threads/thread.h \
 ../machine/machine.h ../threads/utility.h ../machine/translate.h \
 ../machine/disk.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h
system.o: ../threads/system.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/system.h ../threads/utility.h \
 ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/4.9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h ../machine/timer.h \
 ../filesys/synchdisk.h ../machine/disk.h ../threads/synch.h
thread.o: ../threads/thread.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/thread.h ../threads/utility.h \
 ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/4.9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/switch.h \
 ../threads/synch.h ../threads/list.h ../threads/system.h \
 ../threads/scheduler.h ../machine/interrupt.h ../threads/list.h \
 ../machine/stats.h ../machine/timer.h ../filesys/synchdisk.h \
 ../machine/disk.h ../threads/synch.h
utility.o: ../threads/utility.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/utility.h ../threads/bool.h \
 ../machine/sysdep.h ../threads/copyright.h /usr/include/stdio.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/4.9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/stdarg.h
threadtest.o: ../threads/threadtest.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/system.h ../threads/utility.h \
 ../threads/bool.h ../machine/sysdep.h ../threads/copyright.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/4.9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h ../machine/timer.h \
 ../filesys/synchdisk.h ../machine/disk.h ../threads/synch.h \
 ../threads/dllist.h ../threads/synch.h ../threads/Table.h \
 ../threads/BoundedBuffer.h /usr/include/assert.h
interrupt.o: ../machine/interrupt.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../machine/interrupt.h ../threads/list.h \
 ../threads/copyright.h ../threads/utility.h ../threads/bool.h \
 ../machine/sysdep.h /usr/include/stdio.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/4.9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/system.h ../threads/thread.h \
 ../machine/machine.h ../threads/utility.h ../machine/translate.h \
 ../machine/disk.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../threads/scheduler.h ../threads/list.h \
 ../machine/interrupt.h ../machine/stats.h ../machine/timer.h \
 ../filesys/synchdisk.h ../machine/disk.h ../threads/synch.h
sysdep.o: ../machine/sysdep.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h /usr/include/stdio.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/4.9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h /usr/include/signal.h /usr/include/bits/sigset.h \
 /usr/include/bits/signum.h /usr/include/time.h \
 /usr/include/bits/siginfo.h /usr/include/bits/sigaction.h \
 /usr/include/bits/sigcontext.h /usr/include/bits/sigstack.h \
 /usr/include/sys/ucontext.h /usr/include/bits/pthreadtypes.h \
 /usr/include/bits/sigthread.h /usr/include/sys/types.h \
 /usr/include/endian.h /usr/include/bits/endian.h \
 /usr/include/bits/byteswap.h /usr/include/bits/byteswap-16.h \
 /usr/include/sys/select.h /usr/include/bits/select.h \
 /usr/include/bits/time.h /usr/include/sys/sysmacros.h \
 /usr/include/sys/time.h /usr/include/sys/socket.h /usr/include/sys/uio.h \
 /usr/include/bits/uio.h /usr/include/bits/socket.h \
 /usr/include/bits/socket_type.h /usr/include/bits/sockaddr.h \
 /usr/include/asm/socket.h /usr/include/asm-generic/socket.h \
 /usr/include/asm/sockios.h /usr/include/asm-generic/sockios.h \
 /usr/include/sys/file.h /usr/include/fcntl.h /usr/include/bits/fcntl.h \
 /usr/include/bits/fcntl-linux.h /usr/include/bits/stat.h \
 /usr/include/sys/un.h /usr/include/sys/mman.h /usr/include/bits/mman.h \
 /usr/include/bits/mman-linux.h /usr/include/unistd.h \
 /usr/include/bits/posix_opt.h /usr/include/bits/environments.h \
 /usr/include/bits/confname.h /usr/include/getopt.h /usr/include/errno.h \
 /usr/include/bits/errno.h /usr/include/linux/errno.h \
 /usr/include/asm/errno.h /usr/include/asm-generic/errno.h \
 /usr/include/asm-generic/errno-base.h ../machine/interrupt.h \
 ../threads/list.h ../threads/copyright.h ../threads/utility.h \
 ../threads/bool.h ../machine/sysdep.h ../threads/system.h \
 ../threads/thread.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/scheduler.h \
 ../threads/list.h ../machine/interrupt.h ../machine/stats.h \
 ../machine/timer.h ../filesys/synchdisk.h ../machine/disk.h \
 ../threads/synch.h
stats.o: ../machine/stats.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/utility.h ../threads/copyright.h \
 ../threads/bool.h ../machine/sysdep.h /usr/include/stdio.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/4.9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../machine/stats.h
timer.o: ../machine/timer.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../machine/timer.h ../threads/utility.h \
 ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/4.9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/system.h ../threads/utility.h \
 ../threads/thread.h ../machine/machine.h ../machine/translate.h \
 ../machine/disk.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../threads/scheduler.h ../threads/list.h \
 ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
 ../machine/timer.h ../filesys/synchdisk.h ../machine/disk.h \
 ../threads/synch.h
dllist.o: ../threads/dllist.cc /usr/include/stdc-predef.h \
 ../threads/dllist.h /usr/include/c++/4.9/iostream \
 /usr/include/x86_64-linux-gnu/c++/4.9/32/bits/c++config.h \
 /usr/include/x86_64-linux-gnu/c++/4.9/32/bits/os_defines.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/include/x86_64-linux-gnu/c++/4.9/32/bits/cpu_defines.h \
 /usr/include/c++/4.9/ostream /usr/include/c++/4.9/ios \
 /usr/include/c++/4.9/iosfwd /usr/include/c++/4.9/bits/stringfwd.h \
 /usr/include/c++/4.9/bits/memoryfwd.h \
 /usr/include/c++/4.9/bits/postypes.h /usr/include/c++/4.9/cwchar \
 /usr/include/wchar.h /usr/include/stdio.h ../threads/stdarg.h \
 /usr/include/bits/wchar.h \
 /usr/lib/gcc/x86_64-linux-gnu/4.9/include/stddef.h \
 /usr/include/xlocale.h /usr/include/c++/4.9/exception \
 /usr/include/c++/4.9/bits/atomic_lockfree_defines.h \
 /usr/include/c++/4.9/bits/char_traits.h \
 /usr/include/c++/4.9/bits/stl_algobase.h \
 /usr/include/c++/4.9/bits/functexcept.h \
 /usr/include/c++/4.9/bits/exception_defines.h \
 /usr/include/c++/4.9/bits/cpp_type_traits.h \
 /usr/include/c++/4.9/ext/type_traits.h \
 /usr/include/c++/4.9/ext/numeric_traits.h \
 /usr/include/c++/4.9/bits/stl_pair.h /usr/include/c++/4.9/bits/move.h \
 /usr/include/c++/4.9/bits/concept_check.h \
 /usr/include/c++/4.9/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.9/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.9/debug/debug.h \
 /usr/include/c++/4.9/bits/stl_iterator.h \
 /usr/include/c++/4.9/bits/ptr_traits.h \
 /usr/include/c++/4.9/bits/predefined_ops.h \
 /usr/include/c++/4.9/bits/localefwd.h \
 /usr/include/x86_64-linux-gnu/c++/4.9/32/bits/c++locale.h \
 /usr/include/c++/4.9/clocale /usr/include/locale.h \
 /usr/include/bits/locale.h /usr/include/c++/4.9/cctype \
 /usr/include/ctype.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/endian.h \
 /usr/include/bits/endian.h /usr/include/bits/byteswap.h \
 /usr/include/bits/byteswap-16.h /usr/include/c++/4.9/bits/ios_base.h \
 /usr/include/c++/4.9/ext/atomicity.h \
 /usr/include/x86_64-linux-gnu/c++/4.9/32/bits/gthr.h \
 /usr/include/x86_64-linux-gnu/c++/4.9/32/bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/bits/sched.h /usr/include/bits/time.h \
 /usr/include/bits/timex.h /usr/include/bits/pthreadtypes.h \
 /usr/include/bits/setjmp.h \
 /usr/include/x86_64-linux-gnu/c++/4.9/32/bits/atomic_word.h \
 /usr/include/c++/4.9/bits/locale_classes.h /usr/include/c++/4.9/string \
 /usr/include/c++/4.9/bits/allocator.h \
 /usr/include/x86_64-linux-gnu/c++/4.9/32/bits/c++allocator.h \
 /usr/include/c++/4.9/ext/new_allocator.h /usr/include/c++/4.9/new \
 /usr/include/c++/4.9/bits/ostream_insert.h \
 /usr/include/c++/4.9/bits/cxxabi_forced.h \
 /usr/include/c++/4.9/bits/stl_function.h \
 /usr/include/c++/4.9/backward/binders.h \
 /usr/include/c++/4.9/bits/range_access.h \
 /usr/include/c++/4.9/bits/basic_string.h \
 /usr/include/c++/4.9/bits/basic_string.tcc \
 /usr/include/c++/4.9/bits/locale_classes.tcc \
 /usr/include/c++/4.9/streambuf /usr/include/c++/4.9/bits/streambuf.tcc \
 /usr/include/c++/4.9/bits/basic_ios.h \
 /usr/include/c++/4.9/bits/locale_facets.h /usr/include/c++/4.9/cwctype \
 /usr/include/wctype.h \
 /usr/include/x86_64-linux-gnu/c++/4.9/32/bits/ctype_base.h \
 /usr/include/c++/4.9/bits/streambuf_iterator.h \
 /usr/include/x86_64-linux-gnu/c++/4.9/32/bits/ctype_inline.h \
 /usr/include/c++/4.9/bits/locale_facets.tcc \
 /usr/include/c++/4.9/bits/basic_ios.tcc \
 /usr/include/c++/4.9/bits/ostream.tcc /usr/include/c++/4.9/istream \
 /usr/include/c++/4.9/bits/istream.tcc ../threads/system.h \
 ../threads/copyright.h ../threads/utility.h ../threads/bool.h \
 ../machine/sysdep.h ../threads/copyright.h /usr/include/libio.h \
 /usr/include/_G_config.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 ../threads/thread.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/scheduler.h \
 ../threads/list.h ../machine/interrupt.h ../threads/list.h \
 ../machine/stats.h ../machine/timer.h ../filesys/synchdisk.h \
 ../machine/disk.h ../threads/synch.h /usr/include/assert.h \
 ../threads/synch.h
dllist-driver.o: ../threads/dllist-driver.cc /usr/include/stdc-predef.h \
 ../threads/dllist.h /usr/include/c++/4.9/iostream \
 /usr/include/x86_64-linux-gnu/c++/4.9/32/bits/c++config.h \
 /usr/include/x86_64-linux-gnu/c++/4.9/32/bits/os_defines.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/include/x86_64-linux-gnu/c++/4.9/32/bits/cpu_defines.h \
 /usr/include/c++/4.9/ostream /usr/include/c++/4.9/ios \
 /usr/include/c++/4.9/iosfwd /usr/include/c++/4.9/bits/stringfwd.h \
 /usr/include/c++/4.9/bits/memoryfwd.h \
 /usr/include/c++/4.9/bits/postypes.h /usr/include/c++/4.9/cwchar \
 /usr/include/wchar.h /usr/include/stdio.h ../threads/stdarg.h \
 /usr/include/bits/wchar.h \
 /usr/lib/gcc/x86_64-linux-gnu/4.9/include/stddef.h \
 /usr/include/xlocale.h /usr/include/c++/4.9/exception \
 /usr/include/c++/4.9/bits/atomic_lockfree_defines.h \
 /usr/include/c++/4.9/bits/char_traits.h \
 /usr/include/c++/4.9/bits/stl_algobase.h \
 /usr/include/c++/4.9/bits/functexcept.h \
 /usr/include/c++/4.9/bits/exception_defines.h \
 /usr/include/c++/4.9/bits/cpp_type_traits.h \
 /usr/include/c++/4.9/ext/type_traits.h \
 /usr/include/c++/4.9/ext/numeric_traits.h \
 /usr/include/c++/4.9/bits/stl_pair.h /usr/include/c++/4.9/bits/move.h \
 /usr/include/c++/4.9/bits/concept_check.h \
 /usr/include/c++/4.9/bits/stl_iterator_base_types.h \
 /usr/include/c++/4.9/bits/stl_iterator_base_funcs.h \
 /usr/include/c++/4.9/debug/debug.h \
 /usr/include/c++/4.9/bits/stl_iterator.h \
 /usr/include/c++/4.9/bits/ptr_traits.h \
 /usr/include/c++/4.9/bits/predefined_ops.h \
 /usr/include/c++/4.9/bits/localefwd.h \
 /usr/include/x86_64-linux-gnu/c++/4.9/32/bits/c++locale.h \
 /usr/include/c++/4.9/clocale /usr/include/locale.h \
 /usr/include/bits/locale.h /usr/include/c++/4.9/cctype \
 /usr/include/ctype.h /usr/include/bits/types.h \
 /usr/include/bits/typesizes.h /usr/include/endian.h \
 /usr/include/bits/endian.h /usr/include/bits/byteswap.h \
 /usr/include/bits/byteswap-16.h /usr/include/c++/4.9/bits/ios_base.h \
 /usr/include/c++/4.9/ext/atomicity.h \
 /usr/include/x86_64-linux-gnu/c++/4.9/32/bits/gthr.h \
 /usr/include/x86_64-linux-gnu/c++/4.9/32/bits/gthr-default.h \
 /usr/include/pthread.h /usr/include/sched.h /usr/include/time.h \
 /usr/include/bits/sched.h /usr/include/bits/time.h \
 /usr/include/bits/timex.h /usr/include/bits/pthreadtypes.h \
 /usr/include/bits/setjmp.h \
 /usr/include/x86_64-linux-gnu/c++/4.9/32/bits/atomic_word.h \
 /usr/include/c++/4.9/bits/locale_classes.h /usr/include/c++/4.9/string \
 /usr/include/c++/4.9/bits/allocator.h \
 /usr/include/x86_64-linux-gnu/c++/4.9/32/bits/c++allocator.h \
 /usr/include/c++/4.9/ext/new_allocator.h /usr/include/c++/4.9/new \
 /usr/include/c++/4.9/bits/ostream_insert.h \
 /usr/include/c++/4.9/bits/cxxabi_forced.h \
 /usr/include/c++/4.9/bits/stl_function.h \
 /usr/include/c++/4.9/backward/binders.h \
 /usr/include/c++/4.9/bits/range_access.h \
 /usr/include/c++/4.9/bits/basic_string.h \
 /usr/include/c++/4.9/bits/basic_string.tcc \
 /usr/include/c++/4.9/bits/locale_classes.tcc \
 /usr/include/c++/4.9/streambuf /usr/include/c++/4.9/bits/streambuf.tcc \
 /usr/include/c++/4.9/bits/basic_ios.h \
 /usr/include/c++/4.9/bits/locale_facets.h /usr/include/c++/4.9/cwctype \
 /usr/include/wctype.h \
 /usr/include/x86_64-linux-gnu/c++/4.9/32/bits/ctype_base.h \
 /usr/include/c++/4.9/bits/streambuf_iterator.h \
 /usr/include/x86_64-linux-gnu/c++/4.9/32/bits/ctype_inline.h \
 /usr/include/c++/4.9/bits/locale_facets.tcc \
 /usr/include/c++/4.9/bits/basic_ios.tcc \
 /usr/include/c++/4.9/bits/ostream.tcc /usr/include/c++/4.9/istream \
 /usr/include/c++/4.9/bits/istream.tcc /usr/include/c++/4.9/ctime \
 /usr/include/c++/4.9/cstdlib /usr/include/stdlib.h \
 /usr/include/bits/waitflags.h /usr/include/bits/waitstatus.h \
 /usr/include/sys/types.h /usr/include/sys/select.h \
 /usr/include/bits/select.h /usr/include/bits/sigset.h \
 /usr/include/sys/sysmacros.h /usr/include/alloca.h \
 /usr/include/bits/stdlib-float.h
Table.o: ../threads/Table.cc /usr/include/stdc-predef.h \
 ../threads/Table.h ../threads/synch.h ../threads/copyright.h \
 ../threads/thread.h ../threads/utility.h ../threads/bool.h \
 ../machine/sysdep.h ../threads/copyright.h /usr/include/stdio.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/4.9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/list.h \
 /usr/include/assert.h /usr/include/c++/4.9/cstring \
 /usr/include/x86_64-linux-gnu/c++/4.9/32/bits/c++config.h \
 /usr/include/x86_64-linux-gnu/c++/4.9/32/bits/os_defines.h \
 /usr/include/x86_64-linux-gnu/c++/4.9/32/bits/cpu_defines.h \
 ../threads/system.h ../threads/scheduler.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h ../machine/timer.h \
 ../filesys/synchdisk.h ../machine/disk.h ../threads/synch.h
BoundedBuffer.o: ../threads/BoundedBuffer.cc /usr/include/stdc-predef.h \
 ../threads/BoundedBuffer.h ../threads/synch.h ../threads/copyright.h \
 ../threads/thread.h ../threads/utility.h ../threads/bool.h \
 ../machine/sysdep.h ../threads/copyright.h /usr/include/stdio.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/4.9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../machine/machine.h ../threads/utility.h \
 ../machine/translate.h ../machine/disk.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/list.h \
 ../threads/system.h ../threads/scheduler.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h ../machine/timer.h \
 ../filesys/synchdisk.h ../machine/disk.h ../threads/synch.h
addrspace.o: ../userprog/addrspace.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/system.h ../threads/copyright.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/4.9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h ../machine/timer.h \
 ../filesys/synchdisk.h ../machine/disk.h ../threads/synch.h \
 ../userprog/addrspace.h ../bin/noff.h
bitmap.o: ../userprog/bitmap.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../userprog/bitmap.h ../threads/utility.h \
 ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/4.9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../filesys/openfile.h
exception.o: ../userprog/exception.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/system.h ../threads/copyright.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/4.9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h ../machine/timer.h \
 ../filesys/synchdisk.h ../machine/disk.h ../threads/synch.h \
 ../userprog/syscall.h
progtest.o: ../userprog/progtest.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/system.h ../threads/copyright.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/4.9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h ../machine/timer.h \
 ../filesys/synchdisk.h ../machine/disk.h ../threads/synch.h \
 ../machine/console.h ../userprog/addrspace.h
console.o: ../machine/console.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../machine/console.h ../threads/utility.h \
 ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/4.9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/system.h ../threads/utility.h \
 ../threads/thread.h ../machine/machine.h ../machine/translate.h \
 ../machine/disk.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../threads/scheduler.h ../threads/list.h \
 ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
 ../machine/timer.h ../filesys/synchdisk.h ../machine/disk.h \
 ../threads/synch.h
machine.o: ../machine/machine.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../machine/machine.h ../threads/utility.h \
 ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/4.9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../machine/translate.h ../machine/disk.h \
 ../threads/system.h ../threads/utility.h ../threads/thread.h \
 ../machine/machine.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../threads/scheduler.h ../threads/list.h \
 ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
 ../machine/timer.h ../filesys/synchdisk.h ../machine/disk.h \
 ../threads/synch.h
mipssim.o: ../machine/mipssim.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../machine/machine.h ../threads/utility.h \
 ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/4.9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../machine/translate.h ../machine/disk.h \
 ../machine/mipssim.h ../threads/system.h ../threads/utility.h \
 ../threads/thread.h ../machine/machine.h ../userprog/addrspace.h \
 ../filesys/filesys.h ../filesys/openfile.h ../threads/scheduler.h \
 ../threads/list.h ../machine/interrupt.h ../threads/list.h \
 ../machine/stats.h ../machine/timer.h ../filesys/synchdisk.h \
 ../machine/disk.h ../threads/synch.h
translate.o: ../machine/translate.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../machine/machine.h ../threads/utility.h \
 ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/4.9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/system.h ../threads/utility.h ../threads/thread.h \
 ../machine/machine.h ../threads/scheduler.h ../threads/list.h \
 ../machine/interrupt.h ../threads/list.h ../machine/stats.h \
 ../machine/timer.h ../filesys/synchdisk.h ../machine/disk.h \
 ../threads/synch.h
directory.o: ../filesys/directory.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/utility.h ../threads/copyright.h \
 ../threads/bool.h ../machine/sysdep.h /usr/include/stdio.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/4.9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../filesys/filehdr.h ../machine/disk.h \
 ../userprog/bitmap.h ../filesys/openfile.h ../filesys/directory.h \
 ../filesys/openfile.h
filehdr.o: ../filesys/filehdr.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/system.h ../threads/copyright.h \
 ../threads/utility.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/4.9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/thread.h ../machine/machine.h \
 ../threads/utility.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h ../machine/timer.h \
 ../filesys/synchdisk.h ../machine/disk.h ../threads/synch.h \
 ../filesys/filehdr.h ../userprog/bitmap.h ../filesys/openfile.h
filesys.o: ../filesys/filesys.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../machine/disk.h ../threads/utility.h \
 ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/4.9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../userprog/bitmap.h ../filesys/openfile.h \
 ../filesys/directory.h ../filesys/openfile.h ../filesys/filehdr.h \
 ../filesys/filesys.h
fstest.o: ../filesys/fstest.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../threads/utility.h ../threads/copyright.h \
 ../threads/bool.h ../machine/sysdep.h /usr/include/stdio.h \
 /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/4.9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/system.h ../threads/utility.h ../threads/thread.h \
 ../machine/machine.h ../machine/translate.h ../machine/disk.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../threads/scheduler.h \
 ../threads/list.h ../machine/interrupt.h ../threads/list.h \
 ../machine/stats.h ../machine/timer.h ../filesys/synchdisk.h \
 ../machine/disk.h ../threads/synch.h ../threads/thread.h
openfile.o: ../filesys/openfile.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../filesys/filehdr.h ../machine/disk.h \
 ../threads/utility.h ../threads/copyright.h ../threads/bool.h \
 ../machine/sysdep.h /usr/include/stdio.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/4.9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../userprog/bitmap.h ../filesys/openfile.h \
 ../filesys/openfile.h ../threads/system.h ../threads/utility.h \
 ../threads/thread.h ../machine/machine.h ../machine/translate.h \
 ../machine/disk.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h ../machine/timer.h \
 ../filesys/synchdisk.h ../threads/synch.h
synchdisk.o: ../filesys/synchdisk.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../filesys/synchdisk.h ../machine/disk.h \
 ../threads/utility.h ../threads/copyright.h ../threads/bool.h \
 ../machine/sysdep.h /usr/include/stdio.h /usr/include/features.h \
 /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h \
 /usr/include/gnu/stubs.h /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/4.9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/synch.h ../threads/thread.h \
 ../threads/utility.h ../machine/machine.h ../machine/translate.h \
 ../machine/disk.h ../userprog/addrspace.h ../filesys/filesys.h \
 ../filesys/openfile.h ../threads/list.h
disk.o: ../machine/disk.cc /usr/include/stdc-predef.h \
 ../threads/copyright.h ../machine/disk.h ../threads/utility.h \
 ../threads/copyright.h ../threads/bool.h ../machine/sysdep.h \
 /usr/include/stdio.h /usr/include/features.h /usr/include/sys/cdefs.h \
 /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h \
 /usr/include/gnu/stubs-32.h \
 /usr/lib/gcc/x86_64-linux-gnu/4.9/include/stddef.h \
 /usr/include/bits/types.h /usr/include/bits/typesizes.h \
 /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h \
 ../threads/stdarg.h /usr/include/bits/stdio_lim.h \
 /usr/include/bits/sys_errlist.h /usr/include/string.h \
 /usr/include/xlocale.h ../threads/system.h ../threads/utility.h \
 ../threads/thread.h ../machine/machine.h ../machine/translate.h \
 ../userprog/addrspace.h ../filesys/filesys.h ../filesys/openfile.h \
 ../threads/scheduler.h ../threads/list.h ../machine/interrupt.h \
 ../threads/list.h ../machine/stats.h ../machine/timer.h \
 ../filesys/synchdisk.h ../machine/disk.h ../threads/synch.h
# DEPENDENCIES MUST END AT END OF FILE
# IF YOU PUT STUFF HERE IT WILL GO AWAY
# see make depend above
