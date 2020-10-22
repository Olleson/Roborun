// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HideNSneakUnreal/HideAndSneakGameState.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHideAndSneakGameState() {}
// Cross Module References
	HIDENSNEAKUNREAL_API UClass* Z_Construct_UClass_AHideAndSneakGameState_NoRegister();
	HIDENSNEAKUNREAL_API UClass* Z_Construct_UClass_AHideAndSneakGameState();
	ENGINE_API UClass* Z_Construct_UClass_AGameStateBase();
	UPackage* Z_Construct_UPackage__Script_HideNSneakUnreal();
// End Cross Module References
	void AHideAndSneakGameState::StaticRegisterNativesAHideAndSneakGameState()
	{
	}
	UClass* Z_Construct_UClass_AHideAndSneakGameState_NoRegister()
	{
		return AHideAndSneakGameState::StaticClass();
	}
	struct Z_Construct_UClass_AHideAndSneakGameState_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AHideAndSneakGameState_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameStateBase,
		(UObject* (*)())Z_Construct_UPackage__Script_HideNSneakUnreal,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHideAndSneakGameState_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "HideAndSneakGameState.h" },
		{ "ModuleRelativePath", "HideAndSneakGameState.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AHideAndSneakGameState_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AHideAndSneakGameState>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AHideAndSneakGameState_Statics::ClassParams = {
		&AHideAndSneakGameState::StaticClass,
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
		0x009002A4u,
		METADATA_PARAMS(Z_Construct_UClass_AHideAndSneakGameState_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AHideAndSneakGameState_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AHideAndSneakGameState()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AHideAndSneakGameState_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AHideAndSneakGameState, 2460319286);
	template<> HIDENSNEAKUNREAL_API UClass* StaticClass<AHideAndSneakGameState>()
	{
		return AHideAndSneakGameState::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AHideAndSneakGameState(Z_Construct_UClass_AHideAndSneakGameState, &AHideAndSneakGameState::StaticClass, TEXT("/Script/HideNSneakUnreal"), TEXT("AHideAndSneakGameState"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AHideAndSneakGameState);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
