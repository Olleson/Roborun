// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HideNSneakUnreal/CPP_SpeedBoost.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCPP_SpeedBoost() {}
// Cross Module References
	HIDENSNEAKUNREAL_API UClass* Z_Construct_UClass_ACPP_SpeedBoost_NoRegister();
	HIDENSNEAKUNREAL_API UClass* Z_Construct_UClass_ACPP_SpeedBoost();
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	UPackage* Z_Construct_UPackage__Script_HideNSneakUnreal();
// End Cross Module References
	void ACPP_SpeedBoost::StaticRegisterNativesACPP_SpeedBoost()
	{
	}
	UClass* Z_Construct_UClass_ACPP_SpeedBoost_NoRegister()
	{
		return ACPP_SpeedBoost::StaticClass();
	}
	struct Z_Construct_UClass_ACPP_SpeedBoost_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACPP_SpeedBoost_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APawn,
		(UObject* (*)())Z_Construct_UPackage__Script_HideNSneakUnreal,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPP_SpeedBoost_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "CPP_SpeedBoost.h" },
		{ "ModuleRelativePath", "CPP_SpeedBoost.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACPP_SpeedBoost_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACPP_SpeedBoost>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ACPP_SpeedBoost_Statics::ClassParams = {
		&ACPP_SpeedBoost::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ACPP_SpeedBoost_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_SpeedBoost_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACPP_SpeedBoost()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ACPP_SpeedBoost_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ACPP_SpeedBoost, 768252476);
	template<> HIDENSNEAKUNREAL_API UClass* StaticClass<ACPP_SpeedBoost>()
	{
		return ACPP_SpeedBoost::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACPP_SpeedBoost(Z_Construct_UClass_ACPP_SpeedBoost, &ACPP_SpeedBoost::StaticClass, TEXT("/Script/HideNSneakUnreal"), TEXT("ACPP_SpeedBoost"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACPP_SpeedBoost);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
