#include "al2o3_platform/platform.h"
#include "al2o3_memory/memory.h"
#include "nfd.h"
#include "utils_nativefiledialogs/dialogs.h"

AL2O3_EXTERN_C bool NativeFileDialogs_Load(char const *filterList,
																					 char const *defaultPath,
																					 char **outPath) {
	nfdresult_t result = NFD_OpenDialog( filterList,defaultPath, outPath );
	if(result == NFD_ERROR) {
		LOGERROR(NFD_GetError());
		return false;
	}
	if(result == NFD_CANCEL) {
		MEMORY_FREE(outPath);
		*outPath = NULL;
	}

	return true;
}

AL2O3_EXTERN_C NativeFileDialogs_PathSetHandle NativeFileDialogs_LoadMultiple(char const *filterList,
																									 char const *defaultPath) {
	nfdpathset_t* pathSet = MEMORY_MALLOC(sizeof(nfdpathset_t));

	nfdresult_t result = NFD_OpenDialogMultiple( filterList,defaultPath, pathSet );
	if(result != NFD_OKAY) {
		if(result == NFD_ERROR) {
			LOGERROR(NFD_GetError());
		}
		MEMORY_FREE(pathSet);
		return NULL;
	}

	return (NativeFileDialogs_PathSetHandle)pathSet;

}
AL2O3_EXTERN_C void NativeFileDialogs_DestroyPathSet(NativeFileDialogs_PathSetHandle handle) {
	MEMORY_FREE(handle);
}

AL2O3_EXTERN_C bool NativeFileDialogs_Save(char const  *filterList,
																					 char const *defaultPath,
																					 char **outPath) {
	nfdresult_t result = NFD_SaveDialog( filterList,defaultPath, outPath );
	if(result == NFD_ERROR) {
		LOGERROR(NFD_GetError());
		return false;
	}
	if(result == NFD_CANCEL) {
		MEMORY_FREE(outPath);
		*outPath = NULL;
	}

	return true;

}

AL2O3_EXTERN_C bool NativeFileDialogs_PickFolder(char const *defaultPath,
																								 char **outPath) {
	nfdresult_t result = NFD_PickFolder(defaultPath, outPath );
	if(result == NFD_ERROR) {
		LOGERROR(NFD_GetError());
		return false;
	}
	if(result == NFD_CANCEL) {
		MEMORY_FREE(outPath);
		*outPath = NULL;
	}

	return true;
}


