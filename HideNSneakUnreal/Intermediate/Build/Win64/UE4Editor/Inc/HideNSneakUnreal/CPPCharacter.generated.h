// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef HIDENSNEAKUNREAL_CPPCharacter_generated_h
#error "CPPCharacter.generated.h already included, missing '#pragma once' in CPPCharacter.h"
#endif
#define HIDENSNEAKUNREAL_CPPCharacter_generated_h

#define HideNSneakUnreal_Source_HideNSneakUnreal_CPPCharacter_h_12_SPARSE_DATA
#define HideNSneakUnreal_Source_HideNSneakUnreal_CPPCharacter_h_12_RPC_WRAPPERS \
	virtual bool ServerCollectPickups_Validate(); \
	virtual void ServerCollectPickups_Implementation(); \
 \
	DECLARE_FUNCTION(execOnRep_CurrentPower); \
	DECLARE_FUNCTION(execUpdatePower); \
	DECLARE_FUNCTION(execGetCurrentPower); \
	DECLARE_FUNCTION(execGetInitialPower); \
	DECLARE_FUNCTION(execServerCollectPickups); \
	DECLARE_FUNCTION(execCollectPickups);


#define HideNSneakUnreal_Source_HideNSneakUnreal_CPPCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnRep_CurrentPower); \
	DECLARE_FUNCTION(execUpdatePower); \
	DECLARE_FUNCTION(execGetCurrentPower); \
	DECLARE_FUNCTION(execGetInitialPower); \
	DECLARE_FUNCTION(execServerCollectPickups); \
	DECLARE_FUNCTION(execCollectPickups);


#define HideNSneakUnreal_Source_HideNSneakUnreal_CPPCharacter_h_12_EVENT_PARMS
#define HideNSneakUnreal_Source_HideNSneakUnreal_CPPCharacter_h_12_CALLBACK_WRAPPERS
#define HideNSneakUnreal_Source_HideNSneakUnreal_CPPCharacter_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACPPCharacter(); \
	friend struct Z_Construct_UClass_ACPPCharacter_Statics; \
public: \
	DECLARE_CLASS(ACPPCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/HideNSneakUnreal"), NO_API) \
	DECLARE_SERIALIZER(ACPPCharacter) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		CollectionSphereRadius=NETFIELD_REP_START, \
		InitialPower, \
		CurrentPower, \
		NETFIELD_REP_END=CurrentPower	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define HideNSneakUnreal_Source_HideNSneakUnreal_CPPCharacter_h_12_INCLASS \
private: \
	static void StaticRegisterNativesACPPCharacter(); \
	friend struct Z_Construct_UClass_ACPPCharacter_Statics; \
public: \
	DECLARE_CLASS(ACPPCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/HideNSneakUnreal"), NO_API) \
	DECLARE_SERIALIZER(ACPPCharacter) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		CollectionSphereRadius=NETFIELD_REP_START, \
		InitialPower, \
		CurrentPower, \
		NETFIELD_REP_END=CurrentPower	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define HideNSneakUnreal_Source_HideNSneakUnreal_CPPCharacter_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ACPPCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ACPPCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACPPCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACPPCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACPPCharacter(ACPPCharacter&&); \
	NO_API ACPPCharacter(const ACPPCharacter&); \
public:


#define HideNSneakUnreal_Source_HideNSneakUnreal_CPPCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACPPCharacter(ACPPCharacter&&); \
	NO_API ACPPCharacter(const ACPPCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACPPCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACPPCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACPPCharacter)


#define HideNSneakUnreal_Source_HideNSneakUnreal_CPPCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(ACPPCharacter, CameraBoom); } \
	FORCEINLINE static uint32 __PPO__FollowCamera() { return STRUCT_OFFSET(ACPPCharacter, FollowCamera); } \
	FORCEINLINE static uint32 __PPO__CollectionSphere() { return STRUCT_OFFSET(ACPPCharacter, CollectionSphere); } \
	FORCEINLINE static uint32 __PPO__CollectionSphereRadius() { return STRUCT_OFFSET(ACPPCharacter, CollectionSphereRadius); } \
	FORCEINLINE static uint32 __PPO__InitialPower() { return STRUCT_OFFSET(ACPPCharacter, InitialPower); } \
	FORCEINLINE static uint32 __PPO__BaseSpeed() { return STRUCT_OFFSET(ACPPCharacter, BaseSpeed); } \
	FORCEINLINE static uint32 __PPO__SpeedFactor() { return STRUCT_OFFSET(ACPPCharacter, SpeedFactor); } \
	FORCEINLINE static uint32 __PPO__CurrentPower() { return STRUCT_OFFSET(ACPPCharacter, CurrentPower); }


#define HideNSneakUnreal_Source_HideNSneakUnreal_CPPCharacter_h_9_PROLOG \
	HideNSneakUnreal_Source_HideNSneakUnreal_CPPCharacter_h_12_EVENT_PARMS


#define HideNSneakUnreal_Source_HideNSneakUnreal_CPPCharacter_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HideNSneakUnreal_Source_HideNSneakUnreal_CPPCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	HideNSneakUnreal_Source_HideNSneakUnreal_CPPCharacter_h_12_SPARSE_DATA \
	HideNSneakUnreal_Source_HideNSneakUnreal_CPPCharacter_h_12_RPC_WRAPPERS \
	HideNSneakUnreal_Source_HideNSneakUnreal_CPPCharacter_h_12_CALLBACK_WRAPPERS \
	HideNSneakUnreal_Source_HideNSneakUnreal_CPPCharacter_h_12_INCLASS \
	HideNSneakUnreal_Source_HideNSneakUnreal_CPPCharacter_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define HideNSneakUnreal_Source_HideNSneakUnreal_CPPCharacter_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HideNSneakUnreal_Source_HideNSneakUnreal_CPPCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	HideNSneakUnreal_Source_HideNSneakUnreal_CPPCharacter_h_12_SPARSE_DATA \
	HideNSneakUnreal_Source_HideNSneakUnreal_CPPCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	HideNSneakUnreal_Source_HideNSneakUnreal_CPPCharacter_h_12_CALLBACK_WRAPPERS \
	HideNSneakUnreal_Source_HideNSneakUnreal_CPPCharacter_h_12_INCLASS_NO_PURE_DECLS \
	HideNSneakUnreal_Source_HideNSneakUnreal_CPPCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> HIDENSNEAKUNREAL_API UClass* StaticClass<class ACPPCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID HideNSneakUnreal_Source_HideNSneakUnreal_CPPCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
