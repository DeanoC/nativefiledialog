#pragma once
#ifndef UTILS_NATIVEFILEDIALOGS_DIALOGS_H_
#define UTILS_NATIVEFILEDIALOGS_DIALOGS_H_

#include "al2o3_platform/platform.h"

typedef struct NativeFileDialogs_PathSet *NativeFileDialogs_PathSetHandle;

AL2O3_EXTERN_C bool NativeFileDialogs_Load(char const *filterList,
																					 char const *defaultPath,
																					 char **outPath);

AL2O3_EXTERN_C NativeFileDialogs_PathSetHandle NativeFileDialogs_LoadMultiple(char const *filterList,	char const *defaultPath);
AL2O3_EXTERN_C void NativeFileDialogs_DestroyPathSet(NativeFileDialogs_PathSetHandle handle);

AL2O3_EXTERN_C bool NativeFileDialogs_Save(char const *filterList,
																					 char const *defaultPath,
																					 char **outPath);

AL2O3_EXTERN_C bool NativeFileDialogs_PickFolder(char const *defaultPath,
																								 char **outPath);

#endif
