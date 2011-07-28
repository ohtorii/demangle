#include <windows.h>
#include<imagehlp.h>
#include"demangle.h"
#include"cp-demangle.h"
#include<stdio.h>
#include<malloc.h>
#include<string>
#include<iostream>



static bool DeMangleWin(const char*symbol){
	static char buf[1024*2];
	bool		result = false;
	
	buf[0] = 0;
	if(UnDecorateSymbolName(symbol,buf,sizeof(buf),UNDNAME_COMPLETE)){
		std::cout << buf << "\n";
		result=true;
	}else{
		//std::cout << "Failed: " << symbol << "\n";
	}	
	return result;
}


static bool DeMangleGCC( const char *symbol ) {
	bool	result	= false;
	int		options = DMGL_PARAMS | DMGL_ANSI | DMGL_TYPES;
    char	*s		= 0;

#ifdef IN_GLIBCPP_V3
    int status=0;
#endif

    /* Attempt to demangle.  */
#ifdef IN_GLIBCPP_V3
    s = __cxa_demangle ( argv[i], NULL, NULL, &status );
#else
    s = cplus_demangle_v3 ( symbol, options );
#endif

    /* If it worked, print the demangled name.  */
    if ( s != NULL ) {
        std::cout << s << "\n";
        free ( s );
		result=true;
    } else {
#ifdef IN_GLIBCPP_V3
        //std::cout << "Failed: "<< symbol << "(status " << status << ")\n";			
#else
        //std::cout << "Failed: " << symbol << "\n";
#endif
    }
	return result;
}

static bool DeMangle(const char*symbol){
	bool result=false;
	if(! DeMangleGCC(symbol)){
		if(! DeMangleWin(symbol)){
			std::cout << "Failed: " << symbol << "\n";
			result=true;
		}
	}
	return result;
}

int main ( int argc, char *argv[] ) {
	if(1 < argc){
	    for ( int i = 1; i < argc; ++i ) {
			DeMangle(argv[i]);				
	    }
	}else{
		std::string tmp;		
		while(! std::cin.eof()){
			std::getline(std::cin, tmp);
			DeMangle(tmp.c_str());
		}
	}
    
    return 0;
}

