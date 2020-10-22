// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HideNSneakUnreal/SpawnVolume.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSpawnVolume() {}
// Cross Module References
	HIDENSNEAKUNREAL_API UClass* Z_Construct_UClass_ASpawnVolume_NoRegister();
	HIDENSNEAKUNREAL_API UClass* Z_Construct_UClass_ASpawnVolume();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_HideNSneakUnreal();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	HIDENSNEAKUNREAL_API UClass* Z_Construct_UClass_APickup_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(ASpawnVolume::execGetRandomPointInVolume)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=P_THIS->GetRandomPointInVolume();
		P_NATIVE_END;
	}
	void ASpawnVolume::StaticRegisterNativesASpawnVolume()
	{
		UClass* Class = ASpawnVolume::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetRandomPointInVolume", &ASpawnVolume::execGetRandomPointInVolume },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASpawnVolume_GetRandomPointInVolume_Statics
	{
		struct SpawnVolume_eventGetRandomPointInVolume_Parms
		{
			FVector ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASpawnVolume_GetRandomPointInVolume_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SpawnVolume_eventGetRandomPointInVolume_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASpawnVolume_GetRandomPointInVolume_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASpawnVolume_GetRandomPointInVolume_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASpawnVolume_GetRandomPointInVolume_Statics::Function_MetaDataParams[] = {
		{ "Category", "Spawning" },
		{ "Comment", "/** Finds (and returns) a random point in the box component */" },
		{ "ModuleRelativePath", "SpawnVolume.h" },
		{ "ToolTip", "Finds (and returns) a random point in the box component" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASpawnVolume_GetRandomPointInVolume_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASpawnVolume, nullptr, "GetRandomPointInVolume", nullptr, nullptr, sizeof(SpawnVolume_eventGetRandomPointInVolume_Parms), Z_Construct_UFunction_ASpawnVolume_GetRandomPointInVolume_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASpawnVolume_GetRandomPointInVolume_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASpawnVolume_GetRandomPointInVolume_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASpawnVolume_GetRandomPointInVolume_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASpawnVolume_GetRandomPointInVolume()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASpawnVolume_GetRandomPointInVolume_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ASpawnVolume_NoRegister()
	{
		return ASpawnVolume::StaticClass();
	}
	struct Z_Construct_UClass_ASpawnVolume_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WhereToSpawn_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WhereToSpawn;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MinSpawnDelay_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MinSpawnDelay;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxSpawnDelay_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MaxSpawnDelay;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WhatToSpawn_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_WhatToSpawn;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASpawnVolume_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_HideNSneakUnreal,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASpawnVolume_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASpawnVolume_GetRandomPointInVolume, "GetRandomPointInVolume" }, // 3980924308
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASpawnVolume_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SpawnVolume.h" },
		{ "ModuleRelativePath", "SpawnVolume.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASpawnVolume_Statics::NewProp_WhereToSpawn_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Spawning" },
		{ "Comment", "/** This is  the area where pickups will be created */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SpawnVolume.h" },
		{ "ToolTip", "This is  the area where pickups will be created" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASpawnVolume_Statics::NewProp_WhereToSpawn = { "WhereToSpawn", nullptr, (EPropertyFlags)0x00400000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASpawnVolume, WhereToSpawn), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASpawnVolume_Statics::NewProp_WhereToSpawn_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASpawnVolume_Statics::NewProp_WhereToSpawn_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASpawnVolume_Statics::NewProp_MinSpawnDelay_MetaData[] = {
		{ "Category", "Spawning" },
		{ "Comment", "// Minimum time in seconds between spawnings\n" },
		{ "ModuleRelativePath", "SpawnVolume.h" },
		{ "ToolTip", "Minimum time in seconds between spawnings" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASpawnVolume_Statics::NewProp_MinSpawnDelay = { "MinSpawnDelay", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASpawnVolume, MinSpawnDelay), METADATA_PARAMS(Z_Construct_UClass_ASpawnVolume_Statics::NewProp_MinSpawnDelay_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASpawnVolume_Statics::NewProp_MinSpawnDelay_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASpawnVolume_Statics::NewProp_MaxSpawnDelay_MetaData[] = {
		{ "Category", "Spawning" },
		{ "Comment", "// Maximum time in seconds between spawnings\n" },
		{ "ModuleRelativePath", "SpawnVolume.h" },
		{ "ToolTip", "Maximum time in seconds between spawnings" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASpawnVolume_Statics::NewProp_MaxSpawnDelay = { "MaxSpawnDelay", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASpawnVolume, MaxSpawnDelay), METADATA_PARAMS(Z_Construct_UClass_ASpawnVolume_Statics::NewProp_MaxSpawnDelay_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASpawnVolume_Statics::NewProp_MaxSpawnDelay_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASpawnVolume_Statics::NewProp_WhatToSpawn_MetaData[] = {
		{ "Category", "Spawning" },
		{ "Comment", "/* This is the pickup to spawn */" },
		{ "ModuleRelativePath", "SpawnVolume.h" },
		{ "ToolTip", "This is the pickup to spawn" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_ASpawnVolume_Statics::NewProp_WhatToSpawn = { "WhatToSpawn", nullptr, (EPropertyFlags)0x0024080000000001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASpawnVolume, WhatToSpawn), Z_Construct_UClass_APickup_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_ASpawnVolume_Statics::NewProp_WhatToSpawn_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASpawnVolume_Statics::NewProp_WhatToSpawn_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASpawnVolume_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpawnVolume_Statics::NewProp_WhereToSpawn,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpawnVolume_Statics::NewProp_MinSpawnDelay,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpawnVolume_Statics::NewProp_MaxSpawnDelay,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpawnVolume_Statics::NewProp_WhatToSpawn,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASpawnVolume_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASpawnVolume>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ASpawnVolume_Statics::ClassParams = {
		&ASpawnVolume::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ASpawnVolume_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ASpawnVolume_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASpawnVolume_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASpawnVolume_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASpawnVolume()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ASpawnVolume_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ASpawnVolume, 1359780647);
	template<> HIDENSNEAKUNREAL_API UClass* StaticClass<ASpawnVolume>()
	{
		return ASpawnVolume::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASpawnVolume(Z_Construct_UClass_ASpawnVolume, &ASpawnVolume::StaticClass, TEXT("/Script/HideNSneakUnreal"), TEXT("ASpawnVolume"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASpawnVolume);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
