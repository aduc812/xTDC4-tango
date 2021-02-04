#PROTECTED REGION ID(Makefile) ENABLED START#
# COMPILED WITH VISUAL STUDIO 2013(VC12)
HEADER = XTDC4.h XTDC4Class.h

COPTS = /Od /I "." /I "C:\Program Files\tango\win64\include\vc12" \
/I "C:\Program Files\cronologic\xTDC4\driver\include" \
/D "WIN32" /D "_WINSTATIC" /EHsc /RTC1 /MTd /W3 /nologo /c /TP

LDOPTS = /OUT:"XTDC4.exe"\
/LIBPATH:"C:\Program Files\tango\win64\lib\vc12" \
/LIBPATH:"C:\Program Files\cronologic\xTDC4\driver\x64" \
/ERRORREPORT:PROMPT tangod.lib log4tangod.lib COS4d.lib omniDynamic4d.lib \
omniORB4d.lib omnithreadd.lib zmqd.lib mswsock.lib ws2_32.lib comctl32.lib odbc32.lib \
odbccp32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib \
advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib kernel32.lib xtdc4_driver_64.lib

OBJS = ClassFactory.obj main.obj XTDC4.obj XTDC4Class.obj XTDC4StateMachine.obj

XTDC4.exe: $(OBJS) 
	link $(LDOPTS) $(OBJS)

main.obj: main.cpp $(HEADER)
	cl $(COPTS) main.cpp

ClassFactory.obj: ClassFactory.cpp $(HEADER)
	cl $(COPTS) ClassFactory.cpp

XTDC4.obj: XTDC4.cpp $(HEADER)
	cl $(COPTS) XTDC4.cpp

XTDC4Class.obj: XTDC4Class.cpp $(HEADER)
	cl $(COPTS) XTDC4Class.cpp

XTDC4StateMachine.obj: XTDC4StateMachine.cpp $(HEADER)
	cl $(COPTS) XTDC4StateMachine.cpp
	
# MonitorThread.obj: MonitorThread.cpp $(HEADER)
# 	cl $(COPTS) MonitorThread.cpp

CommThread.obj: CommThread.cpp $(HEADER)
	cl $(COPTS) CommThread.cpp
	

clean:
	del /Q $(OBJS)
	del /Q XTDC4.exe
	
MAJOR_VERS = 1
MINOR_VERS = 0
RELEASE    = Release_$(MAJOR_VERS)_$(MINOR_VERS)

#tag:
#ifeq ($(shell ls -d ../tags/$(RELEASE) 2>/dev/null ), ../tags/$(RELEASE))
#	@echo $(RELEASE) exists, specify new version numbers
#else
#	svn copy ../trunk ../tags/$(RELEASE)
#	svn commit ../tags/$(RELEASE) \
#	-m "Tagging the $(RELEASE) of the $(CLASS) project."
#endif#PROTECTED REGION END#

