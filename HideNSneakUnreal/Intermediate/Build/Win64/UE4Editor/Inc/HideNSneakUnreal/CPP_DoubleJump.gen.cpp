// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HideNSneakUnreal/CPP_DoubleJump.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCPP_DoubleJump() {}
// Cross Module References
	HIDENSNEAKUNREAL_API UClass* Z_Construct_UClass_ACPP_DoubleJump_NoRegister();
	HIDENSNEAKUNREAL_API UClass* Z_Construct_UClass_ACPP_DoubleJump();
	HIDENSNEAKUNREAL_API UClass* Z_Construct_UClass_ACPP_Powerup();
	UPackage* Z_Construct_UPackage__Script_HideNSneakUnreal();
// End Cross Module References
	void ACPP_DoubleJump::StaticRegisterNativesACPP_DoubleJump()
	{
	}
	UClass* Z_Construct_UClass_ACPP_DoubleJump_NoRegister()
	{
		return ACPP_DoubleJump::StaticClass();
	}
	struct Z_Construct_UClass_ACPP_DoubleJump_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACPP_DoubleJump_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACPP_Powerup,
		(UObject* (*)())Z_Construct_UPackage__Script_HideNSneakUnreal,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPP_DoubleJump_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "CPP_DoubleJump.h" },
		{ "ModuleRelativePath", "CPP_DoubleJump.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACPP_DoubleJump_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACPP_DoubleJump>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ACPP_DoubleJump_Statics::ClassParams = {
		&ACPP_DoubleJump::StaticClass,
		"Engine",
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
		METADATA_PARAMS(Z_Construct_UClass_ACPP_DoubleJump_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_DoubleJump_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACPP_DoubleJump()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ACPP_DoubleJump_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ACPP_DoubleJump, 2824298825);
	template<> HIDENSNEAKUNREAL_API UClass* StaticClass<ACPP_DoubleJump>()
	{
		return ACPP_DoubleJump::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACPP_DoubleJump(Z_Construct_UClass_ACPP_DoubleJump, &ACPP_DoubleJump::StaticClass, TEXT("/Script/HideNSneakUnreal"), TEXT("ACPP_DoubleJump"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACPP_DoubleJump);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
