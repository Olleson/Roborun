// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AHideNSneakCPPCharacter;
class UPrimitiveComponent;
class AActor;
struct FVector;
struct FHitResult;
#ifdef HIDENSNEAKUNREAL_HideNSneakCPPCharacter_generated_h
#error "HideNSneakCPPCharacter.generated.h already included, missing '#pragma once' in HideNSneakCPPCharacter.h"
#endif
#define HIDENSNEAKUNREAL_HideNSneakCPPCharacter_generated_h

#define HideNSneakUnreal_Source_HideNSneakUnreal_HideNSneakCPPCharacter_h_12_SPARSE_DATA
#define HideNSneakUnreal_Source_HideNSneakUnreal_HideNSneakCPPCharacter_h_12_RPC_WRAPPERS \
	virtual void ServerCaptureHider_Implementation(AHideNSneakCPPCharacter* Hider); \
	virtual void BecomeSeeker_Implementation(); \
 \
	DECLARE_FUNCTION(execIsSeeker); \
	DECLARE_FUNCTION(execServerCaptureHider); \
	DECLARE_FUNCTION(execCaptureHiders); \
	DECLARE_FUNCTION(execOnCompHit); \
	DECLARE_FUNCTION(execTurnIntoSeeker); \
	DECLARE_FUNCTION(execBecomeSeeker);


#define HideNSneakUnreal_Source_HideNSneakUnreal_HideNSneakCPPCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execIsSeeker); \
	DECLARE_FUNCTION(execServerCaptureHider); \
	DECLARE_FUNCTION(execCaptureHiders); \
	DECLARE_FUNCTION(execOnCompHit); \
	DECLARE_FUNCTION(execTurnIntoSeeker); \
	DECLARE_FUNCTION(execBecomeSeeker);


#define HideNSneakUnreal_Source_HideNSneakUnreal_HideNSneakCPPCharacter_h_12_EVENT_PARMS \
	struct HideNSneakCPPCharacter_eventServerCaptureHider_Parms \
	{ \
		AHideNSneakCPPCharacter* Hider; \
	};


#define HideNSneakUnreal_Source_HideNSneakUnreal_HideNSneakCPPCharacter_h_12_CALLBACK_WRAPPERS
#define HideNSneakUnreal_Source_HideNSneakUnreal_HideNSneakCPPCharacter_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAHideNSneakCPPCharacter(); \
	friend struct Z_Construct_UClass_AHideNSneakCPPCharacter_Statics; \
public: \
	DECLARE_CLASS(AHideNSneakCPPCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/HideNSneakUnreal"), NO_API) \
	DECLARE_SERIALIZER(AHideNSneakCPPCharacter) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		CaptureSphereRadius=NETFIELD_REP_START, \
		bIsSeeker, \
		NETFIELD_REP_END=bIsSeeker	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define HideNSneakUnreal_Source_HideNSneakUnreal_HideNSneakCPPCharacter_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAHideNSneakCPPCharacter(); \
	friend struct Z_Construct_UClass_AHideNSneakCPPCharacter_Statics; \
public: \
	DECLARE_CLASS(AHideNSneakCPPCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/HideNSneakUnreal"), NO_API) \
	DECLARE_SERIALIZER(AHideNSneakCPPCharacter) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		CaptureSphereRadius=NETFIELD_REP_START, \
		bIsSeeker, \
		NETFIELD_REP_END=bIsSeeker	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define HideNSneakUnreal_Source_HideNSneakUnreal_HideNSneakCPPCharacter_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AHideNSneakCPPCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AHideNSneakCPPCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AHideNSneakCPPCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AHideNSneakCPPCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AHideNSneakCPPCharacter(AHideNSneakCPPCharacter&&); \
	NO_API AHideNSneakCPPCharacter(const AHideNSneakCPPCharacter&); \
public:


#define HideNSneakUnreal_Source_HideNSneakUnreal_HideNSneakCPPCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AHideNSneakCPPCharacter(AHideNSneakCPPCharacter&&); \
	NO_API AHideNSneakCPPCharacter(const AHideNSneakCPPCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AHideNSneakCPPCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AHideNSneakCPPCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AHideNSneakCPPCharacter)


#define HideNSneakUnreal_Source_HideNSneakUnreal_HideNSneakCPPCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(AHideNSneakCPPCharacter, CameraBoom); } \
	FORCEINLINE static uint32 __PPO__FollowCamera() { return STRUCT_OFFSET(AHideNSneakCPPCharacter, FollowCamera); } \
	FORCEINLINE static uint32 __PPO__CaptureSphere() { return STRUCT_OFFSET(AHideNSneakCPPCharacter, CaptureSphere); } \
	FORCEINLINE static uint32 __PPO__CaptureSphereRadius() { return STRUCT_OFFSET(AHideNSneakCPPCharacter, CaptureSphereRadius); } \
	FORCEINLINE static uint32 __PPO__bIsSeeker() { return STRUCT_OFFSET(AHideNSneakCPPCharacter, bIsSeeker); } \
	FORCEINLINE static uint32 __PPO__BaseSpeed() { return STRUCT_OFFSET(AHideNSneakCPPCharacter, BaseSpeed); } \
	FORCEINLINE static uint32 __PPO__SpeedFactor() { return STRUCT_OFFSET(AHideNSneakCPPCharacter, SpeedFactor); }


#define HideNSneakUnreal_Source_HideNSneakUnreal_HideNSneakCPPCharacter_h_9_PROLOG \
	HideNSneakUnreal_Source_HideNSneakUnreal_HideNSneakCPPCharacter_h_12_EVENT_PARMS


#define HideNSneakUnreal_Source_HideNSneakUnreal_HideNSneakCPPCharacter_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HideNSneakUnreal_Source_HideNSneakUnreal_HideNSneakCPPCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	HideNSneakUnreal_Source_HideNSneakUnreal_HideNSneakCPPCharacter_h_12_SPARSE_DATA \
	HideNSneakUnreal_Source_HideNSneakUnreal_HideNSneakCPPCharacter_h_12_RPC_WRAPPERS \
	HideNSneakUnreal_Source_HideNSneakUnreal_HideNSneakCPPCharacter_h_12_CALLBACK_WRAPPERS \
	HideNSneakUnreal_Source_HideNSneakUnreal_HideNSneakCPPCharacter_h_12_INCLASS \
	HideNSneakUnreal_Source_HideNSneakUnreal_HideNSneakCPPCharacter_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define HideNSneakUnreal_Source_HideNSneakUnreal_HideNSneakCPPCharacter_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HideNSneakUnreal_Source_HideNSneakUnreal_HideNSneakCPPCharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	HideNSneakUnreal_Source_HideNSneakUnreal_HideNSneakCPPCharacter_h_12_SPARSE_DATA \
	HideNSneakUnreal_Source_HideNSneakUnreal_HideNSneakCPPCharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	HideNSneakUnreal_Source_HideNSneakUnreal_HideNSneakCPPCharacter_h_12_CALLBACK_WRAPPERS \
	HideNSneakUnreal_Source_HideNSneakUnreal_HideNSneakCPPCharacter_h_12_INCLASS_NO_PURE_DECLS \
	HideNSneakUnreal_Source_HideNSneakUnreal_HideNSneakCPPCharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> HIDENSNEAKUNREAL_API UClass* StaticClass<class AHideNSneakCPPCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID HideNSneakUnreal_Source_HideNSneakUnreal_HideNSneakCPPCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
