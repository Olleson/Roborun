// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FVector;
#ifdef HIDENSNEAKUNREAL_SpawnVolume_generated_h
#error "SpawnVolume.generated.h already included, missing '#pragma once' in SpawnVolume.h"
#endif
#define HIDENSNEAKUNREAL_SpawnVolume_generated_h

#define HideNSneakUnreal_Source_HideNSneakUnreal_SpawnVolume_h_13_SPARSE_DATA
#define HideNSneakUnreal_Source_HideNSneakUnreal_SpawnVolume_h_13_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetRandomPointInVolume);


#define HideNSneakUnreal_Source_HideNSneakUnreal_SpawnVolume_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetRandomPointInVolume);


#define HideNSneakUnreal_Source_HideNSneakUnreal_SpawnVolume_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASpawnVolume(); \
	friend struct Z_Construct_UClass_ASpawnVolume_Statics; \
public: \
	DECLARE_CLASS(ASpawnVolume, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/HideNSneakUnreal"), NO_API) \
	DECLARE_SERIALIZER(ASpawnVolume)


#define HideNSneakUnreal_Source_HideNSneakUnreal_SpawnVolume_h_13_INCLASS \
private: \
	static void StaticRegisterNativesASpawnVolume(); \
	friend struct Z_Construct_UClass_ASpawnVolume_Statics; \
public: \
	DECLARE_CLASS(ASpawnVolume, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/HideNSneakUnreal"), NO_API) \
	DECLARE_SERIALIZER(ASpawnVolume)


#define HideNSneakUnreal_Source_HideNSneakUnreal_SpawnVolume_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASpawnVolume(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASpawnVolume) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASpawnVolume); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASpawnVolume); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASpawnVolume(ASpawnVolume&&); \
	NO_API ASpawnVolume(const ASpawnVolume&); \
public:


#define HideNSneakUnreal_Source_HideNSneakUnreal_SpawnVolume_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASpawnVolume(ASpawnVolume&&); \
	NO_API ASpawnVolume(const ASpawnVolume&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASpawnVolume); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASpawnVolume); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASpawnVolume)


#define HideNSneakUnreal_Source_HideNSneakUnreal_SpawnVolume_h_13_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__WhatToSpawn() { return STRUCT_OFFSET(ASpawnVolume, WhatToSpawn); } \
	FORCEINLINE static uint32 __PPO__MaxSpawnDelay() { return STRUCT_OFFSET(ASpawnVolume, MaxSpawnDelay); } \
	FORCEINLINE static uint32 __PPO__MinSpawnDelay() { return STRUCT_OFFSET(ASpawnVolume, MinSpawnDelay); } \
	FORCEINLINE static uint32 __PPO__WhereToSpawn() { return STRUCT_OFFSET(ASpawnVolume, WhereToSpawn); }


#define HideNSneakUnreal_Source_HideNSneakUnreal_SpawnVolume_h_10_PROLOG
#define HideNSneakUnreal_Source_HideNSneakUnreal_SpawnVolume_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HideNSneakUnreal_Source_HideNSneakUnreal_SpawnVolume_h_13_PRIVATE_PROPERTY_OFFSET \
	HideNSneakUnreal_Source_HideNSneakUnreal_SpawnVolume_h_13_SPARSE_DATA \
	HideNSneakUnreal_Source_HideNSneakUnreal_SpawnVolume_h_13_RPC_WRAPPERS \
	HideNSneakUnreal_Source_HideNSneakUnreal_SpawnVolume_h_13_INCLASS \
	HideNSneakUnreal_Source_HideNSneakUnreal_SpawnVolume_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define HideNSneakUnreal_Source_HideNSneakUnreal_SpawnVolume_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HideNSneakUnreal_Source_HideNSneakUnreal_SpawnVolume_h_13_PRIVATE_PROPERTY_OFFSET \
	HideNSneakUnreal_Source_HideNSneakUnreal_SpawnVolume_h_13_SPARSE_DATA \
	HideNSneakUnreal_Source_HideNSneakUnreal_SpawnVolume_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	HideNSneakUnreal_Source_HideNSneakUnreal_SpawnVolume_h_13_INCLASS_NO_PURE_DECLS \
	HideNSneakUnreal_Source_HideNSneakUnreal_SpawnVolume_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> HIDENSNEAKUNREAL_API UClass* StaticClass<class ASpawnVolume>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID HideNSneakUnreal_Source_HideNSneakUnreal_SpawnVolume_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
