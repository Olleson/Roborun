// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HideNSneakUnreal/HideNSneakGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHideNSneakGameModeBase() {}
// Cross Module References
	HIDENSNEAKUNREAL_API UClass* Z_Construct_UClass_AHideNSneakGameModeBase_NoRegister();
	HIDENSNEAKUNREAL_API UClass* Z_Construct_UClass_AHideNSneakGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_HideNSneakUnreal();
// End Cross Module References
	void AHideNSneakGameModeBase::StaticRegisterNativesAHideNSneakGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_AHideNSneakGameModeBase_NoRegister()
	{
		return AHideNSneakGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AHideNSneakGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AHideNSneakGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_HideNSneakUnreal,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHideNSneakGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "HideNSneakGameModeBase.h" },
		{ "ModuleRelativePath", "HideNSneakGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AHideNSneakGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AHideNSneakGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AHideNSneakGameModeBase_Statics::ClassParams = {
		&AHideNSneakGameModeBase::StaticClass,
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
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AHideNSneakGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AHideNSneakGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AHideNSneakGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AHideNSneakGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AHideNSneakGameModeBase, 3515841876);
	template<> HIDENSNEAKUNREAL_API UClass* StaticClass<AHideNSneakGameModeBase>()
	{
		return AHideNSneakGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AHideNSneakGameModeBase(Z_Construct_UClass_AHideNSneakGameModeBase, &AHideNSneakGameModeBase::StaticClass, TEXT("/Script/HideNSneakUnreal"), TEXT("AHideNSneakGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AHideNSneakGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
