// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef HIDENSNEAKUNREAL_BatteryPickup_generated_h
#error "BatteryPickup.generated.h already included, missing '#pragma once' in BatteryPickup.h"
#endif
#define HIDENSNEAKUNREAL_BatteryPickup_generated_h

#define HideNSneakUnreal_Source_HideNSneakUnreal_BatteryPickup_h_15_SPARSE_DATA
#define HideNSneakUnreal_Source_HideNSneakUnreal_BatteryPickup_h_15_RPC_WRAPPERS
#define HideNSneakUnreal_Source_HideNSneakUnreal_BatteryPickup_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define HideNSneakUnreal_Source_HideNSneakUnreal_BatteryPickup_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABatteryPickup(); \
	friend struct Z_Construct_UClass_ABatteryPickup_Statics; \
public: \
	DECLARE_CLASS(ABatteryPickup, APickup, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/HideNSneakUnreal"), NO_API) \
	DECLARE_SERIALIZER(ABatteryPickup) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		BatteryPower=NETFIELD_REP_START, \
		NETFIELD_REP_END=BatteryPower	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define HideNSneakUnreal_Source_HideNSneakUnreal_BatteryPickup_h_15_INCLASS \
private: \
	static void StaticRegisterNativesABatteryPickup(); \
	friend struct Z_Construct_UClass_ABatteryPickup_Statics; \
public: \
	DECLARE_CLASS(ABatteryPickup, APickup, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/HideNSneakUnreal"), NO_API) \
	DECLARE_SERIALIZER(ABatteryPickup) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		BatteryPower=NETFIELD_REP_START, \
		NETFIELD_REP_END=BatteryPower	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define HideNSneakUnreal_Source_HideNSneakUnreal_BatteryPickup_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ABatteryPickup(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ABatteryPickup) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABatteryPickup); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABatteryPickup); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABatteryPickup(ABatteryPickup&&); \
	NO_API ABatteryPickup(const ABatteryPickup&); \
public:


#define HideNSneakUnreal_Source_HideNSneakUnreal_BatteryPickup_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABatteryPickup(ABatteryPickup&&); \
	NO_API ABatteryPickup(const ABatteryPickup&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABatteryPickup); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABatteryPickup); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABatteryPickup)


#define HideNSneakUnreal_Source_HideNSneakUnreal_BatteryPickup_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__BatteryPower() { return STRUCT_OFFSET(ABatteryPickup, BatteryPower); }


#define HideNSneakUnreal_Source_HideNSneakUnreal_BatteryPickup_h_12_PROLOG
#define HideNSneakUnreal_Source_HideNSneakUnreal_BatteryPickup_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HideNSneakUnreal_Source_HideNSneakUnreal_BatteryPickup_h_15_PRIVATE_PROPERTY_OFFSET \
	HideNSneakUnreal_Source_HideNSneakUnreal_BatteryPickup_h_15_SPARSE_DATA \
	HideNSneakUnreal_Source_HideNSneakUnreal_BatteryPickup_h_15_RPC_WRAPPERS \
	HideNSneakUnreal_Source_HideNSneakUnreal_BatteryPickup_h_15_INCLASS \
	HideNSneakUnreal_Source_HideNSneakUnreal_BatteryPickup_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define HideNSneakUnreal_Source_HideNSneakUnreal_BatteryPickup_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HideNSneakUnreal_Source_HideNSneakUnreal_BatteryPickup_h_15_PRIVATE_PROPERTY_OFFSET \
	HideNSneakUnreal_Source_HideNSneakUnreal_BatteryPickup_h_15_SPARSE_DATA \
	HideNSneakUnreal_Source_HideNSneakUnreal_BatteryPickup_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	HideNSneakUnreal_Source_HideNSneakUnreal_BatteryPickup_h_15_INCLASS_NO_PURE_DECLS \
	HideNSneakUnreal_Source_HideNSneakUnreal_BatteryPickup_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> HIDENSNEAKUNREAL_API UClass* StaticClass<class ABatteryPickup>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID HideNSneakUnreal_Source_HideNSneakUnreal_BatteryPickup_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
