/***************************************************************************************	File:		AGFile.h	Contains:	Public interface to Apple Guide Database Files.				Does not use or require the Apple Guide extension.	Version:	GX 1.2 or later** Copyright 1993-1996 Apple Computer. All rights reserved.****	You may incorporate this sample code into your applications without**	restriction, though the sample code has been provided "AS IS" and the**	responsibility for its operation is 100% yours.  However, what you are**	not permitted to do is to redistribute the source as "DSC Sample Code"**	after having made changes. If you're going to re-distribute the source,**	we require that you make it clear in the source that the code was**	descended from Apple Sample Code, but that you've made changes.***************************************************************************************/#ifndef __AGFILE__#define __AGFILE__#ifndef __FILES__	#include <Files.h>#endif#ifndef __TYPES__	#include <Types.h>#endif			// typedef'stypedef FSSpec AGFileFSSpecType;typedef short AGFileSelectorCountType;typedef short AGFileSelectorIndexType;typedef OSType AGFileSelectorType;typedef long AGFileSelectorValueType;typedef short AGFileDBType;typedef ConstStr63Param AGFileDBMenuNamePtr;typedef short AGFileDBScriptType;typedef short AGFileDBRegionType;typedef short AGFileMajorRevType;typedef short AGFileMinorRevType;typedef short AGFileCountType;			// Database types (for AGFileDBType parameter).enum{	kAGFileDBTypeAny =			0,	kAGFileDBTypeHelp =			1,	kAGFileDBTypeTutorial =		2,	kAGFileDBTypeShortcuts =	3,	kAGFileDBTypeAbout =		4,	kAGFileDBTypeOther =		8};			// Functions.		// Get the database menu item name.pascal OSErrAGFileGetDBMenuName(AGFileFSSpecType *fileSpec,					AGFileDBMenuNamePtr menuItemNameString);		// Get the database type.pascal OSErrAGFileGetDBType(AGFileFSSpecType *fileSpec,				AGFileDBType *databaseType);		// Get the version of the software		// that created this database.pascal OSErrAGFileGetDBVersion(AGFileFSSpecType *fileSpec,					AGFileMajorRevType *majorRev,					AGFileMinorRevType *minorRev);		// Get the database script and region information.pascal OSErrAGFileGetDBCountry(AGFileFSSpecType *fileSpec,					AGFileDBScriptType *script,					AGFileDBRegionType *region);		// Return the number of selectors in database.pascal AGFileSelectorCountTypeAGFileGetSelectorCount(AGFileFSSpecType *fileSpec);		// Get the i-th database selector (1 to AGFileSelectorCountType)		// and its value.pascal OSErrAGFileGetSelector(AGFileFSSpecType *fileSpec,					AGFileSelectorIndexType selectorNumber,					AGFileSelectorType *selector,					AGFileSelectorValueType *value);		// Return true if database is mixin.pascal BooleanAGFileIsMixin(AGFileFSSpecType *fileSpec);		// Return the number of database files		// of the specified databaseType and main/mixin.		// Any file creator is acceptible,		// but type must be kAGFileMain or kAGFileMixin.pascal AGFileCountTypeAGFileGetDBCount(short vRefNum,					long dirID,					AGFileDBType databaseType,					Boolean wantMixin);		// Get the FSSpec for the dbIndex-th database		// of the specified databaseType and main/mixin.		// Any file creator is acceptible,		// but type must be kAGFileMain or kAGFileMixin.pascal OSErrAGFileGetIndDB(short vRefNum,				long dirID,				AGFileDBType databaseType,				Boolean wantMixin,				short dbIndex,				FSSpec *fileSpec);		// This selector must match with the application		// creator in order for this file to appear in the 		// application's Help menu. Ignored for mixin files		// because they never appear in the Help menu anyway.		// If empty (zeros), will appear in the Help menu		// of any host application.pascal OSErrAGFileGetHelpMenuAppCreator(AGFileFSSpecType *fileSpec,								OSType *helpMenuAppCreator);		// This selector must match in the main and mixin		// files in order for the mixin to mix-in with the main.		// Empty (zeros) selectors are valid matches.		// A '****' selector will mix-in with any main.pascal OSErrAGFileGetMixinMatchSelector(AGFileFSSpecType *fileSpec,								OSType *mixinMatchSelector);		// This is the text of the balloon for the		// Help menu item for this database.pascal OSErrAGFileGetHelpMenuBalloonText(AGFileFSSpecType *fileSpec,								Str255 helpMenuBalloonString);#endif /* __AGFILE__ */