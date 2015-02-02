// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the SHOP_LIB_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// SHOP_LIB_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef SHOP_LIB_EXPORTS
#define SHOP_LIB_API __declspec(dllexport)
#else
#define SHOP_LIB_API __declspec(dllimport)
#endif

// This class is exported from the Shop_Lib.dll
class SHOP_LIB_API CShop_Lib {
public:
	CShop_Lib(void);
	// TODO: add your methods here.
};

extern SHOP_LIB_API int nShop_Lib;

SHOP_LIB_API int fnShop_Lib(void);
