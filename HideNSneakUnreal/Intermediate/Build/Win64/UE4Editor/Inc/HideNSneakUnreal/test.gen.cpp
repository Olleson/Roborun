// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HideNSneakUnreal/test.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodetest() {}
// Cross Module References
	HIDENSNEAKUNREAL_API UClass* Z_Construct_UClass_Atest_NoRegister();
	HIDENSNEAKUNREAL_API UClass* Z_Construct_UClass_Atest();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_HideNSneakUnreal();
// End Cross Module References
	void Atest::StaticRegisterNativesAtest()
	{
	}
	UClass* Z_Construct_UClass_Atest_NoRegister()
	{
		return Atest::StaticClass();
	}
	struct Z_Construct_UClass_Atest_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_Atest_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_HideNSneakUnreal,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_Atest_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "test.h" },
		{ "ModuleRelativePath", "test.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_Atest_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<Atest>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_Atest_Statics::ClassParams = {
		&Atest::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_Atest_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_Atest_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_Atest()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_Atest_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(Atest, 2342404563);
	template<> HIDENSNEAKUNREAL_API UClass* StaticClass<Atest>()
	{
		return Atest::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_Atest(Z_Construct_UClass_Atest, &Atest::StaticClass, TEXT("/Script/HideNSneakUnreal"), TEXT("Atest"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(Atest);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
