// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HideNSneakUnreal/OnlineGameInstance.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOnlineGameInstance() {}
// Cross Module References
	HIDENSNEAKUNREAL_API UClass* Z_Construct_UClass_UOnlineGameInstance_NoRegister();
	HIDENSNEAKUNREAL_API UClass* Z_Construct_UClass_UOnlineGameInstance();
	ENGINE_API UClass* Z_Construct_UClass_UGameInstance();
	UPackage* Z_Construct_UPackage__Script_HideNSneakUnreal();
// End Cross Module References
	void UOnlineGameInstance::StaticRegisterNativesUOnlineGameInstance()
	{
	}
	UClass* Z_Construct_UClass_UOnlineGameInstance_NoRegister()
	{
		return UOnlineGameInstance::StaticClass();
	}
	struct Z_Construct_UClass_UOnlineGameInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UOnlineGameInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_HideNSneakUnreal,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOnlineGameInstance_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "OnlineGameInstance.h" },
		{ "ModuleRelativePath", "OnlineGameInstance.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UOnlineGameInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOnlineGameInstance>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UOnlineGameInstance_Statics::ClassParams = {
		&UOnlineGameInstance::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000A8u,
		METADATA_PARAMS(Z_Construct_UClass_UOnlineGameInstance_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UOnlineGameInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UOnlineGameInstance()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UOnlineGameInstance_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UOnlineGameInstance, 924860004);
	template<> HIDENSNEAKUNREAL_API UClass* StaticClass<UOnlineGameInstance>()
	{
		return UOnlineGameInstance::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UOnlineGameInstance(Z_Construct_UClass_UOnlineGameInstance, &UOnlineGameInstance::StaticClass, TEXT("/Script/HideNSneakUnreal"), TEXT("UOnlineGameInstance"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOnlineGameInstance);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
