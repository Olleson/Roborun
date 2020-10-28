// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HideNSneakUnreal/batman.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodebatman() {}
// Cross Module References
	HIDENSNEAKUNREAL_API UClass* Z_Construct_UClass_Abatman_NoRegister();
	HIDENSNEAKUNREAL_API UClass* Z_Construct_UClass_Abatman();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_HideNSneakUnreal();
// End Cross Module References
	void Abatman::StaticRegisterNativesAbatman()
	{
	}
	UClass* Z_Construct_UClass_Abatman_NoRegister()
	{
		return Abatman::StaticClass();
	}
	struct Z_Construct_UClass_Abatman_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_Abatman_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_HideNSneakUnreal,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_Abatman_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "batman.h" },
		{ "ModuleRelativePath", "batman.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_Abatman_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<Abatman>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_Abatman_Statics::ClassParams = {
		&Abatman::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_Abatman_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_Abatman_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_Abatman()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_Abatman_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(Abatman, 2026768291);
	template<> HIDENSNEAKUNREAL_API UClass* StaticClass<Abatman>()
	{
		return Abatman::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_Abatman(Z_Construct_UClass_Abatman, &Abatman::StaticClass, TEXT("/Script/HideNSneakUnreal"), TEXT("Abatman"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(Abatman);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
