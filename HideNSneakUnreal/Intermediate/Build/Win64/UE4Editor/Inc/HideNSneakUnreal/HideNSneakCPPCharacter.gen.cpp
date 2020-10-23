// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HideNSneakUnreal/HideNSneakCPPCharacter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHideNSneakCPPCharacter() {}
// Cross Module References
	HIDENSNEAKUNREAL_API UClass* Z_Construct_UClass_AHideNSneakCPPCharacter_NoRegister();
	HIDENSNEAKUNREAL_API UClass* Z_Construct_UClass_AHideNSneakCPPCharacter();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_HideNSneakUnreal();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USphereComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(AHideNSneakCPPCharacter::execIsSeeker)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsSeeker();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AHideNSneakCPPCharacter::execServerCaptureHider)
	{
		P_GET_OBJECT(AHideNSneakCPPCharacter,Z_Param_Hider);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ServerCaptureHider_Implementation(Z_Param_Hider);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AHideNSneakCPPCharacter::execCaptureHiders)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CaptureHiders();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AHideNSneakCPPCharacter::execOnCompHit)
	{
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComp);
		P_GET_OBJECT(AActor,Z_Param_OtherActor);
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp);
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse);
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnCompHit(Z_Param_HitComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_NormalImpulse,Z_Param_Out_Hit);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AHideNSneakCPPCharacter::execTurnIntoSeeker)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->TurnIntoSeeker();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AHideNSneakCPPCharacter::execBecomeSeeker)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BecomeSeeker_Implementation();
		P_NATIVE_END;
	}
	static FName NAME_AHideNSneakCPPCharacter_BecomeSeeker = FName(TEXT("BecomeSeeker"));
	void AHideNSneakCPPCharacter::BecomeSeeker()
	{
		ProcessEvent(FindFunctionChecked(NAME_AHideNSneakCPPCharacter_BecomeSeeker),NULL);
	}
	static FName NAME_AHideNSneakCPPCharacter_OnRep_IsSeeker = FName(TEXT("OnRep_IsSeeker"));
	void AHideNSneakCPPCharacter::OnRep_IsSeeker()
	{
		ProcessEvent(FindFunctionChecked(NAME_AHideNSneakCPPCharacter_OnRep_IsSeeker),NULL);
	}
	static FName NAME_AHideNSneakCPPCharacter_ServerCaptureHider = FName(TEXT("ServerCaptureHider"));
	void AHideNSneakCPPCharacter::ServerCaptureHider(AHideNSneakCPPCharacter* Hider)
	{
		HideNSneakCPPCharacter_eventServerCaptureHider_Parms Parms;
		Parms.Hider=Hider;
		ProcessEvent(FindFunctionChecked(NAME_AHideNSneakCPPCharacter_ServerCaptureHider),&Parms);
	}
	void AHideNSneakCPPCharacter::StaticRegisterNativesAHideNSneakCPPCharacter()
	{
		UClass* Class = AHideNSneakCPPCharacter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "BecomeSeeker", &AHideNSneakCPPCharacter::execBecomeSeeker },
			{ "CaptureHiders", &AHideNSneakCPPCharacter::execCaptureHiders },
			{ "IsSeeker", &AHideNSneakCPPCharacter::execIsSeeker },
			{ "OnCompHit", &AHideNSneakCPPCharacter::execOnCompHit },
			{ "ServerCaptureHider", &AHideNSneakCPPCharacter::execServerCaptureHider },
			{ "TurnIntoSeeker", &AHideNSneakCPPCharacter::execTurnIntoSeeker },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AHideNSneakCPPCharacter_BecomeSeeker_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AHideNSneakCPPCharacter_BecomeSeeker_Statics::Function_MetaDataParams[] = {
		{ "Category", "Seeker" },
		{ "Comment", "// Turns a hider into a seeker\n" },
		{ "ModuleRelativePath", "HideNSneakCPPCharacter.h" },
		{ "ToolTip", "Turns a hider into a seeker" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AHideNSneakCPPCharacter_BecomeSeeker_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AHideNSneakCPPCharacter, nullptr, "BecomeSeeker", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04024CC0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AHideNSneakCPPCharacter_BecomeSeeker_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AHideNSneakCPPCharacter_BecomeSeeker_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AHideNSneakCPPCharacter_BecomeSeeker()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AHideNSneakCPPCharacter_BecomeSeeker_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AHideNSneakCPPCharacter_CaptureHiders_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AHideNSneakCPPCharacter_CaptureHiders_Statics::Function_MetaDataParams[] = {
		{ "Category", "Seeker" },
		{ "Comment", "// Entry to capturing hiders\n" },
		{ "ModuleRelativePath", "HideNSneakCPPCharacter.h" },
		{ "ToolTip", "Entry to capturing hiders" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AHideNSneakCPPCharacter_CaptureHiders_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AHideNSneakCPPCharacter, nullptr, "CaptureHiders", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AHideNSneakCPPCharacter_CaptureHiders_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AHideNSneakCPPCharacter_CaptureHiders_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AHideNSneakCPPCharacter_CaptureHiders()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AHideNSneakCPPCharacter_CaptureHiders_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AHideNSneakCPPCharacter_IsSeeker_Statics
	{
		struct HideNSneakCPPCharacter_eventIsSeeker_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AHideNSneakCPPCharacter_IsSeeker_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((HideNSneakCPPCharacter_eventIsSeeker_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AHideNSneakCPPCharacter_IsSeeker_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(HideNSneakCPPCharacter_eventIsSeeker_Parms), &Z_Construct_UFunction_AHideNSneakCPPCharacter_IsSeeker_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AHideNSneakCPPCharacter_IsSeeker_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AHideNSneakCPPCharacter_IsSeeker_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AHideNSneakCPPCharacter_IsSeeker_Statics::Function_MetaDataParams[] = {
		{ "Category", "Seeker" },
		{ "Comment", "// Returns true if the character is a seeker\n" },
		{ "ModuleRelativePath", "HideNSneakCPPCharacter.h" },
		{ "ToolTip", "Returns true if the character is a seeker" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AHideNSneakCPPCharacter_IsSeeker_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AHideNSneakCPPCharacter, nullptr, "IsSeeker", nullptr, nullptr, sizeof(HideNSneakCPPCharacter_eventIsSeeker_Parms), Z_Construct_UFunction_AHideNSneakCPPCharacter_IsSeeker_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AHideNSneakCPPCharacter_IsSeeker_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AHideNSneakCPPCharacter_IsSeeker_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AHideNSneakCPPCharacter_IsSeeker_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AHideNSneakCPPCharacter_IsSeeker()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AHideNSneakCPPCharacter_IsSeeker_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AHideNSneakCPPCharacter_OnCompHit_Statics
	{
		struct HideNSneakCPPCharacter_eventOnCompHit_Parms
		{
			UPrimitiveComponent* HitComp;
			AActor* OtherActor;
			UPrimitiveComponent* OtherComp;
			FVector NormalImpulse;
			FHitResult Hit;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Hit_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Hit;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_NormalImpulse;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OtherComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherComp;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HitComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_HitComp;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AHideNSneakCPPCharacter_OnCompHit_Statics::NewProp_Hit_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AHideNSneakCPPCharacter_OnCompHit_Statics::NewProp_Hit = { "Hit", nullptr, (EPropertyFlags)0x0010008008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(HideNSneakCPPCharacter_eventOnCompHit_Parms, Hit), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(Z_Construct_UFunction_AHideNSneakCPPCharacter_OnCompHit_Statics::NewProp_Hit_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AHideNSneakCPPCharacter_OnCompHit_Statics::NewProp_Hit_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AHideNSneakCPPCharacter_OnCompHit_Statics::NewProp_NormalImpulse = { "NormalImpulse", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(HideNSneakCPPCharacter_eventOnCompHit_Parms, NormalImpulse), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AHideNSneakCPPCharacter_OnCompHit_Statics::NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AHideNSneakCPPCharacter_OnCompHit_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(HideNSneakCPPCharacter_eventOnCompHit_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_AHideNSneakCPPCharacter_OnCompHit_Statics::NewProp_OtherComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AHideNSneakCPPCharacter_OnCompHit_Statics::NewProp_OtherComp_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AHideNSneakCPPCharacter_OnCompHit_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(HideNSneakCPPCharacter_eventOnCompHit_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AHideNSneakCPPCharacter_OnCompHit_Statics::NewProp_HitComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AHideNSneakCPPCharacter_OnCompHit_Statics::NewProp_HitComp = { "HitComp", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(HideNSneakCPPCharacter_eventOnCompHit_Parms, HitComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_AHideNSneakCPPCharacter_OnCompHit_Statics::NewProp_HitComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AHideNSneakCPPCharacter_OnCompHit_Statics::NewProp_HitComp_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AHideNSneakCPPCharacter_OnCompHit_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AHideNSneakCPPCharacter_OnCompHit_Statics::NewProp_Hit,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AHideNSneakCPPCharacter_OnCompHit_Statics::NewProp_NormalImpulse,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AHideNSneakCPPCharacter_OnCompHit_Statics::NewProp_OtherComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AHideNSneakCPPCharacter_OnCompHit_Statics::NewProp_OtherActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AHideNSneakCPPCharacter_OnCompHit_Statics::NewProp_HitComp,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AHideNSneakCPPCharacter_OnCompHit_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "HideNSneakCPPCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AHideNSneakCPPCharacter_OnCompHit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AHideNSneakCPPCharacter, nullptr, "OnCompHit", nullptr, nullptr, sizeof(HideNSneakCPPCharacter_eventOnCompHit_Parms), Z_Construct_UFunction_AHideNSneakCPPCharacter_OnCompHit_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AHideNSneakCPPCharacter_OnCompHit_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C20401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AHideNSneakCPPCharacter_OnCompHit_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AHideNSneakCPPCharacter_OnCompHit_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AHideNSneakCPPCharacter_OnCompHit()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AHideNSneakCPPCharacter_OnCompHit_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AHideNSneakCPPCharacter_OnRep_IsSeeker_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AHideNSneakCPPCharacter_OnRep_IsSeeker_Statics::Function_MetaDataParams[] = {
		{ "Category", "Seeker" },
		{ "Comment", "// Is called on clients when bIsSeeker changes\n" },
		{ "ModuleRelativePath", "HideNSneakCPPCharacter.h" },
		{ "ToolTip", "Is called on clients when bIsSeeker changes" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AHideNSneakCPPCharacter_OnRep_IsSeeker_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AHideNSneakCPPCharacter, nullptr, "OnRep_IsSeeker", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AHideNSneakCPPCharacter_OnRep_IsSeeker_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AHideNSneakCPPCharacter_OnRep_IsSeeker_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AHideNSneakCPPCharacter_OnRep_IsSeeker()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AHideNSneakCPPCharacter_OnRep_IsSeeker_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AHideNSneakCPPCharacter_ServerCaptureHider_Statics
	{
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Hider;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AHideNSneakCPPCharacter_ServerCaptureHider_Statics::NewProp_Hider = { "Hider", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(HideNSneakCPPCharacter_eventServerCaptureHider_Parms, Hider), Z_Construct_UClass_AHideNSneakCPPCharacter_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AHideNSneakCPPCharacter_ServerCaptureHider_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AHideNSneakCPPCharacter_ServerCaptureHider_Statics::NewProp_Hider,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AHideNSneakCPPCharacter_ServerCaptureHider_Statics::Function_MetaDataParams[] = {
		{ "Comment", "// Server side handling of capturing hiders\n" },
		{ "ModuleRelativePath", "HideNSneakCPPCharacter.h" },
		{ "ToolTip", "Server side handling of capturing hiders" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AHideNSneakCPPCharacter_ServerCaptureHider_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AHideNSneakCPPCharacter, nullptr, "ServerCaptureHider", nullptr, nullptr, sizeof(HideNSneakCPPCharacter_eventServerCaptureHider_Parms), Z_Construct_UFunction_AHideNSneakCPPCharacter_ServerCaptureHider_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AHideNSneakCPPCharacter_ServerCaptureHider_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00280CC0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AHideNSneakCPPCharacter_ServerCaptureHider_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AHideNSneakCPPCharacter_ServerCaptureHider_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AHideNSneakCPPCharacter_ServerCaptureHider()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AHideNSneakCPPCharacter_ServerCaptureHider_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AHideNSneakCPPCharacter_TurnIntoSeeker_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AHideNSneakCPPCharacter_TurnIntoSeeker_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "HideNSneakCPPCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AHideNSneakCPPCharacter_TurnIntoSeeker_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AHideNSneakCPPCharacter, nullptr, "TurnIntoSeeker", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AHideNSneakCPPCharacter_TurnIntoSeeker_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AHideNSneakCPPCharacter_TurnIntoSeeker_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AHideNSneakCPPCharacter_TurnIntoSeeker()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AHideNSneakCPPCharacter_TurnIntoSeeker_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AHideNSneakCPPCharacter_NoRegister()
	{
		return AHideNSneakCPPCharacter::StaticClass();
	}
	struct Z_Construct_UClass_AHideNSneakCPPCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SpeedFactor_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_SpeedFactor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BaseSpeed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_BaseSpeed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIsSeeker_MetaData[];
#endif
		static void NewProp_bIsSeeker_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsSeeker;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_targetTagMechanic_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_targetTagMechanic;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_targetActor_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_targetActor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_isSeeker_MetaData[];
#endif
		static void NewProp_isSeeker_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_isSeeker;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BaseLookUpRate_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_BaseLookUpRate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BaseTurnRate_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_BaseTurnRate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CaptureSphereRadius_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_CaptureSphereRadius;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CaptureSphere_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CaptureSphere;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FollowCamera_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_FollowCamera;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CameraBoom;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_HideNSneakUnreal,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AHideNSneakCPPCharacter_BecomeSeeker, "BecomeSeeker" }, // 3016236252
		{ &Z_Construct_UFunction_AHideNSneakCPPCharacter_CaptureHiders, "CaptureHiders" }, // 891211711
		{ &Z_Construct_UFunction_AHideNSneakCPPCharacter_IsSeeker, "IsSeeker" }, // 3410833968
		{ &Z_Construct_UFunction_AHideNSneakCPPCharacter_OnCompHit, "OnCompHit" }, // 3130080232
		{ &Z_Construct_UFunction_AHideNSneakCPPCharacter_OnRep_IsSeeker, "OnRep_IsSeeker" }, // 887841532
		{ &Z_Construct_UFunction_AHideNSneakCPPCharacter_ServerCaptureHider, "ServerCaptureHider" }, // 3176931346
		{ &Z_Construct_UFunction_AHideNSneakCPPCharacter_TurnIntoSeeker, "TurnIntoSeeker" }, // 912263735
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "HideNSneakCPPCharacter.h" },
		{ "ModuleRelativePath", "HideNSneakCPPCharacter.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_SpeedFactor_MetaData[] = {
		{ "BlueprintProtected", "true" },
		{ "Category", "MovementSpeed" },
		{ "Comment", "// Multiplier for controlling current speed depending on role\n" },
		{ "ModuleRelativePath", "HideNSneakCPPCharacter.h" },
		{ "ToolTip", "Multiplier for controlling current speed depending on role" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_SpeedFactor = { "SpeedFactor", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AHideNSneakCPPCharacter, SpeedFactor), METADATA_PARAMS(Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_SpeedFactor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_SpeedFactor_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_BaseSpeed_MetaData[] = {
		{ "BlueprintProtected", "true" },
		{ "Category", "MovementSpeed" },
		{ "Comment", "// Base speed for characters\n" },
		{ "ModuleRelativePath", "HideNSneakCPPCharacter.h" },
		{ "ToolTip", "Base speed for characters" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_BaseSpeed = { "BaseSpeed", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AHideNSneakCPPCharacter, BaseSpeed), METADATA_PARAMS(Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_BaseSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_BaseSpeed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_bIsSeeker_MetaData[] = {
		{ "BlueprintProtected", "true" },
		{ "Category", "Seeker" },
		{ "Comment", "// Wether this character is a seeker or hider\n" },
		{ "ModuleRelativePath", "HideNSneakCPPCharacter.h" },
		{ "ToolTip", "Wether this character is a seeker or hider" },
	};
#endif
	void Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_bIsSeeker_SetBit(void* Obj)
	{
		((AHideNSneakCPPCharacter*)Obj)->bIsSeeker = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_bIsSeeker = { "bIsSeeker", "OnRep_IsSeeker", (EPropertyFlags)0x0020080100020025, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AHideNSneakCPPCharacter), &Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_bIsSeeker_SetBit, METADATA_PARAMS(Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_bIsSeeker_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_bIsSeeker_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_targetTagMechanic_MetaData[] = {
		{ "Category", "HideNSneakCPPCharacter" },
		{ "ModuleRelativePath", "HideNSneakCPPCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_targetTagMechanic = { "targetTagMechanic", nullptr, (EPropertyFlags)0x0010000000020001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AHideNSneakCPPCharacter, targetTagMechanic), Z_Construct_UClass_AHideNSneakCPPCharacter_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_targetTagMechanic_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_targetTagMechanic_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_targetActor_MetaData[] = {
		{ "Category", "HideNSneakCPPCharacter" },
		{ "ModuleRelativePath", "HideNSneakCPPCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_targetActor = { "targetActor", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AHideNSneakCPPCharacter, targetActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_targetActor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_targetActor_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_isSeeker_MetaData[] = {
		{ "Category", "HideNSneakCPPCharacter" },
		{ "ModuleRelativePath", "HideNSneakCPPCharacter.h" },
	};
#endif
	void Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_isSeeker_SetBit(void* Obj)
	{
		((AHideNSneakCPPCharacter*)Obj)->isSeeker = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_isSeeker = { "isSeeker", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AHideNSneakCPPCharacter), &Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_isSeeker_SetBit, METADATA_PARAMS(Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_isSeeker_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_isSeeker_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_BaseLookUpRate_MetaData[] = {
		{ "Category", "Camera" },
		{ "Comment", "/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */" },
		{ "ModuleRelativePath", "HideNSneakCPPCharacter.h" },
		{ "ToolTip", "Base look up/down rate, in deg/sec. Other scaling may affect final rate." },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_BaseLookUpRate = { "BaseLookUpRate", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AHideNSneakCPPCharacter, BaseLookUpRate), METADATA_PARAMS(Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_BaseLookUpRate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_BaseLookUpRate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_BaseTurnRate_MetaData[] = {
		{ "Category", "Camera" },
		{ "Comment", "/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */" },
		{ "ModuleRelativePath", "HideNSneakCPPCharacter.h" },
		{ "ToolTip", "Base turn rate, in deg/sec. Other scaling may affect final turn rate." },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_BaseTurnRate = { "BaseTurnRate", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AHideNSneakCPPCharacter, BaseTurnRate), METADATA_PARAMS(Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_BaseTurnRate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_BaseTurnRate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_CaptureSphereRadius_MetaData[] = {
		{ "AllowPrivateAcces", "true" },
		{ "Category", "Seeker" },
		{ "Comment", "// Variable collection sphere radius, can be changed in the editor\n" },
		{ "ModuleRelativePath", "HideNSneakCPPCharacter.h" },
		{ "ToolTip", "Variable collection sphere radius, can be changed in the editor" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_CaptureSphereRadius = { "CaptureSphereRadius", nullptr, (EPropertyFlags)0x0040000000020021, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AHideNSneakCPPCharacter, CaptureSphereRadius), METADATA_PARAMS(Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_CaptureSphereRadius_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_CaptureSphereRadius_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_CaptureSphere_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Seeker" },
		{ "Comment", "/** Collection Sphere */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "HideNSneakCPPCharacter.h" },
		{ "ToolTip", "Collection Sphere" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_CaptureSphere = { "CaptureSphere", nullptr, (EPropertyFlags)0x00400000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AHideNSneakCPPCharacter, CaptureSphere), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_CaptureSphere_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_CaptureSphere_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_FollowCamera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "/** Follow camera */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "HideNSneakCPPCharacter.h" },
		{ "ToolTip", "Follow camera" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_FollowCamera = { "FollowCamera", nullptr, (EPropertyFlags)0x00400000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AHideNSneakCPPCharacter, FollowCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_FollowCamera_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_FollowCamera_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_CameraBoom_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "/** Camera boom positioning the camera behind the character */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "HideNSneakCPPCharacter.h" },
		{ "ToolTip", "Camera boom positioning the camera behind the character" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_CameraBoom = { "CameraBoom", nullptr, (EPropertyFlags)0x00400000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AHideNSneakCPPCharacter, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_CameraBoom_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_CameraBoom_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_SpeedFactor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_BaseSpeed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_bIsSeeker,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_targetTagMechanic,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_targetActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_isSeeker,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_BaseLookUpRate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_BaseTurnRate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_CaptureSphereRadius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_CaptureSphere,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_FollowCamera,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::NewProp_CameraBoom,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AHideNSneakCPPCharacter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::ClassParams = {
		&AHideNSneakCPPCharacter::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AHideNSneakCPPCharacter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AHideNSneakCPPCharacter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AHideNSneakCPPCharacter, 3314032809);
	template<> HIDENSNEAKUNREAL_API UClass* StaticClass<AHideNSneakCPPCharacter>()
	{
		return AHideNSneakCPPCharacter::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AHideNSneakCPPCharacter(Z_Construct_UClass_AHideNSneakCPPCharacter, &AHideNSneakCPPCharacter::StaticClass, TEXT("/Script/HideNSneakUnreal"), TEXT("AHideNSneakCPPCharacter"), false, nullptr, nullptr, nullptr);

	void AHideNSneakCPPCharacter::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
	{
		static const FName Name_CaptureSphereRadius(TEXT("CaptureSphereRadius"));
		static const FName Name_bIsSeeker(TEXT("bIsSeeker"));

		const bool bIsValid = true
			&& Name_CaptureSphereRadius == ClassReps[(int32)ENetFields_Private::CaptureSphereRadius].Property->GetFName()
			&& Name_bIsSeeker == ClassReps[(int32)ENetFields_Private::bIsSeeker].Property->GetFName();

		checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in AHideNSneakCPPCharacter"));
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AHideNSneakCPPCharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
