// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class APawn;
#ifdef HIDENSNEAKUNREAL_Pickup_generated_h
#error "Pickup.generated.h already included, missing '#pragma once' in Pickup.h"
#endif
#define HIDENSNEAKUNREAL_Pickup_generated_h

#define HideNSneakUnreal_Source_HideNSneakUnreal_Pickup_h_15_SPARSE_DATA
#define HideNSneakUnreal_Source_HideNSneakUnreal_Pickup_h_15_RPC_WRAPPERS \
	virtual void ClientOnPickedUpBy_Implementation(APawn* Pawn); \
	virtual void WasCollected_Implementation(); \
 \
	DECLARE_FUNCTION(execClientOnPickedUpBy); \
	DECLARE_FUNCTION(execOnRep_IsActive); \
	DECLARE_FUNCTION(execPickedUpBy); \
	DECLARE_FUNCTION(execWasCollected); \
	DECLARE_FUNCTION(execSetActive); \
	DECLARE_FUNCTION(execIsActive);


#define HideNSneakUnreal_Source_HideNSneakUnreal_Pickup_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execClientOnPickedUpBy); \
	DECLARE_FUNCTION(execOnRep_IsActive); \
	DECLARE_FUNCTION(execPickedUpBy); \
	DECLARE_FUNCTION(execWasCollected); \
	DECLARE_FUNCTION(execSetActive); \
	DECLARE_FUNCTION(execIsActive);


#define HideNSneakUnreal_Source_HideNSneakUnreal_Pickup_h_15_EVENT_PARMS \
	struct Pickup_eventClientOnPickedUpBy_Parms \
	{ \
		APawn* Pawn; \
	};


#define HideNSneakUnreal_Source_HideNSneakUnreal_Pickup_h_15_CALLBACK_WRAPPERS
#define HideNSneakUnreal_Source_HideNSneakUnreal_Pickup_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPickup(); \
	friend struct Z_Construct_UClass_APickup_Statics; \
public: \
	DECLARE_CLASS(APickup, AStaticMeshActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/HideNSneakUnreal"), NO_API) \
	DECLARE_SERIALIZER(APickup) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		bIsActive=NETFIELD_REP_START, \
		NETFIELD_REP_END=bIsActive	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define HideNSneakUnreal_Source_HideNSneakUnreal_Pickup_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAPickup(); \
	friend struct Z_Construct_UClass_APickup_Statics; \
public: \
	DECLARE_CLASS(APickup, AStaticMeshActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/HideNSneakUnreal"), NO_API) \
	DECLARE_SERIALIZER(APickup) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		bIsActive=NETFIELD_REP_START, \
		NETFIELD_REP_END=bIsActive	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define HideNSneakUnreal_Source_HideNSneakUnreal_Pickup_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APickup(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APickup) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APickup); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APickup); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APickup(APickup&&); \
	NO_API APickup(const APickup&); \
public:


#define HideNSneakUnreal_Source_HideNSneakUnreal_Pickup_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APickup(APickup&&); \
	NO_API APickup(const APickup&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APickup); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APickup); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APickup)


#define HideNSneakUnreal_Source_HideNSneakUnreal_Pickup_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__bIsActive() { return STRUCT_OFFSET(APickup, bIsActive); } \
	FORCEINLINE static uint32 __PPO__PickupInstigator() { return STRUCT_OFFSET(APickup, PickupInstigator); }


#define HideNSneakUnreal_Source_HideNSneakUnreal_Pickup_h_12_PROLOG \
	HideNSneakUnreal_Source_HideNSneakUnreal_Pickup_h_15_EVENT_PARMS


#define HideNSneakUnreal_Source_HideNSneakUnreal_Pickup_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HideNSneakUnreal_Source_HideNSneakUnreal_Pickup_h_15_PRIVATE_PROPERTY_OFFSET \
	HideNSneakUnreal_Source_HideNSneakUnreal_Pickup_h_15_SPARSE_DATA \
	HideNSneakUnreal_Source_HideNSneakUnreal_Pickup_h_15_RPC_WRAPPERS \
	HideNSneakUnreal_Source_HideNSneakUnreal_Pickup_h_15_CALLBACK_WRAPPERS \
	HideNSneakUnreal_Source_HideNSneakUnreal_Pickup_h_15_INCLASS \
	HideNSneakUnreal_Source_HideNSneakUnreal_Pickup_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define HideNSneakUnreal_Source_HideNSneakUnreal_Pickup_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HideNSneakUnreal_Source_HideNSneakUnreal_Pickup_h_15_PRIVATE_PROPERTY_OFFSET \
	HideNSneakUnreal_Source_HideNSneakUnreal_Pickup_h_15_SPARSE_DATA \
	HideNSneakUnreal_Source_HideNSneakUnreal_Pickup_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	HideNSneakUnreal_Source_HideNSneakUnreal_Pickup_h_15_CALLBACK_WRAPPERS \
	HideNSneakUnreal_Source_HideNSneakUnreal_Pickup_h_15_INCLASS_NO_PURE_DECLS \
	HideNSneakUnreal_Source_HideNSneakUnreal_Pickup_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> HIDENSNEAKUNREAL_API UClass* StaticClass<class APickup>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID HideNSneakUnreal_Source_HideNSneakUnreal_Pickup_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
